------------------------------------------------------------
-- register with parallel input / parallel output
------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity parallel_reg is
    port( rst, clk, load: in  std_logic;
	       I:              in  std_logic_vector(3 downto 0);
	       O:              out std_logic_vector(3 downto 0) );
end parallel_reg;

architecture circuit of parallel_reg is
begin

    process(rst, clk)
    begin
	      if clk'event and clk = '1' then
		      if rst = '1' then
			    O <= "0000";
		      elsif load = '1' then
			    O <= I;
		      end if;
	      end if;
    end process;
end circuit;
