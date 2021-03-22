<!DOCTYPE html>
<html>
<head>
	<link rel="stylesheet" type="text/css" href="estilo.css" />
	<meta charset="utf-8">
	<title>Portada</title>
</head>

<body>

<div id="contenedor">

	<?php require_once("cabecera.php"); ?>
	<?php require_once("sidebarIzq.php"); ?>

	<div id="contenido">
		<h1>Página principal</h1>
		<p> Aquí está el contenido público, visible para todos los usuarios. </p>
	</div>
	
	<?php require_once("sidebarDer.php"); ?>
	<?php require_once("pie.php"); ?>
</div> <!-- Fin del contenedor -->

</body>
</html>