#include "c-vector.h"

typedef struct __c_mem_pool {
	void* current;
	void* end;
} mem_pool_t;

#define MEM_POOL_SIZEOF(pool) ((pool->end - pool->current) + sizeof(struct __c_mem_pool))

static mem_pool_t* 
mem_pool_create(size_t size)
{
	mem_pool_t* pool = malloc(sizeof(struct __c_mem_pool) + size);
	memset(pool, 0, sizeof(struct __c_mem_pool) + size);
	pool->current = pool + sizeof(struct __c_mem_pool);
	pool->end = pool->current + size;
	return pool;
}
