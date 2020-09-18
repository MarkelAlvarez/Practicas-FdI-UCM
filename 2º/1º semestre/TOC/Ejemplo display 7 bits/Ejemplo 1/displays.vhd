library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;


entity displays is
    Port ( 
        rst : in STD_LOGIC;
        clk : in STD_LOGIC; 
        velocidad : in  STD_LOGIC_VECTOR (1 downto 0);      
        display : out  STD_LOGIC_VECTOR (6 downto 0);
        display_enable : out  STD_LOGIC_VECTOR (3 downto 0)
     );
end displays;

architecture Behavioral of displays is

    signal contador_refresco : STD_LOGIC_VECTOR (26 downto 0);
    signal ritmo_parapadeo : STD_LOGIC;    

begin

    -- PARPADEO - INICIO
    ritmo_parapadeo <=  contador_refresco (23) when (velocidad = "11") else
                        contador_refresco (24) when (velocidad = "10") else
                        contador_refresco (25) when (velocidad = "01") else
                        contador_refresco (26);
    
    display <=  (others=>'1') when (ritmo_parapadeo = '1') else (others=>'0');

    process(clk)
    begin
        if rising_edge(clk) then
            if (rst = '1') then
                contador_refresco <= (others=>'0');
            else
                contador_refresco <= contador_refresco + 1;
            end if;
        end if;
    end process;

    display_enable <= "0000";      
    -- PARPADEO - FIN

end Behavioral;

