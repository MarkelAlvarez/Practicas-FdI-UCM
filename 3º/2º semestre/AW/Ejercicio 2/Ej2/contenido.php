<?php
	if (!empty($_SESSION))
	{
		session_start();
		if(!isset($_SESSION["loggedin"]) && $_SESSION["loggedin"] === false)
		{
			header("Location: login.php");
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
	<title>Contenido</title>
</head>

<body>

<div id="contenedor">

	<?php require_once("cabecera.php"); ?>
	<?php require_once("sidebarIzq.php"); ?>

	<div id="contenido">
		<h1>Contenido</h1>
		<p>Contenido para usuarios registrados.</p>
	</div>
	
	<?php require_once("sidebarDer.php"); ?>
	<?php require_once("pie.php"); ?>
</div> <!-- Fin del contenedor -->

</body>
</html>