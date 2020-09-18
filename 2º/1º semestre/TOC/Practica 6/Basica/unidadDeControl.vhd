library ieee;
use ieee.std_logic_1164.all;
use ieee.STD_LOGIC_UNSIGNED.ALL;
use ieee.numeric_std.all;

entity unidadDeControl is
	port( 
		clk		  : in  std_logic;
		rst		  : in  std_logic;
		control	  : out std_logic_vector(18 downto 0);
		Zero	  : in  std_logic;
		op		  : in  std_logic_vector(5 downto 0);
		debug	  : in  std_logic;
		sig       : in  std_logic;
		inmediato : in  std_logic_vector(15 downto 0)		
	);
end unidadDeControl;

architecture unidadDeControlArch of unidadDeControl is

    signal control_aux    : std_logic_vector(18 downto 0);
    alias PCWrite         : std_logic is control_aux(0);
    alias IorD            : std_logic is control_aux(1);
    alias MemWrite        : std_logic is control_aux(2);
    alias MemRead         : std_logic is control_aux(3);
    alias IRWrite         : std_logic is control_aux(4);
    alias RegDst          : std_logic is control_aux(5);
    alias MemtoReg        : std_logic_vector(1 downto 0) is control_aux(7 downto 6);
    alias RegWrite        : std_logic is control_aux(8);
    alias AWrite          : std_logic is control_aux(9);
    alias BWrite          : std_logic is control_aux(10);  
    alias ALUScrA         : std_logic_vector(1 downto 0) is control_aux(12 downto 11);
    alias ALUScrB         : std_logic_vector(2 downto 0) is control_aux(15 downto 13);
    alias OutWrite        : std_logic is control_aux(16);
    alias ALUop           : std_logic_vector(1 downto 0) is control_aux(18 downto 17);
  
    type states is (S0, S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, S11, S12, S13, S14, S15, S16, S17);
    signal currentState, nextState: states;

    begin

      control <= control_aux;
    
      stateGen:
      process (currentState, op , zero, debug, sig)
      begin
    
        nextState <= currentState;
        control_aux <= (OTHERS=>'0');
              
        case currentState is
            
            when S0 =>
                if (debug = '0' or (debug = '1' and sig = '1')) then
                    PCWrite <= '1';
                    MemRead <= '1';
                    ALUScrB <= "001";
                    nextState <= S1;
                end if;				  
            when S1 =>
                IRWrite <= '1';
                nextState <= S2;             
            when S2 =>
                AWrite <= '1';
                BWrite <= '1';
                if (op = "000000") then    -- tipo-R
                    nextState <= S8;
                elsif (op = "100011") then -- lw
                    nextState <= S3;
                elsif (op = "101011") then -- sw
                    nextState <= S6;
                elsif (op = "000100") then -- beq
                    nextState <= S10;
                elsif (op = "010000") then -- mv rt, inmediato
                    nextState <= S12;
                elsif (op = "010010") then -- mv rt, rs
                    nextState <= S14;
                elsif (op = "010001") then -- lsw rt, inmediato
                    nextState <= S15;
                end if;
            when S3 =>
                ALUScrA <= "01";
                ALUScrB <= "010";
                OutWrite <= '1';
                nextState <= S4;
            when S4 =>
                MemRead <= '1';
                IorD <= '1';
                nextState <= S5; 
            when S5 =>
                MemtoReg <= "01";
                RegWrite <= '1';
                nextState <= S0;        
            when S6 =>
                ALUScrA <= "01";
                ALUScrB <= "010";
                OutWrite <= '1';
                nextState <= S7;      
            when S7 =>
                MemWrite <= '1';
                IorD <= '1';
                nextState <= S0;            
            when S8 =>
                ALUScrA <= "01";
                ALUOp <= "10";
                OutWrite <= '1';
                nextState <= S9;
            when S9 =>
                RegDst <= '1';
                RegWrite <= '1';
                nextState <= S0;               
            when S10 =>
                ALUScrA <= "01";
                ALUOp <= "01";
                if (Zero = '0') then
                    nextState <= S0;
                else
                    nextState <= S11;
                end if; 
            when S11 =>
                PCWrite <= '1';
                ALUScrB <= "011";
                nextState <= S0;  
            when S12 =>
                ALUScrA <= "10";
                ALUScrB <= "010";
                OutWrite <= '1';
                nextState <= S13;       
            when S13 =>
                RegWrite <= '1';
                nextState <= S0; 
            when S14 =>
                ALUScrA <= "01";
                ALUScrB <= "100";
                OutWrite <= '1';
                nextState <= S13;                    
            when S15 =>
                if (unsigned(inmediato) = "0000000000000000") then
                    nextState <= S16;
                else
                    nextState <= S17;
                end if;
            when S16 =>
                MemtoReg <= "10";
                RegWrite <= '1';
                nextState <= S0;    
            when S17 =>
                MemtoReg <= "11";
                RegWrite <= '1';
                nextState <= S0; 
        end case;
      end process stateGen;
    
  state:
  process (rst, clk)
  begin
    if (rst = '1') then
		currentState <= S0;
    elsif RISING_EDGE(clk) then
		currentState <= nextState;
    end if;
  end process state;
  
end unidadDeControlArch;