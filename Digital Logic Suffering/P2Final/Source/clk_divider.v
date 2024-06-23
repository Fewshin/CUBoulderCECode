module clk_divider (clk, out, rst);
//`include "params.vh"

input clk;
input rst;
output reg out;

reg [31:0] count;
parameter divider = 0;

always @ (posedge clk, negedge rst) begin
  if (rst == 0) begin
    count <= 0;
    out <= 0;
  end else begin
    if (count != divider) begin
      count <= count + 1;
    end else begin
      count <= 0;
      out <= ~out;
    end
  end
end

endmodule