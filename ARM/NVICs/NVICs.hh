// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/NVICs/NVICs.hh
///

#ifndef ARM_NVICs_NVICs_hh
#define ARM_NVICs_NVICs_hh

enum class ARM::NVICs::IRQs {
#if   0<NUM_IRQS
	IRQ_0,
#endif
#if   1<NUM_IRQS
	IRQ_1,
#endif
#if   2<NUM_IRQS
	IRQ_2,
#endif
#if   3<NUM_IRQS
	IRQ_3,
#endif
#if   4<NUM_IRQS
	IRQ_4,
#endif
#if   5<NUM_IRQS
	IRQ_5,
#endif
#if   6<NUM_IRQS
	IRQ_6,
#endif
#if   7<NUM_IRQS
	IRQ_7,
#endif
#if   8<NUM_IRQS
	IRQ_8,
#endif
#if   9<NUM_IRQS
	IRQ_9,
#endif
#if  10<NUM_IRQS
	IRQ_10,
#endif
#if  11<NUM_IRQS
	IRQ_11,
#endif
#if  12<NUM_IRQS
	IRQ_12,
#endif
#if  13<NUM_IRQS
	IRQ_13,
#endif
#if  14<NUM_IRQS
	IRQ_14,
#endif
#if  15<NUM_IRQS
	IRQ_15,
#endif
#if  16<NUM_IRQS
	IRQ_16,
#endif
#if  17<NUM_IRQS
	IRQ_17,
#endif
#if  18<NUM_IRQS
	IRQ_18,
#endif
#if  19<NUM_IRQS
	IRQ_19,
#endif
#if  20<NUM_IRQS
	IRQ_20,
#endif
#if  21<NUM_IRQS
	IRQ_21,
#endif
#if  22<NUM_IRQS
	IRQ_22,
#endif
#if  23<NUM_IRQS
	IRQ_23,
#endif
#if  24<NUM_IRQS
	IRQ_24,
#endif
#if  25<NUM_IRQS
	IRQ_25,
#endif
#if  26<NUM_IRQS
	IRQ_26,
#endif
#if  27<NUM_IRQS
	IRQ_27,
#endif
#if  28<NUM_IRQS
	IRQ_28,
#endif
#if  29<NUM_IRQS
	IRQ_29,
#endif
#if  30<NUM_IRQS
	IRQ_30,
#endif
#if  31<NUM_IRQS
	IRQ_31,
#endif
#if  32<NUM_IRQS
	IRQ_32,
#endif
#if  33<NUM_IRQS
	IRQ_33,
#endif
#if  34<NUM_IRQS
	IRQ_34,
#endif
#if  35<NUM_IRQS
	IRQ_35,
#endif
#if  36<NUM_IRQS
	IRQ_36,
#endif
#if  37<NUM_IRQS
	IRQ_37,
#endif
#if  38<NUM_IRQS
	IRQ_38,
#endif
#if  39<NUM_IRQS
	IRQ_39,
#endif
#if  40<NUM_IRQS
	IRQ_40,
#endif
#if  41<NUM_IRQS
	IRQ_41,
#endif
#if  42<NUM_IRQS
	IRQ_42,
#endif
#if  43<NUM_IRQS
	IRQ_43,
#endif
#if  44<NUM_IRQS
	IRQ_44,
#endif
#if  45<NUM_IRQS
	IRQ_45,
#endif
#if  46<NUM_IRQS
	IRQ_46,
#endif
#if  47<NUM_IRQS
	IRQ_47,
#endif
#if  48<NUM_IRQS
	IRQ_48,
#endif
#if  49<NUM_IRQS
	IRQ_49,
#endif
#if  50<NUM_IRQS
	IRQ_50,
#endif
#if  51<NUM_IRQS
	IRQ_51,
#endif
#if  52<NUM_IRQS
	IRQ_52,
#endif
#if  53<NUM_IRQS
	IRQ_53,
#endif
#if  54<NUM_IRQS
	IRQ_54,
#endif
#if  55<NUM_IRQS
	IRQ_55,
#endif
#if  56<NUM_IRQS
	IRQ_56,
#endif
#if  57<NUM_IRQS
	IRQ_57,
#endif
#if  58<NUM_IRQS
	IRQ_58,
#endif
#if  59<NUM_IRQS
	IRQ_59,
#endif
#if  60<NUM_IRQS
	IRQ_60,
#endif
#if  61<NUM_IRQS
	IRQ_61,
#endif
#if  62<NUM_IRQS
	IRQ_62,
#endif
#if  63<NUM_IRQS
	IRQ_63,
#endif
#if  64<NUM_IRQS
	IRQ_64,
#endif
#if  65<NUM_IRQS
	IRQ_65,
#endif
#if  66<NUM_IRQS
	IRQ_66,
#endif
#if  67<NUM_IRQS
	IRQ_67,
#endif
#if  68<NUM_IRQS
	IRQ_68,
#endif
#if  69<NUM_IRQS
	IRQ_69,
#endif
#if  70<NUM_IRQS
	IRQ_70,
#endif
#if  71<NUM_IRQS
	IRQ_71,
#endif
#if  72<NUM_IRQS
	IRQ_72,
#endif
#if  73<NUM_IRQS
	IRQ_73,
#endif
#if  74<NUM_IRQS
	IRQ_74,
#endif
#if  75<NUM_IRQS
	IRQ_75,
#endif
#if  76<NUM_IRQS
	IRQ_76,
#endif
#if  77<NUM_IRQS
	IRQ_77,
#endif
#if  78<NUM_IRQS
	IRQ_78,
#endif
#if  79<NUM_IRQS
	IRQ_79,
#endif
#if  80<NUM_IRQS
	IRQ_80,
#endif
#if  81<NUM_IRQS
	IRQ_81,
#endif
#if  82<NUM_IRQS
	IRQ_82,
#endif
#if  83<NUM_IRQS
	IRQ_83,
#endif
#if  84<NUM_IRQS
	IRQ_84,
#endif
#if  85<NUM_IRQS
	IRQ_85,
#endif
#if  86<NUM_IRQS
	IRQ_86,
#endif
#if  87<NUM_IRQS
	IRQ_87,
#endif
#if  88<NUM_IRQS
	IRQ_88,
#endif
#if  89<NUM_IRQS
	IRQ_89,
#endif
#if  90<NUM_IRQS
	IRQ_90,
#endif
#if  91<NUM_IRQS
	IRQ_91,
#endif
#if  92<NUM_IRQS
	IRQ_92,
#endif
#if  93<NUM_IRQS
	IRQ_93,
#endif
#if  94<NUM_IRQS
	IRQ_94,
#endif
#if  95<NUM_IRQS
	IRQ_95,
#endif
#if  96<NUM_IRQS
	IRQ_96,
#endif
#if  97<NUM_IRQS
	IRQ_97,
#endif
#if  98<NUM_IRQS
	IRQ_98,
#endif
#if  99<NUM_IRQS
	IRQ_99,
#endif
#if 100<NUM_IRQS
	IRQ_100,
#endif
#if 101<NUM_IRQS
	IRQ_101,
#endif
#if 102<NUM_IRQS
	IRQ_102,
#endif
#if 103<NUM_IRQS
	IRQ_103,
#endif
#if 104<NUM_IRQS
	IRQ_104,
#endif
#if 105<NUM_IRQS
	IRQ_105,
#endif
#if 106<NUM_IRQS
	IRQ_106,
#endif
#if 107<NUM_IRQS
	IRQ_107,
#endif
#if 108<NUM_IRQS
	IRQ_108,
#endif
#if 109<NUM_IRQS
	IRQ_109,
#endif
#if 110<NUM_IRQS
	IRQ_110,
#endif
#if 111<NUM_IRQS
	IRQ_111,
#endif
#if 112<NUM_IRQS
	IRQ_112,
#endif
#if 113<NUM_IRQS
	IRQ_113,
#endif
#if 114<NUM_IRQS
	IRQ_114,
#endif
#if 115<NUM_IRQS
	IRQ_115,
#endif
#if 116<NUM_IRQS
	IRQ_116,
#endif
#if 117<NUM_IRQS
	IRQ_117,
#endif
#if 118<NUM_IRQS
	IRQ_118,
#endif
#if 119<NUM_IRQS
	IRQ_119,
#endif
#if 120<NUM_IRQS
	IRQ_120,
#endif
#if 121<NUM_IRQS
	IRQ_121,
#endif
#if 122<NUM_IRQS
	IRQ_122,
#endif
#if 123<NUM_IRQS
	IRQ_123,
#endif
#if 124<NUM_IRQS
	IRQ_124,
#endif
#if 125<NUM_IRQS
	IRQ_125,
#endif
#if 126<NUM_IRQS
	IRQ_126,
#endif
#if 127<NUM_IRQS
	IRQ_127,
#endif
#if 128<NUM_IRQS
	IRQ_128,
#endif
#if 129<NUM_IRQS
	IRQ_129,
#endif
#if 130<NUM_IRQS
	IRQ_130,
#endif
#if 131<NUM_IRQS
	IRQ_131,
#endif
#if 132<NUM_IRQS
	IRQ_132,
#endif
#if 133<NUM_IRQS
	IRQ_133,
#endif
#if 134<NUM_IRQS
	IRQ_134,
#endif
#if 135<NUM_IRQS
	IRQ_135,
#endif
#if 136<NUM_IRQS
	IRQ_136,
#endif
#if 137<NUM_IRQS
	IRQ_137,
#endif
#if 138<NUM_IRQS
	IRQ_138,
#endif
#if 139<NUM_IRQS
	IRQ_139,
#endif
#if 140<NUM_IRQS
	IRQ_140,
#endif
#if 141<NUM_IRQS
	IRQ_141,
#endif
#if 142<NUM_IRQS
	IRQ_142,
#endif
#if 143<NUM_IRQS
	IRQ_143,
#endif
#if 144<NUM_IRQS
	IRQ_144,
#endif
#if 145<NUM_IRQS
	IRQ_145,
#endif
#if 146<NUM_IRQS
	IRQ_146,
#endif
#if 147<NUM_IRQS
	IRQ_147,
#endif
#if 148<NUM_IRQS
	IRQ_148,
#endif
#if 149<NUM_IRQS
	IRQ_149,
#endif
#if 150<NUM_IRQS
	IRQ_150,
#endif
#if 151<NUM_IRQS
	IRQ_151,
#endif
#if 152<NUM_IRQS
	IRQ_152,
#endif
#if 153<NUM_IRQS
	IRQ_153,
#endif
#if 154<NUM_IRQS
	IRQ_154,
#endif
#if 155<NUM_IRQS
	IRQ_155,
#endif
#if 156<NUM_IRQS
	IRQ_156,
#endif
#if 157<NUM_IRQS
	IRQ_157,
#endif
#if 158<NUM_IRQS
	IRQ_158,
#endif
#if 159<NUM_IRQS
	IRQ_159,
#endif
#if 160<NUM_IRQS
	IRQ_160,
#endif
#if 161<NUM_IRQS
	IRQ_161,
#endif
#if 162<NUM_IRQS
	IRQ_162,
#endif
#if 163<NUM_IRQS
	IRQ_163,
#endif
#if 164<NUM_IRQS
	IRQ_164,
#endif
#if 165<NUM_IRQS
	IRQ_165,
#endif
#if 166<NUM_IRQS
	IRQ_166,
#endif
#if 167<NUM_IRQS
	IRQ_167,
#endif
#if 168<NUM_IRQS
	IRQ_168,
#endif
#if 169<NUM_IRQS
	IRQ_169,
#endif
#if 170<NUM_IRQS
	IRQ_170,
#endif
#if 171<NUM_IRQS
	IRQ_171,
#endif
#if 172<NUM_IRQS
	IRQ_172,
#endif
#if 173<NUM_IRQS
	IRQ_173,
#endif
#if 174<NUM_IRQS
	IRQ_174,
#endif
#if 175<NUM_IRQS
	IRQ_175,
#endif
#if 176<NUM_IRQS
	IRQ_176,
#endif
#if 177<NUM_IRQS
	IRQ_177,
#endif
#if 178<NUM_IRQS
	IRQ_178,
#endif
#if 179<NUM_IRQS
	IRQ_179,
#endif
#if 180<NUM_IRQS
	IRQ_180,
#endif
#if 181<NUM_IRQS
	IRQ_181,
#endif
#if 182<NUM_IRQS
	IRQ_182,
#endif
#if 183<NUM_IRQS
	IRQ_183,
#endif
#if 184<NUM_IRQS
	IRQ_184,
#endif
#if 185<NUM_IRQS
	IRQ_185,
#endif
#if 186<NUM_IRQS
	IRQ_186,
#endif
#if 187<NUM_IRQS
	IRQ_187,
#endif
#if 188<NUM_IRQS
	IRQ_188,
#endif
#if 189<NUM_IRQS
	IRQ_189,
#endif
#if 190<NUM_IRQS
	IRQ_190,
#endif
#if 191<NUM_IRQS
	IRQ_191,
#endif
#if 192<NUM_IRQS
	IRQ_192,
#endif
#if 193<NUM_IRQS
	IRQ_193,
#endif
#if 194<NUM_IRQS
	IRQ_194,
#endif
#if 195<NUM_IRQS
	IRQ_195,
#endif
#if 196<NUM_IRQS
	IRQ_196,
#endif
#if 197<NUM_IRQS
	IRQ_197,
#endif
#if 198<NUM_IRQS
	IRQ_198,
#endif
#if 199<NUM_IRQS
	IRQ_199,
#endif
#if 200<NUM_IRQS
	IRQ_200,
#endif
#if 201<NUM_IRQS
	IRQ_201,
#endif
#if 202<NUM_IRQS
	IRQ_202,
#endif
#if 203<NUM_IRQS
	IRQ_203,
#endif
#if 204<NUM_IRQS
	IRQ_204,
#endif
#if 205<NUM_IRQS
	IRQ_205,
#endif
#if 206<NUM_IRQS
	IRQ_206,
#endif
#if 207<NUM_IRQS
	IRQ_207,
#endif
#if 208<NUM_IRQS
	IRQ_208,
#endif
#if 209<NUM_IRQS
	IRQ_209,
#endif
#if 210<NUM_IRQS
	IRQ_210,
#endif
#if 211<NUM_IRQS
	IRQ_211,
#endif
#if 212<NUM_IRQS
	IRQ_212,
#endif
#if 213<NUM_IRQS
	IRQ_213,
#endif
#if 214<NUM_IRQS
	IRQ_214,
#endif
#if 215<NUM_IRQS
	IRQ_215,
#endif
#if 216<NUM_IRQS
	IRQ_216,
#endif
#if 217<NUM_IRQS
	IRQ_217,
#endif
#if 218<NUM_IRQS
	IRQ_218,
#endif
#if 219<NUM_IRQS
	IRQ_219,
#endif
#if 220<NUM_IRQS
	IRQ_220,
#endif
#if 221<NUM_IRQS
	IRQ_221,
#endif
#if 222<NUM_IRQS
	IRQ_222,
#endif
#if 223<NUM_IRQS
	IRQ_223,
#endif
#if 224<NUM_IRQS
	IRQ_224,
#endif
#if 225<NUM_IRQS
	IRQ_225,
#endif
#if 226<NUM_IRQS
	IRQ_226,
#endif
#if 227<NUM_IRQS
	IRQ_227,
#endif
#if 228<NUM_IRQS
	IRQ_228,
#endif
#if 229<NUM_IRQS
	IRQ_229,
#endif
#if 230<NUM_IRQS
	IRQ_230,
#endif
#if 231<NUM_IRQS
	IRQ_231,
#endif
#if 232<NUM_IRQS
	IRQ_232,
#endif
#if 233<NUM_IRQS
	IRQ_233,
#endif
#if 234<NUM_IRQS
	IRQ_234,
#endif
#if 235<NUM_IRQS
	IRQ_235,
#endif
#if 236<NUM_IRQS
	IRQ_236,
#endif
#if 237<NUM_IRQS
	IRQ_237,
#endif
#if 238<NUM_IRQS
	IRQ_238,
#endif
#if 239<NUM_IRQS
	IRQ_239
#endif
}; // ARM::NVICs::IRQs

#endif // ARM_NVICs_NVICs_hh
