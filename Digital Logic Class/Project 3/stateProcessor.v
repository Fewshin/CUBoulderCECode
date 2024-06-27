module stateProcessor (state, leds, clk, rst);
  input [3:0] state;
  output reg [9:0] leds;
  input clk;
  input rst;

  reg [1:0] count;
  reg swit;

  always @ (posedge clk, negedge rst) begin
    if (rst == 0) begin
      count <= 0;
      swit <= 0;
      //leds <= 10'b0000000000;
    end else begin
      swit <= ~swit;
      if (count < 2'b10) begin
        count <= count + 1;
      end else begin
        count <= 2'b00;
      end
    end
  end

  always @ (*) begin
    if (state >= 4'b1000) begin //hazards
      if (swit) begin
        leds = 10'b1110000111;
      end else begin
        leds = 10'b0000000000;
      end
    end else if (state == 4'b0100 || state == 4'b0110) begin //brakes
      leds = 10'b1110000111;
    end else if (state == 4'b0000 || state == 4'b0010) begin //idle
      leds = 10'b0000000000;
    end else if (state[0] == 1) begin //turn signal handling
      if (state[1] == 0) begin //right turn
        case (count) 
          2'b00 : leds[2:0] = 3'b100; 
          2'b01 : leds[2:0] = 3'b010;
          2'b10 : leds[2:0] = 3'b001;
          default : leds[2:0] = 3'b111;
        endcase
        if (state[2] == 1) begin //brakes
          leds[9:3] = 7'b1110000;
        end else begin
          leds[9:3] = 7'b0000000;
        end
      end else if (state[1] == 1) begin //left turn
        case (count) 
          2'b00 : leds[9:7] = 3'b001; 
          2'b01 : leds[9:7] = 3'b010;
          2'b10 : leds[9:7] = 3'b100;
          default : leds[9:7] = 3'b111;
        endcase
        if (state[2] == 1) begin //brakes
          leds[6:0] = 7'b0000111;
        end else begin
          leds[6:0] = 7'b0000000;
        end
      end
    end else begin
      leds = 10'b1111111111;
    end
  end
endmodule