CREATE TABLE Empleados (
  Nombre VARCHAR2(50) NOT NULL, 
  DNI    VARCHAR2(9) PRIMARY KEY, 
  Sueldo NUMBER(6,2), 
  CHECK (Sueldo BETWEEN 900.00 AND 5000.00));

CREATE TABLE Tel�fonos
  (DNI      VARCHAR2(9) REFERENCES Empleados ON DELETE CASCADE, 
   Tel�fono VARCHAR2(9), 
   PRIMARY KEY (DNI, Tel�fono));

CREATE TABLE "C�digos postales" 
  ("C�digo postal" VARCHAR2(5) PRIMARY KEY, 
   Poblaci�n       VARCHAR2(50) NOT NULL, 
   Provincia       VARCHAR2(50) NOT NULL);
   
CREATE TABLE Domicilios
  (DNI             VARCHAR2(9) REFERENCES Empleados ON DELETE CASCADE,
   Calle           VARCHAR2(50), 
   "C�digo postal" VARCHAR2(5) REFERENCES "C�digos postales", 
   PRIMARY KEY (DNI, Calle, "C�digo postal"));
   
INSERT INTO Empleados VALUES('Antonio Arjona','12345678A',5000.0);
INSERT INTO Empleados VALUES('Carlota Cerezo','12345678C',1000.0);
INSERT INTO Empleados VALUES('Laura L�pez','12345678L',1500.0);
INSERT INTO Empleados VALUES('Pedro P�rez','12345678P',2000.0);

INSERT INTO Tel�fonos VALUES('12345678C','611111111');
INSERT INTO Tel�fonos VALUES('12345678C','931111111');
INSERT INTO Tel�fonos VALUES('12345678L','913333333');
INSERT INTO Tel�fonos VALUES('12345678P','913333333');
INSERT INTO Tel�fonos VALUES('12345678P','644444444');

INSERT INTO "C�digos postales" VALUES('08050','Parets','Barcelona');
INSERT INTO "C�digos postales" VALUES('14200','Pe�arroya','C�rdoba');
INSERT INTO "C�digos postales" VALUES('14900','Lucena','C�rdoba');
INSERT INTO "C�digos postales" VALUES('28040','Madrid','Madrid');
INSERT INTO "C�digos postales" VALUES('50008','Zaragoza','Zaragoza');
INSERT INTO "C�digos postales" VALUES('28004','Arganda','Madrid');

INSERT INTO Domicilios VALUES('12345678A','Avda. Complutense','28040');
INSERT INTO Domicilios VALUES('12345678A','C�ntaro','28004');
INSERT INTO Domicilios VALUES('12345678P','Diamante','14200');
INSERT INTO Domicilios VALUES('12345678P','Carb�n','14900');
INSERT INTO Domicilios VALUES('12345678L','Diamante','14200');

