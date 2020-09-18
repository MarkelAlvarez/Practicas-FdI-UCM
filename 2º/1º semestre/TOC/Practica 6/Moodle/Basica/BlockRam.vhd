library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;

entity BlockRam is
	port (
		clka, wea, ena : in STD_LOGIC;
		addra : in STD_LOGIC_VECTOR (8 downto 0);
		dina : in STD_LOGIC_VECTOR (31 downto 0);
		douta : out STD_LOGIC_VECTOR (31 downto 0)
	);
end BlockRam;

architecture Behavioral of BlockRam is

	type ram_type is array (0 to 511) of std_logic_vector (31 downto 0);
	signal ram : ram_type := 
									(
										x"00631816",-- 			xor R3, R3, R3 (mv R3, #0) Resultado						0x00000000	000000 00011 00011 00011 00000 010110
										x"00842016",--  		xor R4, R4, R4 (mv R4, #0) Para tener un cero				0x00000004	000000 00100 00100 00100 00000 010110
										x"8C80002C",-- 			lw R0, 44(R4)	(lw A, R0)									0x00000008	100011 00100 00000 0000000000101100
										x"8C810030",-- 			lw R1, 48(R4)  (lw B, R1)									0x0000000C	100011 00100 00001 0000000000110000
										x"8C820034",-- 			lw R2, 52(R4)  (lw UNO, R2)									0x00000010	100011 00100 00010 0000000000110100
										x"10240003",-- WHILE:	beq R1, R4, FIN												0x00000014	000100 00001 00100 0000000000000011
										x"00601820",-- 			add R3, R3, R0												0x00000018	000000 00011 00000 00011 00000 100000
										x"00220822",-- 			sub R1, R1, R2												0x0000001C	000000 00001 00010 00001 00000 100010
										x"1000FFFC",-- 			beq R0, R0, WHILE											0x00000020	000100 00000 00000 1111111111111100
										x"AC830038",-- FIN: 	sw R3, 56(R4)  (sw R3, C) 									0x00000024	101011 00100 00011 0000000000111000
										x"1000FFFF",-- FINAL:	beq R0, R0, FINAL											0x00000028	000100 00000 00000 1111111111111111
										x"00000007",-- 			VALOR A ¿Sin tabla de literales para simplificar?			0x0000002C	0x00000007
										x"00000003",-- 			VALOR B														0x00000030	0x00000003
										x"00000001",--			VALOR UNO													0x00000034	0x00000001
													--			VALOR C = A*B												0x00000038
										others => x"00000000"
									);

begin

	process( clka )
	begin
		if rising_edge(clka) then
			if ena = '1' then
				if wea = '1' then
					ram(to_integer(unsigned(addra))) <= dina;
					douta <= dina;
				else
					douta <= ram(to_integer(unsigned(addra)));
				end if;
			end if;
		end if;
	end process;
	
end Behavioral;

