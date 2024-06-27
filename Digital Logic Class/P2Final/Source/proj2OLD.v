module proj2 (SW, HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, KEY, LEDR, ADC_CLK_10);
`include "params.vh"

input [9:0] SW;//switches
output [7:0] HEX0, HEX1, HEX2, HEX3, HEX4, HEX5; //Displays
input [1:0] KEY; //buttons
output [9:0] LEDR; //LEDs
input ADC_CLK_10; //10 Mhz clock

reg [23 : 0] smolCount = 0; //Counting posedge clocks
reg [7: 0] bigCountDisp = 0; //Counting seconds for display
reg [7: 0] bigCount = 0; //Counting seconds for date

reg ledStatus; //LED on or Off
assign LEDR[0] = ledStatus;

sevenSeg U4 (.a1(bigCountDisp[3:0]), .a2(4'h0), .b(1'b1), .x(HEX4));
sevenSeg U5 (.a1(bigCountDisp[7:4]), .a2(4'h0), .b(1'b1), .x(HEX5));

always @ (posedge ADC_CLK_10) begin
  if (smolCount == timing/2) begin
    ledStatus <= 0;
  end
  if (KEY[0] == 0 || bigCount == 8'd100) begin
    bigCountDisp <= 0;
    bigCount <= 0;
  end
  if (smolCount == timing) begin //24'd1000000 timing for 1 second at 10 mhz
    ledStatus <= 1;
    bigCount <= bigCount + 1;
    smolCount <= 0;
    if (bigCountDisp[3:0] == 4'h9) begin
      bigCountDisp <= bigCountDisp + 4'h7;
    end else begin
      bigCountDisp <= bigCountDisp + 1;
    end
  end

  smolCount <= smolCount + 1;

end

endmodule