LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY TestBenchMIPSMulticiclo IS
END TestBenchMIPSMulticiclo;
 
ARCHITECTURE behavior OF TestBenchMIPSMulticiclo IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT MIPSMulticiclo
    PORT(
         clk : IN  std_logic;
         rst : IN  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal rst : std_logic := '0';

   -- Clock period definitions
   constant clk_period : time := 100 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: MIPSMulticiclo PORT MAP (
          clk => clk,
          rst => rst
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 200 ns.
		rst <= '0';
      wait for 200 ns;	

		rst <= '1';
      wait for clk_period*10;

      -- insert stimulus here 

      wait;
   end process;

END;
