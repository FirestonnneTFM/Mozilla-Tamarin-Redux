// Initialization code for generated selftest code
#include "avmshell.h"
namespace avmplus {
#ifdef AVMPLUS_SELFTEST
#if defined AVMPLUS_SELFTEST
extern void create_avmplus_basics(AvmCore* core);
#endif
#if defined AVMPLUS_SELFTEST && defined AVMPLUS_PEEPHOLE_OPTIMIZER
extern void create_avmplus_peephole(AvmCore* core);
#endif
void SelftestRunner::createGeneratedSelftestClasses() {
#if defined AVMPLUS_SELFTEST
create_avmplus_basics(core);
#endif
#if defined AVMPLUS_SELFTEST && defined AVMPLUS_PEEPHOLE_OPTIMIZER
create_avmplus_peephole(core);
#endif
}
#endif // AVMPLUS_SELFTEST
}
