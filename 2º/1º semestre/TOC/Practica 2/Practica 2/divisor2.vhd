----------------------------------------------------------------------------------
-- Company: Universidad Complutense de Madrid
-- Engineer: Hortensia Mecha
--
-- Design Name: divisor
-- Module Name:    divisor - divisor_arch
-- Project Name:
-- Target Devices:
-- Description: Creaci�n de un reloj de 1Hz a partir de
--		un clk de 100 MHz
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;
USE IEEE.numeric_std.ALL;

entity divisor is
    port (
        rst: in STD_LOGIC;
        clk_entrada: in STD_LOGIC; -- reloj de entrada de la entity superior
        clk_salida: out STD_LOGIC -- reloj que se utiliza en los process del programa principal
    );
end divisor;

architecture divisor_arch of divisor is
 SIGNAL cuenta: unsigned(25 downto 0);
 SIGNAL clk_aux: std_logic;

  begin
  
clk_salida<=clk_aux;
  contador:
  PROCESS(rst, clk_entrada)
  BEGIN
    IF (rst='1') THEN
      cuenta<= (OTHERS=>'0');
      clk_aux<='0';
    ELSIF(clk_entrada'EVENT AND clk_entrada='1') THEN
      IF (cuenta="11111111111111111111111111") THEN
      	clk_aux <= not clk_aux;
        cuenta<= (OTHERS=>'0');
      ELSE
        cuenta <= cuenta + 1;
	clk_aux<=clk_aux;
      END IF;
    END IF;
  END PROCESS contador;

end divisor_arch;
