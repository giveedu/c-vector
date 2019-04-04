cmake_minimum_required(VERSION 3.5)

# Project for c-vector library #
PROJECT(c-vector)

ADD_DEFINITIONS(-DVEC_MEM_POOL_START=500 -DVEC_ITEM_START=20)

SET(c-vector-sources
   c-vector.c
)

ADD_LIBRARY(GiveEduVec STATIC "${c-vector-sources}")
ADD_LIBRARY(GiveEduVecD SHARED "${c-vector-sources}")

enable_testing()
ADD_SUBDIRECTORY(tests)


string(TIMESTAMP c_vector_build_time)
