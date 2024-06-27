module Lab3(
	input  [1:0] KEY,
	input  [9:0] SW,
	output [9:0] LEDR,
	output [7:0] HEX0, HEX1, HEX2, HEX3, HEX4, HEX5
);

assign LEDR[0] = (SW[2]&SW[0]&!SW[3]&!SW[1])|(SW[3]&(SW[2]^SW[1])&SW[0]);

endmodule
