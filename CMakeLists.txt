cmake_minimum_required(VERSION 3.5)

# Project for c-vector library #
PROJECT(c-vector)

SET(c-vector-sources
   c-vector.c
)

ADD_LIBRARY(GiveEduVec STATIC "${c-vector-sources}")
ADD_LIBRARY(GiveEduVec SHARED "${c-vector-sources}")


string(TIMESTAMP c_vector_build_time)
