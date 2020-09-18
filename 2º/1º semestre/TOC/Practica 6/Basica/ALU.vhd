library IEEE;
use IEEE.std_logic_1164.all;
use ieee.numeric_std.all; 

entity ALU is
	port( 		
		A			: in  std_logic_vector(31 downto 0);
		B			: in  std_logic_vector(31 downto 0);
		ALUop		: in  std_logic_vector(1 downto 0);
		funct		: in  std_logic_vector(5 downto 0);
		Zero		: out std_logic;
		R			: out std_logic_vector(31 downto 0)
	);
end ALU;

architecture ALUArch of ALU is
   
	signal A_signed : signed(31 downto 0);
	signal B_signed : signed(31 downto 0);
	signal R_signed : signed(31 downto 0);
	
begin

	R <= std_logic_vector(R_signed);	
	Zero <= '1' when (R_signed = x"00000000") else '0';
	
	A_signed <= signed(A);
	B_signed <= signed(B);
	
	R_signed <= A_signed + B_signed when (ALUop = "00") else
					A_signed - B_signed when (ALUop = "01") else
					A_signed + B_signed when (funct = "100000") else  -- ADD
					A_signed - B_signed when (funct = "100010") else  -- SUB
					A_signed and B_signed when (funct = "100100") else  -- AND
					A_signed or B_signed when (funct = "100101") else -- OR
					A_signed nor B_signed when (funct = "010111") else -- NOR
					A_signed xor B_signed when (funct = "010110") else -- XOR
					(others=>'-');
	
end ALUArch;