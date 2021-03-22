<?php
	session_start();
	// Change this to your connection info.
	define('DB_SERVER', 'localhost');
	define('DB_USERNAME', 'root');
	define('DB_PASSWORD', '');
	define('DB_NAME', 'abd-p7');
	/* Attempt to connect to MySQL database */
	$mysqli = new mysqli(DB_SERVER, DB_USERNAME, DB_PASSWORD, DB_NAME);
	
	// Check connection
	if($mysqli === false)
	{
		die("ERROR: Could not connect. " . $mysqli->connect_error);
	}

	function getCategories()
	{
		global $mysqli;
		// Cogemos la info de las bases de datos	
		$resultado = $mysqli->query("SELECT * FROM categoria");

		while($row = $resultado->fetch_array())
		{
			echo '<option value="' . $row['categoria'] . '">' . $row['categoria'] . '</option>';
		}
	}

	if($_SERVER["REQUEST_METHOD"] == "POST")
	{
		// Check if username is empty
		if(empty(trim($_POST["min"])) && empty(trim($_POST["max"])))
		{
			exit("Los campos del precio no pueden estar vacios.");
		}
		
		// Prepare our SQL, preparing the SQL statement will prevent SQL injection.
		if ($stmt = $mysqli->prepare('SELECT * FROM libros WHERE categoria = ? AND precio BETWEEN ? AND ?'))
		{
			// Bind parameters (s = string, i = int, b = blob, etc), in our case the username is a string so we use "s"
			$stmt->bind_param('sdd', $_POST['categoria'], $_POST['min'], $_POST['max']);
			$stmt->execute();
			//$stmt->store_result();
			$result = $stmt->get_result();
			$table = <<< HTML
			<div class="login">
				<div class="form-group">
					<table>
						<thead>
							<tr>
								<th>TITULO</th>
								<th>CATEGORIA</th>
								<th>PRECIO</th>
							</tr>
						</thead>
						<tbody>
			HTML;
			echo $table;
			if($result->num_rows > 0)
			{
				//while($row = $stmt->fetch_array())
				while ($row = $result->fetch_assoc()) {
				{
					echo "<tr>";
						echo "<td>" . $row['titulo'] . "</td>";
						echo "<td>" . $row['categoria'] . "</td>";
						echo "<td>" . $row['precio'] . "</td>";
					echo "</tr>";
				}
				echo"</tbody>
				</table>
				</div>
				</div>";
			}

			$stmt->close();
		}
	}
}
?>

<!DOCTYPE html>
<html lang="es">

<head>
	<meta charset="utf-8">
	<title>P7</title>
	<link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.1/css/all.css">
	<link href="style.css" rel="stylesheet" type="text/css">
	<meta name="viewport" content="width=device-width, initial-scale=1">
</head>

<body class=>
	<div class="login">
		<h1>Busqueda</h1>
		<form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
			<div class="form-group" style="margin: 0% 10% 5%">
				<select name="categoria" id=categoria>
					<?php getCategories() ?>
				</select>
			</div>

			<div class="form-group">
				<label for="min">Precio mínimo</label>
				<input type="text" name="min" placeholder="Precio mínimo" id="min" class="form-control">

				<label for="max">Precio máximo</label>
				<input type="text" name="max" placeholder="Precio máximo" id="max" class="form-control">
			</div>

			<input type="submit" value="Buscar">
		</form>
	</div>
</body>

</html>