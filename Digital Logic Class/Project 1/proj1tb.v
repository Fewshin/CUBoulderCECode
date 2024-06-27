`timescale 1 ns / 100 ps

module proj1tb();

reg [9:0] swsin;
reg [1:0] b;


wire [9:0] x;
wire [7:0] y0; //Seven Segment Displays
wire [7:0] y1;
wire [7:0] y2;
wire [7:0] y3;
wire [7:0] y4;
wire [7:0] y5;

proj1 p1(.SW(swsin[9:0]), .HEX0(y0[7:0]), .HEX1(y1[7:0]), .HEX2(y2[7:0]), .HEX3(y3[7:0]), .HEX4(y4[7:0]), .HEX5(y5[7:0]), .KEY(b[1:0]), .LEDR(x[9:0]));
initial
  begin
    $dumpfile("proj1dump.vcd");
	  $dumpvars;

    //Design Unit 1
    $display ("Design Unit 1:");
    swsin = 10'b00_0000_0000;
    b[0] = 0;
    b[1] = 0;
    swsin = 10'b00_0000_0000;
    #10 b[0] = 1;
    #10 b[0] = 0;
    #10 swsin = 10'b01_1111_1111;
    #10 b[0] = 1;
    #10 b[1] = 1;

    #10$display ("Flipping Switch[9]...");
    #10 swsin = 10'b11_1111_1111;

    //Design Unit 2
    #10$display ("Design Unit 2:");
    //greater than
    #10 swsin = 10'b10_1111_0000;
    //less than
    #10 swsin = 10'b10_0000_1111;
    //equal to
    #10 swsin = 10'b10_0011_0011;

    #10 $finish;
  end


initial
  begin
    $monitor($time, "swsin = %10b, b = %2b, x = %10b, y0 = %7b, y1 = %7b, y2 = %7b, y3 = %7b, y4 = %7b, y5 = %7b",
    swsin, b, x, y0, y1, y2, y3, y4, y5);
  end

endmodule
