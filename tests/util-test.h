#ifndef CVEC_UTIL_TEST_H
#define CVEC_UTIL_TEST_H

#include <stdio.h>
#include <stdlib.h>

#define TEST_FAILURE_EXIT_CODE 3

#define TEST_CHECK_POINT(expression) \
                   if(!(expression)) { \
                   	    fprintf(stderr, "FAILURE: File: %s, Line: %u, Expression: %s\n", __FILE__, __LINE__, #expression); \
                   	    exit(TEST_FAILURE_EXIT_CODE); \
                   }

#endif // CVEC_UTIL_TEST_H
