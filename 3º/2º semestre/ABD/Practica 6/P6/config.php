<?php
	session_start();
	// Change this to your connection info.
	define('DB_SERVER', 'localhost');
	define('DB_USERNAME', 'root');
	define('DB_PASSWORD', '');
	define('DB_NAME', 'abd-p6');
	/* Attempt to connect to MySQL database */
	$mysqli = new mysqli(DB_SERVER, DB_USERNAME, DB_PASSWORD, DB_NAME);
	
	// Check connection
	if($mysqli === false)
	{
		die("ERROR: Could not connect. " . $mysqli->connect_error);
	}
?>