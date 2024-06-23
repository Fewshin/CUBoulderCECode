`ifdef sim
  parameter timing = 20'd2;
  parameter divider1 = 32'd10;
  parameter divider2 = 32'd2;
`else 
  parameter timing = 20'd100000;
  parameter divider1 = 32'd2500000;
  parameter divider2 = 32'd1000000;
`endif