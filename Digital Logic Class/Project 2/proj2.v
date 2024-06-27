module proj2 (SW, HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, KEY, LEDR, ADC_CLK_10);
`include "params.vh"

input [9:0] SW;//switches
output [7:0] HEX0, HEX1, HEX2, HEX3, HEX4, HEX5; //Displays
input [1:0] KEY; //buttons
output [9:0] LEDR; //LEDs
input ADC_CLK_10; //10 Mhz clock

wire clk1; //2 Hz clk
wire clk2; //5 Hz clk
wire clk; //Clock being used
wire [7:0] doy; //Value of counter for display
wire [7:0] doyA; //Actual value of counter
wire [3:0] month; //Month display
wire [7:0] domA; //Day of month for display
wire [3:0] doyTens; //Day of the year for display in the tens place

assign LEDR[0] = clk;
assign clk = KEY[1] ? clk1 : clk2;
assign doyA = doy[7:4] * 10 + {4'b0, doy[3:0]};
assign doyTens = doy[7:4] ? doy[7:4] : 4'hA;

sevenSeg U0 (.a1(domA[3:0]), .a2(4'h0), .b(1'b1), .x(HEX0));
sevenSeg U1 (.a1(domA[7:4]), .a2(4'h0), .b(1'b1), .x(HEX1));
sevenSeg U2 (.a1(month), .a2(4'h0), .b(1'b1), .x(HEX2));
sevenSeg U3 (.a1(4'hA), .a2(4'h0), .b(1'b1), .x(HEX3));
sevenSeg U4 (.a1(doy[3:0]), .a2(4'h0), .b(1'b1), .x(HEX4));
sevenSeg U5 (.a1(doyTens), .a2(4'h0), .b(1'b1), .x(HEX5));

clk_divider #(divider1) cd0 (.clk(ADC_CLK_10), .out(clk1), .rst(KEY[0]));
clk_divider #(divider2) cd1 (.clk(ADC_CLK_10), .out(clk2), .rst(KEY[0]));

counter c0 (.clk(clk), .out(doy), .rst(KEY[0]));

monthProcesssor m0 (.doy(doyA), .month(month), .yearCount(SW[9]), .domA(domA));

// always @ (*) begin



// end

endmodule