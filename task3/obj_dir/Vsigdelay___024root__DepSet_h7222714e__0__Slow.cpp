// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsigdelay.h for the primary calling header

#include "verilated.h"

#include "Vsigdelay___024root.h"

VL_ATTR_COLD void Vsigdelay___024root___eval_initial(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

VL_ATTR_COLD void Vsigdelay___024root___eval_settle(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_settle\n"); );
}

VL_ATTR_COLD void Vsigdelay___024root___final(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___final\n"); );
}

VL_ATTR_COLD void Vsigdelay___024root___ctor_var_reset(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->wr_en = VL_RAND_RESET_I(1);
    vlSelf->rd_en = VL_RAND_RESET_I(1);
    vlSelf->delay_offset = VL_RAND_RESET_I(8);
    vlSelf->mic_signal = VL_RAND_RESET_I(8);
    vlSelf->delayed_signal = VL_RAND_RESET_I(8);
    vlSelf->sigdelay__DOT__wr_addr = VL_RAND_RESET_I(8);
    vlSelf->sigdelay__DOT__rd_addr = VL_RAND_RESET_I(8);
    for (int __Vi0=0; __Vi0<256; ++__Vi0) {
        vlSelf->sigdelay__DOT__ram__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->__Vdly__sigdelay__DOT__wr_addr = VL_RAND_RESET_I(8);
}
