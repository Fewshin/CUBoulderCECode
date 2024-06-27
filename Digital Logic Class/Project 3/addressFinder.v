module addressFinder (clk, address, rst);

  input clk;
  output reg [2:0] address;
  input rst;

  always @ (posedge clk, negedge rst) begin
    if (rst == 0) begin
      address <= 3'b000;
    end else begin
      if (address < 3'd7) begin
        address <= address + 1;
      end else begin
        address <= 3'b000;
      end
    end
  end

endmodule