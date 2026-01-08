// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku
#include <behaviors.dtsi>
#include <behaviors/unicode.dtsi>
#include <zmk-unicode/keys-extra.h> 
#include "../zmk-nodefree-config/helper.h"

#if defined (MIRYOKU_KEYBOARD_CORNE)

#define dt_left &kp LC(LG(LEFT))
#define dt_right &kp LC(LG(RIGHT))

#define XXX &none

/ {
  macros {
    linux_oe_lower: linux_oe_lower {
      compatible = "zmk,behavior-macro";
      #binding-cells = <0>;
      bindings = <
        &macro_tap &kp INS
        &macro_tap &kp DQT
        &macro_tap &kp O
      >;
    };

    linux_oe_upper: linux_oe_upper {
      compatible = "zmk,behavior-macro";
      #binding-cells = <0>;
      bindings = <
        &macro_tap &kp INS
        &macro_tap &kp DQT
        &macro_tap &kp LS(O)
      >;
    };

    linux_ae_lower: linux_ae_lower {
      compatible = "zmk,behavior-macro";
	  #binding-cells = <0>;
      bindings = <
        &macro_tap &kp INS
        &macro_tap &kp DQT
        &macro_tap &kp A
      >;
    };

    linux_ae_upper: linux_ae_upper {
      compatible = "zmk,behavior-macro";
	  #binding-cells = <0>;
      bindings = <
        &macro_tap &kp INS
        &macro_tap &kp DQT
        &macro_tap &kp LS(A)
      >;
    };

    linux_ao_lower: linux_ao_lower {
      compatible = "zmk,behavior-macro";
	  #binding-cells = <0>;
      bindings = <
        &macro_tap &kp INS
        &macro_tap &kp O
        &macro_tap &kp A
      >;
    };

    linux_ao_upper: linux_ao_upper {
      compatible = "zmk,behavior-macro";
	  #binding-cells = <0>;
      bindings = <
        &macro_tap &kp INS
        &macro_tap &kp O
        &macro_tap &kp LS(A)
      >;
    };
  };

  behaviors {
    linux_oe: linux_oe {
      compatible = "zmk,behavior-mod-morph";
      #binding-cells = <0>;
      bindings = <&linux_oe_lower>, <&linux_oe_upper>;
      mods = <(MOD_LSFT|MOD_RSFT)>;
    };
    linux_ae: linux_ae {
      compatible = "zmk,behavior-mod-morph";
      #binding-cells = <0>;
      bindings = <&linux_ae_lower>, <&linux_ae_upper>;
      mods = <(MOD_LSFT|MOD_RSFT)>;
    };
    linux_ao: linux_ao {
      compatible = "zmk,behavior-mod-morph";
      #binding-cells = <0>;
      bindings = <&linux_ao_lower>, <&linux_ao_upper>;
      mods = <(MOD_LSFT|MOD_RSFT)>;
    };
  };

};

#define MIRYOKU_LAYERMAPPING_BASE( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
     &tog U_LINUX K00  K01  K02  K03  K04       K05  K06  K07  K08  K09  &uc UC_SV_AO /* å / Å */ \
     XXX          K10  K11  K12  K13  K14       K15  K16  K17  K18  K19  &uc UC_SV_AE /* ä / Ä */ \
     &kp LGUI     K20  K21  K22  K23  K24       K25  K26  K27  K28  K29  &kp SQT \
                            K32  K33  K34       K35  K36  K37

#define MIRYOKU_LAYERMAPPING_NAV( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
     XXX  K00  K01  K02  K03  K04       K05  K06  K07  K08  K09  XXX \
     XXX  K10  K11  K12  K13  K14       K15  K16  K17  K18  K19  &kp LA(INS) \
&kp LGUI  K20  K21  K22  K23  K24       K25  K26  K27  K28  K29  dt_right \
                    K32  K33  K34       K35  K36  K37

#define MIRYOKU_LAYERMAPPING_LINUX( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
     &tog U_LINUX K00  K01  K02  K03  K04       K05  K06  K07  K08  K09  &linux_ao /* å / Å */ \
     XXX          K10  K11  K12  K13  K14       K15  K16  K17  K18  K19  &linux_ae /* ä / Ä */ \
     &kp LGUI     K20  K21  K22  K23  K24       K25  K26  K27  K28  K29  &kp SQT \
                            K32  K33  K34       K35  K36  K37

#endif


#define MIRYOKU_LAYER_BASE \
&kp Q,             &kp W,             &kp E,             &kp R,             &kp T,             &kp Y,             &kp U,             &kp I,             &kp O,             &kp P,     \
&kp A,             U_MT(LALT, S),     U_MT(LCTRL, D),    U_MT(LSHFT, F),    &kp G,             &kp H,             U_MT(LSHFT, J),    U_MT(LCTRL, K),    U_MT(LALT, L),     &uc UC_SV_OE /* ö / Ö */,    \
U_LT(U_BUTTON, Z), U_MT(RALT, X),     &kp C,             &kp V,             &kp B,             &kp N,             &kp M,             &kp COMMA,         U_MT(RALT, DOT),   U_LT(U_BUTTON, SLASH),\
U_NP,              U_NP,              U_LT(U_MEDIA, ESC),U_LT(U_MOUSE, TAB),U_LT(U_NAV, SPACE),U_LT(U_SYM, RET),  U_LT(U_NUM, BSPC), U_LT(U_FUN, DEL),  U_NP,              U_NP

#define MIRYOKU_LAYER_LINUX \
&trans, &trans, &trans, &trans, &trans, &trans, &trans, &trans, &trans, &trans,     \
&trans, &trans, &trans, &trans, &trans, &trans, &trans, &trans, &trans, &linux_oe /* ö / Ö */,    \
&trans, &trans, &trans, &trans, &trans, &trans, &trans, &trans, &trans, &trans,     \
&trans, &trans, &trans, &trans, &trans, &trans, &trans, &trans, &trans, &trans

#define MIRYOKU_LAYER_NAV \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
&kp LGUI,          &kp LALT,          &kp LCTRL,         &kp LSHFT,         U_NA,              &u_caps_word,      &kp LEFT,          &kp DOWN,          &kp UP,            &kp RIGHT,         \
U_NA,              &kp RALT,          &u_to_U_NUM,       &u_to_U_NAV,       U_NA,              dt_left,           &kp HOME,          &kp PG_DN,         &kp PG_UP,         &kp END,           \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              &kp RET,           &kp BSPC,          &kp DEL,           U_NP,              U_NP

#define MIRYOKU_LAYER_FUN \
&kp F12,           &kp F7,            &kp F8,            &kp F9,            &kp PSCRN,         U_NA,              &u_to_U_BASE,      &u_to_U_EXTRA,     &u_to_U_TAP,       U_BOOT,            \
&kp F11,           &kp F4,            &kp F5,            &kp F6,            &kp SLCK,          U_NA,              &kp LSHFT,         &kp LCTRL,         &kp LALT,          &kp LGUI,          \
&kp F10,           &kp F1,            &kp F2,            &kp F3,            &kp PAUSE_BREAK,   U_NA,              &u_to_U_FUN,       &u_to_U_MEDIA,     &kp RALT,          U_NA,              \
U_NP,              U_NP,              &kp K_APP,         &kp TAB,           &kp SPACE,         U_NA,              U_NA,              U_NA,              U_NP,              U_NP

&uc {
	default-mode = <UC_MODE_WIN_COMPOSE>;
};

