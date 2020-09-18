library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity Multi_secuencial is
 Port (
    clk: in std_logic;
    rst: in std_logic;
    ini: in std_logic;
    a: in std_logic_vector(3 downto 0);
    b: in std_logic_vector(3 downto 0);
    res: out std_logic_vector(7 downto 0);
    led: out std_logic_vector(15 downto 0)
  );
end Multi_secuencial;

architecture Behavioral of Multi_secuencial is

signal aux_a: std_logic_vector(7 downto 0);
signal aux_b: std_logic_vector(3 downto 0);
signal acc: std_logic_vector(7 downto 0);

begin
ASM:
	process (rst, clk)
	 
	 type estados is (set, idle, done); 
	 variable estado: estados;
	 variable n: integer;
	 begin
	 
	 if(rst='1') then
	 res <= (others=>'0');
     aux_a <= (others=>'0');
     aux_b <= (others=>'0');
     acc <= (others=>'0');
     estado:= done;
     else if(clk'event and clk='1') then
     case estado is
     
		  when done =>
		         res  <= acc;
		         led <= "1111111111111111";
				 if ini = '1' then
					 estado := set;
				 else 
					 estado := done;
				 end if;
				 
		  when set => 
              led <=(others=>'0');
              aux_a <= "0000" & a;
              aux_b <= b;
              n := 4;
              acc <= (others=>'0');
		      estado := idle;
		      
		   when idle =>
		      if to_bit(aux_b(0)) = '1' then
	          acc <= std_logic_vector(unsigned(acc) + unsigned(aux_a));
	          end if;
	          aux_a <= std_logic_vector(aux_a(6 downto 0) & '0');
		      aux_b <= std_logic_vector('0' & aux_b(3 downto 1));
		      n := n-1;
		   if n = 0 then
		      estado := done;
		   else
		      estado:= idle;
		   end if;
		   
		end case;
	 end if;
	 end if;
	 
    end process;
end Behavioral;