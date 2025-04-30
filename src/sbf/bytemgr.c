#include "bytemgr.h"

void *bytecode_mgr(Thread *thread, int len)
{
	int i = 0;
	while (i < len) {
		switch (thread->task.content[thread->task.iter]) {
		case BYTEKIND_FUNCTION:
			int id = thread->task.content[++(thread->task.iter)];
			if (fmem_hasId(thread->fmem, id) == false) {
				Function f;
				f.id = id;
				f.contents.length = thread->task.content[++thread->task.iter];
				thread->fmem->loc[thread->fmem->count++] = f;
				thread->task.iter++;
			}
			break;
		case BYTEKIND_SET:
			thread->task.iter++;
			bytecode_mgr(thread, 2);
			break;
		case BYTEKIND_VAR:
			id = thread->task.content[++thread->task.iter];
			Variable *v = vmem_getById(&thread->vmem, id);
			if (v == NULL) {
				Variable v;
				if (thread->task.content[thread->task.iter - 2] == BYTEKIND_SET) {
					v.id = id;
					v.type =
						thread->task.content[++thread->task.iter];
					v.pos = mem_queryavailable(thread->mem, 1);
					if (v.pos > thread->mem->capacity-1) {
						v.pos = thread->mem->capacity-1;
					}
					if (v.pos < 0) v.pos = 0;
					thread->mem->loc[v.pos] = thread->task.content[thread->task.iter++];
					// if (vmem_hasId(thread, id) == false) {
					// }
				}
			} else
				return v;
			break;
		case BYTEKIND_LOOP:
			

		default:
			printf(	"[INTERNAL RUNTIME ERROR]: Unknown byte code %d!\nPlease create an issue on the github repository (https://github.com/NullifyDev/Sphere/issues)!\n", 
	 			   thread->task.content[thread->task.iter]
			);
			exit(1);
			break;
		}
		i++;
	}
	return NULL;
}
