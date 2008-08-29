/* tab-width: 4 */

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

typedef struct codestruct codestruct_t;
typedef struct trie trie_t;
typedef struct seq seq_t;

struct codestruct {
    unsigned int *code;
    unsigned int start;
    unsigned int limit;
    codestruct_t *next;
};

struct trie {
    unsigned int opcode;
    unsigned int count;
    trie_t *right_sibling;
    trie_t *left_child;
};

struct seq {
    unsigned int* data;
    unsigned int length;
    unsigned int count;
    int suffix;
};

enum {
    OP_bkpt=0x01,
    OP_throw=0x03,
    OP_getsuper=0x04,
    OP_setsuper=0x05,
    OP_dxns=0x06,
    OP_dxnslate=0x07,
    OP_kill=0x08,
    OP_ifnlt=0x0C,
    OP_ifnle=0x0D,
    OP_ifngt=0x0E,
    OP_ifnge=0x0F,
    OP_jump=0x10,
    OP_iftrue=0x11,
    OP_iffalse=0x12,
    OP_ifeq=0x13,
    OP_ifne=0x14,
    OP_iflt=0x15,
    OP_ifle=0x16,
    OP_ifgt=0x17,
    OP_ifge=0x18,
    OP_ifstricteq=0x19,
    OP_ifstrictne=0x1A,
    OP_lookupswitch=0x1B,
    OP_pushwith=0x1C,
    OP_popscope=0x1D,
    OP_nextname=0x1E,
    OP_hasnext=0x1F,
    OP_pushnull=0x20,
    OP_pushundefined=0x21,
    OP_nextvalue=0x23,
    OP_pushtrue=0x26,
    OP_pushfalse=0x27,
    OP_pushnan=0x28,
    OP_pop=0x29,
    OP_dup=0x2A,
    OP_swap=0x2B,
    OP_pushstring=0x2C,
    OP_pushdouble=0x2F,
    OP_pushscope=0x30,
    OP_pushnamespace=0x31,
    OP_hasnext2=0x32,
    OP_newfunction=0x40,
    OP_call=0x41,
    OP_construct=0x42,
    OP_callmethod=0x43,
    OP_callstatic=0x44,
    OP_callsuper=0x45,
    OP_callproperty=0x46,
    OP_returnvoid=0x47,
    OP_returnvalue=0x48,
    OP_constructsuper=0x49,
    OP_constructprop=0x4A,
    OP_callproplex=0x4C,
    OP_callsupervoid=0x4E,
    OP_callpropvoid=0x4F,
    OP_applytype=0x53,
    OP_newobject=0x55,
    OP_newarray=0x56,
    OP_newactivation=0x57,
    OP_newclass=0x58,
    OP_getdescendants=0x59,
    OP_newcatch=0x5A,
    OP_findpropstrict=0x5D,
    OP_findproperty=0x5E,
    OP_finddef=0x5F,
    OP_getlex=0x60,
    OP_setproperty=0x61,
    OP_getlocal=0x62,
    OP_setlocal=0x63,
    OP_getglobalscope=0x64,
    OP_getscopeobject=0x65,
    OP_getproperty=0x66,
    OP_getouterscope=0x67,
    OP_initproperty=0x68,
    OP_deleteproperty=0x6A,
    OP_getslot=0x6C,
    OP_setslot=0x6D,
    OP_getglobalslot=0x6E,
    OP_setglobalslot=0x6F,
    OP_convert_s=0x70,
    OP_esc_xelem=0x71,
    OP_esc_xattr=0x72,
    OP_convert_i=0x73,
    OP_convert_u=0x74,
    OP_convert_d=0x75,
    OP_convert_b=0x76,
    OP_convert_o=0x77,
    OP_checkfilter=0x78,
    OP_coerce=0x80,
    OP_coerce_b=0x81,
    OP_coerce_a=0x82,
    OP_coerce_i=0x83,
    OP_coerce_d=0x84,
    OP_coerce_s=0x85,
    OP_astype=0x86,
    OP_astypelate=0x87,
    OP_coerce_u=0x88,
    OP_coerce_o=0x89,
    OP_negate=0x90,
    OP_increment=0x91,
    OP_inclocal=0x92,
    OP_decrement=0x93,
    OP_declocal=0x94,
    OP_typeof=0x95,
    OP_not=0x96,
    OP_bitnot=0x97,
    OP_add=0xA0,
    OP_subtract=0xA1,
    OP_multiply=0xA2,
    OP_divide=0xA3,
    OP_modulo=0xA4,
    OP_lshift=0xA5,
    OP_rshift=0xA6,
    OP_urshift=0xA7,
    OP_bitand=0xA8,
    OP_bitor=0xA9,
    OP_bitxor=0xAA,
    OP_equals=0xAB,
    OP_strictequals=0xAC,
    OP_lessthan=0xAD,
    OP_lessequals=0xAE,
    OP_greaterthan=0xAF,
    OP_greaterequals=0xB0,
    OP_instanceof=0xB1,
    OP_istype=0xB2,
    OP_istypelate=0xB3,
    OP_in=0xB4,
    OP_increment_i=0xC0,
    OP_decrement_i=0xC1,
    OP_inclocal_i=0xC2,
    OP_declocal_i=0xC3,
    OP_negate_i=0xC4,
    OP_add_i=0xC5,
    OP_subtract_i=0xC6,
    OP_multiply_i=0xC7,
    OP_getlocal0=0xD0,
    OP_getlocal1=0xD1,
    OP_getlocal2=0xD2,
    OP_getlocal3=0xD3,
    OP_setlocal0=0xD4,
    OP_setlocal1=0xD5,
    OP_setlocal2=0xD6,
    OP_setlocal3=0xD7,
    OP_debugline=0xF0,
    OP_debugfile=0xF1,
    OP_bkptline=0xF2,
    OP_ext_pushbits=0x101,
    OP_ext_push_doublebits=0x102
};

