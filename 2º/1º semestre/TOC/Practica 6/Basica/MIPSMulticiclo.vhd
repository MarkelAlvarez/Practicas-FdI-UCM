library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity MIPSMulticiclo is
	port( 
		clk		          : in  std_logic;
		rst   		      : in  std_logic;
		display	          : out std_logic_vector(6 downto 0);
		display_enable    : out std_logic_vector(3 downto 0);
		debug		      : in 	std_logic;
		sig               : in 	std_logic;
		switch            : in  std_logic_vector (7 downto 0)
	);
end MIPSMulticiclo;

architecture MIPSMulticicloArch of MIPSMulticiclo is

	component unidadDeControl is
		port( 
			clk		    : in  std_logic;
			rst 		: in  std_logic;
			control	    : out std_logic_vector(18 downto 0);
			Zero		: in  std_logic;
			op			: in  std_logic_vector(5 downto 0);
			debug		: in  std_logic;
			sig         : in  std_logic;
			inmediato   : in  std_logic_vector(15 downto 0)
		);
	end component;

	component rutaDeDatos is
		port( 
			clk		    : in  std_logic;
			rst 		: in  std_logic;
			control	    : in  std_logic_vector(18 downto 0);
			Zero		: out std_logic;
			op			: out std_logic_vector(5 downto 0);
			R3			: out std_logic_vector(31 downto 0);
			PCout		: out std_logic_vector(31 downto 0);
			inmediato_rd: out std_logic_vector(15 downto 0);
			switch      : in  std_logic_vector(7 downto 0)
		);
	end component;
	
    component displays
        port( 
            rst           : in std_logic;
            clk           : in std_logic;       
            digito_0      : in std_logic_vector(3 downto 0);
            digito_1      : in std_logic_vector(3 downto 0);
            digito_2      : in std_logic_vector(3 downto 0);
            digito_3      : in std_logic_vector(3 downto 0);
            display       : out std_logic_vector(6 downto 0);
            display_enable: out std_logic_vector(3 downto 0)
         );
    end component;

	component debouncer
	  port(
		 rst              : in std_logic;
		 clk              : in std_logic;
		 x                : in std_logic;
		 xDeb             : out std_logic;
		 xDebFallingEdge  : out std_logic;
		 xDebRisingEdge   : out std_logic
	  );
	end component;
  
	signal control             : std_logic_vector(18 downto 0);
	signal Zero	               : std_logic;
	signal op                  : std_logic_vector(5 downto 0);
	signal inmediato_aux       : std_logic_vector(15 downto 0);
	signal nextDebouncer       : std_logic;
	signal PC                  : std_logic_vector(31 downto 0);
	signal R3                  : std_logic_vector(31 downto 0);

    begin
	debounce: debouncer port map(rst => rst, clk => clk, x => sig, xDeb => open, xDebFallingEdge => open, xDebRisingEdge => nextDebouncer);
	UC: unidadDeControl port map(clk => clk, rst => rst, control => control, Zero => Zero, op => op, debug => debug, sig => nextDebouncer, inmediato => inmediato_aux);	
	RD: rutaDeDatos port map(clk => clk, rst => rst, control => control, Zero => Zero, op => op, R3 => R3, PCout => PC, inmediato_rd => inmediato_aux, switch => switch);
	pantalla: displays port map(rst => rst, clk => clk, digito_0 => R3(3 downto 0), digito_1 => R3(7 downto 4), digito_2 => "0000", digito_3 => PC(5 downto 2), display => display, display_enable => display_enable);
	
end MIPSMulticicloArch;