#include "Vsinegen.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env){

    int i;

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
    top->incr = 1; // Initial increment

    // Reset the design for 2 cycles
    for (i = 0; i < 2; i++) {
        top->clk = !top->clk;  // Toggle clock
        top->eval();  // Evaluate the model
        tfp->dump(i);  // Dump simulation state at time i
    }

    // Release reset
    top->rst = 0;

    // Main simulation loop
    for (i = 2; i < 1000000; i++) {
        top->clk = !top->clk;  // Toggle clock
        top->eval();  // Evaluate the model

        tfp->dump(i);  // Dump simulation state at each clock cycle

        // Adjust the increment value dynamically from Vbuddy
        top->incr = vbdValue();

        // Plot the sine wave output to Vbuddy
        vbdPlot(int(top->dout), 0, 255);
        vbdCycle(i);  // Advance the Vbuddy simulation cycle

        // Finish simulation if 'q' is pressed or Verilator signals finish
        if (Verilated::gotFinish() || vbdGetkey() == 'q') {
            break;  // Exit the loop
        }
    }

    // Cleanup
    vbdClose();
    tfp->close();
    delete top;  // Delete the top module instance
    return 0;
}
