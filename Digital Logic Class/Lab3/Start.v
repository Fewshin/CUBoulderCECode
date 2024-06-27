module Start (a, b, c, d, x);

input a, b, c, d;
output x;

assign x = (b&d&!a&!c)|(a&(b^c)&d);

endmodule