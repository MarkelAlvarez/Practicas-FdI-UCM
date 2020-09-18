library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity adder2b is
	port( a: in  std_logic_vector(1 downto 0);
		  b: in  std_logic_vector(1 downto 0);
		  c: out std_logic_vector(1 downto 0) );
end adder2b;

architecture arch of adder2b is
	signal a_u, b_u, c_u: unsigned(1 downto 0);
	
	begin
		a_u <= unsigned(a);
		b_u <= unsigned(b);
		c_u <= a_u + b_u;
		c   <= std_logic_vector(c_u(1 downto 0));
end arch;
