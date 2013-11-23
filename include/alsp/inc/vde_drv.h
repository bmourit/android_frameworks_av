
#if 0 // _GL5201_
#include "vpx_drv.h"

#define VDE_QUERY               VPX_QUERY
#define VDE_ENABLE_CLK          VPX_ENABLE_CLK
#define VDE_DISABLE_CLK         VPX_DISABLE_CLK
#define VDE_RUN                 VPX_RUN
#define VDE_REGISTER_BASE       0xb0310000

#else



//#define VDE_QUERY               0x00
//#define VDE_ENABLE_CLK          0x01
//#define VDE_DISABLE_CLK         0x02
//#define VDE_RUN                 0x03
//#define VDE_DUMP                0x04
#ifdef __cplusplus
extern "C" {
#endif
#define VDE_MAGIC_NUMBER                'v'
/******************************************************************************/

#define VDE_QUERY                        _IOWR(VDE_MAGIC_NUMBER, 0xf0, unsigned long)

#define VDE_ENABLE_CLK                   _IOWR(VDE_MAGIC_NUMBER, 0xf1, unsigned long)

#define VDE_DISABLE_CLK                     _IOWR(VDE_MAGIC_NUMBER, 0xf2, unsigned long)

#define VDE_RUN                     _IOWR(VDE_MAGIC_NUMBER, 0xf3, unsigned long)
#define VDE_DUMP                    _IOWR(VDE_MAGIC_NUMBER, 0xf4,unsigned long)
#define VDE_SET_FREQ                     _IOWR(VDE_MAGIC_NUMBER, 0xf5, unsigned long)
#define VDE_GET_FREQ                    _IOWR(VDE_MAGIC_NUMBER, 0xf6,unsigned long)
#define VDE_SET_MULTI                   _IOWR(VDE_MAGIC_NUMBER, 0xf7,unsigned long)



// 20121020 : VDE Clk derived from DISPLAY_PLL, and DISPLAY_PLL is Set to 720M, VDE freq can be set at this levels
// 20121105 : VDE Clk derived from DISPLAY_PLL, and DISPLAY_PLL is Set to 642M
#define VDE_FREQ_DEFAULT 360
#define VDE_FREQ_D1      180 //minimize 4 div
#define VDE_FREQ_720P    240
#define VDE_FREQ_1080P   360
#define VDE_FREQ_MULTI   480
#define VDE_FREQ_4Kx2K   540



//#define VDE_REGISTER_BASE       0xb0270000
#ifdef __cplusplus
}
#endif

#endif
