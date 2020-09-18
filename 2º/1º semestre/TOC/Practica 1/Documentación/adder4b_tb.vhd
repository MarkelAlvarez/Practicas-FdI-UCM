-- We add the libraries needed
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

-- Entity declaration
ENTITY simadd IS
END simadd;

-- Architecture
ARCHITECTURE testbench_arch OF simadd IS
    -- Component declaration
    COMPONENT adder4b
    PORT(
         A : IN  std_logic_vector(3 downto 0);
         B : IN  std_logic_vector(3 downto 0);
         C : OUT std_logic_vector(3 downto 0)
        );
    END COMPONENT;

   -- Inputs
   signal A : std_logic_vector(3 downto 0) := (others => '0');
   signal B : std_logic_vector(3 downto 0) := (others => '0');

   -- Outputs
   signal C : std_logic_vector(3 downto 0);

   BEGIN
     -- Instantiation of the unit under test
      uut: adder4b PORT MAP (
             A => A,
             B => B,
             C => C );
     -- Stimuli process
   stim_proc: process
       begin
           A <= "0000";        B <= "0000";
           wait for 100 ns;
           A <= "0101";        B <= "0100";
           wait for 100 ns;
           A <= "0000";        B <= "0111";
           wait for 100 ns;
           A <= "0011";        B <= "1000";
           wait for 100 ns;
           A <= "1011";        B <= "1111";
           wait for 100 ns;
           A <= "1001";        B <= "0110";
           wait;
   end process;

   END testbench_arch;
