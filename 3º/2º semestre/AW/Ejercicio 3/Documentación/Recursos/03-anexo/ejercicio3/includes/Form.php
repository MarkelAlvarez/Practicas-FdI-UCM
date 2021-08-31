<?php
namespace es\ucm\fdi\aw;

/**
 * Clase base para la gestión de formularios.
 *
 * Además de la gestión básica de los formularios.
 */
abstract class Form
{

    /**
     * @var string Cadena utilizada como valor del atributo "id" de la etiqueta &lt;form&gt; asociada al formulario y 
     * como parámetro a comprobar para verificar que el usuario ha enviado el formulario.
     */
    private $formId;

    /**
     * @var string URL asociada al atributo "action" de la etiqueta &lt;form&gt; del fomrulario y que procesará el 
     * envío del formulario.
     */
    private $action;

    /**
     * Crea un nuevo formulario.
     *
     * Posibles opciones:
     * <table>
     *   <thead>
     *     <tr>
     *       <th>Opción</th>
     *       <th>Valor por defecto</th>
     *       <th>Descripción</th>
     *     </tr>
     *   </thead>
     *   <tbody>
     *     <tr>
     *       <td>action</td>
     *       <td><code>$_SERVER['PHP_SELF']</code></td>       
     *       <td>URL asociada al atributo "action" de la etiqueta &lt;form&gt; del fomrulario y que procesará el envío del formulario.</td>
     *     </tr>
     *   </tbody>
     * </table>

     * @param string $formId    Identificador utilizado en el atributo "id" de la etiqueta &lt;form&gt; asociada al formulario y como parámetro
     *                          a comprobar para verificar que el usuario ha enviado el formulario.
     *
     * @param array $opciones (ver más arriba).
     */
    public function __construct($formId, $opciones = array() )
    {
        $this->formId = $formId;

        $opcionesPorDefecto = array( 'action' => null, );
        $opciones = array_merge($opcionesPorDefecto, $opciones);

        $this->action   = $opciones['action'];
        
        if ( !$this->action ) {
            $this->action = htmlentities($_SERVER['PHP_SELF']);
        }
    }
  
    /**
     * Se encarga de orquestar todo el proceso de gestión de un formulario.
     * 
     * El proceso es el siguiente:
     * <ul>
     *   <li>O bien se quiere mostrar el formulario (petición GET)</li>
     *   <li>O bien hay que procesar el formulario (petición POST) y hay dos situaciones:
     *     <ul>
     *       <li>El formulario se ha procesado correctamente y se devuelve un <code>string</code> en {@see Form::procesaFormulario()}
     *           que será la URL a la que se rederigirá al usuario. Se redirige al usuario y se termina la ejecución del script.</li>
     *       <li>El formulario NO se ha procesado correctamente (errores en los datos, datos incorrectos, etc.) y se devuelve
     *           un <code>array</code> con entradas (campo, mensaje) con errores específicos para un campo o (entero, mensaje) si el mensaje
     *           es un mensaje que afecta globalmente al formulario. Se vuelve a generar el formulario pasándole el array de errores.</li> 
     *     </ul>
     *   </li>
     * </ul>
     */
    public function gestiona()
    {   
        if ( ! $this->formularioEnviado($_POST) ) {
            return $this->generaFormulario();
        } else {
            $result = $this->procesaFormulario($_POST);
            if ( is_array($result) ) {
                return $this->generaFormulario($_POST, $result);
            } else {
                header('Location: '.$result);
                exit();
            }
        }  
    }

    /**
     * Genera el HTML necesario para presentar los campos del formulario.
     * 
     * Si el formulario ya ha sido enviado y hay errores en {@see Form::procesaFormulario()} se llama a este método
     * nuevamente con los datos que ha introducido el usuario en <code>$datosIniciales</code> y los errores al procesar
     * el formulario en <code>$errores</code>
     *
     * @param string[] $datosIniciales Datos iniciales para los campos del formulario (normalmente <code>$_POST</code>).
     *
     * @param string[] $errores (opcional)Lista / Tabla asociativa de errores asociados al formulario.
     * 
     * @return string HTML asociado a los campos del formulario.
     */
    protected function generaCamposFormulario($datosIniciales, $errores = array())
    {
        return '';
    }

