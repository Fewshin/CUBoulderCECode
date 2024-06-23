module monthProcesssor (doy, month, yearCount, domA);

input [7:0] doy;
input yearCount;
output reg [3:0] month;
output reg [7:0] domA;
reg [7:0] dom;

always @ (*) begin
  if (doy <= 8'd31) begin
    month = 4'h1;
    dom = doy;
  end else if (doy <= (8'd59 + yearCount)) begin
    month = 4'h2;
    dom = (doy - 31);
  end else if (doy <= (8'd90 + yearCount)) begin
    month = 4'h3;
    dom = (doy - (8'd59 + yearCount));
  end else begin
    month = 4'h4;
    dom = (doy - (8'd90 + yearCount));
  end
end

always @ (*) begin
  if (dom <= 8'd9) begin
    domA[7:4] = 8'hA;
    domA[3:0] = dom[3:0];
  end else if (dom <= 8'd19) begin
    domA[7:4] = 1;
    domA[3:0] = dom - 10;
  end else if (dom <= 8'd29) begin
    domA[7:4] = 2;
    domA[3:0] = dom - 20;    
  end else begin
    domA[7:4] = 3;
    domA[3:0] = dom - 30;
  end
end

endmodule