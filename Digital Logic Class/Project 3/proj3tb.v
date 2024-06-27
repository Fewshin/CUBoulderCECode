`timescale 10ns/100ps
module proj3tb ();

reg clk = 0;
wire [7:0] DISP0, DISP1, DISP2, DISP3, DISP4, DISP5;
wire [9:0] LEDS;
reg [9:0] SWIT;
reg [1:0] BUTT;

proj3 B0 (.SW(SWIT), .HEX0(DISP0), .HEX1(DISP1), .HEX2(DISP2), .HEX3(DISP3), .HEX4(DISP4), .HEX5(DISP5), .KEY(BUTT), .LEDR(LEDS), .ADC_CLK_10(clk));

initial begin
  $dumpfile("proj3tb.vcd");
  $dumpvars;
  SWIT[9] = 0;
  BUTT[0] = 0;
  BUTT[1] = 1;
  #10 BUTT[0] = 1;
  #10 SWIT[2:0] = 3'b001; //hazards
  #2000 SWIT[2:0] = 3'b010; //Left Turn
  #2000 BUTT[1] = 0; //Right Turn
  #2000 SWIT[2:0] = 3'b110; //Right Turn + Brakes
  #2000 BUTT[1] = 1; //Left Turn + Brakes
  #2000 SWIT[2:0] = 3'b100; //Brakes
  #2000 SWIT[2:0] = 3'b000; //Idle
  #2000 $finish;
end


always #1 clk=~clk;

endmodule