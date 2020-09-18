library IEEE;
use IEEE.std_logic_1164.all;

entity MIPSMulticiclo is
	port( 
		clk		: in  std_logic;
		rst	    : in  std_logic
	);
end MIPSMulticiclo;

architecture MIPSMulticicloArch of MIPSMulticiclo is

	component unidadDeControl is
		port( 
			clk		: in  std_logic;
			rst  	: in  std_logic;
			control	: out std_logic_vector(15 downto 0);
			Zero	: in  std_logic;
			op		: in  std_logic_vector(5 downto 0)
		);
	end component;

	component rutaDeDatos is
		port( 
			clk		: in  std_logic;
			rst 	: in  std_logic;
			control	: in  std_logic_vector(15 downto 0);
			Zero	: out std_logic;
			op		: out std_logic_vector(5 downto 0)
		);
	end component;
  
	signal control : std_logic_vector(15 downto 0);
	signal Zero	   : std_logic;
	signal op      : std_logic_vector(5 downto 0);

begin

    UC : unidadDeControl port map(clk => clk, rst => rst, control => control, Zero => Zero, op => op);
		
    RD: rutaDeDatos port map(clk => clk, rst => rst, control => control, Zero => Zero, op => op); 

end MIPSMulticicloArch;