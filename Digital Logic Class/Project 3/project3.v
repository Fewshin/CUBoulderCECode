module project 3 (SW, HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, KEY, LEDR, ADC_CLK_10);
`include "params.vh"

input [9:0] SW;//switches
output [7:0] HEX0, HEX1, HEX2, HEX3, HEX4, HEX5; //Displays
input [1:0] KEY; //buttons
output [9:0] LEDR; //LEDs
input ADC_CLK_10; //10 Mhz clock

wire clk; //3 hz clock

clk_divider #(divider) cd0 (.clk(ADC_CLK_10), .out(clk), .rst(KEY[0]));

endmodule