<?php
	$cabecera =<<< HTML
		<div id="cabecera">
			<h1>Mi gran página web</h1>
	HTML;
	echo $cabecera;
	if(isset($_SESSION["loggedin"]) && $_SESSION["loggedin"] === true)
	{
		echo '<div class="saludo"> Hola ' . $_SESSION['name'] . ' <a href="logout.php">Salir</a>	</div></div>';
	}
	else
	{
		echo '<div class="saludo">Usuario desconocido. <a href="login.php">Login</a>	</div></div>';
	}	
?>