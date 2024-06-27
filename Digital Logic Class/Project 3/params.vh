`ifdef sim
  parameter timing = 20'd2;
  parameter divider1 = 32'd250;
  parameter divider2 = 32'd2500;
  parameter divider3 = 32'd125;
`else 
  parameter timing = 20'd100000;
  parameter divider1 = 32'd2500000;
  parameter divider2 = 32'd25000000;
  parameter divider3 = 32'd1250000;
`endif