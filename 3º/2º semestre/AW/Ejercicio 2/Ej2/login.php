<!DOCTYPE html>
<html>
<head>
	<link rel="stylesheet" type="text/css" href="estilo.css" />
	<meta charset="utf-8">
	<title>Login</title>
</head>

<body>

<div id="contenedor">

	<?php require_once("cabecera.php"); ?>
	<?php require_once("sidebarIzq.php"); ?>

	<div id="contenido">
		<h1>Login</h1>
        <br> 
		<form action="procesarLogin.php" method="post">
        <fieldset>
            <legend>Datos personales</legend>
                Nombre:
                <br> 
                <input type="text" name="username" required>
                <br>
                Contraseña: 
                <br> 
                <input type="password" name="password" required>
                <br><br>
				<input type="submit">
        </fieldset>
    </form>
	</div>
	
	<?php require_once("sidebarDer.php"); ?>
	<?php require_once("pie.php"); ?>
</div> <!-- Fin del contenedor -->

</body>
</html>