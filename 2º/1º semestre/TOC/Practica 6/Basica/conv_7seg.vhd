library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity conv_7seg is
    Port ( x : in  STD_LOGIC_VECTOR (3 downto 0);
           display : out  STD_LOGIC_VECTOR (6 downto 0));
end conv_7seg;

architecture Behavioral of conv_7seg is

    signal display_i : STD_LOGIC_VECTOR (6 downto 0);

begin

with x select
	display_i <= "0000110" when "0001",
	      	    "1011011" when "0010",
	      	    "1001111" when "0011",
	      	    "1100110" when "0100",
                "1101101" when "0101",
                "1111101" when "0110",
                "0000111" when "0111",
                "1111111" when "1000",
                "1101111" when "1001",
                "1110111" when "1010",
                "1111100" when "1011",
                "0111001" when "1100",
                "1011110" when "1101",
                "1111001" when "1110",
                "1110001" when "1111",
                "0111111" when others;
    display <= not display_i;

end Behavioral;

