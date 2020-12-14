-- Markel Alvarez Martinez --
/abolish

/* Creaciones de tabla e inserciones. */
CREATE TABLE programadores(dni string primary key, nombre string, dirección string, teléfono string);
INSERT INTO programadores(dni, nombre, dirección, teléfono) VALUES('1','Jacinto','Jazmín 4','91-8888888');
INSERT INTO programadores(dni, nombre, dirección, teléfono) VALUES('2','Herminia','Rosa 4','91-7777777');
INSERT INTO programadores(dni, nombre, dirección, teléfono) VALUES('3','Calixto','Clavel 3','91-1231231');
INSERT INTO programadores(dni, nombre, dirección, teléfono) VALUES('4','Teodora','Petunia 3','91-6666666');

CREATE TABLE analistas(dni string primary key, nombre string, dirección string, teléfono string);
INSERT INTO analistas(dni, nombre, dirección, teléfono) VALUES('4','Teodora','Petunia 3','91-6666666');
INSERT INTO analistas(dni, nombre, dirección, teléfono) VALUES('5','Evaristo','Luna 1','91-1111111');
INSERT INTO analistas(dni, nombre, dirección, teléfono) VALUES('6','Luciana','Júpiter 2','91-8888888');
INSERT INTO analistas(dni, nombre, dirección, teléfono) VALUES('7','Nicodemo','Plutón 3', NULL);

-- Para crear una clave primaria de más de un atributo hay que añadir al final como si fuese otro campo lo siguiente: primary key (códigopr, dniemp)
CREATE TABLE distribución(códigopr string, dniemp string, horas int, primary key (códigopr, dniemp));
INSERT INTO distribución(códigopr, dniemp, horas) VALUES('P1','1',10);
INSERT INTO distribución(códigopr, dniemp, horas) VALUES('P1','2',40);
INSERT INTO distribución(códigopr, dniemp, horas) VALUES('P1','4',5);
INSERT INTO distribución(códigopr, dniemp, horas) VALUES('P2','4',10);
INSERT INTO distribución(códigopr, dniemp, horas) VALUES('P3','1',10);
INSERT INTO distribución(códigopr, dniemp, horas) VALUES('P3','3',40);
INSERT INTO distribución(códigopr, dniemp, horas) VALUES('P3','4',5);
INSERT INTO distribución(códigopr, dniemp, horas) VALUES('P3','5',30);
INSERT INTO distribución(códigopr, dniemp, horas) VALUES('P4','4',20);
INSERT INTO distribución(códigopr, dniemp, horas) VALUES('P4','5',10);

CREATE TABLE proyectos(código string primary key, descripción string, dnidir string);
INSERT INTO proyectos(código, descripción, dnidir) VALUES('P1','Nómina','4');
INSERT INTO proyectos(código, descripción, dnidir) VALUES('P2','Contabilidad','4');
INSERT INTO proyectos(código, descripción, dnidir) VALUES('P3','Producción','5');
INSERT INTO proyectos(código, descripción, dnidir) VALUES('P4','Clientes','5');
INSERT INTO proyectos(código, descripción, dnidir) VALUES('P5','Ventas','6');

/* Vistas */
CREATE VIEW vista1 as SELECT dni 
					  FROM programadores 
					  INTERSECT 
					  SELECT dni 
					  FROM analistas;

CREATE VIEW vista2 as SELECT programadores.dni, distribución.horas
					  FROM programadores
					  

/* Visualización de las vistas */
SELECT * FROM (vista1);
SELECT * FROM (vista2);
SELECT * FROM (vista3);
SELECT * FROM (vista4);
SELECT * FROM (vista5);
SELECT * FROM (vista6);
SELECT * FROM (vista7);
SELECT * FROM (vista8);
SELECT * FROM (vista9);