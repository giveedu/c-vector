#include "util-test.h"
/** 
 * Done to expose local macros + functions
 */
#include "c-vector.c"

static void test_mem_pool_create(void)
{
	mem_pool_t* pool = mem_pool_create(50);
	size_t pool_size = MEM_POOL_SPACE(pool);
	TEST_CHECK_POINT(pool_size == 50);
	free(pool);
}


int main(int argc, char const *argv[])
{
	test_mem_pool_create();
	return 0;
}
