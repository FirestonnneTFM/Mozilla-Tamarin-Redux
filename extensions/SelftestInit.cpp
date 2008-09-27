// Initialization code for generated selftest code
#include "avmplus.h"
namespace avmplus {
#ifdef AVMPLUS_SELFTEST
void SelftestRunner::createGeneratedSelftestClasses() {
#if defined AVMPLUS_SELFTEST
extern void create_avmplus_basics(AvmCore* core);
create_avmplus_basics(core);
#endif
#if defined AVMPLUS_SELFTEST && defined AVMPLUS_PEEPHOLE_OPTIMIZER
extern void create_avmplus_peephole(AvmCore* core);
create_avmplus_peephole(core);
#endif
}
#endif
}
