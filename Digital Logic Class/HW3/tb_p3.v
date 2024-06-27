`timescale 1 ns /  100 ps
module tb_p3 ();

reg [7:0] m = 8'b1010_0101;
reg [7:0] n = 8'b0101_0101;
wire p;

Problem3 U0 (.a(m), .b(n), .x(p));

initial 
  begin
    #1
    $monitor("x = %b\n", p);
  end

endmodule