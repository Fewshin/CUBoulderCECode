`timescale 10ns/100ps
module tb_proj2 ();

reg clk = 0;
wire [7:0] DISP0, DISP1, DISP2, DISP3, DISP4, DISP5;
wire [9:0] LEDS;
reg [9:0] SWIT;
reg [1:0] BUTT;

proj2 B0 (.SW(SWIT), .HEX0(DISP0), .HEX1(DISP1), .HEX2(DISP2), .HEX3(DISP3), .HEX4(DISP4), .HEX5(DISP5), .KEY(BUTT), .LEDR(LEDS), .ADC_CLK_10(clk));

initial begin
  $dumpfile("tb_proj2.vcd");
  $dumpvars;
  $dumplimit(1000000);
  //clk = 0;
  SWIT[9] = 0;
  BUTT[0] = 0;
  BUTT[1] = 1;
  #10 BUTT[0] = 1;
  #100 BUTT[1] = 0;
  #1000 SWIT[9] = 1;
  #500 BUTT[0] = 0;
  #510 BUTT[0] = 1;
  #10000 $finish;
end


always #1 clk=~clk;

endmodule