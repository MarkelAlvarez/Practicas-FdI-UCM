library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity lose_leds is
	port(rst: in std_logic;
  		 clk: in std_logic;
  		 leds: out std_logic_vector(9 downto 0));
end lose_leds;

architecture behavioral of lose_leds is
 
 	signal tmp : std_logic_vector(9 downto 0);
 
 	begin
 		process(clk,rst,tmp)
		begin
			if rst = '1' then
		   		tmp <= (others => '0');
		  	elsif rising_edge(clk) then 
		   		if tmp = "0101010101" then
					tmp <= "1010101010";
		   		else 
					tmp <= "0101010101";
		   		end if;
		  	end if;
		end process;

 	leds <= tmp;

end architecture behavioral;