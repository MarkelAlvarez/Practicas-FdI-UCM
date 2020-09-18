library IEEE;
use IEEE.STD_LOGIC_1164.ALL; 
use IEEE.STD_LOGIC_unsigned.ALL;

entity Adder2b is
	port(
		A    : in std_logic_vector(1 downto 0);
		B    : in std_logic_vector(1 downto 0);
		Cin  :  in std_logic;
		Cout : out std_logic;
		S    : out std_logic_vector(1 downto 0)
	);
end Adder2b;

architecture Behavioral of Adder2b is

	COMPONENT Adder1b
		PORT(
			A : IN std_logic;
			B : IN std_logic;
			Cin : IN std_logic;          
			Cout : OUT std_logic;
			S : OUT std_logic
			);
	END COMPONENT;
	
	signal c1 : std_logic;
		
	begin
		U1: Adder1b PORT MAP(
			A => A(0),
			B => B(0),
			Cin => Cin,
			Cout => c1,
			S => S(0)
		);
		
		U2: Adder1b PORT MAP(
			A => A(1),
			B => B(1),
			Cin => c1,
			Cout => Cout,
			S => S(1)
		);
end Behavioral;