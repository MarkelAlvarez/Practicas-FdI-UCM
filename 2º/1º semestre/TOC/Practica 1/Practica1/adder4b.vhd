library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity adder4b is
    port( a: in  std_logic_vector(3 downto 0);
          b: in  std_logic_vector(3 downto 0);
          c: out std_logic_vector(3 downto 0) );
end adder4b;

architecture rtl of adder4b is
    signal a_u, b_u, c_u: unsigned(3 downto 0);
begin
    a_u <= unsigned(a);
    b_u <= unsigned(b);
    c_u <= a_u + b_u;
    c   <= std_logic_vector(c_u(3 downto 0));
end rtl;
