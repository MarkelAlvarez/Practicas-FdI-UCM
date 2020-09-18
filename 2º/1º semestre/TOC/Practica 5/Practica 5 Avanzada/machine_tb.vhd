--01/12
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity machine_tb is
end machine_tb;

architecture Behavioral of machine_tb is

component machine is
 port(
  rst: in std_logic;
  clk: in std_logic;
  ini : in std_logic;
  fin : in std_logic;
  display: out std_logic_vector(6 downto 0);
  display_enable: out std_logic_vector(3 downto 0);
  leds: out std_logic_vector(9 downto 0)
 );
end component;

  signal rst: std_logic := '0';
  signal clk: std_logic := '0';
  signal ini : std_logic := '0';
  signal fin : std_logic := '0';
  signal display: std_logic_vector(6 downto 0);
  signal display_enable: std_logic_vector(3 downto 0);
  signal leds: std_logic_vector(9 downto 0);

begin

mach: machine
 port map(
  rst => rst,
  clk => clk,
  ini => ini,
  fin => fin,
  display => display,
  display_enable => display_enable,
  leds => leds
 );
 
 process
 begin
    if(clk='1') then 
		clk<='0';
	else
		clk<='1';
	end if;
	
	wait for 30 ns;
		
end process;

process
begin

    rst <= '1';
	wait for 60 ns;
	
	rst <= '0';
	wait for 60 ns;
	
	ini <= '1';
	wait for 60 ns;
	
	ini <= '0';
	wait for 200 ns;
	
	fin <= '1';
	wait for 60 ns; 
	
	fin <= '0';
	wait for 200 ns;
	
	rst <= '1';
	wait for 60 ns;
	
	rst <= '0';
	wait for 60 ns;
	
	ini <= '1';
	wait for 60 ns;
	
	ini <= '0';
	wait for 150 ns;
	
	fin <= '1';
	wait for 60 ns; 
	
	fin <= '0';
	wait for 2000 ns;

end process;

end Behavioral;