#define LAST_INSTR    0x102
#define INSTRCOUNT    LAST_INSTR+1
#define DEF(name)     iname[name] = #name + 3

const char *progname;
codestruct_t codestructs[1000];
int wordsize = 4;
int nextcodestruct = 0;
trie_t toplevel[INSTRCOUNT];
int jumps[INSTRCOUNT];
const char *iname[INSTRCOUNT];
unsigned int ibuf[1000];
int cutoff = 100;
seq_t seqs[10000];
int nextseq = 0;

void read_code(const char* filename);
void read_samples(const char* filename);
void extract_superwords();
int fail(const char *s, ...);
int codestruct_cmp(const void *a, const void *b);
int pc_cmp(const void *a, const void *b);
int seq_cmp(const void *a, const void *b);
trie_t* new_trie_node(unsigned int opcode);
void descend(trie_t *t, int level);
void emit(int level, unsigned int count);
void *safemalloc(size_t nbytes);

int main(int argc, char** argv) 
{
    int i;

    for ( i=0 ; i < INSTRCOUNT ; i++ ) {
	toplevel[i].opcode = i;
	toplevel[i].count = 0;
	toplevel[i].left_child = NULL;
	toplevel[i].right_sibling = NULL;
	jumps[i] = 0;
	iname[i] = "***";
    }
    jumps[OP_throw] = 1;
    jumps[OP_ifnlt] = 1;
    jumps[OP_ifnle] = 1;
    jumps[OP_ifngt] = 1;
    jumps[OP_ifnge] = 1;
    jumps[OP_jump] = 1;
    jumps[OP_iftrue] = 1;
    jumps[OP_iffalse] = 1;
    jumps[OP_ifeq] = 1;
    jumps[OP_ifne] = 1;
    jumps[OP_iflt] = 1;
    jumps[OP_ifle] = 1;
    jumps[OP_ifgt] = 1;
    jumps[OP_ifge] = 1;
    jumps[OP_ifstricteq] = 1;
    jumps[OP_ifstrictne] = 1;
    jumps[OP_lookupswitch] = 1;
    jumps[OP_returnvoid] = 1;
    jumps[OP_returnvalue] = 1;

    DEF(OP_bkpt);
    DEF(OP_throw);
    DEF(OP_getsuper);
    DEF(OP_setsuper);
    DEF(OP_dxns);
    DEF(OP_dxnslate);
    DEF(OP_kill);
    DEF(OP_ifnlt);
    DEF(OP_ifnle);
    DEF(OP_ifngt);
    DEF(OP_ifnge);
    DEF(OP_jump);
    DEF(OP_iftrue);
    DEF(OP_iffalse);
    DEF(OP_ifeq);
    DEF(OP_ifne);
    DEF(OP_iflt);
    DEF(OP_ifle);
    DEF(OP_ifgt);
    DEF(OP_ifge);
    DEF(OP_ifstricteq);
    DEF(OP_ifstrictne);
    DEF(OP_lookupswitch);
    DEF(OP_pushwith);
    DEF(OP_popscope);
    DEF(OP_nextname);
    DEF(OP_hasnext);
    DEF(OP_pushnull);
    DEF(OP_pushundefined);
    DEF(OP_nextvalue);
    DEF(OP_pushtrue);
    DEF(OP_pushfalse);
    DEF(OP_pushnan);
    DEF(OP_pop);
    DEF(OP_dup);
    DEF(OP_swap);
    DEF(OP_pushstring);
    DEF(OP_pushdouble);
    DEF(OP_pushscope);
    DEF(OP_pushnamespace);
    DEF(OP_hasnext2);
    DEF(OP_newfunction);
    DEF(OP_call);
    DEF(OP_construct);
    DEF(OP_callmethod);
    DEF(OP_callstatic);
    DEF(OP_callsuper);
    DEF(OP_callproperty);
    DEF(OP_returnvoid);
    DEF(OP_returnvalue);
    DEF(OP_constructsuper);
    DEF(OP_constructprop);
    DEF(OP_callproplex);
    DEF(OP_callsupervoid);
    DEF(OP_callpropvoid);
    DEF(OP_applytype);
    DEF(OP_newobject);
    DEF(OP_newarray);
    DEF(OP_newactivation);
    DEF(OP_newclass);
    DEF(OP_getdescendants);
    DEF(OP_newcatch);
    DEF(OP_findpropstrict);
    DEF(OP_findproperty);
    DEF(OP_finddef);
    DEF(OP_getlex);
    DEF(OP_setproperty);
    DEF(OP_getlocal);
    DEF(OP_setlocal);
    DEF(OP_getglobalscope);
    DEF(OP_getscopeobject);
    DEF(OP_getproperty);
    DEF(OP_getouterscope);
    DEF(OP_initproperty);
    DEF(OP_deleteproperty);
    DEF(OP_getslot);
    DEF(OP_setslot);
    DEF(OP_getglobalslot);
    DEF(OP_setglobalslot);
    DEF(OP_convert_s);
    DEF(OP_esc_xelem);
    DEF(OP_esc_xattr);
    DEF(OP_convert_i);
    DEF(OP_convert_u);
    DEF(OP_convert_d);
    DEF(OP_convert_b);
    DEF(OP_convert_o);
    DEF(OP_checkfilter);
    DEF(OP_coerce);
    DEF(OP_coerce_b);
    DEF(OP_coerce_a);
    DEF(OP_coerce_i);
    DEF(OP_coerce_d);
    DEF(OP_coerce_s);
    DEF(OP_astype);
    DEF(OP_astypelate);
    DEF(OP_coerce_u);
    DEF(OP_coerce_o);
    DEF(OP_negate);
    DEF(OP_increment);
    DEF(OP_inclocal);
    DEF(OP_decrement);
    DEF(OP_declocal);
    DEF(OP_typeof);
    DEF(OP_not);
    DEF(OP_bitnot);
    DEF(OP_add);
    DEF(OP_subtract);
    DEF(OP_multiply);
    DEF(OP_divide);
    DEF(OP_modulo);
    DEF(OP_lshift);
    DEF(OP_rshift);
    DEF(OP_urshift);
    DEF(OP_bitand);
    DEF(OP_bitor);
    DEF(OP_bitxor);
    DEF(OP_equals);
    DEF(OP_strictequals);
    DEF(OP_lessthan);
    DEF(OP_lessequals);
    DEF(OP_greaterthan);
    DEF(OP_greaterequals);
    DEF(OP_instanceof);
    DEF(OP_istype);
    DEF(OP_istypelate);
    DEF(OP_in);
    DEF(OP_increment_i);
    DEF(OP_decrement_i);
    DEF(OP_inclocal_i);
    DEF(OP_declocal_i);
    DEF(OP_negate_i);
    DEF(OP_add_i);
    DEF(OP_subtract_i);
    DEF(OP_multiply_i);
    DEF(OP_getlocal0);
    DEF(OP_getlocal1);
    DEF(OP_getlocal2);
    DEF(OP_getlocal3);
    DEF(OP_setlocal0);
    DEF(OP_setlocal1);
    DEF(OP_setlocal2);
    DEF(OP_setlocal3);
    DEF(OP_debugline);
    DEF(OP_debugfile);
    DEF(OP_bkptline);
    DEF(OP_ext_pushbits);
    DEF(OP_ext_push_doublebits);

    progname = argv[0];

    i=1;
    while (i < argc && argv[i][0] == '-') {
	if (strcmp(argv[i], "-c") == 0) {
	    if (i+1 == argc || sscanf(argv[i+1], "%d", &cutoff) != 1) {
		i=argc;
		break;
	    }
	    i += 2;
	}
	else {
	    i = argc;
	    break;
	}
    }
 
    if (i > argc-2) {
	fprintf(stderr, "Usage: %s [options] code_file sample_file\n\n", progname);
	fprintf(stderr, "Options:\n");
	fprintf(stderr, "  -c n     Set sample cutoff = n (default 100)\n");
	return 1;
    }

    read_code(argv[i]);
    read_samples(argv[i+1]);
    extract_superwords();

    return 0;
}

