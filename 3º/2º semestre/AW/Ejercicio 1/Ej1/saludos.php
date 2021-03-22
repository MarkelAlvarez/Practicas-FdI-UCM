<!DOCTYPE html>
<html>
  	<head>
		<meta charset="utf-8">
		<title>P1</title>
	</head>
	<body>
        <?php
			$vueltas = $_GET['num'];
			if ($vueltas == 42)
            {
                echo '<h1>Me has pedido que te salude 42 veces.</h1>';
                echo '<p> En realidad, esa es la respuesta a la pregunta final sobre la vida, el universo y todo lo demás. </p>';
            }
            else
            {
                for ($i = 0; $i < $vueltas; $i++)
                {
                    echo '<p>' . $i . ' - ¡Hola Mundo!</p>';
                }
            }	
		?>
	</body>
</html>
