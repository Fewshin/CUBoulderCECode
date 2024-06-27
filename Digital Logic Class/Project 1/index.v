module index (aS, aD0, aD1, aD2, aD3, aD4, aD5, b0, b1, l);

input [9:0] aS;//switches
output [7:0] aD0; //Seven Segment Displays
output [7:0] aD1;
output [7:0] aD2;
output [7:0] aD3;
output [7:0] aD4;
output [7:0] aD5;
input b0, b1; //buttons
output [9:0] l; //LEDs

parameter bd0 = 24'd071201; //Felix's Birthday
parameter bd1 = 24'd120997; //Thomas' Birthday

birthday bd (.a1(bd0), .a2(bd1), .b(b1), .x0(aD0), .x1(aD1), .x2(aD2), .x3(aD3), .x4(aD4), .x5(aD5));
switches s0 (.a(aS), .b(b0), .x(l));
endmodule
