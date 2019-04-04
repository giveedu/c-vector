#ifndef GIVEEDU_C_VECTOR_H
#define GIVEEDU_C_VECTOR_H

#include <stdlib.h>
#include <string.h>

typedef struct __c_mem_pool {
	void* current;
	void* end;
	size_t size;
} mem_pool_t;

typedef struct _c_vector_item {
	size_t size;
	void* data;
} c_vector_item_t;

typedef struct _c_vector {
	mem_pool_t* memory;
	size_t len;
	size_t cap;
	c_vector_item_t* items;
} c_vector_t;


/*PUBLIC API*/
extern c_vector_t* c_vector_new(void);
/*PUBLIC API*/
extern void c_vector_del(c_vector_t* vec);

#endif
