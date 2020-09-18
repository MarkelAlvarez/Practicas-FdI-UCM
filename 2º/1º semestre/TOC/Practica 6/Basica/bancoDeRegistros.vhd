library IEEE;
use IEEE.std_logic_1164.all;
use ieee.numeric_std.all; 

entity bancoDeRegistros is
	port( 
		clk		    : in  std_logic;
		rst 		: in  std_logic;
		RA			: in  std_logic_vector(4 downto 0);
		RB			: in  std_logic_vector(4 downto 0);
		RegWrite	: in  std_logic;
		RW			: in  std_logic_vector(4 downto 0);
		busW		: in  std_logic_vector(31 downto 0);
		busA		: out std_logic_vector(31 downto 0);
		busB		: out std_logic_vector(31 downto 0);
		R3			: out std_logic_vector(31 downto 0)
	);
end bancoDeRegistros;

architecture bancoDeRegistrosArch of bancoDeRegistros is
   
	type banco_regsitro_type  is array (31 downto 0) of std_logic_vector(31 downto 0);
	signal bancoDeRegistros : banco_regsitro_type;
	
begin

	escritura:
	process(clk, rst)
	begin
		if (rst = '1') then
			for i in 0 to 31 loop
				bancoDeRegistros(i) <= (others=>'0');
			end loop;		
		elsif rising_edge(clk) then
			if (RegWrite = '1') then
            bancoDeRegistros(to_integer(unsigned(RW))) <= busW;
         end if;
		end if;
   end process;
	
	lectura:
	busA <= bancoDeRegistros(to_integer(unsigned(RA)));
	busB <= bancoDeRegistros(to_integer(unsigned(RB)));
	
	R3 <= bancoDeRegistros(3);

end bancoDeRegistrosArch;