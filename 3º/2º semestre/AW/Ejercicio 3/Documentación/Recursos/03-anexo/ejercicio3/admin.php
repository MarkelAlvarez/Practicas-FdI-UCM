<?php

require_once __DIR__.'/includes/config.php';

$tituloPagina = 'Administrar';

$contenidoPrincipal = '';

if (!isset($_SESSION["esAdmin"])) {
	$contenidoPrincipal .= <<<EOS
	<h1>Acceso denegado!</h1>
	<p>No tienes permisos suficientes para administrar la web.</p>
	EOS;
} else {
	$contenidoPrincipal .= <<<EOS
	<h1>Consola de administración</h1>
	<p>Aquí estarían todos los controles de administración</p>
	EOS;
}

require __DIR__.'/includes/plantillas/plantilla.php';