<?php
	// Initialize the session
	session_start();
	
	// Check if the user is already logged in, if yes then redirect him to welcome page
	if(isset($_SESSION["loggedin"]) && $_SESSION["loggedin"] === true)
	{
		header("Location: contenido.php");
		exit;
	}

	// Define variables and initialize with empty values
	$username = $password = "";
	
	// Processing form data when form is submitted
	if($_SERVER["REQUEST_METHOD"] == "POST")
	{
		$username = trim($_POST["username"]);
		$password = trim($_POST["password"]);
		
		if ($_POST["username"] == "admin" && $_POST["password"] == "adminpass")
        {
            session_regenerate_id();
            $_SESSION["loggedin"] = TRUE;
            $_SESSION["name"] = "Administrador";
            $_SESSION["id"] = $id;
            $_SESSION["admin"] = TRUE;

            header('Location: contenido.php');
        }
        else if ($_POST["username"] == "user" && $_POST["password"] == "userpass")
        {
            session_regenerate_id();
            $_SESSION["loggedin"] = TRUE;
            $_SESSION["name"] = "Usuario";
            $_SESSION["id"] = $id;
            $_SESSION["admin"] = FALSE;

            header('Location: contenido.php');
        }
        else
        {
            // Incorrect username
            echo 'Usuario y/o contraseña incorrectos.';
            header('Location: login.php');
        }
	}
?>