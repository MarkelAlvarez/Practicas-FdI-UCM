/* Apartado 1 */
-- 1.- a)
DROP TABLE pedidos;
DROP TABLE contiene;
DROP TABLE auditoría;

CREATE TABLE pedidos(código char(6) primary key, fecha char(10), importe number(6,2), cliente char(20), notas char(1024));
CREATE TABLE contiene(pedido char(6), plato char(20), precio number(6,2), unidades number(2,0), primary key (pedido, plato));
CREATE TABLE auditoría(operación char(6), tabla char(50), fecha char(10), hora char(8));
CREATE TABLE resumenClientes(cliente char(20), numPedidos integer, sumaImportes number(8,2));
-- 1.- b)
CREATE OR REPLACE TRIGGER trigger_pedidos
AFTER INSERT OR DELETE OR UPDATE ON pedidos
BEGIN
	IF INSERTING THEN
		INSERT INTO auditoría VALUES ('INSERT', 'pedidos', to_char(sysdate,'dd/mm/yyyy'), to_char(sysdate,'hh:mi:ss'));
	ELSIF DELETING THEN
		INSERT INTO auditoría VALUES ('DELETE', 'pedidos', to_char(sysdate,'dd/mm/yyyy'), to_char(sysdate,'hh:mi:ss'));
	ELSIF UPDATING THEN
		INSERT INTO auditoría VALUES ('UPDATE', 'pedidos', to_char(sysdate,'dd/mm/yyyy'), to_char(sysdate,'hh:mi:ss'));
	END IF;
END trigger_pedidos;
/
INSERT INTO pedidos VALUES ('P1','1-1-1',1,'C1','N1');
UPDATE pedidos SET importe=2;
DELETE FROM pedidos;

/* Apartado 2 */
CREATE OR REPLACE TRIGGER trigger_contiene
AFTER INSERT OR UPDATE OR DELETE ON contiene
FOR EACH ROW
BEGIN
	IF INSERTING THEN
		UPDATE pedidos SET
			importe = importe + :NEW.precio * :NEW.unidades
		WHERE código = :NEW.pedido;
	ELSIF DELETING THEN
		UPDATE pedidos SET
			importe = importe - :OLD.precio * :OLD.unidades
		WHERE código = :OLD.pedido;
	ELSIF UPDATING THEN
		UPDATE pedidos SET
			importe = importe - :OLD.precio * :OLD.unidades + :NEW.precio * :NEW.unidades
		WHERE código = :NEW.pedido;
	END IF;
END;
/
SHOW ERRORS;
INSERT INTO contiene VALUES ('P4', 'Barbacoa', 5.2, 3);

/* Apartado 3 */
CREATE OR REPLACE TRIGGER trigger_actualizar
AFTER INSERT OR DELETE OR UPDATE ON pedidos
FOR EACH ROW
DECLARE
	inexistente EXCEPTION;
	v_cliente resumenClientes.cliente%TYPE;
    v_pedido resumenClientes.numpedidos%TYPE;
    v_existe INTEGER;
	
BEGIN	
    IF DELETING THEN
        UPDATE resumenClientes SET
            numpedidos = numpedidos - 1,
            sumaimportes = sumaimportes - :OLD.importe
        WHERE resumenClientes.cliente = :NEW.cliente;
        
        SELECT numpedidos INTO v_pedido
        FROM resumenClientes;
        
		IF v_pedido = 0 THEN
			DELETE FROM resumenClientes WHERE resumenClientes.cliente = cliente;
        END IF;
    ELSIF UPDATING THEN
        UPDATE resumenClientes SET
            sumaimportes = sumaimportes - :OLD.importe + :NEW.importe
        WHERE resumenClientes.cliente = :NEW.cliente;
    ELSIF INSERTING THEN
        SELECT COUNT(*) INTO v_existe
        FROM resumenClientes
        WHERE cliente = :NEW.cliente;
    
        IF v_existe = 0 THEN
            INSERT INTO resumenclientes VALUES (:NEW.cliente, 1, 0.00);
        ELSE
            UPDATE resumenClientes SET
                resumenClientes.numpedidos = resumenClientes.numpedidos + 1,
                resumenClientes.sumaimportes = resumenClientes.sumaimportes + :NEW.importe
            WHERE resumenClientes.cliente = :NEW.cliente;
        END IF;
	END IF;
END;