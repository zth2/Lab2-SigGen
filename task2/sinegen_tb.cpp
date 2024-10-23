#include "Vsinegen.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env){

    int i;
    int clk;

    Verilated::commandArgs(argc, argv);
    Vsinegen* top = new Vsinegen;
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);  // Trace 99 levels of hierarchy
    tfp->open("sinegen.vcd");  // Open VCD file for waveform output

    // Initialize Vbuddy
    if (vbdOpen() != 1) return -1;
    vbdHeader("SigGen");

    // Initialize inputs
    top->clk = 1;
    top->rst = 0;  // Assert reset
    top->en = 1;   // Enable signal
    top->incr = 1;  //Initial increment

    // Main simulation loop
    for (i = 2; i < 1000000; i++) {
        for (clk = 0; clk < 2; clk++) {
            tfp->dump (2*i+clk);
            top->clk = !top->clk;
            top->eval ();
        }
        // Adjust the increment value dynamically from Vbuddy
        top->incr = vbdValue();
        top->phase_offset = vbdValue();
        // Plot the sine wave output to Vbuddy
        vbdPlot(int(top->dout1), 0, 255);
        vbdPlot(int(top->dout2), 0, 255);
        
        vbdCycle(i);  // Advance the Vbuddy simulation cycle

        // Finish simulation if 'q' is pressed or Verilator signals finish
        if (Verilated::gotFinish() || vbdGetkey() == 'q') {
            exit(0);  // Exit the loop
        }
    }
    // Cleanup
    vbdClose();
    tfp->close();
    exit(0);
}
