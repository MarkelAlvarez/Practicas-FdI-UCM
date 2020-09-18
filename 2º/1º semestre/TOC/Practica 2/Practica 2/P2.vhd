library IEEE;use IEEE.STD_LOGIC_1164.ALL; use IEEE.STD_LOGIC_ARITH.All;use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity padlock is
	port(rst:             in std_logic;
		  clk:             in std_logic;
		  keyCombination:  in std_logic_vector(7 downto 0);
		  isUnlocked:     out std_logic;
		  attemptsLeft:   out std_logic_vector(3 downto 0));
end padlock;

architecture Behavioral of padlock is
	-- States allowed
	type states is (Si, S1, S2, S3, Sf);
	
	-- Attemts we let to find out our key
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
		-- Default output values
		isUnlocked 	 <= '0';
		nextState    <= Si;
		nextKey      <= storedKey;
		attemptsLeft <= (others => '0');
		
		-- Depending the actualState
		case actualState is
		when Si => 
			nextState    <= S1;
			nextKey      <= keyCombination;
			isUnlocked   <= '1';
			
		when S1 =>
			if(keyCombination /= storedKey) then
				nextState <= S2;
			end if;
			
			attemptsLeft <= INTENTOS;		
		when S2 =>
			if(keyCombination /= storedKey) then
				nextState <= S3;
			end if;
			
			attemptsLeft <= "0010";
		when S3 =>
			if(keyCombination /= storedKey) then
				nextState <= Sf;
			end if;
			
			attemptsLeft <= "0001";
		when others =>
			nextState <= Sf;
		
		end case;	
	end process;

end Behavioral;