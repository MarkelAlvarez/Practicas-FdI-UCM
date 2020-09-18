library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity divisor is
	port(rst: in STD_LOGIC;
		 clk_entrada: in STD_LOGIC; 
		 clk_salida: out STD_LOGIC;
		 clk_salida_a: out STD_LOGIC;
		 clk_salida_b: out STD_LOGIC);
end divisor;

architecture divisor_arch of divisor is

	signal cuenta: std_logic_vector(25 downto 0);
	signal cuenta_a: std_logic_vector(25 downto 0);
	signal cuenta_b: std_logic_vector(25 downto 0);
	signal clk_aux: std_logic;
	signal clk_aux_a: std_logic;
	signal clk_aux_b: std_logic;
	
	begin
	
	clk_salida <= clk_aux;
	clk_salida_a <= clk_aux_a;
	clk_salida_b <= clk_aux_b;

	contador: process(rst, clk_entrada)
	begin
		if (rst = '1') then
			cuenta <= (others=>'0');
			cuenta_a <= (others=>'0');
			cuenta_b <= (others=>'0');
			clk_aux <= '0';
			clk_aux_a <= '0';
			clk_aux_b <= '0';
		elsif(clk_entrada'EVENT AND clk_entrada='1') then
			if (cuenta = "11111111111111111111111111") then 
				clk_aux <= not clk_aux;
				cuenta <= (others=>'0');
			else
				cuenta <= cuenta+'1';
				clk_aux <= clk_aux;
			end if;
			
			if (cuenta_a = "00000001011100011101101110") then 
				clk_aux_a <= not clk_aux_a;
				cuenta_a <= (others=>'0');
			else
				cuenta_a <= cuenta_a+'1';
				clk_aux_a <= clk_aux_a;
			end if;
			
			if (cuenta_b = "01000111111100110001111011") then 
				clk_aux_b <= not clk_aux_b;
				cuenta_b <= (others=>'0');
			else
				cuenta_b <= cuenta_b+'1';
				clk_aux_b <= clk_aux_b;
			end if;
		end if;
	end process contador;
end divisor_arch;