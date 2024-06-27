module stateDecider (clk, state, swit, butt);
  input clk;
  output reg [3:0] state;
  input [2:0] swit;
  input [1:0] butt;
  always @ (posedge clk, negedge butt[0]) begin
    if (butt[0] == 0) begin
      state <= 4'b0000;
    end else begin
      if (swit[0] == 1) begin
        state <= 4'b1000;
      end else begin
        state[0] <= swit[1];
        state[1] <= butt[1];
        state[2] <= swit[2];
        state[3] <= swit[0];
      end
    end
  end
endmodule