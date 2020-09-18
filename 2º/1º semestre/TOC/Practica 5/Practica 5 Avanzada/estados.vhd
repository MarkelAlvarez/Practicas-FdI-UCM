library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity estados is
	port(clk: in std_logic;
		 rst: in std_logic;
		 ini : in std_logic;
		 fin : in std_logic;
		 control_data : in std_logic_vector(1 downto 0);
		 control:out std_logic_vector (6 downto 0));
end estados;

architecture behavioral of estados is

	alias comp_a_b : std_logic is control_data(1);
	alias comp_n_10 : std_logic is control_data(0);
  
 	type states is (s0, s1, s2, s3, s4);
 
	signal actual, siguiente: states;
	signal aux_control: std_logic_vector(6 downto 0);
	alias cont_rst: std_logic is aux_control(0); 
	alias cont_enable: std_logic is aux_control(1);
	alias seq_rst : std_logic is aux_control(2);
	alias seq_enable:  std_logic is aux_control(3);
	alias mux_leds_a :  std_logic is aux_control(4);
	alias mux_leds_b :  std_logic is aux_control(5);
	alias att_rst :  std_logic is aux_control(6);

	begin

	control <= aux_control;

	process (clk,rst)
	begin
		if rst = '1' then 
			actual <= s0;
	   	elsif rising_edge(clk) then 
			actual <= siguiente;
	   	end if;
	end process;
	  
	process(ini,fin,comp_a_b,comp_n_10,actual)
	begin
		case actual is
			when s0 => 
			 	if ini='1' then
					siguiente <= s1;
			 	else 
			  		siguiente <= s0;
			 	end if;
			 
			when s1 =>
				if fin = '1' then 
			 		if comp_a_b = '1' then 
			  			siguiente <= s2;
			 		else 
			  			siguiente <= s3;
			 		end if;
				else 
			 		siguiente <= s1;
				end if;	

		   	when s2 =>
				if comp_n_10 = '1' then
				 	siguiente <= s0;
				else
					 siguiente <= s2;
				end if;
			
		   	when others =>
				if comp_n_10 = '1' then
				 	siguiente <= s0;
				else
				 	siguiente <= s3;
				end if;
		end case;
	end process;

	process(actual)
	begin 
		case actual is
			when s0 => 
				cont_rst <= '1';
				cont_enable <=  '0';
				seq_rst <=  '1';
				seq_enable <=  '0';
				mux_leds_a <=  '1';
				mux_leds_b <=  '0';
				att_rst <=  '0';
		   	when s1 =>
				cont_rst <=  '0';
				cont_enable <=  '1';
				seq_rst <=  '1';
				seq_enable <=  '0';
				mux_leds_a <=  '0';
				mux_leds_b <=  '0';
				att_rst <=  '1';
		   	when s2 => 
				cont_rst <=  '0';
				cont_enable<=  '0';
				seq_rst <=  '0';
				seq_enable <=  '1';
				mux_leds_a <=  '1';
				mux_leds_b <=  '1';
				att_rst <=  '1';
		   	when s3 => 
				cont_rst <=  '0';
				cont_enable <=  '0';
				seq_rst <=  '0';
				seq_enable <=  '1';
				mux_leds_a <= '0';
				mux_leds_b <=  '1';
				att_rst <=  '1';
			when  others => 
				aux_control <=  (others => '0');
		end case;
	end process;
	
end behavioral;