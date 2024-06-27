module switches (a, b, x);

input [7:0] a;
input b;
output reg [9:0] x;

always @ (*)
begin 
  x[8] = 0;
  x[9] = 0;
  if (b) begin 
     x[0] = a[0];
     x[1] = a[1];
     x[2] = a[2];
     x[3] = a[3];
     x[4] = a[4];
     x[5] = a[5];
     x[6] = a[6];
     x[7] = a[7];
  end else begin 
     x[0] = !a[0];
     x[1] = !a[1];
     x[2] = !a[2];
     x[3] = !a[3];
     x[4] = !a[4];
     x[5] = !a[5];
     x[6] = !a[6];
     x[7] = !a[7];
  end
end

endmodule