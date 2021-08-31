<?php

//Inicio del procesamiento
session_start();

?>

<!DOCTYPE html>
<html>
<head>
<link rel="stylesheet" type="text/css" href="estilo.css" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>Contenido</title>
</head>

<body>

<div id="contenedor">

<?php
	require("includes/comun/cabecera.php");
	require("includes/comun/sidebarIzq.php");
?>

<main>
	<article>
	<?php
		if (!isset($_SESSION["login"])) {
			echo "<h1>Usuario no registrado!</h1>";
			echo "<p>Debes iniciar sesión para ver el contenido..</p>";
		} else {
	?>
		<h1>Texto del contenido principal para usuarios</h1>
		<p> Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam augue sem, molestie vel elementum quis, consequat consectetur velit. Sed malesuada in arcu quis placerat. Proin sed ligula leo. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Integer pretium, sapien ut ornare ornare, odio felis vulputate nisi, at hendrerit libero sapien ut sapien. Vestibulum laoreet auctor suscipit. Suspendisse id eros ut diam egestas luctus. Donec consequat, leo eu pretium sollicitudin, metus mi suscipit risus, non porta augue purus nec velit. Donec lobortis magna eget feugiat porttitor. In suscipit arcu quis urna lobortis dapibus.</p>

		<p> Maecenas nec orci mollis, pretium erat in, blandit felis. Etiam vestibulum eu sapien a sagittis. Maecenas eget posuere turpis. Fusce egestas lacus at tortor scelerisque vulputate. Mauris tincidunt massa sem, nec dapibus risus facilisis vitae. Nulla risus sem, sodales at viverra ut, elementum sit amet nisl. Fusce placerat bibendum pharetra. Etiam ultricies metus lectus, eget consequat elit imperdiet a. Sed eu ipsum augue. Phasellus eget iaculis nisl. Sed bibendum, sem posuere pretium sagittis, nibh orci porta urna, id dictum ante felis quis ante. Ut quis tortor vel sapien lacinia rutrum. Morbi at nisi sit amet elit iaculis vulputate. Curabitur dignissim diam ac porta bibendum.</p>

		<p>Proin elementum blandit diam id ullamcorper. Duis semper nunc semper nisi vehicula consectetur. Donec quis ante iaculis, rhoncus ante et, pellentesque sem. Cras tempus rutrum sapien vitae feugiat. Cras dapibus ut diam a commodo. Duis vel leo arcu. Suspendisse mollis purus eget eros elementum, vel pulvinar elit interdum. Etiam sit amet orci mi. Integer tristique lacus eu consequat rutrum. Sed tempor hendrerit mauris, eu sollicitudin ante ullamcorper scelerisque. Praesent ullamcorper sed mauris porta aliquet.</p>
	<?php
		}
	?>
	</article>
</main>
<?php

	require("includes/comun/sidebarDer.php");
	require("includes/comun/pie.php");

?>
</div>

</body>
</html>