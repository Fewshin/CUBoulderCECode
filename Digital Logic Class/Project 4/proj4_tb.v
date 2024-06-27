`timescale 1ns/10ps
module proj4_tb ();

reg clk = 0;
reg [1:0] BUTT;
wire [3:0] vidR, vidG, vidB;
wire hs, vs;

always #1 clk=~clk;

Project4 P0 (.MAX10_CLK1_50(clk), .KEY(BUTT), .VGA_B(vidB), .VGA_G(vidG), .VGA_R(vidR), .VGA_HS(hs), .VGA_VS(vs));

initial begin
  $dumpfile("proj4_tb.vcd");
  $dumpvars;
  BUTT[0] = 0;
  #25 BUTT[0] = 1;
  #19999975 $finish;
end

endmodule