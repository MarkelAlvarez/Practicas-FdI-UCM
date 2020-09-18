library ieee; 
use ieee.std_logic_1164.all;

entity multiplexor2a1 is 
	generic(
		bits_entradas: positive := 32
	); 
	port( 
		entrada0	: in  std_logic_vector(bits_entradas-1 downto 0); 
		entrada1	: in  std_logic_vector(bits_entradas-1 downto 0); 
		seleccion   : in  std_logic; 
		salida	    : out std_logic_vector(bits_entradas-1 downto 0)  
	); 
end multiplexor2a1; 

architecture multiplexor2a1Arch of multiplexor2a1 is 

begin 

	salida <= entrada0 when (seleccion = '0') else entrada1;  
	
end multiplexor2a1Arch;