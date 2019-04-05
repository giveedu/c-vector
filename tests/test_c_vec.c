#include "util-test.h"
/** 
 * Done to expose local macros + functions
 */
#include "c-vector.c"

static void test_c_vec_new_del(void)
{
	c_vector_t* vec = c_vector_new();
	TEST_CHECK_POINT(vec->len == 0);
	TEST_CHECK_POINT(vec->items != NULL);
	c_vector_del(vec);
}

static void test_c_vec_push(void)
{
	int foo = 7;
	c_vector_t* vec = c_vector_new();
	c_vector_push(vec, &foo, sizeof(int));
	TEST_CHECK_POINT(vec->len == 1);
	TEST_CHECK_POINT(vec->items[0].size == sizeof(int));
	TEST_CHECK_POINT(*(int*)(vec->items[0].data) == 7);
	c_vector_del(vec);
}

int main(int argc, char const *argv[])
{
	test_c_vec_new_del();
	test_c_vec_push();
	return 0;
}
