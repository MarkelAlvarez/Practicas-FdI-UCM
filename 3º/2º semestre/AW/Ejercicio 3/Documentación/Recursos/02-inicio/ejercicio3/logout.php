<?php

//Inicio del procesamiento
session_start();

//Doble seguridad: unset + destroy
unset($_SESSION["login"]);
unset($_SESSION["esAdmin"]);
unset($_SESSION["nombre"]);


session_destroy();
?>

<!DOCTYPE html>
<html>
<head>
<link rel="stylesheet" type="text/css" href="estilo.css" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>Portada</title>
</head>

<body>

<div id="contenedor">
<?php
	require("includes/comun/cabecera.php");
	require("includes/comun/sidebarIzq.php");
?>

<main>
	<article>
		<h1>Hasta pronto!</h1>
	</article>
</main>
<?php
	require("includes/comun/sidebarDer.php");
	require("includes/comun/pie.php");
?>
</div>

</body>
</html>