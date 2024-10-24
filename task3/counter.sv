module counter #(
    parameter WIDTH = 8
)(
    input logic clk,
    input logic rst,
    input logic en,
    input logic [WIDTH-1:0] incr,
    output logic [WIDTH-1:0] addr
);

always_ff @ (posedge clk)
    if(rst) addr <= {WIDTH{1'b0}};
    else addr <= addr + {{WIDTH-1{1'b0}}, en};

endmodule
