----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 11/15/2019 08:56:07 AM
-- Design Name: 
-- Module Name: ConversorBCD_tb - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity bcd_tb is
end bcd_tb;

architecture Behavioral of bcd_tb is

component Conv_bcd3 
 Port (
  num: in std_logic_vector(11 downto 0);
  bcd_num: out std_logic_vector(15 downto 0)
  
  );
  end component;
  
  signal num: std_logic_vector(11 downto 0);
  signal bcd_num: std_logic_vector(15 downto 0);
  
begin


uut: Conv_bcd3 port map ( num => num,
                          bcd_num => bcd_num );
                          
  stimulus: process
  begin
  
    -- Put initialisation code here
    num <="000000000000";
    wait for 20 ns;
    
    num <="111111111111";
    wait for 20 ns;
   
    
    num <="000010111111";
    wait for 20 ns;
    wait;
   
    end process;
end Behavioral;
