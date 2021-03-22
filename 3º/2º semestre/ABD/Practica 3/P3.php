<!DOCTYPE html>
<html>
  	<head>
		<meta charset="utf-8">
		<title>P3</title>
	</head>
	<body>
		<?php
			echo "<table>";
			for ($i = 1; $i <= 10; $i++)
			{
				echo "<tr>";
				for ($j = 0; $j <= 10; $j++)
				{
					$prod = $i * $j;
					echo "<th>" . $prod . "</th>";
				}
				echo "</tr>";
			}
			echo "</table>";
		?>
	</body>
</html>