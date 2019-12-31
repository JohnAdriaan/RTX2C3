// © 2019 John Adriaan. Licensed under the "3-clause BSD License"
///
/// \file ARM/ISRs/ISRs.cc
///

#include "../ISRs.hh"
#include "../NVICs.hh"

using namespace ARM;

extern unsigned _Stack_Top; ///< Value defined in Linker Script

WEAK INTERRUPT void ISRs::Default() {
	for (;;) {
	} // for
} // ISRs::Default()

SECTION(".ISR_Vectors") // Tell linker where to put it
ISRs::Vectors ISRs::vectors = {
	stack     : &_Stack_Top,
	exception : {},
	irq       : {
#if   0<NUM_IRQS
		&NVICs::IRQ0,
#endif
#if   1<NUM_IRQS
		&NVICs::IRQ1,
#endif
#if   2<NUM_IRQS
		&NVICs::IRQ2,
#endif
#if   3<NUM_IRQS
		&NVICs::IRQ3,
#endif
#if   4<NUM_IRQS
		&NVICs::IRQ4,
#endif
#if   5<NUM_IRQS
		&NVICs::IRQ5,
#endif
#if   6<NUM_IRQS
		&NVICs::IRQ6,
#endif
#if   7<NUM_IRQS
		&NVICs::IRQ7,
#endif
#if   8<NUM_IRQS
		&NVICs::IRQ8,
#endif
#if   9<NUM_IRQS
		&NVICs::IRQ9,
#endif
#if  10<NUM_IRQS
		&NVICs::IRQ10,
#endif
#if  11<NUM_IRQS
		&NVICs::IRQ11,
#endif
#if  12<NUM_IRQS
		&NVICs::IRQ12,
#endif
#if  13<NUM_IRQS
		&NVICs::IRQ13,
#endif
#if  14<NUM_IRQS
		&NVICs::IRQ14,
#endif
#if  15<NUM_IRQS
		&NVICs::IRQ15,
#endif
#if  16<NUM_IRQS
		&NVICs::IRQ16,
#endif
#if  17<NUM_IRQS
		&NVICs::IRQ17,
#endif
#if  18<NUM_IRQS
		&NVICs::IRQ18,
#endif
#if  19<NUM_IRQS
		&NVICs::IRQ19,
#endif
#if  20<NUM_IRQS
		&NVICs::IRQ20,
#endif
#if  21<NUM_IRQS
		&NVICs::IRQ21,
#endif
#if  22<NUM_IRQS
		&NVICs::IRQ22,
#endif
#if  23<NUM_IRQS
		&NVICs::IRQ23,
#endif
#if  24<NUM_IRQS
		&NVICs::IRQ24,
#endif
#if  25<NUM_IRQS
		&NVICs::IRQ25,
#endif
#if  26<NUM_IRQS
		&NVICs::IRQ26,
#endif
#if  27<NUM_IRQS
		&NVICs::IRQ27,
#endif
#if  28<NUM_IRQS
		&NVICs::IRQ28,
#endif
#if  29<NUM_IRQS
		&NVICs::IRQ29,
#endif
#if  30<NUM_IRQS
		&NVICs::IRQ30,
#endif
#if  31<NUM_IRQS
		&NVICs::IRQ31,
#endif
#if  32<NUM_IRQS
		&NVICs::IRQ32,
#endif
#if  33<NUM_IRQS
		&NVICs::IRQ33,
#endif
#if  34<NUM_IRQS
		&NVICs::IRQ34,
#endif
#if  35<NUM_IRQS
		&NVICs::IRQ35,
#endif
#if  36<NUM_IRQS
		&NVICs::IRQ36,
#endif
#if  37<NUM_IRQS
		&NVICs::IRQ37,
#endif
#if  38<NUM_IRQS
		&NVICs::IRQ38,
#endif
#if  39<NUM_IRQS
		&NVICs::IRQ39,
#endif
#if  40<NUM_IRQS
		&NVICs::IRQ40,
#endif
#if  41<NUM_IRQS
		&NVICs::IRQ41,
#endif
#if  42<NUM_IRQS
		&NVICs::IRQ42,
#endif
#if  43<NUM_IRQS
		&NVICs::IRQ43,
#endif
#if  44<NUM_IRQS
		&NVICs::IRQ44,
#endif
#if  45<NUM_IRQS
		&NVICs::IRQ45,
#endif
#if  46<NUM_IRQS
		&NVICs::IRQ46,
#endif
#if  47<NUM_IRQS
		&NVICs::IRQ47,
#endif
#if  48<NUM_IRQS
		&NVICs::IRQ48,
#endif
#if  49<NUM_IRQS
		&NVICs::IRQ49,
#endif
#if  50<NUM_IRQS
		&NVICs::IRQ50,
#endif
#if  51<NUM_IRQS
		&NVICs::IRQ51,
#endif
#if  52<NUM_IRQS
		&NVICs::IRQ52,
#endif
#if  53<NUM_IRQS
		&NVICs::IRQ53,
#endif
#if  54<NUM_IRQS
		&NVICs::IRQ54,
#endif
#if  55<NUM_IRQS
		&NVICs::IRQ55,
#endif
#if  56<NUM_IRQS
		&NVICs::IRQ56,
#endif
#if  57<NUM_IRQS
		&NVICs::IRQ57,
#endif
#if  58<NUM_IRQS
		&NVICs::IRQ58,
#endif
#if  59<NUM_IRQS
		&NVICs::IRQ59,
#endif
#if  60<NUM_IRQS
		&NVICs::IRQ60,
#endif
#if  61<NUM_IRQS
		&NVICs::IRQ61,
#endif
#if  62<NUM_IRQS
		&NVICs::IRQ62,
#endif
#if  63<NUM_IRQS
		&NVICs::IRQ63,
#endif
#if  64<NUM_IRQS
		&NVICs::IRQ64,
#endif
#if  65<NUM_IRQS
		&NVICs::IRQ65,
#endif
#if  66<NUM_IRQS
		&NVICs::IRQ66,
#endif
#if  67<NUM_IRQS
		&NVICs::IRQ67,
#endif
#if  68<NUM_IRQS
		&NVICs::IRQ68,
#endif
#if  69<NUM_IRQS
		&NVICs::IRQ69,
#endif
#if  70<NUM_IRQS
		&NVICs::IRQ70,
#endif
#if  71<NUM_IRQS
		&NVICs::IRQ71,
#endif
#if  72<NUM_IRQS
		&NVICs::IRQ72,
#endif
#if  73<NUM_IRQS
		&NVICs::IRQ73,
#endif
#if  74<NUM_IRQS
		&NVICs::IRQ74,
#endif
#if  75<NUM_IRQS
		&NVICs::IRQ75,
#endif
#if  76<NUM_IRQS
		&NVICs::IRQ76,
#endif
#if  77<NUM_IRQS
		&NVICs::IRQ77,
#endif
#if  78<NUM_IRQS
		&NVICs::IRQ78,
#endif
#if  79<NUM_IRQS
		&NVICs::IRQ79,
#endif
#if  80<NUM_IRQS
		&NVICs::IRQ80,
#endif
#if  81<NUM_IRQS
		&NVICs::IRQ81,
#endif
#if  82<NUM_IRQS
		&NVICs::IRQ82,
#endif
#if  83<NUM_IRQS
		&NVICs::IRQ83,
#endif
#if  84<NUM_IRQS
		&NVICs::IRQ84,
#endif
#if  85<NUM_IRQS
		&NVICs::IRQ85,
#endif
#if  86<NUM_IRQS
		&NVICs::IRQ86,
#endif
#if  87<NUM_IRQS
		&NVICs::IRQ87,
#endif
#if  88<NUM_IRQS
		&NVICs::IRQ88,
#endif
#if  89<NUM_IRQS
		&NVICs::IRQ89,
#endif
#if  90<NUM_IRQS
		&NVICs::IRQ90,
#endif
#if  91<NUM_IRQS
		&NVICs::IRQ91,
#endif
#if  92<NUM_IRQS
		&NVICs::IRQ92,
#endif
#if  93<NUM_IRQS
		&NVICs::IRQ93,
#endif
#if  94<NUM_IRQS
		&NVICs::IRQ94,
#endif
#if  95<NUM_IRQS
		&NVICs::IRQ95,
#endif
#if  96<NUM_IRQS
		&NVICs::IRQ96,
#endif
#if  97<NUM_IRQS
		&NVICs::IRQ97,
#endif
#if  98<NUM_IRQS
		&NVICs::IRQ98,
#endif
#if  99<NUM_IRQS
		&NVICs::IRQ99,
#endif
#if 100<NUM_IRQS
		&NVICs::IRQ100,
#endif
#if 101<NUM_IRQS
		&NVICs::IRQ101,
#endif
#if 102<NUM_IRQS
		&NVICs::IRQ102,
#endif
#if 103<NUM_IRQS
		&NVICs::IRQ103,
#endif
#if 104<NUM_IRQS
		&NVICs::IRQ104,
#endif
#if 105<NUM_IRQS
		&NVICs::IRQ105,
#endif
#if 106<NUM_IRQS
		&NVICs::IRQ106,
#endif
#if 107<NUM_IRQS
		&NVICs::IRQ107,
#endif
#if 108<NUM_IRQS
		&NVICs::IRQ108,
#endif
#if 109<NUM_IRQS
		&NVICs::IRQ109,
#endif
#if 110<NUM_IRQS
		&NVICs::IRQ110,
#endif
#if 111<NUM_IRQS
		&NVICs::IRQ111,
#endif
#if 112<NUM_IRQS
		&NVICs::IRQ112,
#endif
#if 113<NUM_IRQS
		&NVICs::IRQ113,
#endif
#if 114<NUM_IRQS
		&NVICs::IRQ114,
#endif
#if 115<NUM_IRQS
		&NVICs::IRQ115,
#endif
#if 116<NUM_IRQS
		&NVICs::IRQ116,
#endif
#if 117<NUM_IRQS
		&NVICs::IRQ117,
#endif
#if 118<NUM_IRQS
		&NVICs::IRQ118,
#endif
#if 119<NUM_IRQS
		&NVICs::IRQ119,
#endif
#if 120<NUM_IRQS
		&NVICs::IRQ120,
#endif
#if 121<NUM_IRQS
		&NVICs::IRQ121,
#endif
#if 122<NUM_IRQS
		&NVICs::IRQ122,
#endif
#if 123<NUM_IRQS
		&NVICs::IRQ123,
#endif
#if 124<NUM_IRQS
		&NVICs::IRQ124,
#endif
#if 125<NUM_IRQS
		&NVICs::IRQ125,
#endif
#if 126<NUM_IRQS
		&NVICs::IRQ126,
#endif
#if 127<NUM_IRQS
		&NVICs::IRQ127,
#endif
#if 128<NUM_IRQS
		&NVICs::IRQ128,
#endif
#if 129<NUM_IRQS
		&NVICs::IRQ129,
#endif
#if 130<NUM_IRQS
		&NVICs::IRQ130,
#endif
#if 131<NUM_IRQS
		&NVICs::IRQ131,
#endif
#if 132<NUM_IRQS
		&NVICs::IRQ132,
#endif
#if 133<NUM_IRQS
		&NVICs::IRQ133,
#endif
#if 134<NUM_IRQS
		&NVICs::IRQ134,
#endif
#if 135<NUM_IRQS
		&NVICs::IRQ135,
#endif
#if 136<NUM_IRQS
		&NVICs::IRQ136,
#endif
#if 137<NUM_IRQS
		&NVICs::IRQ137,
#endif
#if 138<NUM_IRQS
		&NVICs::IRQ138,
#endif
#if 139<NUM_IRQS
		&NVICs::IRQ139,
#endif
#if 140<NUM_IRQS
		&NVICs::IRQ140,
#endif
#if 141<NUM_IRQS
		&NVICs::IRQ141,
#endif
#if 142<NUM_IRQS
		&NVICs::IRQ142,
#endif
#if 143<NUM_IRQS
		&NVICs::IRQ143,
#endif
#if 144<NUM_IRQS
		&NVICs::IRQ144,
#endif
#if 145<NUM_IRQS
		&NVICs::IRQ145,
#endif
#if 146<NUM_IRQS
		&NVICs::IRQ146,
#endif
#if 147<NUM_IRQS
		&NVICs::IRQ147,
#endif
#if 148<NUM_IRQS
		&NVICs::IRQ148,
#endif
#if 149<NUM_IRQS
		&NVICs::IRQ149,
#endif
#if 150<NUM_IRQS
		&NVICs::IRQ150,
#endif
#if 151<NUM_IRQS
		&NVICs::IRQ151,
#endif
#if 152<NUM_IRQS
		&NVICs::IRQ152,
#endif
#if 153<NUM_IRQS
		&NVICs::IRQ153,
#endif
#if 154<NUM_IRQS
		&NVICs::IRQ154,
#endif
#if 155<NUM_IRQS
		&NVICs::IRQ155,
#endif
#if 156<NUM_IRQS
		&NVICs::IRQ156,
#endif
#if 157<NUM_IRQS
		&NVICs::IRQ157,
#endif
#if 158<NUM_IRQS
		&NVICs::IRQ158,
#endif
#if 159<NUM_IRQS
		&NVICs::IRQ159,
#endif
#if 160<NUM_IRQS
		&NVICs::IRQ160,
#endif
#if 161<NUM_IRQS
		&NVICs::IRQ161,
#endif
#if 162<NUM_IRQS
		&NVICs::IRQ162,
#endif
#if 163<NUM_IRQS
		&NVICs::IRQ163,
#endif
#if 164<NUM_IRQS
		&NVICs::IRQ164,
#endif
#if 165<NUM_IRQS
		&NVICs::IRQ165,
#endif
#if 166<NUM_IRQS
		&NVICs::IRQ166,
#endif
#if 167<NUM_IRQS
		&NVICs::IRQ167,
#endif
#if 168<NUM_IRQS
		&NVICs::IRQ168,
#endif
#if 169<NUM_IRQS
		&NVICs::IRQ169,
#endif
#if 170<NUM_IRQS
		&NVICs::IRQ170,
#endif
#if 171<NUM_IRQS
		&NVICs::IRQ171,
#endif
#if 172<NUM_IRQS
		&NVICs::IRQ172,
#endif
#if 173<NUM_IRQS
		&NVICs::IRQ173,
#endif
#if 174<NUM_IRQS
		&NVICs::IRQ174,
#endif
#if 175<NUM_IRQS
		&NVICs::IRQ175,
#endif
#if 176<NUM_IRQS
		&NVICs::IRQ176,
#endif
#if 177<NUM_IRQS
		&NVICs::IRQ177,
#endif
#if 178<NUM_IRQS
		&NVICs::IRQ178,
#endif
#if 179<NUM_IRQS
		&NVICs::IRQ179,
#endif
#if 180<NUM_IRQS
		&NVICs::IRQ180,
#endif
#if 181<NUM_IRQS
		&NVICs::IRQ181,
#endif
#if 182<NUM_IRQS
		&NVICs::IRQ182,
#endif
#if 183<NUM_IRQS
		&NVICs::IRQ183,
#endif
#if 184<NUM_IRQS
		&NVICs::IRQ184,
#endif
#if 185<NUM_IRQS
		&NVICs::IRQ185,
#endif
#if 186<NUM_IRQS
		&NVICs::IRQ186,
#endif
#if 187<NUM_IRQS
		&NVICs::IRQ187,
#endif
#if 188<NUM_IRQS
		&NVICs::IRQ188,
#endif
#if 189<NUM_IRQS
		&NVICs::IRQ189,
#endif
#if 190<NUM_IRQS
		&NVICs::IRQ190,
#endif
#if 191<NUM_IRQS
		&NVICs::IRQ191,
#endif
#if 192<NUM_IRQS
		&NVICs::IRQ192,
#endif
#if 193<NUM_IRQS
		&NVICs::IRQ193,
#endif
#if 194<NUM_IRQS
		&NVICs::IRQ194,
#endif
#if 195<NUM_IRQS
		&NVICs::IRQ195,
#endif
#if 196<NUM_IRQS
		&NVICs::IRQ196,
#endif
#if 197<NUM_IRQS
		&NVICs::IRQ197,
#endif
#if 198<NUM_IRQS
		&NVICs::IRQ198,
#endif
#if 199<NUM_IRQS
		&NVICs::IRQ199,
#endif
#if 200<NUM_IRQS
		&NVICs::IRQ200,
#endif
#if 201<NUM_IRQS
		&NVICs::IRQ201,
#endif
#if 202<NUM_IRQS
		&NVICs::IRQ202,
#endif
#if 203<NUM_IRQS
		&NVICs::IRQ203,
#endif
#if 204<NUM_IRQS
		&NVICs::IRQ204,
#endif
#if 205<NUM_IRQS
		&NVICs::IRQ205,
#endif
#if 206<NUM_IRQS
		&NVICs::IRQ206,
#endif
#if 207<NUM_IRQS
		&NVICs::IRQ207,
#endif
#if 208<NUM_IRQS
		&NVICs::IRQ208,
#endif
#if 209<NUM_IRQS
		&NVICs::IRQ209,
#endif
#if 210<NUM_IRQS
		&NVICs::IRQ210,
#endif
#if 211<NUM_IRQS
		&NVICs::IRQ211,
#endif
#if 212<NUM_IRQS
		&NVICs::IRQ212,
#endif
#if 213<NUM_IRQS
		&NVICs::IRQ213,
#endif
#if 214<NUM_IRQS
		&NVICs::IRQ214,
#endif
#if 215<NUM_IRQS
		&NVICs::IRQ215,
#endif
#if 216<NUM_IRQS
		&NVICs::IRQ216,
#endif
#if 217<NUM_IRQS
		&NVICs::IRQ217,
#endif
#if 218<NUM_IRQS
		&NVICs::IRQ218,
#endif
#if 219<NUM_IRQS
		&NVICs::IRQ219,
#endif
#if 220<NUM_IRQS
		&NVICs::IRQ220,
#endif
#if 221<NUM_IRQS
		&NVICs::IRQ221,
#endif
#if 222<NUM_IRQS
		&NVICs::IRQ222,
#endif
#if 223<NUM_IRQS
		&NVICs::IRQ223,
#endif
#if 224<NUM_IRQS
		&NVICs::IRQ224,
#endif
#if 225<NUM_IRQS
		&NVICs::IRQ225,
#endif
#if 226<NUM_IRQS
		&NVICs::IRQ226,
#endif
#if 227<NUM_IRQS
		&NVICs::IRQ227,
#endif
#if 228<NUM_IRQS
		&NVICs::IRQ228,
#endif
#if 229<NUM_IRQS
		&NVICs::IRQ229,
#endif
#if 230<NUM_IRQS
		&NVICs::IRQ230,
#endif
#if 231<NUM_IRQS
		&NVICs::IRQ231,
#endif
#if 232<NUM_IRQS
		&NVICs::IRQ232,
#endif
#if 233<NUM_IRQS
		&NVICs::IRQ233,
#endif
#if 234<NUM_IRQS
		&NVICs::IRQ234,
#endif
#if 235<NUM_IRQS
		&NVICs::IRQ235,
#endif
#if 236<NUM_IRQS
		&NVICs::IRQ236,
#endif
#if 237<NUM_IRQS
		&NVICs::IRQ237,
#endif
#if 238<NUM_IRQS
		&NVICs::IRQ238,
#endif
#if 239<NUM_IRQS
		&NVICs::IRQ239
#endif
	} // irq
}; // vectors
