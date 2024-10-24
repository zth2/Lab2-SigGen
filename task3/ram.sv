module ram #(
    parameter   ADDRESS_WIDTH = 8,
                DATA_WIDTH = 8
)(
    input logic                     clk,
    input logic                     wr_en,
    input logic                     rd_en,
    input logic [ADDRESS_WIDTH-1:0] wr_addr,
    input logic [ADDRESS_WIDTH-1:0] rd_addr,
    input logic [DATA_WIDTH-1:0]    mic_signal,
    output logic [DATA_WIDTH-1:0]   delayed_signal
);

logic [DATA_WIDTH-1:0] ram_array [2**ADDRESS_WIDTH-1:0];

always_ff @(posedge clk) begin
    if (wr_en == 1'b1)
        ram_array[wr_addr] <= mic_signal;
    if (rd_en == 1'b1)
        delayed_signal <= ram_array [rd_addr];
end
endmodule
