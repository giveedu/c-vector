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

static void test_mem_pool_alloc1(void)
{
	size_t before;
	size_t after;
	void* chunk;
	mem_pool_t* pool = mem_pool_create(50);
	before = MEM_POOL_SPACE(pool);
	MEM_POOL_ALLOC(chunk, pool, 5);
	after = MEM_POOL_SPACE(pool);
	TEST_CHECK_POINT(before == 50);
	TEST_CHECK_POINT(after == 45);
	free(pool);
}

static void test_mem_pool_alloc2(void)
{
	size_t before;
	size_t after;
	void* chunk;
	mem_pool_t* pool = mem_pool_create(50);
	before = MEM_POOL_SPACE(pool);
	MEM_POOL_ALLOC(chunk, pool, 70);
	after = MEM_POOL_SPACE(pool);
	TEST_CHECK_POINT(before == 50);
	TEST_CHECK_POINT(after == 45);
	free(pool);
}


int main(int argc, char const *argv[])
{
	test_mem_pool_create();
	test_mem_pool_alloc1();
	return 0;
}
