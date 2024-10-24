// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsigdelay.h for the primary calling header

#include "verilated.h"

#include "Vsigdelay___024root.h"

VL_INLINE_OPT void Vsigdelay___024root___sequent__TOP__0(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->__Vdly__sigdelay__DOT__wr_addr = vlSelf->sigdelay__DOT__wr_addr;
    if (vlSelf->rst) {
        vlSelf->__Vdly__sigdelay__DOT__wr_addr = 0U;
    } else if (vlSelf->wr_en) {
        vlSelf->__Vdly__sigdelay__DOT__wr_addr = (0xffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->sigdelay__DOT__wr_addr)));
    }
}

VL_INLINE_OPT void Vsigdelay___024root___sequent__TOP__1(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___sequent__TOP__1\n"); );
    // Init
    CData/*7:0*/ __Vdlyvdim0__sigdelay__DOT__ram__DOT__ram_array__v0;
    CData/*7:0*/ __Vdlyvval__sigdelay__DOT__ram__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvset__sigdelay__DOT__ram__DOT__ram_array__v0;
    // Body
    __Vdlyvset__sigdelay__DOT__ram__DOT__ram_array__v0 = 0U;
    if (vlSelf->wr_en) {
        __Vdlyvval__sigdelay__DOT__ram__DOT__ram_array__v0 
            = vlSelf->mic_signal;
        __Vdlyvset__sigdelay__DOT__ram__DOT__ram_array__v0 = 1U;
        __Vdlyvdim0__sigdelay__DOT__ram__DOT__ram_array__v0 
            = vlSelf->sigdelay__DOT__wr_addr;
    }
    if (vlSelf->rd_en) {
        vlSelf->delayed_signal = vlSelf->sigdelay__DOT__ram__DOT__ram_array
            [vlSelf->sigdelay__DOT__rd_addr];
    }
    if (__Vdlyvset__sigdelay__DOT__ram__DOT__ram_array__v0) {
        vlSelf->sigdelay__DOT__ram__DOT__ram_array[__Vdlyvdim0__sigdelay__DOT__ram__DOT__ram_array__v0] 
            = __Vdlyvval__sigdelay__DOT__ram__DOT__ram_array__v0;
    }
}

VL_INLINE_OPT void Vsigdelay___024root___sequent__TOP__2(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___sequent__TOP__2\n"); );
    // Body
    vlSelf->sigdelay__DOT__rd_addr = ((IData)(vlSelf->rst)
                                       ? 0U : (0xffU 
                                               & ((IData)(vlSelf->sigdelay__DOT__wr_addr) 
                                                  - (IData)(vlSelf->delay_offset))));
    vlSelf->sigdelay__DOT__wr_addr = vlSelf->__Vdly__sigdelay__DOT__wr_addr;
}

void Vsigdelay___024root___eval(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vsigdelay___024root___sequent__TOP__0(vlSelf);
    }
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vsigdelay___024root___sequent__TOP__1(vlSelf);
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vsigdelay___024root___sequent__TOP__2(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void Vsigdelay___024root___eval_debug_assertions(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->wr_en & 0xfeU))) {
        Verilated::overWidthError("wr_en");}
    if (VL_UNLIKELY((vlSelf->rd_en & 0xfeU))) {
        Verilated::overWidthError("rd_en");}
}
#endif  // VL_DEBUG
