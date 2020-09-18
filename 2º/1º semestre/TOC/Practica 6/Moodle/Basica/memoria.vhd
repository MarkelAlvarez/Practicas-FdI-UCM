library IEEE;
use IEEE.std_logic_1164.all;

entity memoria is
	port( 
		clk	      : in  std_logic;
		ADDR	  : in  std_logic_vector(31 downto 0 );
		MemWrite  : in  std_logic;
		MemRead	  : in  std_logic;
		DW		  : in  std_logic_vector(31 downto 0 );
		DR		  : out std_logic_vector(31 downto 0 ) 
	);
end memoria;

architecture memoriaArch of memoria is

	-- Este componente se ha creado como un IPCore usando un fichero .coe para su inicialización
--	COMPONENT mem32x512
--	  PORT (
--		 clka 	: IN  STD_LOGIC;
--		 ena 	: IN  STD_LOGIC;
--		 wea 	: IN  STD_LOGIC_VECTOR(0 DOWNTO 0);
--		 addra	: IN  STD_LOGIC_VECTOR(8 DOWNTO 0);
--		 dina	: IN  STD_LOGIC_VECTOR(31 DOWNTO 0);
--		 douta	: OUT STD_LOGIC_VECTOR(31 DOWNTO 0)
--	  );
--	END COMPONENT; 	
  
	-- Este componente se ha creado en VHDL y la inicialización se indica dentro de la propia memoria
	COMPONENT BlockRam is
		port (
			clka, wea, ena : in STD_LOGIC;
			addra : in STD_LOGIC_VECTOR (8 downto 0);
			dina : in STD_LOGIC_VECTOR (31 downto 0);
			douta : out STD_LOGIC_VECTOR (31 downto 0)
		);
	end COMPONENT;  
  
	signal wea : std_logic_vector(0 downto 0);
	signal ena : std_logic;
  
begin

--	mem: mem32x512 PORT MAP(
--		 clka 	=> clk,
--		 ena	=> ena,
--		 wea 	=> wea,
--		 addra	=> ADDR(10 downto 2), -- Reducimos el tamaño de la memoria a 512 posiciones (datos y direcciones de 4 en 4 bytes)
--		 dina	=> DW,
--		 douta	=> DR
--	  );
	  
	mem: BlockRam PORT MAP(
		 clka 	=> clk,
		 ena	=> ena,
		 wea 	=> MemWrite,
		 addra 	=> ADDR(10 downto 2), -- Reducimos el tamaño de la memoria a 512 posiciones (datos y direcciones de 4 en 4 bytes)
		 dina	=> DW,
		 douta	=> DR
	  );	  

	ena <= '1' when (MemWrite = '1' or MemRead = '1') else '0';
	wea <= "1" when (MemWrite = '1') else "0";
	  

end memoriaArch;