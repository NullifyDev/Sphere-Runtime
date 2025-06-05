#include "bytecode_init.h"
#include "bytemgr.h"
#include "datatypes.h"
#include "parser/datatype/value.h"
/* Loads instructions to memory by loading instruction blocks,
 * providing their pointers to the object in question for execution, 
 * while loading objects into their respective memory
 *
 * All this ONLY WHEN THE OBJECT IS REFERENCED
 */
void *bytecode_init(Thread *t, unsigned int inst_count) 
{
    unsigned int i = 0, id, j = 0, k = 0;
    while (i < inst_count) 
    {
		if (atEnd(t->task, 0)) return NULL;
        char curr = peek(t->task, 0);
		Task *task = (Task*)stack_getTop(t->task);
        switch (curr) 
        {
			case BYTEKIND_RET:
				return value_newV(next(t->task, 1), next(t->task, 1));
            case BYTEKIND_FUNCTION:
                id = next(t->task, 1);
				if (fmem_hasId(t->fmem, id) == false) 
				{
					next(t->task, 1);
					Function * f = &t->fmem->loc[t->fmem->count];

					f = func_new(t, id, (Block*)bytecode_init(t, 1));
					if (f == NULL) break;
					
					// printf("\033[1m\033[38;2;0;255;255m[NEW FUNCTION!]\033[0m %d | ", f->id);
					
					// for (j = 0; j < f->contents->length; j++)
					// 	printf("%d ", f->contents->instructions[j]);

					// printf("\n");

					next(t->task, 1);
					t->fmem->count++;
				}
                break;
			case BYTEKIND_SET:
				char byte = next(t->task, 1);
				switch (byte) 
				{
					case BYTEKIND_VAR:
						Variable *var = bytecode_init(t, 1);

						unsigned char ty = next(t->task, 1);
						if (var->type != ty + 4) 
						{
							printf("variable %d is %s not %s\n", var->id, datatype_getDataType(var->type), datatype_getDataType(ty));
						}

						unsigned int p = var->pos,
									valLen = next(t->task, 1);
						
						while (p < var->length && p < valLen) {
							t->mem->loc[p++] = next(t->task, 1);
						}
				}
				next(t->task, 1);
				break;
            case BYTEKIND_VAR:
				char dtype = next(t->task, 1);
				
				switch (dtype) 
				{
					case DATATYPE_FLOAT:
					case DATATYPE_INT:
					case DATATYPE_CHAR:
					case DATATYPE_BOOL:
						Variable *var = &t->vmem->loc[t->vmem->count++];
						
						var->type = dtype;
						var->id = next(t->task, 1);
						var->isNull = false;
						var->pos = mem_queryavailable(t->mem, 1);
						var->length = next(t->task, 1);
					
						if (var->pos >= t->mem->capacity) var->pos = t->mem->capacity-1;

                        return &var->id;
                    default: break;
                }
                break;
            case BYTEKIND_BLOCK:
                
				unsigned int count = next(t->task, 1),
							 length  = next(t->task, 1);

				if (count == 0 || length == 0) {
                    next(t->task, 1);
                    return 0;
                }

                Block *blk = block_new(t->bmem->count++, count, length);

                // blk->id = t.
				blk->instructions = calloc(blk->length, sizeof(unsigned char));
				// unsigned char *inst = blk->instructions;
				unsigned char *inst = blk->instructions;

				j = 0, k = 0;
				volatile bool loop = true;
				while (loop && !atEnd(t->task, 1) && j < blk->length) {
					char c = next(t->task, 1);
					switch (c) 
					{
						case BYTEKIND_SET:
							bytecode_init(t, 1);
							k++;
							break;
						case BYTEKIND_BLOCK:
						case BYTEKIND_VAR:
							inst[j++] = c;
							break;
						case BYTEKIND_RET:
							Value *ret = (Value *)bytecode_init(t, 1);
							if (ret->type == DATATYPE_VOID) 
							{
								loop = false;
								continue;
							}
							task->returnAddress = ret;
							continue;
					}
					
					inst[j++] = *(char *)bytecode_init(t, 1);
                }
				blk->length = j;
				blk->count -= k;

                bmem_add(t->bmem, blk);
                next(t->task, 1);
				return &blk->id;

            default:
				// next(t->task, 1);
				task = (Task *)stack_getTop(t->task);
				if (task->iter >= task->length) return NULL;
                return &curr;
        }

    }
    return NULL;
}