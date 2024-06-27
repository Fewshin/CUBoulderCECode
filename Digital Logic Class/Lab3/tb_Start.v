`timescale 1 ns /  100 ps
module tb_Start ();
reg a,b,c,d;
wire x;
integer i;
reg [15:0] result = 16'b0010_1000_0010_0000;

Start U0 (.a(a), .b(b), .c(c), .d(d), .x(x));

initial
    begin
        $display ("Starting simulation.....");
        for (i = 0; i <= 15; i = i+1)
            begin
                {a,b,c,d} = i;
                #1;
                if (x != result[i])
                    $display ("Incorrect value for %h", i);
                    #1;
            end
        $display ("Felix Pawlowski");
    end

endmodule