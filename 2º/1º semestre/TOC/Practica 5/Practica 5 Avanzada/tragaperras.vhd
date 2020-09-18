library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tragaperras is
    port(rst: in std_logic;
        clk: in std_logic;
        ini: in std_logic;
        fin: in std_logic;
        entrada1: in std_logic_vector(3 downto 0);
        entrada2: in std_logic_vector(3 downto 0);
        display: out std_logic_vector(6 downto 0);
        display_enable: out std_logic_vector(3 downto 0);
        leds: out std_logic_vector(9 downto 0));
end tragaperras;

architecture behavioral of tragaperras is
 
 component divisor 
    port(rst: in std_logic;
         clk_entrada: in std_logic;
         clk_salida: out std_logic;
         clk_salida_a: out std_logic; 
         clk_salida_b: out std_logic);
 end component;

 component estados
    port(clk: in std_logic;
         rst: in std_logic;
         ini: in std_logic;
         fin: in std_logic;
         control_data: in std_logic_vector(1 downto 0);
         control: out std_logic_vector (6 downto 0));
 end component;
 
 component ruta_de_datos
    port(clk_1hleds: in std_logic;
         clk_a: in std_logic;
         clk_b: in std_logic;
         entrada1: in std_logic_vector(3 downto 0);
         entrada2: in std_logic_vector(3 downto 0);
         control: in std_logic_vector(6 downto 0);
         display_out_a: out std_logic_vector(3 downto 0);
         display_out_b: out std_logic_vector(3 downto 0);
         control_data: out std_logic_vector(1 downto 0);
         leds: out std_logic_vector(9 downto 0));
 end component;
 
 component debouncer is
    port(rst: in  std_logic;
         clk: in  std_logic;
         x: in  std_logic;
         xdeb: out std_logic;
         xdebfallingedge: out std_logic;
         xdebrisingedge: out std_logic);
 end component;
 
 component displays is
    port(rst: in STD_LOGIC;
         clk: in STD_LOGIC;       
         digito_0: in  STD_LOGIC_VECTOR (3 downto 0);
         digito_1: in  STD_LOGIC_VECTOR (3 downto 0);
         digito_2: in  STD_LOGIC_VECTOR (3 downto 0);
         digito_3: in  STD_LOGIC_VECTOR (3 downto 0);
         display: out  STD_LOGIC_VECTOR (6 downto 0);
         display_enable: out  STD_LOGIC_VECTOR (3 downto 0));
 end component;
 
     signal button_rst, button_ini, button_fin, xdebfallingedge_rst, xdebfallingedge_ini, xdebfallingedge_fin, xdebrisingedge0, xdebrisingedge1, xdebrisingedge2: std_logic;
     signal clk_1hleds, clk_a, clk_b : std_logic;
     signal disp_aux_a, disp_aux_b : std_logic_vector(3 downto 0);
     signal control_link : std_logic_vector (6 downto 0);
     signal control_data_link : std_logic_vector (1 downto 0);
     signal rst_not : std_logic;
     signal entrada1_aux, entrada2_aux: std_logic_vector(3 downto 0);
 
 begin
 
process(entrada1, entrada2)
    begin
    if entrada1 < entrada2 then
        entrada1_aux <= entrada1; 
        entrada2_aux <= entrada2;
    else
        entrada1_aux <= entrada1;
        entrada2_aux <= entrada1;
    end if;
 end process;

 rst_not <= not rst;
 
 rst_debouncer: debouncer 
    port map(rst => '1', 
            clk => clk, 
            x => rst, 
            xdeb => button_rst, 
            xdebfallingedge => xdebfallingedge_rst, 
            xdebrisingedge => xdebrisingedge0);
             
 ini_debouncer: debouncer 
    port map(rst => '1', 
             clk => clk, 
             x => ini, 
             xdeb => button_ini, 
             xdebfallingedge => xdebfallingedge_ini, 
             xdebrisingedge => xdebrisingedge1);
  
 fin_debouncer: debouncer 
    port map(rst => '1', 
             clk => clk, 
             x => fin, 
             xdeb => button_fin, 
             xdebfallingedge => xdebfallingedge_fin, 
             xdebrisingedge => xdebrisingedge2);
               
 div: divisor
    port map(rst => button_rst,
             clk_entrada => clk, 
             clk_salida => clk_1hleds,
             clk_salida_a => clk_a,
             clk_salida_b => clk_b);
  
 dp: ruta_de_datos 
    port map(clk_1hleds => clk_1hleds,
             clk_a => clk_a, 
             clk_b => clk_b,
             entrada1 => entrada1_aux,
             entrada2 => entrada2_aux,
             control => control_link, 
             display_out_a => disp_aux_a, 
             display_out_b => disp_aux_b, 
             control_data => control_data_link, 
             leds => leds);
 
 cu: estados
    port map(clk => clk, 
             rst => button_rst,
             ini => button_ini, 
             fin => button_fin, 
             control_data => control_data_link, 
             control => control_link);
  
  dsp: displays
    port map(rst => button_rst,
             clk => clk,       
             digito_0 => disp_aux_a,
             digito_1  => disp_aux_b,
             digito_2 => "0000",
             digito_3 => "0000",
             display => display,
             display_enable => display_enable);
 
end architecture behavioral;