create or replace NONEDITIONABLE PROCEDURE PR_EMPLEADOS_TLF AS
    v_Nombre Empleados.Nombre%TYPE;
    v_DNI Tel�fonos.DNI%TYPE;
    v_Telefono TEL�FONOS."TEL�FONO"%TYPE;
    
    v_comprobar TEL�FONOS."TEL�FONO"%TYPE := 913333333;
    v_duplicado TEL�FONOS."TEL�FONO"%TYPE;
    v_acumulador INTEGER := 0;
    
    inexistente EXCEPTION;
    
    CURSOR c_telefonos IS
        SELECT empleados.nombre, empleados.dni, Tel�fonos."TEL�FONO"
        FROM Empleados FULL OUTER JOIN Tel�fonos
            ON empleados.dni=tel�fonos.dni;
    
BEGIN

    OPEN c_telefonos;
    WHILE v_acumulador != 1 LOOP
        FETCH c_telefonos INTO v_nombre, v_dni, v_telefono;
        EXIT WHEN c_telefonos%NOTFOUND;          
        
        SELECT TEL�FONO INTO v_duplicado
        FROM Tel�fonos
        --WHERE v_duplicado=v_comprobar
        GROUP BY "TEL�FONO"
        HAVING COUNT(*)>1;  
            
        IF v_duplicado = v_comprobar THEN
            DBMS_OUTPUT.put_line('Hay m�s de un empleado con el tel�fono ' || v_duplicado);
            v_acumulador := v_acumulador + 1;
        END IF;
        IF v_telefono = v_comprobar AND v_acumulador != 1 THEN
            DBMS_OUTPUT.put_line('El empleado con el tel�fono ' || v_telefono || ' es: ' || v_nombre || ', con DNI: '|| v_dni);
            v_acumulador := v_acumulador + 1;
        END IF;
    END LOOP;
    
    IF v_acumulador = 0 THEN
        RAISE inexistente;
    END IF;
      
    CLOSE c_telefonos;
    
    EXCEPTION
        WHEN inexistente THEN
            DBMS_OUTPUT.put_line('No se encontr� el empleado con el tel�fono ' || v_comprobar);
            CLOSE c_telefonos;
        WHEN TOO_MANY_ROWS THEN
            DBMS_OUTPUT.put_line('Demasiados numeros');
            CLOSE c_telefonos;
        WHEN NO_DATA_FOUND THEN
            DBMS_OUTPUT.put_line('No se encontr� tel�fono');
            CLOSE c_telefonos;
END;