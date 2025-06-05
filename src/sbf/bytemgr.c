#include "bytemgr.h"

bool atEnd(Stack *t, unsigned int ahead) {
	Task *task = (Task*)stack_getTop(t);
	return (task->iter + ahead) >= task->length;
}

unsigned char peek(Stack *t, unsigned int ahead) {
	Task *task = (Task*)stack_getTop(t);
	return !atEnd(t, ahead) ? task->content[task->iter + ahead] : 0;
}

unsigned char *peek_ptr(Stack *t, unsigned int ahead) {
	Task *task = (Task*)stack_getTop(t);
	return !atEnd(t, ahead) ? &task->content[task->iter + ahead] : NULL;
}

unsigned char next(Stack *t, unsigned int ahead) {
	if (ahead < 1) ahead = 1;
	Task *task = (Task *)stack_getTop(t);

	task->iter = !atEnd(t, ahead) ? task->iter + ahead : task->iter;
	
	return task->content[task->iter];
}

unsigned char *next_ptr(Stack *t, unsigned int ahead) {
	if (ahead < 1) ahead = 1;
	Task *task = (Task *)stack_getTop(t);

	if(atEnd(t, ahead)) return NULL; 
	task->iter += ahead;
	
	return &task->content[task->iter];
}

// Should return NULL if an error occurred. 
void *bytecode_mgr(Thread *thread, unsigned int inst_count)
{
	Thread *t = thread;
	Task *task = (Task *)stack_getTop(t->task);
	unsigned int i = 0, j = 0, len = 0;
	unsigned char id = 0;
	while (i < inst_count) 
	{
		char curr = peek(t->task, 0);  
		switch (curr) 
		{
			case BYTEKIND_GET:
				next(t->task, 1);
				return bytecode_mgr(t, 1);
			case BYTEKIND_OUTLN:
				unsigned int end = 0;
				char c = next(t->task, 2);
				switch (c) 
				{
					case BYTEKIND_VAR:
						Variable *v = vmem_getById(t->vmem, next(t->task, 1)); 
						end = v->length + v->pos;
						j = v->pos;
						break;
					default:
						printf("unknown byte %d\n", c);
						return NULL;
				}

				while (j < end) 
				{
					printf("%c", t->mem->loc[j]);
					j++;
				}
				printf("\n");
				return value_newV(BYTEKIND_STATUS, 0);


			case BYTEKIND_OUT:
				len = next(t->task, 1);
				j = 0;
				while (j < len) {
					printf("%c", next(t->task, 1));
					j++;
				}
				next(t->task, 1);
				return value_newV(BYTEKIND_STATUS, 0);

			case BYTEKIND_MODULO:
				next(t->task, 1);
				printf("modulo: ");
				Value *one = bytecode_mgr(t, 1),
					  *two = bytecode_mgr(t, 1);
				
				return value_newV(BYTEKIND_INT, (*one->value % *two->value));
			
			/* REDUNDANT - bytecode_init() already does this
			case BYTEKIND_BLOCK:
				Block *blk = (Block *)calloc(1, sizeof(Block));

				blk->count = next(t->task, 1);
				blk->length = next(t->task, 1);

				unsigned int j = 0;
				unsigned char *insts = calloc(blk->length, sizeof(char));

				while (j < blk->length)
					insts[j++] = next(t->task, 1);

				blk->instructions = insts;
				next(t->task, 1);
				return blk;
			*/

			case BYTEKIND_INCR:
				switch (next(t->task, 1)) {

					case DATATYPE_INT:
					case DATATYPE_FLOAT:
					case DATATYPE_CHAR:
					case BYTEKIND_CALL:
					case BYTEKIND_ARR:
					case BYTEKIND_VAR:
						Value *obj = (Value*)bytecode_mgr(t, 1);

						if (atEnd(t->task, 0)) obj->value++;
						else 
						{
							switch (next(t->task, 1)) 
							{ 
								case DATATYPE_INT:
								case DATATYPE_CHAR:
								case DATATYPE_FLOAT:
								case BYTEKIND_CALL:
								case BYTEKIND_ARR:
								case BYTEKIND_VAR:
									obj->value += (int)next(t->task, 1);
									break;

								default:
									error_out(BYTEKIND_INCR | 2);
									break;
							}
						}
						break;
					
					default:
						error_out((BYTEKIND_INCR << 8) | 1);
						break;

				}
				break;
				

			case BYTEKIND_ARR: 
				ByteKind type = next(t->task, 1);
				if (peek(t->task, -1) == BYTEKIND_ARR) {
					int len = next(t->task, 1);
					char contents[len];
					
					for(j = 0; i < task->content[task->iter]; j++)
						 contents[j] = task->content[task->iter++];

					Value *val = value_new(type, len, contents);
					// next(t->task, 1);
					return val;
				}
			break;
			case BYTEKIND_CHAR:
			case BYTEKIND_FLOAT:
			case BYTEKIND_BOOL:
			case BYTEKIND_INT:
				Value * v = value_newV(peek(t->task, 0), next(t->task, 1));
				next(t->task, 1);
				return v;

			case BYTEKIND_CALL: 
				_func_run(t, next(t->task, 1));
				break;

			case BYTEKIND_FUNCTION:
				id = next(t->task, 1);
				if (!fmem_hasId(t->fmem, id) == false) 
				{
					printf("no such function %d\n", id);
				}
				break;
			
			case BYTEKIND_RET:
				return bytecode_mgr(t, task->content[task->iter]);

			case BYTEKIND_SET:
				next(t->task, 1);
				v = (Value*)bytecode_mgr(thread, 1);
				// v = (Value*)bytecode_mgr(thread, 1);
				// next(t->task, 1);
				Value * val = bytecode_mgr(thread, 1);
				v->value = val->value;
				value_free(v);
				value_free(val);
				break;

			case BYTEKIND_VAR:
				id = next(t->task, 1);
				Variable *var = vmem_getById(t->vmem, id);

				if (var == NULL) 
					error_out(BYTEKIND_VAR << 8 | 1);

				next(t->task, 1);
				return value_new(var->type, var->length, &t->mem->loc[var->pos]);

				// error_out(BYTEKIND_VAR << 8 | 2);
				break;
			case BYTEKIND_LOOP:
				next(t->task, 1);
				Block *cond = bytecode_mgr(t, 1),
					  *body = bytecode_mgr(t, 1);
				
				while ((bool)_block_run(t, cond) == true) 
				{
					_block_run(t, body);
				}
				break;
				
			case BYTEKIND_CMP:
				
				Value *lhs = _cmp_parseObj(t);
				Value *rhs = _cmp_parseObj(t);
				Value *con = _cmp_parseObj(t);
				// next(t->task, 1);

				if (peek(t->task, 1) == BYTEKIND_BLOCK) {
					if (peek(t->task, 2) == 0) 
					{ 
						next(t->task, 3);
						return value_newV(
							BYTEKIND_BOOL, 
							_cmp_compare(t, lhs, rhs, con)
						);
					}
					else if (_cmp_compare(t, lhs, rhs, con)) {
						next(t->task,1);
						bytecode_mgr(t, 1);
						return value_newV(BYTEKIND_STATUS, 0);
					}
				}
				
				return value_newV(BYTEKIND_BOOL, _cmp_compare(t,
					lhs,
					rhs, 
					con
				));
				
				break;

			default:
				if (atEnd(t->task, 1))
					return value_newV(BYTEKIND_STATUS, 0);

				printf(	"[INTERNAL RUNTIME ERROR]: Unknown bytecode %d at %d! stack depth iter: %d (#%d) | iter: %d \nPlease create an issue on the github repository (https://github.com/NullifyDev/Sphere/issues)!\n",
					task->content[task->iter],
					task->iter,
					t->task->count-1,
					t->task->count,
					task->iter
				);
				exit(1);
				break;
		}
		i++;
	}
	return value_newV(BYTEKIND_STATUS, 0);
}
