module top (input [3:0] SW, output [9:0] LEDR);

assign LEDR[9:1] = 0;
week2 U0 (.a(SW[3]), .b(SW[2]), .c(SW[1]), .d(SW[0]), .f(LEDR[0]));

endmodule