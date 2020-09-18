library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Componentes is
  Port ( clk: in std_logic;
    rst: in std_logic;
    ini: in std_logic;
    a: in std_logic_vector(3 downto 0);
    b: in std_logic_vector(3 downto 0);
    c: in std_logic_vector(3 downto 0);
    led: out std_logic_vector(15 downto 0);
    display : out  STD_LOGIC_VECTOR (6 downto 0);
    display_enable : out  STD_LOGIC_VECTOR (3 downto 0));
end Componentes;

architecture Behavioral of Componentes is

component Mult_3Num 
Port (
    clk: in std_logic;
    rst: in std_logic;
    ini: in std_logic;
    a: in std_logic_vector(3 downto 0);
    b: in std_logic_vector(3 downto 0);
    c: in std_logic_vector(3 downto 0);
    res: out std_logic_vector(11 downto 0);
    led: out std_logic_vector(15 downto 0)
  );
  end component;
  
component Conv_bcd3
Port (
  num: in std_logic_vector(11 downto 0);
  bcd_num: out std_logic_vector(15 downto 0)
  );
end component;

component  debouncer
Port (
    rst: IN std_logic;
    clk: IN std_logic;
    x: IN std_logic;
    xDeb: OUT std_logic;
    xDebFallingEdge: OUT std_logic;
    xDebRisingEdge: OUT std_logic
  );
end component;

component displays
    Port ( 
        rst : in STD_LOGIC;
        clk : in STD_LOGIC;       
        digito_0 : in  STD_LOGIC_VECTOR (3 downto 0);
        digito_1 : in  STD_LOGIC_VECTOR (3 downto 0);
        digito_2 : in  STD_LOGIC_VECTOR (3 downto 0);
        digito_3 : in  STD_LOGIC_VECTOR (3 downto 0);
        display : out  STD_LOGIC_VECTOR (6 downto 0);
        display_enable : out  STD_LOGIC_VECTOR (3 downto 0)
     );
end component;

signal mult_aux: std_logic_vector(11 downto 0);
signal aux_bcd: std_logic_vector(15 downto 0);

begin

mod_multiplicador: Mult_3Num 
port map (
clk => clk,
rst => rst,
ini => ini,    
a => a,
b => b, 
c => c,
res => mult_aux,
led => led
);

mod_bcd: Conv_bcd3 
port map (
num => mult_aux,
bcd_num => aux_bcd
);

mod_displays: displays 
port map (
clk => clk,
rst => rst,
digito_0 => aux_bcd(3 downto 0),
digito_1 => aux_bcd(7 downto 4),
digito_2 => aux_bcd(11 downto 8),
digito_3 => aux_bcd(15 downto 12),
display => display,
display_enable => display_enable
);

end Behavioral;
