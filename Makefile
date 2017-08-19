CXX=clang++

main: main.cpp MdSpi.cpp tmp
	$(CXX) -std=c++11 -g -Wall -fPIC -pthread -Bsymbol -Wl,-rpath,\$$ORIGIN -I./include -L. -lthostmduserapi -ldl main.cpp MdSpi.cpp -o main

tmp:
	mkdir tmp

clean:
	rm -rf main tmp
