CXX = g++
CXXFLAGS = -O2 \
		   -Wall

name ?= 0

test: ./dist/${name}_test
	$<

./dist/%_test: ./dist %.cpp
	${CXX} $@.cpp ${CXXFLAGS} -o $<

./dist:
	mkdir dist
