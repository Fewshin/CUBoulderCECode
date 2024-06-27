`timescale 1 ns / 100 ps

module p1tb();


reg [9:0] swsin;
reg b0, b1;
reg [23:0] bd1, bd2;

wire [9:0] x;
wire [7:0] y0; //Seven Segment Displays
wire [7:0] y1;
wire [7:0] y2;
wire [7:0] y3;
wire [7:0] y4;
wire [7:0] y5;



//switches sws (.a(swsin), .b(b0), .x(x));
//birthday bday (.a1(bd1), .a2(bd2), .b(b1), .x(y))
index p1 (.aS(swsin), .aD0(y0), .aD1(y1), .aD2(y2), .aD3(y3), .aD4(y4), .aD5(y5), .b0(b0), .b1(b1), .l(x));

initial
  begin
    $dumpfile("p1.vcd");
	  $dumpvars;
    $display ("Design Unit 1:");
    b0 = 0;
    b1 = 0;
    swsin = 10'b00_0000_0000;
    #10 b0 = 1;
    #10 b0 = 0;
    #10 swsin = 10'b11_1111_1111;
    #10 b0 = 1;
    #10 b1 = 1;
    #10 $finish;
  end

initial
  begin
    $monitor($time, "swsin = %8b, b0 = %b, b1 = %b, x = %10b, y0 = %7b, y1 = %7b, y2 = %7b, y3 = %7b, y4 = %7b, y5 = %7b",
    swsin, b0, b1, x, y0, y1, y2, y3, y4, y5);
  end

endmodule
