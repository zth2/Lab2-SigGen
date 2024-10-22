module sinegen #(

    parameter   ADDRESS_WIDTH = 8,
                DATA_WIDTH = 8
)(
    
    input logic clk,
    input logic rst,
    input logic en,
    input logic [DATA_WIDTH-1:0] incr,
    output logic [DATA_WIDTH-1:0] dout
);

    logic [ADDRESS_WIDTH-1:0] addr;

counter counter(

    .clk (clk),
    .rst (rst),
    .en (en),
    .incr (incr),
    .addr (addr)
);

rom rom(

    .clk (clk),
    .addr (addr),
    .dout (dout)
);

endmodule
