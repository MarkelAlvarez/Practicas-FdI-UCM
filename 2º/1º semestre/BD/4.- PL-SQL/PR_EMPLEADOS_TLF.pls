create or replace NONEDITIONABLE PROCEDURE PR_EMPLEADOS_TLF AS
    v_Nombre Empleados.Nombre%TYPE;
    v_DNI Teléfonos.DNI%TYPE;
    v_Telefono TELÉFONOS."TELÉFONO"%TYPE;
    
    v_comprobar TELÉFONOS."TELÉFONO"%TYPE := 913333333;
    v_duplicado TELÉFONOS."TELÉFONO"%TYPE;
    v_acumulador INTEGER := 0;
    
    inexistente EXCEPTION;
    
    CURSOR c_telefonos IS
        SELECT empleados.nombre, empleados.dni, Teléfonos."TELÉFONO"
        FROM Empleados FULL OUTER JOIN Teléfonos
            ON empleados.dni=teléfonos.dni;
    
BEGIN

    OPEN c_telefonos;
    WHILE v_acumulador != 1 LOOP
        FETCH c_telefonos INTO v_nombre, v_dni, v_telefono;
        EXIT WHEN c_telefonos%NOTFOUND;          
        
        SELECT TELÉFONO INTO v_duplicado
        FROM Teléfonos
        --WHERE v_duplicado=v_comprobar
        GROUP BY "TELÉFONO"
        HAVING COUNT(*)>1;  
            
        IF v_duplicado = v_comprobar THEN
            DBMS_OUTPUT.put_line('Hay más de un empleado con el teléfono ' || v_duplicado);
            v_acumulador := v_acumulador + 1;
        END IF;
        IF v_telefono = v_comprobar AND v_acumulador != 1 THEN
            DBMS_OUTPUT.put_line('El empleado con el teléfono ' || v_telefono || ' es: ' || v_nombre || ', con DNI: '|| v_dni);
            v_acumulador := v_acumulador + 1;
        END IF;
    END LOOP;
    
    IF v_acumulador = 0 THEN
        RAISE inexistente;
    END IF;
      
    CLOSE c_telefonos;
    
    EXCEPTION
        WHEN inexistente THEN
            DBMS_OUTPUT.put_line('No se encontró el empleado con el teléfono ' || v_comprobar);
            CLOSE c_telefonos;
        WHEN TOO_MANY_ROWS THEN
            DBMS_OUTPUT.put_line('Demasiados numeros');
            CLOSE c_telefonos;
        WHEN NO_DATA_FOUND THEN
            DBMS_OUTPUT.put_line('No se encontró teléfono');
            CLOSE c_telefonos;
END;