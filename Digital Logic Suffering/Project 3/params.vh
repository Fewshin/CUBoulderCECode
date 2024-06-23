`ifdef sim
  parameter timing = 20'd2;
  parameter divider1 = 32'd5;
  parameter divider2 = 32'd25;
`else 
  parameter timing = 20'd100000;
  parameter divider1 = 32'd5000000;
  parameter divider2 = 32'd25000000;
`endif