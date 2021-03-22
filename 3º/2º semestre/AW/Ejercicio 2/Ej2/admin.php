<?php
	session_start();
	if(isset($_SESSION["loggedin"]) && $_SESSION["loggedin"] === true)
	{
		if(isset($_SESSION["admin"]) && $_SESSION["admin"] === false)
		{ 
		    header("Location: contenido.php");
			exit;
		}
	}
	else
	{
		header("Location: login.php");
		exit;
	}
?>

<!DOCTYPE html>
<html>
<head>
	<link rel="stylesheet" type="text/css" href="estilo.css" />
	<meta charset="utf-8">
	<title>Administrador</title>
</head>

<body>

<div id="contenedor">

	<?php require_once("cabecera.php"); ?>
	<?php require_once("sidebarIzq.php"); ?>

	<div id="contenido">
		<h1>CONSOLA</h1>
		<p>Bienvenido administrador.</p>
	</div>
	
	<?php require_once("sidebarDer.php"); ?>
	<?php require_once("pie.php"); ?>
</div> <!-- Fin del contenedor -->

</body>
</html>