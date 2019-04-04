#include "c-vector.h"

#ifdef MEM_POOL_E_EXPAND
#endif

#define MEM_POOL_SIZEOF(pool) ((pool->end - pool->current) + sizeof(struct __c_mem_pool))

#define MEM_POOL_SPACE(pool) (pool->end - pool->current)

static mem_pool_t* 
mem_pool_create(size_t size)
{
	mem_pool_t* pool = malloc(sizeof(struct __c_mem_pool) + size);
	memset(pool, 0, sizeof(struct __c_mem_pool) + size);
	pool->current = pool + sizeof(struct __c_mem_pool);
	pool->end = pool->current + size;
	return pool;
}

#define MEM_POOL_ALLOC(block, pool, bsize) do { \
	if(bsize > MEM_POOL_SPACE(pool)) { \
		size_t new_size = MEM_POOL_SIZEOF(pool) + bsize; \
		size_t cur_occ = pool->current - sizeof(struct __c_mem_pool); \
		pool = realloc(pool, new_size); \
		pool->current = pool + cur_occ; \
		pool->end = pool->current + new_size;\
	} \
	block = pool->current; \
	pool->current += bsize; \
} while (0)




