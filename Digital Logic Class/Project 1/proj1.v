module proj1 (SW, HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, KEY, LEDR);

input [9:0] SW;//switches
output [7:0] HEX0, HEX1, HEX2, HEX3, HEX4, HEX5; //Displays
input [1:0] KEY; //buttons
output [9:0] LEDR; //LEDs
reg [7:0] DISP0, DISP1, DISP2, DISP3, DISP4, DISP5; //Intermediary Displays
reg [9:0] LITE0; //Intermediary LEDs
assign HEX0 = DISP0;
assign HEX1 = DISP1;
assign HEX2 = DISP2;
assign HEX3 = DISP3;
assign HEX4 = DISP4;
assign HEX5 = DISP5;
assign LEDR = LITE0;
reg [7:0] D00, D10, D20, D30, D40, D50; //Output holders for Part 1 displays
reg [7:0] D01, D11, D21, D31, D41, D51; //Output holders for Part 2 displays
reg [9:0] L0; //Output holder for Part 1 LEDs
reg [9:0] L1; //Output holders for part 2 LEDs
wire [7:0] WD0, WD1, WD2, WD3, WD4, WD5; //Output wires to assign to regs
wire [9:0] WL1; //Ouput wires to assign to regs

parameter bd0 = 24'h071201; //Felix's Birthday
//parameter bd0 = 24'b000001110001001000000001;
parameter bd1 = 24'h120997; //Thomas' Birthday

birthday b0 (.a1(bd0), .a2(bd1), .b(KEY[1]), .x0(D00), .x1(D10), .x2(D20), .x3(D30), .x4(D40), .x5(D50));
switches s0 (.a(SW[7:0]), .b(KEY[0]), .x(L0));

switchesHex s1 (.a(SW[7:0]), .w(WL1), .x0(WD0), .x1(WD1), .x2(WD2), .x3(WD3), .x4(WD4), .x5(WD5));

always @ (*) begin
  D01 = WD0;
  D11 = WD1;
  D21 = WD2;
  D31 = WD3;
  D41 = WD4;
  D51 = WD5;
  L1 = WL1;
  if (!SW[9]) begin
    DISP0 = D00;
    DISP1 = D10;
    DISP2 = D20;
    DISP3 = D30;
    DISP4 = D40;
    DISP5 = D50;
    LITE0 = L0;
  end else begin
    DISP0 = D01;
    DISP1 = D11;
    DISP2 = D21;
    DISP3 = D31;
    DISP4 = D41;
    DISP5 = D51;
    LITE0 = L1;
  end
end

endmodule
