LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY debouncer IS
  PORT (
    rst: IN std_logic;
    clk: IN std_logic;
    x: IN std_logic;
    xDeb: OUT std_logic;
    xDebFallingEdge: OUT std_logic;
    xDebRisingEdge: OUT std_logic
  );
END debouncer;

ARCHITECTURE debouncerArch of debouncer is
  
  SIGNAL XSyncAnterior : std_logic;
  SIGNAL XSync : std_logic;
  
   -- espera 50 ms para un reloj a 100 MHz
  CONSTANT timeOut: unsigned (22 DOWNTO 0) := "10011000100101101000000";
  SIGNAL count: unsigned (22 DOWNTO 0);
  
  TYPE states IS (waitingPression, pressionDebouncing, waitingDepression, depressionDebouncing); 
  SIGNAL state, next_state: states;
  SIGNAL startTimer, timerEnd: std_logic; 
  
BEGIN

  synchronizer:
  PROCESS (rst, clk)
    VARIABLE aux1: std_logic;
  BEGIN
    IF (rst = '0') THEN
      XSyncAnterior <= '1';
      XSync <= '1';
    ELSIF (RISING_EDGE(clk)) THEN
      XSync <= XSyncAnterior;
      XSyncAnterior <= x;           
    END IF;
  END PROCESS synchronizer;

  timer:
  PROCESS (rst, clk)
  BEGIN
    IF (rst = '0') THEN
      count <= (OTHERS=>'0');
    ELSIF (RISING_EDGE(clk)) THEN
      IF (startTimer = '1') THEN
        count <= (OTHERS=>'0');
      ELSIF (timerEnd = '0') THEN
        count <= count + 1;
      END IF;
    END IF;
  END PROCESS timer;
    
  timerEnd <= '1' WHEN (count = timeOut) ELSE '0';	 
	 
  CU_sync:
  PROCESS (rst, clk)
  BEGIN
    IF (rst = '0') THEN
      state <= waitingPression;
    ELSIF (RISING_EDGE(clk)) THEN
		state <= next_state;
	 END IF;
  END PROCESS CU_sync;	 
	 
  CU_comb:
  PROCESS (state, xSync, timerEnd)
  BEGIN 
  
    xDeb <= '1';
    xDebFallingEdge <= '0';
    xDebRisingEdge <= '0';
    startTimer <= '0';
	 next_state <= state;

    CASE state IS

      WHEN waitingPression =>
        IF (xSync='0') THEN          
          xDebFallingEdge <= '1';
          startTimer <= '1';
			 next_state <= pressionDebouncing;
        END IF;

      WHEN pressionDebouncing =>
        xDeb <= '0';
        IF (timerEnd = '1') THEN
          next_state <= waitingDepression;
        END IF;		  

      WHEN waitingDepression =>
        xDeb <= '0';
        IF (xSync='1') THEN
          xDebRisingEdge <= '1';
          startTimer <= '1';
			 next_state <= depressionDebouncing;
        END IF;

      WHEN depressionDebouncing =>
        IF (timerEnd = '1') THEN
			 next_state <= waitingPression;
        END IF;

      END CASE;
  END PROCESS CU_comb;  
	 

END debouncerArch;
