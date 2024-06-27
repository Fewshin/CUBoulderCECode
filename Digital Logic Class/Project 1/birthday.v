module birthday (a1, a2, b, x0, x1, x2, x3, x4, x5);

input [23:0] a1, a2;
input b;
output [7:0] x0, x1, x2, x3, x4, x5;

sevenSeg U0 (.a1(a1[23:20]), .a2(a2[23:20]), .b(b), .x(x5));
sevenSeg U1 (.a1(a1[19:16]), .a2(a2[19:16]), .b(b), .x(x4));
sevenSeg U2 (.a1(a1[15:12]), .a2(a2[15:12]), .b(b), .x(x3));
sevenSeg U3 (.a1(a1[11:8]), .a2(a2[11:8]), .b(b), .x(x2));
sevenSeg U4 (.a1(a1[7:4]), .a2(a2[7:4]), .b(b), .x(x1));
sevenSeg U5 (.a1(a1[3:0]), .a2(a2[3:0]), .b(b), .x(x0));

endmodule