<?php

//Inicio del procesamiento
session_start();

?>

<!DOCTYPE html>
<html>
<head>
<link rel="stylesheet" type="text/css" href="estilo.css" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>Login</title>
</head>

<body>

<div id="contenedor">

<?php
	require("includes/comun/cabecera.php");
	require("includes/comun/sidebarIzq.php");
?>

<main>
	<article>
		<h1>Acceso al sistema</h1>

		<form action="procesarLogin.php" method="POST">
		<fieldset>
            <legend>Usuario y contraseña</legend>
            <div class="grupo-control">
                <label>Nombre de usuario:</label> <input type="text" name="nombreUsuario" />
            </div>
            <div class="grupo-control">
                <label>Password:</label> <input type="password" name="password" />
            </div>
            <div class="grupo-control"><button type="submit" name="login">Entrar</button></div>
		</fieldset>
	</article>
</main>

<?php
	require("includes/comun/sidebarDer.php");
	require("includes/comun/pie.php");
?>
</div>

</body>
</html>