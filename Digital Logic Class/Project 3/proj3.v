module proj3 (SW, HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, KEY, LEDR, ADC_CLK_10);
  `include "params.vh"

  input [9:0] SW;//switches
  output [7:0] HEX0, HEX1, HEX2, HEX3, HEX4, HEX5; //Displays
  input [1:0] KEY; //buttons
  output [9:0] LEDR; //LEDs
  input ADC_CLK_10; //10 Mhz clock

  wire clk1; //?? Hz clk fast but slow
  wire clk2; //?? Hz clk slow
  wire clk3; //?? Hz clk its fast I guess
  clk_divider #(divider1) cd0 (.clk(ADC_CLK_10), .out(clk1), .rst(KEY[0]));
  clk_divider #(divider2) cd1 (.clk(ADC_CLK_10), .out(clk2), .rst(KEY[0]));
  clk_divider #(divider3) cd2 (.clk(ADC_CLK_10), .out(clk3), .rst(KEY[0]));

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
  reg [3:0] stateHolder;
  assign state = stateHolder;

  wire [3:0] memState; 
  wire [2:0] memAddress;

  wire [3:0] baseState;

  stateDecider sd0 (.clk(clk1), .state(baseState), .swit(SW[2:0]), .butt(KEY[1:0]));

  sevenSeg ss0 (.a(state), .x(HEX0));

  stateProcessor sp0 (.state(state), .leds(LEDR), .clk(clk3), .rst(KEY[0]));

  proj3Mem m0 (.address(memAddress), .clock(ADC_CLK_10), .q(memState));

  addressFinder af0 (.clk(clk2), .address(memAddress), .rst(KEY[0]));

  always @ (*) begin
    if (SW[9] == 1) begin
      stateHolder = memState;
    end else begin
      stateHolder = baseState;
    end
  end

endmodule