/* First pass: read the code vectors */

void read_code(const char* filename)
{
    FILE *code_fp;
    unsigned int total_wordcount, numcodes;
    codestruct_t *codestruct;

    (code_fp = fopen(filename, "rb")) != NULL || fail("No such file: %s", filename);

    total_wordcount = 0;
    numcodes = 0;
    for (;;) {
	unsigned int start, limit, wordcount;
	unsigned int *codebuf;
	int res;

	if (fread(&start, sizeof(unsigned int), 1, code_fp) != 1) 
	    break;
	fread(&limit, sizeof(unsigned int), 1, code_fp) || fail("Could not read end");
	wordcount = (limit - start) / wordsize;
	total_wordcount += wordcount;
	codebuf = (unsigned int*)safemalloc(wordcount * sizeof(unsigned int));
	(res = fread(codebuf, sizeof(unsigned int), wordcount, code_fp)) == wordcount || fail("Could not read code vector: %08x %08x %d (%d) %d", start, limit, wordcount, numcodes, res);
	nextcodestruct < sizeof(codestructs)/sizeof(codestruct_t) || fail("Out of codestruct memory: %d", nextcodestruct);
	codestruct = &codestructs[nextcodestruct++];
	codestruct->code = codebuf;
	codestruct->start = start;
	codestruct->limit = limit;
	numcodes++;
    }

    fclose(code_fp);

    qsort(codestructs, nextcodestruct, sizeof(codestruct_t), codestruct_cmp);

    // debugging
    {
	int i;
	for ( i=0 ; i < nextcodestruct-1 ; i++ )
	    if (codestructs[i].start >= codestructs[i+1].start)
		fprintf(stderr, "ERROR!\n");
    }

    fprintf(stderr, "Number of code structs: %d\n", nextcodestruct);
    fprintf(stderr, "Words of code: %d\n", total_wordcount);
}

