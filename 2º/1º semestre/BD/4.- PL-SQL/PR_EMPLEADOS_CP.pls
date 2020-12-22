create or replace NONEDITIONABLE PROCEDURE PR_EMPLEADOS_CP AS 
    v_CP DOMICILIOS."C�digo postal"%TYPE;
    v_Empleados INTEGER;
    v_SueldoMedio NUMBER(8,2);
    
    v_Nombre empleados.nombre%TYPE;
    v_Sueldo empleados.sueldo%TYPE;
    v_Calle domicilios.Calle%TYPE;
    
    v_TotalEmpleados INTEGER := 0;
    
    CURSOR cps IS
        SELECT "C�digo postal", COUNT(*) AS Empleados, AVG(Sueldo) AS SueldoMedio
        FROM Empleados NATURAL JOIN Domicilios
        GROUP BY "C�digo postal"
        ORDER BY "C�digo postal";
        
    CURSOR c_Empleados(cps DOMICILIOS."C�digo postal"%TYPE) IS
        SELECT Nombre, Calle, Sueldo
        FROM Empleados NATURAL JOIN Domicilios
        WHERE "C�digo postal"=cps;
BEGIN
    OPEN cps;
    LOOP
        FETCH cps INTO v_CP, v_empleados, v_sueldomedio;
        EXIT WHEN cps%NOTFOUND;
        DBMS_OUTPUT.put_line('C�digo postal: ' || v_CP);
        
        OPEN c_Empleados(v_CP);
        LOOP
            FETCH c_Empleados INTO v_nombre, v_calle, v_sueldo;
            EXIT WHEN c_Empleados%NOTFOUND;
            DBMS_OUTPUT.put_line('  ' || v_nombre || ', ' || v_calle || ', ' || v_sueldo);
            v_TotalEmpleados := v_TotalEmpleados + 1;
        END LOOP;
        CLOSE c_Empleados;
        
        DBMS_OUTPUT.put_line('      N� de empleados: ' || v_empleados || ', Sueldo medio: ' || v_sueldomedio);
        
        
    END LOOP;
    CLOSE cps;
    
    DBMS_OUTPUT.put_line('Total empleados: ' || v_TotalEmpleados);
END;