    /**
     * Procesa los datos del formulario.
     *
     * @param string[] $datos Datos enviado por el usuario (normalmente <code>$_POST</code>).
     *
     * @return string|string[] Devuelve el resultado del procesamiento del formulario, normalmente una URL a la que
     * se desea que se redirija al usuario, o un array con los errores que ha habido durante el procesamiento del formulario.
     */
    protected function procesaFormulario($datos)
    {
        return array();
    }
  
    /**
     * Función que verifica si el usuario ha enviado el formulario.
     * 
     * Comprueba si existe el parámetro <code>$formId</code> en <code>$params</code>.
     *
     * @param string[] $params Array que contiene los datos recibidos en el envío formulario.
     *
     * @return boolean Devuelve <code>true</code> si <code>$formId</code> existe como clave en <code>$params</code>
     */
    private function formularioEnviado(&$params)
    {
        return isset($params['action']) && $params['action'] == $this->formId;
    } 

    /**
     * Función que genera el HTML necesario para el formulario.
     *
     * @param string[] $datos (opcional) Array con los valores por defecto de los campos del formulario.
     *
     * @param string[] $errores (opcional) Array con los mensajes de error de validación y/o procesamiento del formulario.
     *
     * @return string HTML asociado al formulario.
     */
    private function generaFormulario(&$datos = array(), &$errores = array())
    {
        $htmlCamposFormularios = $this->generaCamposFormulario($datos, $errores);

        /* <<< Permite definir cadena en múltiples líneas.
         * Revisa https://www.php.net/manual/en/language.types.string.php#language.types.string.syntax.heredoc
         */
        $htmlForm = <<<EOS
            <form method="POST" action="$this->action" id="$this->formId" >
                <input type="hidden" name="action" value="$this->formId" />
                $htmlCamposFormularios
            </form>
        EOS;
        return $htmlForm;
    }

    /**
     * Genera la lista de mensajes de errores globales (no asociada a un campo) a incluir en el formulario.
     *
     * @param string[] $errores (opcional) Array con los mensajes de error de validación y/o procesamiento del formulario.
     *
     * @param string $classAtt (opcional) Valor del atributo class de la lista de errores.
     *
     * @return string El HTML asociado a los mensajes de error.
     */
    protected static function generaListaErroresGlobales($errores = array(), $classAtt='')
    {
        $html='';
        $clavesErroresGenerales = array_filter(array_keys($errores), function ($elem) {
            return is_numeric($elem);
        });

        $numErrores = count($clavesErroresGenerales);
        if ($numErrores > 0) {
            $html = "<ul class=\"$classAtt\">";
            if (  $numErrores == 1 ) {
                $html .= "<li>$errores[0]</li>";
            } else {
                foreach($clavesErroresGenerales as $clave) {
                    $html .= "<li>$errores[$clave]</li>";
                }
                $html .= "</li>";
            }
            $html .= '</ul>';
        }
        return $html;
    }

    /**
     * Crea una etiqueta para mostrar un mensaje de error. Sólo creará el mensaje de error
     * si existe una clave <code>$idError</code> dentro del array <code>$errores</code>.
     * 
     * @param string[] $errores     (opcional) Array con los mensajes de error de validación y/o procesamiento del formulario.
     * @param string   $idError     (opcional) Clave dentro de <code>$errores</code> del error a mostrar.
     * @param string   $htmlElement (opcional) Etiqueta HTML a crear para mostrar el error.
     * @param array    $atts        (opcional) Tabla asociativa con los atributos a añadir a la etiqueta que mostrará el error.
     */
    protected static function createMensajeError($errores=array(), $idError='', $htmlElement='span', $atts = array())
    {
        $html = '';
        if (isset($errores[$idError])) {
            $att = '';
            foreach($atts as $key => $value) {
                $att .= "$key=$value";
            }
            $html = " <$htmlElement $att>{$errores[$idError]}</$htmlElement>";
        }

        return $html;
    }
}
