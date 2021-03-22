<?php
	// Initialize the session
	//session_start();
	
	// Check if the user is already logged in, if yes then redirect him to welcome page
	if(isset($_SESSION["loggedin"]) && $_SESSION["loggedin"] === true)
	{
		echo "Acceso correcto";
	}
	
	// Include config file
	require_once "config.php";

	// Define variables and initialize with empty values
	$username = $password = "";
	$username_err = $password_err = "";
	
	// Processing form data when form is submitted
	if($_SERVER["REQUEST_METHOD"] == "POST")
	{
		// Check if username is empty
		if(empty(trim($_POST["username"])))
		{
			$username_err = "Introduce un nombre de usuario.";
		}
		else
		{
			$username = trim($_POST["username"]);
		}
		
		// Check if password is empty
		if(empty(trim($_POST["password"])))
		{
			$password_err = "Introduce la contraseña.";
		}
		else
		{
			$password = trim($_POST["password"]);
		}
		
		// Validate credentials
		if(empty($username_err) && empty($password_err))
		{
			// Prepare our SQL, preparing the SQL statement will prevent SQL injection.
			if ($stmt = $mysqli->prepare('SELECT id, contraseña FROM usuarios WHERE usuario = ?'))
			{
				// Bind parameters (s = string, i = int, b = blob, etc), in our case the username is a string so we use "s"
				$stmt->bind_param('s', $_POST['username']);
				$stmt->execute();
				// Store the result so we can check if the account exists in the database.
				$stmt->store_result();

				if ($stmt->num_rows > 0)
				{
					$stmt->bind_result($id, $password);
					$stmt->fetch();
					// Account exists, now we verify the password.
					// Note: remember to use password_hash in your registration file to store the hashed passwords.
					if (password_verify($_POST['password'], $password))
					{
						// Verification success! User has logged-in!
						// Create sessions, so we know the user is logged in, they basically act like cookies but remember the data on the server.
						session_regenerate_id();
						$_SESSION['loggedin'] = TRUE;
						$_SESSION['name'] = $_POST['username'];
						$_SESSION['id'] = $id;

						echo "Acceso correcto";
					}
					else
					{
						// Incorrect password
						header('Location: proceso.php');
					}
				}
				else
				{
					// Incorrect password
					header('Location: proceso2.php');
				}

				$stmt->close();
			}
		}
	}
?>