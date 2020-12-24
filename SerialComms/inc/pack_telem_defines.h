/// BEGIN AUTOGENERATED SECTION - MODIFICATIONS TO THIS CODE WILL BE OVERWRITTEN

/// pack_telem_defines.h
/// Autogenerated by telem_defines_globals_generate.py on Tue Dec 22 14:50:25 2020

#include "globals.h"
#include <stdint.h>

#define	TELEM_ITEM_0	((uint32_t) (valve_states*1)) >> 0 
#define	TELEM_ITEM_1	((uint32_t) (valve_states*1)) >> 8 
#define	TELEM_ITEM_2	((uint32_t) (valve_states*1)) >> 16 
#define	TELEM_ITEM_3	((uint32_t) (valve_states*1)) >> 24 
#define	TELEM_ITEM_4	((int16_t) (pressure[0]*1)) >> 0 
#define	TELEM_ITEM_5	((int16_t) (pressure[0]*1)) >> 8 
#define	TELEM_ITEM_6	((int16_t) (pressure[1]*1)) >> 0 
#define	TELEM_ITEM_7	((int16_t) (pressure[1]*1)) >> 8 
#define	TELEM_ITEM_8	((int16_t) (pressure[2]*1)) >> 0 
#define	TELEM_ITEM_9	((int16_t) (pressure[2]*1)) >> 8 
#define	TELEM_ITEM_10	((int16_t) (pressure[3]*1)) >> 0 
#define	TELEM_ITEM_11	((int16_t) (pressure[3]*1)) >> 8 
#define	TELEM_ITEM_12	((int16_t) (pressure[4]*1)) >> 0 
#define	TELEM_ITEM_13	((int16_t) (pressure[4]*1)) >> 8 
#define	TELEM_ITEM_14	((int16_t) (pressure[5]*1)) >> 0 
#define	TELEM_ITEM_15	((int16_t) (pressure[5]*1)) >> 8 
#define	TELEM_ITEM_16	((int16_t) (pressure[6]*1)) >> 0 
#define	TELEM_ITEM_17	((int16_t) (pressure[6]*1)) >> 8 
#define	TELEM_ITEM_18	((int16_t) (pressure[7]*1)) >> 0 
#define	TELEM_ITEM_19	((int16_t) (pressure[7]*1)) >> 8 
#define	TELEM_ITEM_20	((int16_t) (ebatt*1000)) >> 0 
#define	TELEM_ITEM_21	((int16_t) (ebatt*1000)) >> 8 
#define	TELEM_ITEM_22	((int16_t) (ibus*100)) >> 0 
#define	TELEM_ITEM_23	((int16_t) (ibus*100)) >> 8 
#define	TELEM_ITEM_24	((uint8_t) (STATE*1)) >> 0 
#define	TELEM_ITEM_25	((uint16_t) (load[0]*1)) >> 0 
#define	TELEM_ITEM_26	((uint16_t) (load[0]*1)) >> 8 
#define	TELEM_ITEM_27	((uint16_t) (load[1]*1)) >> 0 
#define	TELEM_ITEM_28	((uint16_t) (load[1]*1)) >> 8 
#define	TELEM_ITEM_29	((uint16_t) (load[2]*1)) >> 0 
#define	TELEM_ITEM_30	((uint16_t) (load[2]*1)) >> 8 
#define	TELEM_ITEM_31	((uint16_t) (load[3]*1)) >> 0 
#define	TELEM_ITEM_32	((uint16_t) (load[3]*1)) >> 8 
#define	TELEM_ITEM_33	((uint16_t) (load[4]*1)) >> 0 
#define	TELEM_ITEM_34	((uint16_t) (load[4]*1)) >> 8 
#define	TELEM_ITEM_35	((uint16_t) (load[5]*1)) >> 0 
#define	TELEM_ITEM_36	((uint16_t) (load[5]*1)) >> 8 
#define	TELEM_ITEM_37	((uint16_t) (load[6]*1)) >> 0 
#define	TELEM_ITEM_38	((uint16_t) (load[6]*1)) >> 8 
#define	TELEM_ITEM_39	((uint16_t) (load[7]*1)) >> 0 
#define	TELEM_ITEM_40	((uint16_t) (load[7]*1)) >> 8 
#define	TELEM_ITEM_41	((uint8_t) (ivlv[0]*10)) >> 0 
#define	TELEM_ITEM_42	((uint8_t) (ivlv[1]*10)) >> 0 
#define	TELEM_ITEM_43	((uint8_t) (ivlv[2]*10)) >> 0 
#define	TELEM_ITEM_44	((uint8_t) (ivlv[3]*10)) >> 0 
#define	TELEM_ITEM_45	((uint8_t) (ivlv[4]*10)) >> 0 
#define	TELEM_ITEM_46	((uint8_t) (ivlv[5]*10)) >> 0 
#define	TELEM_ITEM_47	((uint8_t) (ivlv[6]*10)) >> 0 
#define	TELEM_ITEM_48	((uint8_t) (ivlv[7]*10)) >> 0 
#define	TELEM_ITEM_49	((uint8_t) (evlv[0]*10)) >> 0 
#define	TELEM_ITEM_50	((uint8_t) (evlv[1]*10)) >> 0 
#define	TELEM_ITEM_51	((uint8_t) (evlv[2]*10)) >> 0 
#define	TELEM_ITEM_52	((uint8_t) (evlv[3]*10)) >> 0 
#define	TELEM_ITEM_53	((uint8_t) (evlv[4]*10)) >> 0 
#define	TELEM_ITEM_54	((uint8_t) (evlv[5]*10)) >> 0 
#define	TELEM_ITEM_55	((uint8_t) (evlv[6]*10)) >> 0 
#define	TELEM_ITEM_56	((uint8_t) (evlv[7]*10)) >> 0 
#define	TELEM_ITEM_57	((int32_t) (e3v*100)) >> 0 
#define	TELEM_ITEM_58	((int32_t) (e3v*100)) >> 8 
#define	TELEM_ITEM_59	((int32_t) (e3v*100)) >> 16 
#define	TELEM_ITEM_60	((int32_t) (e3v*100)) >> 24 
#define	TELEM_ITEM_61	((int32_t) (e5v*100)) >> 0 
#define	TELEM_ITEM_62	((int32_t) (e5v*100)) >> 8 
#define	TELEM_ITEM_63	((int32_t) (e5v*100)) >> 16 
#define	TELEM_ITEM_64	((int32_t) (e5v*100)) >> 24 
#define	TELEM_ITEM_65	((int16_t) (e28v*100)) >> 0 
#define	TELEM_ITEM_66	((int16_t) (e28v*100)) >> 8 
#define	TELEM_ITEM_67	((uint8_t) (i5v*100)) >> 0 
#define	TELEM_ITEM_68	((uint8_t) (i3v*100)) >> 0 
#define	TELEM_ITEM_69	((uint16_t) (last_command_id*100)) >> 0 
#define	TELEM_ITEM_70	((uint16_t) (last_command_id*100)) >> 8 
#define	TELEM_ITEM_71	((uint16_t) (tc[0]*100)) >> 0 
#define	TELEM_ITEM_72	((uint16_t) (tc[0]*100)) >> 8 
#define	TELEM_ITEM_73	((uint16_t) (tc[1]*100)) >> 0 
#define	TELEM_ITEM_74	((uint16_t) (tc[1]*100)) >> 8 
#define	TELEM_ITEM_75	((uint16_t) (tc[2]*100)) >> 0 
#define	TELEM_ITEM_76	((uint16_t) (tc[2]*100)) >> 8 
#define	TELEM_ITEM_77	((uint16_t) (tc[3]*100)) >> 0 
#define	TELEM_ITEM_78	((uint16_t) (tc[3]*100)) >> 8 
#define	TELEM_ITEM_79	((uint16_t) (tc[4]*100)) >> 0 
#define	TELEM_ITEM_80	((uint16_t) (tc[4]*100)) >> 8 
#define	TELEM_ITEM_81	((uint16_t) (tc[5]*100)) >> 0 
#define	TELEM_ITEM_82	((uint16_t) (tc[5]*100)) >> 8 
#define	TELEM_ITEM_83	((uint16_t) (tc[6]*100)) >> 0 
#define	TELEM_ITEM_84	((uint16_t) (tc[6]*100)) >> 8 
#define	TELEM_ITEM_85	((uint16_t) (tc[7]*100)) >> 0 
#define	TELEM_ITEM_86	((uint16_t) (tc[7]*100)) >> 8 
#define	TELEM_ITEM_87	((uint16_t) (rtd[0]*100)) >> 0 
#define	TELEM_ITEM_88	((uint16_t) (rtd[0]*100)) >> 8 
#define	TELEM_ITEM_89	((uint16_t) (rtd[1]*100)) >> 0 
#define	TELEM_ITEM_90	((uint16_t) (rtd[1]*100)) >> 8 
#define	TELEM_ITEM_91	((uint16_t) (rtd[2]*100)) >> 0 
#define	TELEM_ITEM_92	((uint16_t) (rtd[2]*100)) >> 8 
#define	TELEM_ITEM_93	((uint16_t) (rtd[3]*100)) >> 0 
#define	TELEM_ITEM_94	((uint16_t) (rtd[3]*100)) >> 8 
#define	TELEM_ITEM_95	((uint16_t) (rtd[4]*100)) >> 0 
#define	TELEM_ITEM_96	((uint16_t) (rtd[4]*100)) >> 8 
#define	TELEM_ITEM_97	((uint16_t) (rtd[5]*100)) >> 0 
#define	TELEM_ITEM_98	((uint16_t) (rtd[5]*100)) >> 8 
#define	TELEM_ITEM_99	((uint16_t) (rtd[6]*100)) >> 0 
#define	TELEM_ITEM_100	((uint16_t) (rtd[6]*100)) >> 8 
#define	TELEM_ITEM_101	((uint16_t) (rtd[7]*100)) >> 0 
#define	TELEM_ITEM_102	((uint16_t) (rtd[7]*100)) >> 8 
#define	TELEM_ITEM_103	((uint16_t) (i_mtr_ab[0]*100)) >> 0 
#define	TELEM_ITEM_104	((uint16_t) (i_mtr_ab[0]*100)) >> 8 
#define	TELEM_ITEM_105	((uint16_t) (i_mtr_ab[1]*100)) >> 0 
#define	TELEM_ITEM_106	((uint16_t) (i_mtr_ab[1]*100)) >> 8 
#define	TELEM_ITEM_107	((uint16_t) (i_mtr_ab[2]*100)) >> 0 
#define	TELEM_ITEM_108	((uint16_t) (i_mtr_ab[2]*100)) >> 8 
#define	TELEM_ITEM_109	((uint16_t) (i_mtr_ab[3]*100)) >> 0 
#define	TELEM_ITEM_110	((uint16_t) (i_mtr_ab[3]*100)) >> 8 
#define	TELEM_ITEM_111	((uint16_t) (i_mtr[0]*100)) >> 0 
#define	TELEM_ITEM_112	((uint16_t) (i_mtr[0]*100)) >> 8 
#define	TELEM_ITEM_113	((uint16_t) (i_mtr[1]*100)) >> 0 
#define	TELEM_ITEM_114	((uint16_t) (i_mtr[1]*100)) >> 8 
#define	TELEM_ITEM_115	((uint16_t) (pot[0]*1000)) >> 0 
#define	TELEM_ITEM_116	((uint16_t) (pot[0]*1000)) >> 8 
#define	TELEM_ITEM_117	((uint16_t) (pot[1]*1000)) >> 0 
#define	TELEM_ITEM_118	((uint16_t) (pot[1]*1000)) >> 8 
#define	TELEM_ITEM_119	((uint16_t) (pot[2]*1000)) >> 0 
#define	TELEM_ITEM_120	((uint16_t) (pot[2]*1000)) >> 8 
#define	TELEM_ITEM_121	((uint16_t) (pot[3]*1000)) >> 0 
#define	TELEM_ITEM_122	((uint16_t) (pot[3]*1000)) >> 8 
#define	CLB_NUM_TELEM_ITEMS	123

/**
 * Takes in a uint8_t array of size CLB_NUM_TELEM_ITEMS and packs the 
 * global variables into it as defined in pack_telem_defines.h
 *
 * @param dst	<uint8_t*>	Array to write the global variables to after packing their bytes for telemetry.
**/
extern void pack_telem_data(uint8_t* dst);
