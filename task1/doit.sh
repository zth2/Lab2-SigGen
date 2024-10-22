#!/bin/bash

~/Documents/iacLAB-0/lab0-devtools/tools/attach_usb.sh

rm -rf obj_dir
rm -f sinegen.vcd

# Step 1: Compile the Verilog files along with the testbench
verilator -Wall --cc --trace sinegen.sv --exe sinegen_tb.cpp

# Step 2: Build the executable for the simulation
make -j -C obj_dir/ -f Vsinegen.mk Vsinegen

# Step 3: Run the simulation
./obj_dir/Vsinegen
