# tzvirechel@gmail.com

CXX=clang++
CXXFLAGS=-std=c++11 -Werror
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

run: demo
	./$^

demo: demo.o
	$(CXX) $(CXXFLAGS) $^ -o demo

test: Test.o
	$(CXX) $(CXXFLAGS) $^ -o test	
	
demo.o: demo.cpp Tree.hpp Node.hpp
	$(CXX) $(CXXFLAGS) --compile demo.cpp -o demo.o

Test.o: Test.cpp Tree.hpp Node.hpp
	$(CXX) $(CXXFLAGS) --compile Test.cpp -o Test.o

valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

clean:
	rm -f *.o demo test
