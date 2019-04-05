#ifndef GIVEEDU_C_VECTOR_H
#define GIVEEDU_C_VECTOR_H

#include <stdlib.h>
#include <string.h>
/**
 * Small memory pool struct,
 * basically keeps track of available memory region and
 * the total size.
 */
typedef struct __c_mem_pool {
	void* current;
	void* end;
	size_t size;
} mem_pool_t;
/**
 * represents a single item inside the larger vector struct.
 */
typedef struct _c_vector_item {
	size_t size;
	void* data;
} c_vector_item_t;
/**
 * A heterogenous vector data structure, meant to have constant time
 * random access, pushing, and popping. 
 */
typedef struct _c_vector {
	mem_pool_t* memory;
	size_t len;
	size_t cap;
	c_vector_item_t* items;
} c_vector_t;


/*PUBLIC API*/
/**
 * Creates a new vector with a default mem pool and item capacity.
 * Can be destroyed by calling c_vector_del().
 */
extern c_vector_t* c_vector_new(void);
/*PUBLIC API*/
/**
 * This pushes a new item onto the end of the vector.
 * Calling this does not incur a new memory allocation,
 * new memory is onyl allocated when the item length 
 * reaches capacity, or the memory pool becomes used up.
 */
extern void c_vector_push(c_vector_t* vec, void* item, size_t item_size);
/**
 * PUBLIC API
 * The append macro differs from the push function in that it is 
 * intended to be used on literal objects and not a pointer.
 */
#define C_VECTOR_APPEND(vec, obj) c_vector_push(vec, &obj, sizeof(obj))
/**
 * PUBLIC API
 * The pop method returns a pointer to the last item in the vec,
 * and then removes it from the vec. The pointer points to a location within the memory
 * pool assoiciated with the vector. The vec retains ownership of it, and will be destroyed
 * automatically.
 */
extern void* c_vector_pop(c_vector_t* vec);
/*PUBLIC API*/
extern void* c_vector_at(c_vector_t* vec, size_t index);
/*PUBLIC API*/
extern void c_vector_del(c_vector_t* vec);

#endif
