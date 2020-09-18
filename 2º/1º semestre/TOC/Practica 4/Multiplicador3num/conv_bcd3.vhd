----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 11/15/2019 05:07:56 AM
-- Design Name: 
-- Module Name: ConversorBCD - Behavioral
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
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Conv_bcd3 is
  Port (
  num: in std_logic_vector(11 downto 0);
  bcd_num: out std_logic_vector(15 downto 0)
  );
end Conv_bcd3;

architecture Behavioral of Conv_bcd3 is

begin
process(num)
variable temp: STD_LOGIC_VECTOR(27 downto 0);
begin
        
        temp := (others => '0');
        -- desplazamos tres veces al inicio
        temp(14 downto 3) := num;
        for i in 0 to 8 loop
            if temp(15 downto 12) > 4 then
                temp(15 downto 12) := temp(15 downto 12) + 3;
            end if;
            
            if temp(19 downto 16) > 4 then
                temp(19 downto 16) := temp(19 downto 16) + 3;
            end if;
           
            if temp(23 downto 20) > 4 then
                temp(23 downto 20) := temp(23 downto 20) + 3;
            end if;
            if temp(27 downto 24) > 4 then
                temp(27 downto 24) := temp(22 downto 19) + 3;
            end if;
            
            -- desplazamos a la izquierda
            temp(27 downto 1) := temp(26 downto 0);
        end loop;
       
        bcd_num <= temp(27 downto 12);
    end process;
end Behavioral;
