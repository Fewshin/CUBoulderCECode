module counter (clk, out, rst);

input clk;
input rst;
output [7:0] out;

reg [7:0] count;

assign out = count;

always @ (posedge clk, negedge rst) begin
  if (rst == 0) begin
    count[3:0] <= 1;
  end else begin
    if (count[3:0] != 9) begin
      count[3:0] <= count[3:0] + 1;
    end else begin
      if (count[7:4] != 9) begin
        count[3:0] <= 0;
      end else begin
        count[3:0] <= 1;
      end
    end
  end
end

always @ (posedge clk, negedge rst) begin
  if (rst == 0) begin
    count[7:4] <= 0;
  end else begin
    if (count[3:0] == 9 && count[7:4] != 9) begin
      count[7:4] <= count[7:4] + 1;
    end else if (count[3:0] == 9 && count[7:4] == 9) begin
      count[7:4] <= 0;
    end
  end
end

endmodule