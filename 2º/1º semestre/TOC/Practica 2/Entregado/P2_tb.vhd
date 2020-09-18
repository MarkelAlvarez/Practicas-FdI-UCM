library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;

entity padlockSim is
end padlockSim;

architecture Behavioral of padlockSim is
	
	component padlock
	port(rst:             in std_logic;
		  clk:             in std_logic;
		  keyCombination:  in std_logic_vector(7 downto 0);
		  isUnlocked:     out std_logic;
		  attemptsLeft:   out std_logic_vector(3 downto 0));
	end component;
	
	signal rst: std_logic;
	signal clk: std_logic := '0';
	signal key: std_logic_vector(7 downto 0);
	signal unlocked: std_logic;
	signal remaining: std_logic_vector(3 downto 0);
	
begin
	uut: padlock port map
	(
		rst => rst,
		clk => clk,
		keyCombination => key,
		isUnlocked => unlocked,
		attemptsLeft => remaining
	);
	
	process 
	begin
		if(clk='1') then
			clk <= '0';
		else 
			clk <= '1';
		end if;
		
		wait for 50 ns;
	end process;
	
	process
	begin
		rst <= '1';
		wait for 25 ns;
		
		rst <= '0';
		
		key <= "01010101";
		wait for 100 ns;
		
		key <= "00000000";
		wait for 200 ns;
		
		key <= "01010101";	
		wait for 100 ns;
		
		key <= "11111111";
		wait for 100 ns;
		
		key <= "01111111";
		wait for 100 ns;
		
		key <= "11111111";	
		wait for 50 ns;
		key <= "11111110";	
		wait for 50 ns;
		
		key <= "01010101";
		wait for 100 ns;
		
		key <= "11111111";	
		wait for 200 ns;
		
		rst <= '0';
		wait for 25 ns;
		
		rst <= '1';
		key <= "00001111";
		wait for 100 ns;
		
		wait;
	end process;


end Behavioral;