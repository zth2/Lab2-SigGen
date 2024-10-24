module sigdelay #(

    parameter   ADDRESS_WIDTH = 8, 
                DATA_WIDTH = 8 //8-bit data
)(
    
    input logic                     clk,
    input logic                     rst,
    input logic                     wr_en,
    input logic                     rd_en,
    input logic [ADDRESS_WIDTH-1:0] delay_offset,
    input logic [DATA_WIDTH-1:0]   mic_signal,
    output logic [DATA_WIDTH-1:0]   delayed_signal
);

    logic [ADDRESS_WIDTH-1:0] wr_addr;
    logic [ADDRESS_WIDTH-1:0] rd_addr;

ram ram(

    .clk (clk),
    .wr_addr (wr_addr[7:0]),
    .rd_addr (rd_addr[7:0]),
    .wr_en (wr_en),
    .rd_en (rd_en),
    .mic_signal (mic_signal),
    .delayed_signal (delayed_signal)
);

always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
         wr_addr <= 0;
    end else if (wr_en) begin
        wr_addr <= wr_addr + 1;  // Increment write address
    end
end

    // Read address counter with delay offset
always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
        rd_addr <= 0;
    end else begin
        rd_addr <= wr_addr - delay_offset;  // Apply delay
    end
end

endmodule
