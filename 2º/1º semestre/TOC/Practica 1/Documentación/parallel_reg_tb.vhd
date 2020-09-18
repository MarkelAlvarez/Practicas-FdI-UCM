-- We add the libraries needed
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

-- Entity declaration
ENTITY parallel_reg_tb IS
END parallel_reg_tb;

-- Architecture
ARCHITECTURE testbench_arch OF parallel_reg_tb IS
		-- Component declaration
		COMPONENT parallel_reg
		 port( rst, clk, load: in  std_logic;
				 I:              in  std_logic_vector(3 downto 0);
				 O:              out std_logic_vector(3 downto 0) );
		END COMPONENT;

	-- Inputs
	signal rst : std_logic;
	signal clk: std_logic;
	signal load : std_logic;
	signal I : std_logic_vector(3 downto 0);
	-- Outputs
	signal O : std_logic_vector(3 downto 0);

	constant clk_period: time := 10ns;

	begin
		uut: parallel_reg port map(
				clk => clk,
				rst => rst,
				load => load,
				I => I,
				O => O
			);

		clk_process: process
		begin
			for i in 1 to 20 loop
				clk <= '0';
				wait for clk_period;
				clk <= '1';
				wait for clk_period;
			end loop;
		end process;

		stim_pro: process
		begin
		    rst <= '1';
			load <= '0';
			I <= "0000";
			wait for 10ns;
			
			rst <= '1';
			load <= '1';
			I <= "0001";
			wait for 10ns;

			rst <= '0';
			load <= '0';
			I <= "0010";
			wait for 10ns;

			rst <= '0';
			load <= '1';
			I <= "0011";
			wait for 10ns;
			
			rst <= '0';
			load <= '0';
			I <= "0100";
			wait for 10ns;
			
			rst <= '0';
			load <= '1';
			I <= "0101";
			wait for 10ns;
			
			rst <= '0';
			load <= '0';
			I <= "0111";
			wait for 10ns;
			
			rst <= '0';
			load <= '1';
			I <= "1111";
			wait for 10ns;
		wait;
		end process;
END testbench_arch;
