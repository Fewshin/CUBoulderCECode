module proj3 (SW, HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, KEY, LEDR, ADC_CLK_10);
  `include "params.vh"

  input [9:0] SW;//switches
  output [7:0] HEX0, HEX1, HEX2, HEX3, HEX4, HEX5; //Displays
  input [1:0] KEY; //buttons
  output [9:0] LEDR; //LEDs
  input ADC_CLK_10; //10 Mhz clock

  wire clk1; //1 Hz clk
  wire clk2; //0.2 Hz clk
  clk_divider #(divider1) cd0 (.clk(ADC_CLK_10), .out(clk1), .rst(KEY[0]));
  clk_divider #(divider2) cd1 (.clk(ADC_CLK_10), .out(clk2), .rst(KEY[0]));

  wire [3:0] state; /*State the machine is in. 
  0000 = idle
  0001 = right turn
  0010 = idle
  0011 = left turn
  0100 = brake
  0101 = brake + right turn
  0111 = brake + left turn
  1000 and above = hazards
  7 unique states*/
  stateDecider sd0 (.clk(clk1), .state(state), .swit(SW[2:0]), .butt(KEY[1:0]));

  sevenSeg ss0 (.a(state), .x(HEX0));

  stateProcessor sp0 ();
endmodule