/* Second pass: read the execution records.  Maintain a trie that is
 * indexed by the opcode on the top level and where each sub-level is
 * a linked list of instructions along with execution counts and their
 * subtrees.  Also maintain an array of current positions in the trie:
 * for each new instruction we get to, a new entry is added to this
 * array so that we track the sequence starting at that instruction
 * too.
 */
void read_samples(const char* filename)
{
    static unsigned int bigbuf[1000000];
    FILE *sample_fp;
    unsigned int total_samples;
    unsigned int prev_pc;
    codestruct_t *prev_codestruct;
    trie_t* tracker[1000];
    int nexttracker;
    int trie_nodes = 0;
    int bigbuflim = 0;
    int bigbufptr = 0;

    (sample_fp = fopen(filename, "rb")) != NULL || fail("No such file: %s", filename);

    total_samples = 0;
    prev_codestruct = NULL;
    prev_pc = 0;
    nexttracker = 0;
    for (;;) {
	unsigned int pc, opcode, prev_opcode;
	codestruct_t *codestruct;

	if (bigbufptr == bigbuflim) {
	    int res;
	    res = fread(bigbuf, sizeof(unsigned int), sizeof(bigbuf)/sizeof(bigbuf[0]), sample_fp);
	    if (res <= 0)
		break;
	    bigbufptr = 0;
	    bigbuflim = res;
	}
	pc = bigbuf[bigbufptr++];
	total_samples++;
	codestruct = (codestruct_t*)bsearch(&pc, codestructs, nextcodestruct, sizeof(codestruct_t), pc_cmp);
	codestruct != NULL || fail("Could not find pc=%08x anywhere in code memory.", pc);
	opcode = codestruct->code[(pc - codestruct->start)/wordsize];
	if (prev_opcode == OP_getlocal && opcode == OP_getlocal)
	{
	    int i = 10;
	    (void)i;
	}

	if (opcode > 255)
	    opcode = 256 + (opcode >> 8);
	if (prev_codestruct != codestruct)
	    nexttracker = 0;
	else {
	    int i;
	    for ( i=0 ; i < nexttracker ; i++ ) {
		trie_t *t = tracker[i];
		if (t->left_child == NULL) {
		    t->left_child = new_trie_node(opcode);
		    ++trie_nodes;
		    tracker[i] = t->left_child;
		}
		else {
		    trie_t *t2 = t->left_child;
		    while (t2 != NULL && t2->opcode != opcode)
			t2 = t2->right_sibling;
		    if (t2 != NULL)
			t2->count++;
		    else {
			t2 = new_trie_node(opcode);
			++trie_nodes;
			t2->right_sibling = t->left_child;
			t->left_child = t2;
		    }
		    tracker[i] = t2;
		}
	    }
	    nexttracker < sizeof(tracker)/sizeof(tracker[0]) || fail("Out of tracker memory, probably a bug");
	}
	tracker[nexttracker++] = &toplevel[opcode];
	toplevel[opcode].count++;
	prev_codestruct = codestruct;
	prev_pc = pc;
	if (jumps[opcode]) 
	    nexttracker = 0;
	prev_opcode = opcode;
    }

    fclose(sample_fp);

    fprintf(stderr, "Samples processed: %d\n", total_samples);
    fprintf(stderr, "Trie nodes: %d\n", trie_nodes);
}

