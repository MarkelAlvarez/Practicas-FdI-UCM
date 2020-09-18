library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity ffd is
	port(	
		clk: in bit;
		d: in bit;
		nclear: in bit;
		q: out bit;
		qn: out bit );
end ffd;

architecture comportamiento OF ffd is

	begin

		process(clk)
		begin
			if (nclear='0') then
				q <= '0';
				qn<='1';
			elsif (rising_edge (clk)) then
				q <= d;
				qn <= not d;
			end if;
		end process;

end comportamiento;

--AND--
entity and3 is
	port(
		e1, e2, e3 : IN bit;
		s : OUT bit);
end and3;

architecture comportamiento OF and3 is

	begin
		s <= e1 AND e2 AND e3;

end comportamiento;

entity and2 is
 	port(
 		e1, e2 : IN bit;
  		s : OUT bit);
end and2;

architecture comportamiento OF and2 is

	begin
	  s <= e1 AND e2;

end comportamiento;

--OR--
entity or2 is
	port(
		e1, e2 : IN bit;
		s : OUT bit);
end or2;

architecture comportamiento OF or2 is
	begin
	  s <= e1 OR e2;
end comportamiento;

--INVERSOR--
entity inv is
	port(
		e : IN bit;
		s : OUT bit);
end inv;

architecture comportamiento OF inv is
	
	begin
	  s <= NOT e;

end comportamiento;

--reconocedor del patron 010------
entity reconocedor is
	port(
		clk, nclear, x : IN bit;
		z : OUT bit);
end reconocedor;

architecture estructural OF reconocedor is
	--declaración de componentes
	component inv is
		port(
			e : IN bit;
			s : OUT bit);
	end component inv;

	component or2 is
		port(
			e1, e2 : IN bit;
			s : OUT bit);
	end component or2;

	component and2 is
		port(
	 		e1, e2 : IN bit;
	  		s : OUT bit);
	end component and2;

	component and3 is
		port(
			e1, e2, e3 : IN bit;
			s : OUT bit);
	end component and3;

	component ffd is
		port(	
			clk: in bit;
			d: in bit;
			nclear: in bit;
			q: out bit;
			qn: out bit );
	end component ffd;

	--declaración de señales
	signal sal_and2_1: bit;
	signal sal_and3_1: bit;
	signal sal_or2_1: bit;
	signal sal_inv: bit;
	signal sal_ffd1_1: bit;
	signal sal_ffd1_2: bit;
	signal sal_ffd2_1: bit;
	signal sal_ffd2_2: bit;

	begin
	--descripción estructural de la arquitectura 
	--utilizando las componentes, inv,or2,and2,and3 y ffd
	i_inv : inv PORT MAP (x, sal_inv);
	i_and1 : and2 PORT MAP (sal_ffd1_1, x, sal_and2_1);
	i_and3 : and3 PORT MAP (sal_ffd1_2, sal_inv, sal_ffd2_1, sal_and3_1);
	i_or1 : or2 PORT MAP (sal_and2_1, sal_and3_1, sal_or2_1);
	i_ffd1 : ffd PORT MAP (clk, sal_inv, nclear, sal_ffd1_1, sal_ffd1_2);
	i_fdd2 : ffd PORT MAP (clk, sal_or2_1, nclear, sal_ffd2_1, sal_ffd2_2);
	i_and2 : and2 PORT MAP (sal_ffd1_1, sal_ffd2_1, z);


end estructural;