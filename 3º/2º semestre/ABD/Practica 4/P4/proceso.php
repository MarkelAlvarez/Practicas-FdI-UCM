<?php
	echo "<h2>Datos personales</h2>";
	echo '<p>' . $_POST["nom"] . '</p>';
	echo '<p>' . $_POST["tel"] . '</p>';
	echo '<p>' . $_POST["mail"] . '</p>';
	echo '<p>' . $_POST["dir"] . '</p>';

	echo "<h2>Datos del pedido</h2>";
	echo "<h3>Primer plato</h3>";
	echo '<p>' . $_POST["primero"] . '</p>';
	echo "<h3>Segundo plato</h3>";
	echo '<p>' . $_POST["segundo"] . '</p>';
	echo "<h3>Café o té</h3>";
	if($_POST["cafeote"] == 'C')
	{
		echo "<p>Café</p>";
	}
	else
	{
		echo "<p>Té</p>";
	}
	echo "<h3>Observaciones</h3>";
	if(empty($_POST["obs"]))
	{
		echo "<p>Sin observaciones</p>";
	}
	else
	{
		echo '<p>' . $_POST["obs"] . '</p>';
	}
	echo "<h3>Condiciones</h3>";
	if(isset($_POST["condi"]))
	{
		echo "<p>Acepta las condiciones</p>";
	}
?>