<?php

//Inicio del procesamiento
session_start();

$tituloPagina = 'Registro';

$contenidoPrincipal = <<<EOS
<h1>Registro de usuario</h1>

<form action="procesarRegistro.php" method="POST">
<fieldset>
	<div class="grupo-control">
		<label>Nombre de usuario:</label> <input class="control" type="text" name="nombreUsuario" />
	</div>
	<div class="grupo-control">
		<label>Nombre completo:</label> <input class="control" type="text" name="nombre" />
	</div>
	<div class="grupo-control">
		<label>Password:</label> <input class="control" type="password" name="password" />
	</div>
	<div class="grupo-control"><label>Vuelve a introducir el Password:</label> <input class="control" type="password" name="password2" /><br /></div>
	<div class="grupo-control"><button type="submit" name="registro">Registrar</button></div>
</fieldset>
</form>
EOS;

require __DIR__.'/includes/plantillas/plantilla.php';