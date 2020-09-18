-------------------------------------------
-- definición de puertas para el full_adder
-------------------------------------------
--puerta lógica or de dos entradas
ENTITY or2 IS
  PORT(i1, i2 : IN bit; o : OUT bit);
END or2;

ARCHITECTURE comportamiento OF or2 IS
BEGIN
  o <= i1 OR i2;
END comportamiento;
--puerta lógica and de dos entradas
ENTITY and2 IS
  PORT(i1, i2 : IN bit; o : OUT bit);
END and2;

ARCHITECTURE comportamiento OF and2 IS
BEGIN
  o <= i1 AND i2;
END comportamiento;
--puerta lógica xor de dos entradas
ENTITY xor2 IS
  PORT(i1, i2 : IN bit; o : OUT bit);
END xor2;

ARCHITECTURE comportamiento OF xor2 IS
BEGIN
  o <= i1 XOR i2;
END comportamiento;

----------------------------------------
-- full_adder de 1 bit
----------------------------------------
ENTITY full_adder IS
  PORT(ai, bi : IN bit; ci : IN bit; si : OUT bit; co : OUT bit);
END full_adder;

--USE work.ALL;
ARCHITECTURE puertas OF full_adder IS
--declaración de componentes
  COMPONENT or2 
    PORT(i1, i2 : IN bit; o : OUT bit);
  END COMPONENT;
  COMPONENT and2
    PORT(i1, i2 : IN bit; o : OUT bit);
  END COMPONENT;
  COMPONENT xor2
    PORT(i1, i2 : IN bit; o : OUT bit);
  END COMPONENT;
  
  --declaración de señales internas
  SIGNAL sal_and1, sal_and2, sal_xor1 : bit;
--empieza el cuerpo de la arquitectura  
BEGIN
  i_and1 : and2  PORT MAP(ai, bi, sal_and1);
  i_xor1 : xor2  PORT MAP(ai, bi, sal_xor1);
  i_and2 : and2  PORT MAP(sal_xor1, ci, sal_and2);
  i_xor2 : xor2  PORT MAP(sal_xor1, ci, si);
  i_or   : or2   PORT MAP(sal_and1, sal_and2, co);
END puertas;

