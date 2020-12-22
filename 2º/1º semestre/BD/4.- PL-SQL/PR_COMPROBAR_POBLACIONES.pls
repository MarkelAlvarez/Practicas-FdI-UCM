create or replace NONEDITIONABLE PROCEDURE PR_COMPROBAR_POBLACIONES AS
	excepcion EXCEPTION;
	v_población "Códigos postales".población%TYPE;
	CURSOR c_cp IS
		SELECT población
		FROM 
			(SELECT DISTINCT población, provincia
			 FROM "Códigos postales")
		GROUP BY población
		HAVING COUNT (población) > 1;
BEGIN
	OPEN c_cp;
	LOOP 
		FETCH c_cp INTO v_población;
		EXIT WHEN c_cp%NOTFOUND;
		RAISE excepcion;
	END LOOP;
	CLOSE c_cp;
	
	DBMS_OUTPUT.put_line('No hay dos o más provincias que compartan la misma población.');
EXCEPTION
	WHEN excepcion THEN
		DBMS_OUTPUT.put_line('A la población '|| TRIM(v_población) ||' no le corresponde siempre la misma provincia.');
		CLOSE c_cp;
END;