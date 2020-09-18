----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 11/18/2019 05:26:57 AM
-- Design Name: 
-- Module Name: caja_tb - Behavioral
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

entity caja_tb is
--  Port ( );
end caja_tb;

architecture Behavioral of caja_tb is

component Caja
Port ( clk: in std_logic;
    rst: in std_logic;
    ini: in std_logic;
    a: in std_logic_vector(3 downto 0);
    b: in std_logic_vector(3 downto 0);
    led: out std_logic_vector(15 downto 0);
    display : out  STD_LOGIC_VECTOR (6 downto 0);
    display_enable : out  STD_LOGIC_VECTOR (3 downto 0));
end component;

signal clk, rst, ini: std_logic;
signal a, b: std_logic_vector(3 downto 0);
signal led: std_logic_vector(15 downto 0);
signal display: STD_LOGIC_VECTOR (6 downto 0);
signal display_enable: STD_LOGIC_VECTOR (3 downto 0);
constant clk_period: time := 10 ns;

begin

uut: Caja port map (
clk => clk,
rst => rst,
ini => ini,
a => a,
b => b,
led => led,
display => display,
display_enable => display_enable
 );

stimulus: process
  begin
  
    -- Put initialisation code here
    rst <='1';
    wait for 10 ns;
    rst <='0';
    wait for 10 ns;

    ini <='1';
    a <="0011"; b <="0010";
    wait for 50 ns;
    
    
    a <="1000"; b <="0010";
    wait for 170 ns;
    ini <= '0';
    wait for 5 ns;
   
    wait for 20 ns;
    
    
    a<="0001"; b <= "1110";
    wait;
  end process;
  
clk_process: process 
begin
 clk <= '0';
 wait for clk_period/2;
 clk <= '1';
  wait for clk_period/2;
  end process;

end Behavioral;
