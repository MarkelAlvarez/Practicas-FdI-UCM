----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 11/16/2019 08:36:24 AM
-- Design Name: 
-- Module Name: Mult3_tb - Behavioral
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

entity Mult3_tb is
--  Port ( );
end Mult3_tb;

architecture Behavioral of Mult3_tb is

component Mult_3Num 

Port(clk: in std_logic;
    rst: in std_logic;
    ini: in std_logic;
    a: in std_logic_vector(3 downto 0);
    b: in std_logic_vector(3 downto 0);
    c: in std_logic_vector(3 downto 0);
    res: out std_logic_vector(11 downto 0);
    led: out std_logic_vector(15 downto 0));
end component;

signal clk, rst, ini: std_logic;
signal a, b, c: std_logic_vector(3 downto 0);
signal res:  std_logic_vector(11 downto 0);
signal led: std_logic_vector(15 downto 0);
constant clk_period: time := 10 ns;

begin

uut: Mult_3Num port map (
clk => clk,
rst => rst,
ini => ini,
a => a,
b => b,
c => c,
res => res,
led => led
 );
 
 stimulus: process
  begin
  
    -- Put initialisation code here
    rst <='1';
    wait for 10 ns;
    rst <='0';
    wait for 10 ns;

    ini <='1';
    a <="0011"; b <="0110"; c <="0011";
    wait for 20 ns;
    ini <='0';
    wait for 200 ns;
    
    ini <='1';
    a <="1111"; b <="1111"; c <="1111";
    wait for 20 ns;
    
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
