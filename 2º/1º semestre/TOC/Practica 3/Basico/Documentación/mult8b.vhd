library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity mult8b is
	port( X: in  std_logic_vector(3 downto 0);
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
	
    begin        
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
            a => X2,
            b => Z0,
            c => Z1 );
        s3: adder8b port map (
            a => X3,
            b => Z1,
            c => Z );
end rtl;
