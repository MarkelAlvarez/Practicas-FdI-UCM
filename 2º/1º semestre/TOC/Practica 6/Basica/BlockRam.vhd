library ieee;
use ieee.STD_LOGIC_1164.ALL;
use ieee.numeric_std.all;

entity BlockRam is
	port(
		clka, wea, ena : in STD_LOGIC;
		addra : in STD_LOGIC_VECTOR (8 downto 0);
		dina : in STD_LOGIC_VECTOR (31 downto 0);
		douta : out STD_LOGIC_VECTOR (31 downto 0)
	);
end BlockRam;

architecture Behavioral of BlockRam is

	type ram_type is array (0 to 511) of std_logic_vector (31 downto 0);
	signal ram : ram_type := (
								x"8C830030",-- 			lw R3, 48(R4)  (lw B, R3)					      		    0x0000000C	100011 00100 00011 0000000000110000
                                x"44030000",--          lsw R3, #inmed                                              0x00000014  010001 00000 00011 0000000000000000
                                x"44030003",--          lsw R3, #inmed                                              0x00000018  010001 00000 00011 0000000000000011
                                x"8C830034",-- 			lw R3, 52(R4)  (lw UNO, R3)		       					    0x00000010	100011 00100 00011 0000000000110100
                                x"00631816",-- 			xor R3, R3, R3 (mv R3, #0) Resultado						0x00000000	000000 00011 00011 00011 00000 010110
                                x"00842016",--  		xor R4, R4, R4 (mv R4, #0) Para tener un cero				0x00000004	000000 00100 00100 00100 00000 010110
                                x"48830000",--          mv R3, R4                                                   0x00000024  010010 00100 00011 0000000000000000						
                                x"8C840034",-- 			lw R4, 52(R4)  (lw UNO, R4)	    						    0x00000020	100011 00100 00100 0000000000110100
                                x"40030005",--          mv R3, #inmed                                               0x0000001C  010000 00000 00011 0000000000000101
                                x"8C83002C",-- 			lw R3, 44(R4)	(lw A, R3)						      		0x00000008	100011 00100 00011 0000000000101100
								x"1000FFFF",-- FINAL:	beq R0, R0, FINAL											0x00000028	000100 00000 00000 1111111111111111
								x"00000007",-- 			VALOR A ¿Sin tabla de literales para simplificar?			0x0000002C	0x00000007
								x"00000003",-- 			VALOR B														0x00000030	0x00000003
								x"00000001",--			VALOR UNO													0x00000034	0x00000001
											--			VALOR C = A*B												0x00000038
								others => x"00000000"
									);
    begin

        process(clka)
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