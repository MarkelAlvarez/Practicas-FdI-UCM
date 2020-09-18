library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;

entity waiting_leds is
	port(rst: in std_logic;
		 clk: in std_logic;
		 leds: out std_logic_vector(9 downto 0));
end waiting_leds;

architecture behavioral of waiting_leds is
 
 	signal tmp : std_logic_vector(9 downto 0);
 
 	begin

 		process(clk,rst,tmp)
 		begin
  			if rst = '1' then
  				tmp <= (others => '0');
  			elsif rising_edge(clk) then 
   				if tmp(9) = '1' then
					tmp(9 downto 1) <= tmp(8 downto 0);
					tmp(0) <= '0';
   				else
					tmp(9 downto 1) <= tmp(8 downto 0);
					tmp(0) <= '1';
   				end if;
 		 	end if;
 	end process;
 
  	leds <= tmp;

end architecture behavioral;