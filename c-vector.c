#include "c-vector.h"


#define MEM_POOL_SIZEOF(pool) ((pool->end - pool->current) + sizeof(struct __c_mem_pool))

#define MEM_POOL_SPACE(pool) (pool->end - pool->current)

static mem_pool_t* 
mem_pool_create(size_t size)
{
	mem_pool_t* pool = malloc(sizeof(struct __c_mem_pool) + size);
	memset(pool, 0, sizeof(struct __c_mem_pool) + size);
	pool->size = size;
	pool->current = pool + sizeof(struct __c_mem_pool);
	pool->end = pool->current + size;
	return pool;
}

#define MEM_POOL_ALLOC(block, pool, bsize) do { \
	if(bsize > MEM_POOL_SPACE(pool)) { \
		size_t new_size = MEM_POOL_SIZEOF(pool) + (bsize * bsize); \
		size_t cur_occ = pool->size - sizeof(struct __c_mem_pool); \
		pool = realloc(pool, new_size); \
		pool->size = new_size; \
		pool->current = pool + cur_occ; \
		pool->end = pool->current + new_size;\
	} \
	block = pool->current; \
	pool->current += bsize; \
} while (0)

#define MEM_POOL_DESTROY(pool) free(pool)

#ifndef VEC_MEM_POOL_START
#define VEC_MEM_POOL_START 500
#endif // VEC_MEM_POOL_START

#ifndef VEC_ITEM_START
#define VEC_ITEM_START 20
#endif

static inline void
_c_vector_expand(c_vector_t* vec)
{
#ifdef C_VEC_EXPAND_2X
	vec->cap *= 2;
#else
	vec->cap *= (vec->cap);
#endif // C_VEC_EXPAND_2X
	vec->items = realloc(vec->items, vec->cap);
}

/*PUBLIC API*/
extern c_vector_t* c_vector_new(void)
{
	c_vector_t* vec = malloc(sizeof(struct _c_vector));
	vec->items = malloc(sizeof(struct _c_vector_item) * VEC_ITEM_START);
	vec->memory = mem_pool_create(VEC_MEM_POOL_START);
	vec->len = 0;
	vec->cap = VEC_ITEM_START;
	return vec;
}

extern void c_vector_del(c_vector_t* vec)
{
	MEM_POOL_DESTROY(vec->memory);
	free(vec->items);
	free(vec);
}
