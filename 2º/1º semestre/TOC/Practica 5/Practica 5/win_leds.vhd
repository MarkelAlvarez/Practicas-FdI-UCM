library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity win_leds is
	port(rst: in std_logic;
		 clk: in std_logic;
		 leds: out std_logic_vector(9 downto 0));
end win_leds;

architecture behavioral of win_leds is
 
 	signal tmp : std_logic_vector(9 downto 0);
 
	begin
 
 	process(clk,rst,tmp)
 	begin
  		if rst = '1' then
   			tmp <= (others => '0');
  		elsif rising_edge(clk) then 
   			if tmp = "0000000000" then
				tmp <= "1111111111";
   			else 
				tmp <= "0000000000";
   			end if;
  		end if;
 	end process;
 
 	leds <= tmp;
 
end architecture behavioral;