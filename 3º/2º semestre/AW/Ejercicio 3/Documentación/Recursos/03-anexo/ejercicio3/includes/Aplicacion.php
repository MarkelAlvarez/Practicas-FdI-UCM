<?php
namespace es\ucm\fdi\aw;

/**
 * Clase que mantiene el estado global de la aplicación.
 */
class Aplicacion
{
	const ATTRIBUTO_SESSION_ATTRIBUTOS_PETICION = 'attsPeticion';

	private static $instancia;
	
	/**
	 * Devuele una instancia de {@see Aplicacion}.
	 * 
	 * @return Applicacion Obtiene la única instancia de la <code>Aplicacion</code>
	 */
	public static function getSingleton() {
		if (  !self::$instancia instanceof self) {
			self::$instancia = new self;
		}
		return self::$instancia;
	}

	/**
	 * @var array Almacena los datos de configuración de la BD
	 */
	private $bdDatosConexion;
	
	/**
	 * Almacena si la Aplicacion ya ha sido inicializada.
	 * 
	 * @var boolean
	 */
	private $inicializada = false;
	
	/**
	 * @var \mysqli Conexión de BD.
	 */
	private $conn;

	/**
	 * @var array Tabla asociativa con los atributos pendientes de la petición.
	 */
	private $atributosPeticion;
	
	/**
	 * Evita que se pueda instanciar la clase directamente.
	 */
	private function __construct() {
	}
	
	/**
	 * Evita que se pueda utilizar el operador clone.
	 */
	public function __clone()
	{
		throw new Exception('No tiene sentido el clonado');
	}


	/**
	 * Evita que se pueda utilizar serialize().
	 */
	public function __sleep()
	{
		throw new Exception('No tiene sentido el serializar el objeto');
	}

	/**
	 * Evita que se pueda utilizar unserialize().
	 */
	public function __wakeup()
	{
		throw new Exception('No tiene sentido el deserializar el objeto');
	}
	
	/**
	 * Inicializa la aplicación.
	 * 
	 * @param array $bdDatosConexion datos de configuración de la BD
	 */
	public function init($bdDatosConexion)
	{
        if ( ! $this->inicializada ) {
    	    $this->bdDatosConexion = $bdDatosConexion;
    		
			session_start();

			/* Se inicializa los atributos asociados a la petición en base a la sesión y se eliminan para que
			 * no estén disponibles después de la gestión de esta petición.
			 */
			$this->atributosPeticion = $_SESSION[self::ATTRIBUTO_SESSION_ATTRIBUTOS_PETICION] ?? array();
			unset($_SESSION[self::ATTRIBUTO_SESSION_ATTRIBUTOS_PETICION]);

    		$this->inicializada = true;
        }
	}
	
	/**
	 * Cierre de la aplicación.
	 */
	public function shutdown()
	{
	    $this->compruebaInstanciaInicializada();
	    if ($this->conn !== null && ! $this->conn->connect_errno) {
	        $this->conn->close();
	    }
	}
	
	/**
	 * Comprueba si la aplicación está inicializada. Si no lo está muestra un mensaje y termina la ejecución.
	 */
	private function compruebaInstanciaInicializada()
	{
	    if (! $this->inicializada ) {
	        echo "Aplicacion no inicializa";
	        exit();
	    }
	}
	
	/**
	 * Devuelve una conexión a la BD. Se encarga de que exista como mucho una conexión a la BD por petición.
	 * 
	 * @return \mysqli Conexión a MySQL.
	 */
	public function conexionBd()
	{
	    $this->compruebaInstanciaInicializada();
		if (! $this->conn ) {
			$bdHost = $this->bdDatosConexion['host'];
			$bdUser = $this->bdDatosConexion['user'];
			$bdPass = $this->bdDatosConexion['pass'];
			$bd = $this->bdDatosConexion['bd'];
			
			$driver = new \mysqli_driver();
			$driver->report_mode = MYSQLI_REPORT_ERROR | MYSQLI_REPORT_STRICT;
			$this->conn = new \mysqli($bdHost, $bdUser, $bdPass, $bd);
			if ( $this->conn->connect_errno ) {
			    throw new \Exception("Error de conexión a la BD: (" . $this->conn->connect_errno . ") " . utf8_encode($this->conn->connect_error));
			}
			if ( ! $this->conn->set_charset("utf8mb4")) {
			    throw new \Exception("Error al configurar la codificación de la BD: (" . $this->conn->errno . ") " . utf8_encode($this->conn->error));
			}
		}
		return $this->conn;
	}

	/**
	 * Añade un atributo <code>$valor</code> para que esté disponible en la siguiente petición bajo la clave <code>$clave</code>.
	 * 
	 * @param string $clave Clave bajo la que almacenar el atributo.
	 * @param any    $valor Valor a almacenar como atributo de la petición.
	 * 
	 */
	public function putAtributoPeticion($clave, $valor)
	{
		$atts = null;
		if (isset($_SESSION[self::ATTRIBUTO_SESSION_ATTRIBUTOS_PETICION])) {
			$atts = &$_SESSION[self::ATTRIBUTO_SESSION_ATTRIBUTOS_PETICION];
		} else {
			$atts = array();
			$_SESSION[self::ATTRIBUTO_SESSION_ATTRIBUTOS_PETICION] = &$atts;
		}
		$atts[$clave] = $valor;
	}

	/**
	 * Devuelve un atributo establecido en la petición actual o en la petición justamente anterior.
	 * 
	 * 
	 * @param string $clave Clave sobre la que buscar el atributo.
	 * 
	 * @return any Attributo asociado a la sesión bajo la clave <code>$clave</code> o <code>null</code> si no existe.
	 */
	public function getAtributoPeticion($clave)
	{
		$result = $this->atributosPeticion[$clave] ?? null;
		if(is_null($result) && isset($_SESSION[self::ATTRIBUTO_SESSION_ATTRIBUTOS_PETICION])) {
			$result = $_SESSION[self::ATTRIBUTO_SESSION_ATTRIBUTOS_PETICION][$clave] ?? null;
		}
		return $result;
	}
}