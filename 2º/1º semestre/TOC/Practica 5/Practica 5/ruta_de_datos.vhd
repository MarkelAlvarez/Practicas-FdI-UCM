library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ruta_de_datos is
	port(clk_1hleds: in std_logic;
  		 clk_a : in std_logic;
	     clk_b : in std_logic;
	     control : in std_logic_vector(6 downto 0);
	     display_out_a : out std_logic_vector(3 downto 0);
	     display_out_b : out std_logic_vector(3 downto 0);
	     control_data : out std_logic_vector(1 downto 0);
	     leds: out std_logic_vector(9 downto 0));
end ruta_de_datos;

architecture behavioral of ruta_de_datos is

 	component cont_mod10
  		port(rst: in std_logic;
		     clk: in std_logic;
		     enable : in std_logic;
		     leds : out std_logic_vector(3 downto 0));
 	end component;
 
 	component conv_7seg
  		port (x: in std_logic_vector (3 downto 0);
  			  display : out std_logic_vector (6 downto 0));
 	end component;

	 component waiting_leds
		port (rst: in std_logic;
		     clk: in std_logic;
		     leds: out std_logic_vector(9 downto 0));
	 end component;
 
	component win_leds
		port (rst: in std_logic;
	  		  clk: in std_logic;
	  		  leds: out std_logic_vector(9 downto 0));
	end component;
 
 	component lose_leds
  		port (rst: in std_logic;
   			  clk: in std_logic;
   			  leds: out std_logic_vector(9 downto 0));
 	end component;
 
	signal lose,waiting,win : std_logic_vector(9 downto 0);
	signal out_cont_a,out_cont_b,out_cont_n, dsp_a_ram, dsp_b_ram : std_logic_vector(3 downto 0);
	signal control_aux : std_logic_vector(1 downto 0);
	signal error_s : std_logic_vector(3 downto 0) := "1101";
  
	alias cont_rst: std_logic is control(0); 
	alias cont_enable: std_logic is control(1);
	alias seq_rst : std_logic is control(2);
	alias seq_enable:  std_logic is control(3);
	alias mux_leds_A :  std_logic is control(4);
	alias mux_leds_B :  std_logic is control(5);
	alias rst_attract :  std_logic is control(6);
 
	begin
	control_data <= control_aux;
	display_out_a <= out_cont_a;
	display_out_b <= out_cont_b;
 
 	cont_a : cont_mod10
 		port map(rst => cont_rst,
			     clk => clk_a,
			     enable => cont_enable,
			     leds => out_cont_a);
 
	 cont_b : cont_mod10
		port map(rst => cont_rst,
				 clk => clk_b,
				 enable => cont_enable,
				 leds => out_cont_b);
	 
	 cont_n : cont_mod10
	 	port map(rst => seq_rst,
			    clk => clk_1hleds,
			    enable => seq_enable,
			    leds => out_cont_n);
 
	process (out_cont_n)
	begin 
		if out_cont_n = "1001" then
	  	 	control_aux(0) <= '1';
	  	else 
	   		control_aux(0) <= '0';
	  	end if;
	end process;
 
 	process (out_cont_a,out_cont_b)
 	begin 
  		if out_cont_a = out_cont_b then 
  			control_aux(1) <= '1';
  		else 
   			control_aux(1) <= '0';
  		end if;
 	end process;
 
	at: waiting_leds 
		port map(
	  rst => rst_attract,
	  clk => clk_1hleds,
	  leds => waiting
	 );
 
	vi: win_leds 
		port map(rst => seq_rst,
				 clk => clk_1hleds,
				 leds => win);
	 
	de: lose_leds
	 	port map(rst => seq_rst,
				 clk => clk_1hleds,
				 leds => lose);
 
 	process(win,lose,waiting,control, mux_leds_A, mux_leds_B,clk_a,clk_b)
  	begin
   		if mux_leds_B = '0' and mux_leds_A = '0' then 
			leds <= "0000000000";
   		elsif mux_leds_B = '1' and mux_leds_A = '1' then
			leds <= win;
   		elsif mux_leds_B = '1' and mux_leds_A = '0' then 
			leds <= lose;
   		else 
		leds <= waiting;
  		 end if;
 	end process; 
 	
end architecture behavioral;