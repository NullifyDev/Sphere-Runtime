#include "bytemgr.h"

void *bytecode_mgr(Thread *thread, int len)
{
	/* so Line 11 fucks up the address of a COMPLETELY unrelated pointer (mem->loc) to 0x1, somehow. And Line 8 is the solution??????? 
	WTAF is this Voodoo dogshit? THIS SHIT MAKES NO SENSE!!! 
	If anyone asks about the purpose of Line 8, read line 5 again and DONT @ ME! */
	Thread *t = thread;
	int i = 0;
	while (i < len) {
		switch (t->task.content[t->task.iter]) {
		case BYTEKIND_FUNCTION:
			int id = t->task.content[++(t->task.iter)];
			if (fmem_hasId(t->fmem, id) == false) {
				Function f;
				f.id = id;
				f.contents.length = t->task.content[++t->task.iter];
				t->fmem->loc[thread->fmem->count++] = f;
				t->task.iter++;
			}
			break;
		case BYTEKIND_SET:
			t->task.iter++;
			bytecode_mgr(thread, 2);
			break;
		case BYTEKIND_VAR:
			id = t->task.content[++t->task.iter];
			Variable *v = vmem_getById(&t->vmem, id);
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
