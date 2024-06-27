`timescale 1 ns / 100 ps
module tb();
reg a, b;
wire c;
my_and U1 (.in1(a), .in2(b), .out1(c));
initial
 begin
 $dumpfile("output.vcd");
 $dumpvars;
 $display("Starting simulation");
 a = 0;
 b = 0;
 #10 a = 1;
 #10 b = 1;
 #10 a = 0;
 #10 $display("Simulation ended.");
 $display("Felix Pawlowski");
 $finish;
end
initial
 $monitor($time, " a = %b, b = %b, c = %b", a, b, c);
endmodule