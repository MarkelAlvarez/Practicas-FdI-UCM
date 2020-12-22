create or replace NONEDITIONABLE PROCEDURE PR_COMPROBAR_POBLACIONES AS
	excepcion EXCEPTION;
	v_poblaci�n "C�digos postales".poblaci�n%TYPE;
	CURSOR c_cp IS
		SELECT poblaci�n
		FROM 
			(SELECT DISTINCT poblaci�n, provincia
			 FROM "C�digos postales")
		GROUP BY poblaci�n
		HAVING COUNT (poblaci�n) > 1;
BEGIN
	OPEN c_cp;
	LOOP 
		FETCH c_cp INTO v_poblaci�n;
		EXIT WHEN c_cp%NOTFOUND;
		RAISE excepcion;
	END LOOP;
	CLOSE c_cp;
	
	DBMS_OUTPUT.put_line('No hay dos o m�s provincias que compartan la misma poblaci�n.');
EXCEPTION
	WHEN excepcion THEN
		DBMS_OUTPUT.put_line('A la poblaci�n '|| TRIM(v_poblaci�n) ||' no le corresponde siempre la misma provincia.');
		CLOSE c_cp;
END;