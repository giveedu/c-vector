# testing cmake #

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})

ADD_EXECUTABLE(test_mem_pool test_mem_pool.c)
ADD_TEST(test_mem_pool test_mem_pool)
