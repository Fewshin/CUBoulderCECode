module Problem3 (a, b, x);
input [7:0] a;
input [7:0] b;
output x;
assign x = (a[6] | b[5] | a[0]) ^ b[0];
endmodule