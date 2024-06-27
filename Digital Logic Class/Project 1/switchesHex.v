module switchesHex (a, w, x0, x1, x2, x3, x4, x5);

input [7:0] a;
output reg [9:0] w;
output [7:0] x0, x1, x2, x3, x4, x5;
reg [3:0] sym = 4'hA;

sevenSeg V5 (.a1(a[7:4]), .a2(4'hA), .b(1), .x(x5));
sevenSegNum V4 (.a1(4'hA), .a2(4'hA), .b(1), .x(x4));
sevenSegNum V3 (.a1(sym), .a2(4'hA), .b(1), .x(x3));
sevenSegNum V2 (.a1(4'hA), .a2(4'hA), .b(1), .x(x2));
sevenSeg V1 (.a1(a[3:0]), .a2(4'hA), .b(1), .x(x1));
sevenSegNum V0 (.a1(4'hA), .a2(4'hA), .b(1), .x(x0));

always @ (*) begin
  w[9:3] = 7'b000000;
  if (a[7:4] > a[3:0]) begin
    w[0] = 0;
    w[1] = 1;
    w[2] = 0;
    sym[3:0] = 4'hA;
  end else if (a[7:4] < a[3:0]) begin
    w[0] = 1;
    w[1] = 0;
    w[2] = 0;
    sym[3:0] = 4'hB;
  end else begin
    w[0] = 0;
    w[1] = 0;
    w[2] = 1;
    sym[3:0] = 4'hE;
  end

end

endmodule