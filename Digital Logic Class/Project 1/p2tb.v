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
switchesHex s1 (.a(swsin[7:0]), .w(x), .x0(y0), .x1(y1), .x2(y2), .x3(y3), .x4(y4), .x5(y5));

initial
  begin
    $dumpfile("p2.vcd");
	  $dumpvars;
    $display ("Design Unit 2:");
    //greater than
    swsin = 10'b00_1111_0000;
    //less than
    #10 swsin = 10'b00_0000_1111;
    //equal to
    #10 swsin = 10'b00_0011_0011;

    #10 $finish;
  end

initial
  begin
    $monitor($time, "swsin = %8b, b0 = %b, b1 = %b, x = %10b, y[0] = %7b, y[1] = %7b, y[2] = %7b, y[3] = %7b, y[4] = %7b, y[5] = %7b",
    swsin, b0, b1, x, y0, y1, y2, y3, y4, y5);
  end

endmodule
