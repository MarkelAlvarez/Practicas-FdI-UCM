<!DOCTYPE html>
<html>
  	<head>
		<meta charset="utf-8">
		<title>P2</title>
	</head>
    <body>
		<?php
			$dias = array("L" => "Lunes", "M" => "Martes", "X" => "Miercoles", "J" => "Jueves", "V" => "Viernes", "S" => "Sabado", "D" => "Domingo");
			$seleccionados = array("L", "M", "X", "J", "V");

			foreach ($seleccionados as $selec)
			{
				echo $dias[$selec] . "<br>";
			}
		?>
    </body>
</html>