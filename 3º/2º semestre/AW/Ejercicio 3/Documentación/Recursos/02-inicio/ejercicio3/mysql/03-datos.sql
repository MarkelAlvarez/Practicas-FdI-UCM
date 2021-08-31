TRUNCATE TABLE `Usuarios`;

/*
  user: userpass
  admin: adminpass
*/
INSERT INTO `Usuarios` (`id`, `nombreUsuario`, `nombre`, `rol`, `password`) VALUES
(1, 'admin', 'Administrador', 'admin', '$2y$10$NnEv2dRjbqswil6ey1F6lemzBiTpPSZ6qtYwpbM.b53/VJ4lDVj3u'),
(2, 'user', 'Usuario', 'user', '$2y$10$ImLgzNnDkWlI7LBB5a1mk.vNu8Fb8z79syAsoOXqM7jy5hrTaZKnG');