/* Third pass: extract all sequences and their execution counts.  We
 * walk the toplevel and then recur throughout each tree; if the count
 * at one level is less than the count at the previous level then one
 * sequence ended at the previous level but continues with the lower
 * count at this level.
 *
 * Discard sequences of length 1 (duh) and anything below the
 * user-settable cutoff.
 *
 * Every sequence that is a proper suffix of another sequence with the
 * same execution count is discarded too (subsumed by the longer
 * sequence).
 */
void extract_superwords()
{
    int i, j, ki, kj;

    for ( i=0 ; i < INSTRCOUNT ; i++ ) 
	descend(&toplevel[i], 0);

    qsort(seqs, nextseq, sizeof(seq_t), seq_cmp);

    for ( i=0 ; i < nextseq ; i++ ) {
	for ( j=i+1 ; j < nextseq && seqs[i].count == seqs[j].count ; j++ ) {
	    if (seqs[j].length < seqs[i].length) {
		for ( ki=seqs[i].length-1, kj=seqs[j].length-1 ; kj >= 0 && seqs[i].data[ki] == seqs[j].data[kj] ; ki--, kj-- )
		    ;
		if (kj < 0)
		    seqs[j].suffix = 1;
	    }
	}
    }

    for ( i=0 ; i < nextseq ; i++ ) {
	if (!seqs[i].suffix) {
	    printf("%d\t(", seqs[i].count);
	    for ( j=0 ; j < seqs[i].length ; j++ )
		printf("%s ", iname[seqs[i].data[j]]);
	    printf(")   ");
	    for ( j=0 ; j < seqs[i].length ; j++ )
		printf("%x ", seqs[i].data[j]);
	    printf("\n");
	}
    }
}

