<?php
	$sidebarIzq =<<< HTML
		<div id="sidebar-left">
			<h3>Navegación</h3>
			<ul>
				<li><a href="index.php">Inicio</a></li>
	HTML;
	echo $sidebarIzq;
	
	if (!empty($_SESSION))
	{
		echo '<li><a href="contenido.php">Ver contenido</a></li>';
		if($_SESSION['admin'])
		{
			$link =<<< HTML
				<li><a href="admin.php">Administrar</a></li>
			HTML;
			echo $link;
		}
	}
	
	$sidebarIzq2 =<<< HTML
			</ul>
		</div>
	HTML;
	echo $sidebarIzq2;
	
?>