library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity clock_divider is
    port( rst:     in std_logic;
          clk_in:  in std_logic; 
          clk_out: out std_logic );
end clock_divider;

architecture arch_divider of clock_divider is
  signal count      : unsigned(25 downto 0);
  signal clk_aux: std_logic;
  
  begin

  process(rst, clk_in)
  begin
    if (rst='1') then
      count<= (others=>'0');
      clk_aux<='0';
    elsif(clk_in'event and clk_in='1') then
      if (count=50000000) then 
        clk_aux <= not clk_aux;
        count<= (others=>'0');
      else
        count <= count+1;
        clk_aux<=clk_aux;
      end if;
    end if;
  end process;

  clk_out <= clk_aux;

end arch_divider;
