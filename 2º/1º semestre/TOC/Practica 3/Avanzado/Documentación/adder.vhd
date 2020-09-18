library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity adder8b is
    port( a: in  std_logic_vector(7 downto 0);
          b: in  std_logic_vector(7 downto 0);
          c: out std_logic_vector(7 downto 0) );
end adder8b;

architecture rtl of adder8b is
    signal a_u, b_u, c_u: unsigned(7 downto 0);
begin
    a_u <= unsigned(a);
    b_u <= unsigned(b);
    c_u <= a_u + b_u;
    c   <= std_logic_vector(c_u(7 downto 0));
end rtl;