/* t is not NULL, and may or may not have children.  ibuf holds
 * instructions for parent nodes through level-1.  For each of t's
 * children, determine whether to emit an instruction sequence here
 * (if the count of child is lower than the count of t) or to continue
 * descending.  Only emit once.
 */
void descend(trie_t *t, int level)
{
    trie_t *t2, *t3;

    for ( t2=t ; t2 != NULL ; t2 = t2->right_sibling) {
	int emitted = 0;

	ibuf[level] = t2->opcode;

	if (t2->left_child == NULL) {
	    emit(level+1, t2->count);
	    continue;
	}

	for ( t3=t2->left_child ; t3 != NULL ; t3 = t3->right_sibling ) {
	    if (t3->count < t2->count && !emitted) {
		emitted = 1;
		emit(level+1, t2->count);
	    }
	}

	descend(t2->left_child, level+1);
    }
}

void emit(int level, unsigned int count)
{
    if (level > 1 && count >= cutoff) {
	nextseq < sizeof(seqs)/sizeof(seq_t) || fail("Out of seq memory.");
	seq_t *seq = &seqs[nextseq++];
	seq->data = (unsigned int*) safemalloc(sizeof(unsigned int) * level);
	seq->count = count;
	seq->length = level;
	seq->suffix = 0;
	memcpy(seq->data, ibuf, level*sizeof(unsigned int));
    }
}

trie_t* new_trie_node(unsigned int opcode)
{
    trie_t* t2 = (trie_t*)malloc(sizeof(trie_t));
    t2 != NULL || fail("allocation failure: trie_t");
    t2->opcode = opcode;
    t2->count = 1;
    t2->left_child = NULL;
    t2->right_sibling = NULL;
    return t2;
}

int seq_cmp(const void *a, const void *b)
{
    // descending by count, longest first
    int res = ((seq_t*)b)->count - ((seq_t*)a)->count;
    if (res != 0)
	return res;
    return ((seq_t*)b)->length - ((seq_t*)a)->length;
}

int codestruct_cmp(const void *a, const void *b)
{
    if (a == b)
	return 0;
    if (((codestruct_t*)a)->start < ((codestruct_t*)b)->start)
	return -1;
    return 1;
}

int pc_cmp(const void *a, const void *b) {
    unsigned int pc = *(unsigned int*)a;
    codestruct_t* elt = (codestruct_t*)b;
    if (pc >= elt->start && pc < elt->limit)
	return 0;
    if (pc < elt->start)
	return -1;
    return 1;
}

void *safemalloc(size_t nbytes)
{
    void *m = malloc(nbytes);
    m != NULL || fail("Allocation failure: %d", nbytes);
    return m;
}

int fail(const char *s, ...)
{
    va_list args;
    
    fprintf(stderr, "%s: ", progname);
    va_start(args, s);
    vfprintf(stderr, s, args);
    va_end(args);
    fprintf(stderr, "\n");
    exit(1);
    return 0;
}
