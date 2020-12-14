create table programadores(dni VARCHAR2(9)  primary key, nombre VARCHAR2(50), dirección VARCHAR2(60), teléfono VARCHAR2(10));
insert into programadores values('1','Jacinto','Jazmín 4','91-8888888');
insert into programadores values('2','Herminia','Rosa 4','91-7777777');
insert into programadores values('3','Calixto','Clavel 3','91-1231231');
insert into programadores values('4','Teodora','Petunia 3','91-6666666');

create table analistas(dni VARCHAR2(9) primary key, nombre VARCHAR2(50), dirección VARCHAR2(60), teléfono VARCHAR2(10));
insert into analistas values('4','Teodora','Petunia 3','91-6666666');
insert into analistas values('5','Evaristo','Luna 1','91-1111111');
insert into analistas values('6','Luciana','Júpiter 2','91-8888888');
insert into analistas values('7','Nicodemo','Plutón 3',NULL);

create table distribución(códigoPr CHAR(2), dniEmp VARCHAR2(9), horas int, primary key (códigoPr, dniEmp));
insert into distribución values('P1','1',10);
insert into distribución values('P1','2',40);
insert into distribución values('P1','4',5);
insert into distribución values('P2','4',10);
insert into distribución values('P3','1',10);
insert into distribución values('P3','3',40);
insert into distribución values('P3','4',5);
insert into distribución values('P3','5',30);
insert into distribución values('P4','4',20);
insert into distribución values('P4','5',10);

create table proyectos(código CHAR(2) primary key, descripción VARCHAR2(60), dniDir VARCHAR2(9));
insert into proyectos values('P1','Nómina','4');
insert into proyectos values('P2','Contabilidad','4');
insert into proyectos values('P3','Producción','5');
insert into proyectos values('P4','Clientes','5');
insert into proyectos values('P5','Ventas','6');

CREATE VIEW vista1 AS SELECT dni
                      FROM analistas
                      UNION
                      SELECT dni
                      FROM programadores;
                      
CREATE VIEW vista2 AS SELECT A.dni
                      FROM analistas A JOIN programadores P ON A.dni = P.dni;

CREATE VIEW vista3 AS SELECT dni, nombre
                      FROM analistas A
                      WHERE A."TELÉFONO" IS null
                      UNION
                      SELECT dni, nombre
                      FROM programadores P
                      WHERE P."TELÉFONO" IS null;

CREATE VIEW vista4 AS SELECT dni 
					  FROM vista1 
					  WHERE dni not IN (SELECT dniemp 
					  					FROM distribución 
					  					UNION 
					  					SELECT dnidir 
					  					FROM proyectos);

CREATE VIEW vista5 AS SELECT código 
					  FROM proyectos 
					  WHERE código not IN (SELECT distribución.códigopr 
					  					   FROM distribución 
					  					   JOIN analistas ON distribución.dniemp = analistas.dni);
                                           
CREATE VIEW vista6 AS SELECT DISTINCT dni 
					  FROM analistas 
					  JOIN proyectos ON analistas.dni = proyectos.dnidir 
					  WHERE dni not IN (SELECT dni
                                        FROM programadores);            

CREATE VIEW vista7 as SELECT proyectos.descripción, programadores.nombre, distribución.horas 
					  FROM (proyectos JOIN distribución ON proyectos.código = distribución.códigopr) JOIN programadores ON programadores.dni = distribución.dniemp 
					  ORDER BY proyectos.código, programadores.dni;

CREATE VIEW vista8 as SELECT teléfono 
					  FROM programadores
					  INTERSECT 
					  SELECT teléfono 
					  FROM analistas 
					  WHERE dni not IN (SELECT dni 
					  					FROM vista2);
                                        
CREATE VIEW vista9 as ;