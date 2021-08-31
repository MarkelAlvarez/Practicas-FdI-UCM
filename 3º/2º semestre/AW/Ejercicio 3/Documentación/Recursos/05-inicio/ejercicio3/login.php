<?php

require_once __DIR__.'/includes/config.php';

$tituloPagina = 'Login';

$contenidoPrincipal = <<<EOS
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
</form>
EOS;

require __DIR__.'/includes/plantillas/plantilla.php';