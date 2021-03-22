<?php
	$usuarios = array("markel" => "markel1", "pablo" => "pablo1");
	/**
	 * Si el usuario no se encuentra en la base de datos se debe dar de alta en el array y mostrar su contenido en formato de tabla HTML.
	 * Si el usuario existe en la base de datos se debe mostrar un error indicando que el usuario ya existe.
	 */
	if (!isset($_POST['username'], $_POST['password']))
	{
		exit('Rellena el formulario');
	}
	if (empty($_POST['username']) || empty($_POST['password']))
	{
		exit('Rellena el formulario.');
	}
	if (array_key_exists($_POST['username'], $usuarios))
	{
		echo '<p> El usuario ' . $_POST['username'] . ' ya existe.';
	}
	else
	{
		echo '<p> El usuario ' . $_POST['username'] . ' no existe, procedemos a darlo de alta.';
		$usuarios += [ $_POST['username'] => $_POST['password'] ];

		echo "
		<table border='1'>
			<thead>
				<tr>
					<th>Usuario</th>
					<th>Contraseña</th>
				</tr>
			</thead>
			<tbody>";
		foreach ($usuarios as $user => $pass)
		{
			echo "
				<tr>
					<td> $user </td>
					<td> $pass </td>
				</tr>";
		}
		echo "
			</tbody>
		</table>";
	}
?>