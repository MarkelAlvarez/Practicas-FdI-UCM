<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Registrarse</title>
		<link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.1/css/all.css">
        <link href="style.css" rel="stylesheet" type="text/css">
        <meta name="viewport" content="width=device-width, initial-scale=1">
	</head>
	<body>
		<div class="register">
			<h1>Registrarse</h1>
			<form action="proceso2.php" method="post" autocomplete="off">
				<label for="username"><i class="fas fa-user"></i></label>
				<input type="text" name="username" placeholder="Usuario" id="username" required>
				
                <label for="password"><i class="fas fa-lock"></i></label>
				<input type="password" name="password" placeholder="Contraseña" id="password" required>

				<label for="password2"><i class="fas fa-lock"></i></label>
				<input type="password" name="password2" placeholder="Confirmar contraseña" id="password2" required>
				
                <input type="submit" value="Registrarse">
			</form>
		</div>
	</body>
</html>

<?php
	require_once "config.php";
	// Now we check if the data was submitted, isset() function will check if the data exists.
	if (!isset($_POST['username'], $_POST['password'], $_POST['password2']))
	{
		// Could not get the data that should have been sent.
		exit('Please complete the registration form!');
	}
	// Make sure the submitted registration values are not empty.
	if (empty($_POST['username']) || empty($_POST['password']) || empty($_POST['password2']))
	{
		// One or more values are empty.
		exit('Please complete the registration form');
	}
	//Invalid Characters Validation
	if (preg_match('/^[a-zA-Z0-9]+$/', $_POST['username']) == 0)
	{
		exit('Username is not valid!');
	}
	//Character Length Check
	if (strlen($_POST['password']) > 255 || strlen($_POST['password']) < 5)
	{
		exit('Password must be > 8 characters long!');
	}
	if ($_POST['password'] != $_POST['password2'])
	{
		exit('Las contraseñas no coinciden');
	}
	// We need to check if the account with that username exists.
	if ($stmt = $mysqli->prepare('SELECT id, contraseña FROM usuarios WHERE usuario = ?'))
	{
		// Bind parameters (s = string, i = int, b = blob, etc), hash the password using the PHP password_hash function.
		$stmt->bind_param('s', $_POST['username']);
		$stmt->execute();
		$stmt->store_result();
		// Store the result so we can check if the account exists in the database.
		if ($stmt->num_rows > 0)
		{
			// Username already exists
			echo 'Username exists, please choose another!';
		}
		else
		{
			// Username doesnt exists, insert new account
			if ($stmt = $mysqli->prepare('INSERT INTO usuarios (usuario, contraseña) VALUES (?, ?)'))
			{
				// We do not want to expose passwords in our database, so hash the password and use password_verify when a user logs in.
				$password = password_hash($_POST['password'], PASSWORD_DEFAULT);
				$stmt->bind_param('ss', $_POST['username'], $password);
				$stmt->execute();
				
				echo 'You have successfully registered, you can now login!';
				header('Location: login.php');
			}
			else
			{
				// Something is wrong with the sql statement, check to make sure cuentas table exists with all 3 fields.
				echo 'Could not prepare statement!';
			}
		}
		$stmt->close();
	}
	else
	{
		// Something is wrong with the sql statement, check to make sure cuentas table exists with all 3 fields.
		echo 'Could not prepare statement!';
	}
	$mysqli->close();
?>