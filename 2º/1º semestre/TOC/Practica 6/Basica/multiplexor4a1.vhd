library ieee; 
use ieee.std_logic_1164.all; 

entity multiplexor4a1 is 
	generic(
		bits_entradas: positive := 32
	); 
	port( 
		entrada0	: in  std_logic_vector(bits_entradas-1 downto 0);
		entrada1	: in  std_logic_vector(bits_entradas-1 downto 0);
		entrada2	: in  std_logic_vector(bits_entradas-1 downto 0);
		entrada3	: in  std_logic_vector(bits_entradas-1 downto 0);
		seleccion: in  std_logic_vector(1 downto 0); 
		salida	: out std_logic_vector(bits_entradas-1 downto 0)  
	); 
end multiplexor4a1; 

architecture multiplexor4a1Arch of multiplexor4a1 is 

begin 

	salida <= entrada0 when (seleccion = "00") else 
				 entrada1 when (seleccion = "01") else 
				 entrada2 when (seleccion = "10") else 
				 entrada3;  
	
end multiplexor4a1Arch;