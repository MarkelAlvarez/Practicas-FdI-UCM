library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity mult8b is
	port( clk: in std_logic;
		  rst: in std_logic;
		  X: in  std_logic_vector(3 downto 0);
		  Y: in  std_logic_vector(3 downto 0);
		  Z: out std_logic_vector(7 downto 0) );
end mult8b;

architecture rtl of mult8b is
	component adder8b
        port(a: in std_logic_vector(7 downto 0);
             b: in std_logic_vector(7 downto 0);
             c: out std_logic_vector(7 downto 0) );
	end component;
	
	signal X0, X1, X2, X3: std_logic_vector(7 downto 0) := (others => '0');
	signal Y0, Y1, Y2, Y3: std_logic_vector(3 downto 0);
	signal Z0, Z1: std_logic_vector(7 downto 0);
	signal reg1Out, reg2Out, reg3Out, reg4Out, reg5Out: std_logic_vector(7 downto 0);
	
	begin
		p_reg:process(clk,rst)
		begin
		
			if(clk'event and clk='1') then
				if(rst='1') then
					reg1Out <= (others =>'0');
					reg2Out <= (others =>'0');
					reg3Out <= (others =>'0');
					reg4Out <= (others =>'0');
					reg5Out <= (others =>'0');
				else 
					reg1Out <= X3;
					reg2Out <= X2;	
					reg3Out <= Z0;
					reg4Out <= reg1Out;
					reg5Out <= Z1;		
				end if;
			end if;
		
		end process;
        
        Y0 <= (others => Y(0));
        Y1 <= (others => Y(1));
        Y2 <= (others => Y(2));
        Y3 <= (others => Y(3));
        X0(3 downto 0) <= X and Y0;
        X1(4 downto 1) <= X and Y1;
        X2(5 downto 2) <= X and Y2;
        X3(6 downto 3) <= X and Y3;
        
        s1: adder8b port map(
            a => X0,
            b => X1,
            c => Z0 );      
        s2: adder8b port map (
            a => reg2Out,
            b => reg3Out,
            c => Z1 );
        s3: adder8b port map (
            a => reg4Out,
            b => reg5Out,
            c => Z );
end rtl;
