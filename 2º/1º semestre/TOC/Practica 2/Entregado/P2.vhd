library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;

entity padlock is
	port(rst:             in std_logic;
		  clk:             in std_logic;
		  btn: in std_logic := '0';
		  keyCombination:  in std_logic_vector(7 downto 0);
		  isUnlocked:     out std_logic;
		  attemptsLeft:   out std_logic_vector(3 downto 0));
end padlock;

architecture Behavioral of padlock is
	type states is (Si, S1, S2, S3, Sf);
	
	constant INTENTOS: std_logic_vector(3 downto 0) := "0011";
	
	signal actualState: states := Si;
	signal nextState:   states := Si;
	signal storedKey: std_logic_vector(7 downto 0);
	signal nextKey:   std_logic_vector(7 downto 0);
begin

	process(rst, clk)
	begin
	
		if(rst='0') then
			actualState <= Si;
		elsif(clk'event and clk='1') then
			actualState <= nextState;
			storedKey   <= nextKey;
		end if;
	
	end process;
	
	process(actualState, keyCombination)
	begin
		isUnlocked 	 <= '0';
		nextState    <= Si;
		nextKey      <= storedKey;
		attemptsLeft <= (others => '0');
		
		case actualState is
		when Si => 
			nextState    <= S1;
			nextKey      <= keyCombination;
			isUnlocked   <= '1';
			
		when S1 =>
			if (btn = '1' AND keyCombination /= storedKey) then
				nextState <= S2;
			end if;
			
			attemptsLeft <= INTENTOS;		
		when S2 =>
			if(btn = '1' AND keyCombination /= storedKey) then
				nextState <= S3;
			end if;
			
			attemptsLeft <= "0010";
		when S3 =>
			if(btn = '1' AND keyCombination /= storedKey) then
				nextState <= Sf;
			end if;
			
			attemptsLeft <= "0001";
		when others =>
			nextState <= Sf;
		
		end case;	
	end process;

end Behavioral;