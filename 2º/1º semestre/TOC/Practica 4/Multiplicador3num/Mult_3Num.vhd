library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity Mult_3Num is
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
end Mult_3Num;

architecture Behavioral of Mult_3Num is
signal aux_a: std_logic_vector(11 downto 0);
signal aux_b: std_logic_vector(3 downto 0);
signal aux_c: std_logic_vector(3 downto 0);
signal acc: std_logic_vector(11 downto 0);

begin

ASM:
	process (rst, clk)
	 
	 
	 type estados is (set, set2, set3, idle1, idle2, done); 
	 variable estado: estados;
	 variable n: integer;
	 variable i: integer;
	 
	 begin
	
	 
	 if(rst='1') then
     res <= (others=>'0');
     aux_a <= (others=>'0');
     aux_b <= (others=>'0');
     aux_c <= (others=>'0');
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
                        aux_a <= "00000000" & a;
                        aux_b <= b;
                        aux_c <= c;
                        i := 2;
                       estado := idle1;
		      
		   when idle1 =>
		           if i = 0 then
		               estado := done;
		           else
		               estado := set2;
		           end if;
		           
		   when set2 =>
                      n := 4;
                      acc <= (others=>'0');
		              estado := idle2;
		              
		   when idle2 =>
                      if n = 0 then
                           estado := set3;
                      else
                           if to_bit(aux_b(0)) = '1' then
                           acc <= std_logic_vector(unsigned(acc) + unsigned(aux_a));
                           end if;
                           aux_a <= std_logic_vector(aux_a(10 downto 0) & '0');
                           aux_b <= std_logic_vector('0' & aux_b(3 downto 1));
                           n := n-1;
                           estado := idle2;
                      end if;
		    when set3 =>
		              aux_a <= acc;
                      aux_b <= aux_c;
		              i:= i - 1;
		              estado := idle1;
		end case;
	 end if;
	 end if;
	 
    end process;

end Behavioral;
