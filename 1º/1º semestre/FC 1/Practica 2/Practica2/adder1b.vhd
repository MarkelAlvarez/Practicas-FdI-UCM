entity Adder1b is
	port(A: in std_logic;
		 B: in std_logic;
		 Cin: in std_logic;
		 Cout: out std_logic;
		 S: out std_logic
		);
end Adder1b;

architecture Behavioral of Adder1b is
	begin
		Cout <= (B and Cin) or (A and Cin) or (A and B);
		S <= A xor (B xor Cin);
end Behavioral;