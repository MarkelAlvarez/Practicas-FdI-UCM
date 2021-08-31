<?php
require_once __DIR__.'/includes/config.php';
require_once __DIR__.'/includes/Usuario.php';

if (! isset($_POST['login']) ) {
	header('Location: login.php');
	exit();
}

$tituloPagina = 'Login';

$contenidoPrincipal = '';

$erroresFormulario = array();

$nombreUsuario = isset($_POST['nombreUsuario']) ? $_POST['nombreUsuario'] : null;

if ( empty($nombreUsuario) ) {
	$erroresFormulario['nombreUsuario'] = "El nombre de usuario no puede estar vacío";
}

$password = isset($_POST['password']) ? $_POST['password'] : null;
if ( empty($password) ) {
	$erroresFormulario['password'] = "El password no puede estar vacío.";
}

if (count($erroresFormulario) === 0) {
    $usuario = Usuario::buscaUsuario($nombreUsuario);

	if (!$usuario) {
		$erroresFormulario[] = "El usuario o el password no coinciden";
	} else {
	    if ( $usuario->compruebaPassword($password) ) {
    		$_SESSION['login'] = true;
    		$_SESSION['nombre'] = $nombreUsuario;
    		$_SESSION['esAdmin'] = strcmp($fila['rol'], 'admin') == 0 ? true : false;
    		header('Location: index.php');
    		exit();
	    } else {
	        $erroresFormulario[] = "El usuario o el password no coinciden";
	    }
	}
}

if (isset($_SESSION["login"])) {
	$contenidoPrincipal .= <<<EOS
	<h1>Bienvenido {$_SESSION[nombre]}</h1>
	<p>Usa el menú de la izquierda para navegar.</p>
	EOS;
} else {
	$contenidoPrincipal .= <<<EOS
	<form action="procesarLogin.php" method="POST">
	<h1>ERROR</h1>
	EOS;
	if (count($erroresFormulario) > 0) {
		$contenidoPrincipal .= '<ul class="errores">';
	}
	foreach($erroresFormulario as $clave => $error) {
		if (is_numeric($clave)) {
			$contenidoPrincipal .= "<li>$error</li>";
		}
	}
	if (count($erroresFormulario) > 0) {
		$contenidoPrincipal .= '</ul>';
	}

	$errorNombreUsuario = '';
	if (isset($erroresFormulario['nombreUsuario'])) {
		$errorNombreUsuario = " <span class=\"error\">{$erroresFormulario[nombreUsuario]}</span>";
	}
	$errorPassword = '';
	if (isset($erroresFormulario['password'])) {
		$errorPassword = " <span class=\"error\">{$erroresFormulario[password]}</span>";
	}
	$contenidoPrincipal .= <<<EOS
	<fieldset>
		<legend>Usuario y contraseña</legend>
		<div class="grupo-control">
			<label>Nombre de usuario:</label> <input type="text" name="nombreUsuario" value="<?= $nombreUsuario ?>" />$errorNombreUsuario
		</div>
		<div class="grupo-control">
			<label>Password:</label> <input type="password" name="password" value="<?= $password ?>" />$errorPassword
		</div>
		<div class="grupo-control"><button type="submit" name="login">Entrar</button></div>
	</fieldset>
	</form>
	EOS;
}


require __DIR__.'/includes/plantillas/plantilla.php';