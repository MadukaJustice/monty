#include "monty.h"
#define VOIDED(x)(((void) (x)))

/**
 * load_opcodes - loads the necessary opcodes in a array
 * @opcodes: The array to load into
 * @size: the size of the array
 */
void load_opcodes(instruction_t opcodes[], int size)
{
	/*
	 * the size of the array if to know how many opcodes to load
	 * but the opcodes are to be loaded manually, not in a loop
	 */
	instruction_t op;

	VOIDED(size);
	op.opcode = "push";
	op.f = push;
	opcodes[0] = op;

	op.opcode = "add";
	op.f = add;
	opcodes[1] = op;

	op.opcode = "pall";
	op.f = pall;
	opcodes[2] = op;

	op.opcode = "pint";
	op.f = pint;
	opcodes[3] = op;

	op.opcode = "pop";
	op.f = pop;
	opcodes[4] = op;

	op.opcode = "swap";
	op.f = swap;
	opcodes[5] = op;

	op.opcode = "nop";
	op.f = nop;
	opcodes[6] = op;
}
