CC = g++ -std=c++17
#CC = gcc -Wall -Werror -Wextra -std=c++17
# FLAGS = -lgtest -lm -lsubunit -lstdc++ -ftest-coverage -fprofile-arcs

OS = $(shell uname)
ifeq ($(OS), Linux)
FLAGS=`pkg-config --cflags --libs gtest` -lm -g
else
FLAGS= -lm -lgtest -g
endif

all: test

# s21_containersplus.a:
# 	$(CC) $(FLAGS) -c *.cc
# 	ar -crs s21_containersplus.a *.o 
# удалить ar -crs s21_containersplus.a *.o  зачем архив?

test: clean
	$(CC) tests/test.cc $(FLAGS) -o test
	./test

gcov_report:
	@$(MAKE) clean
	@$(MAKE) test FLAGS="--coverage $(FLAGS)"
	@gcovr --html-details ./gcov_report.html 
	@gcovr --xml ./cov.xml
	@xdg-open ./gcov_report.html

debug: clean
	$(MAKE) s21_containersplus.a >/dev/null
	$(CC) $(FLAGS) debug/*.cc -L. -l:s21_containersplus.a -o debug/debug.out -lstdc++ -lgtest -lgtest_main
	echo;debug/debug.out;echo;

valgrind: clean
	$(CC) tests/test.cc $(FLAGS) -o test
	valgrind  --tool=memcheck --track-fds=yes --trace-children=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./test
# valgrind  --tool=memcheck --leak-check=yes ./test

style:
	cp ../materials/linters/.clang-format .
	clang-format -n *.cc *.h
	clang-format -i *.cc *.h
	rm .clang-format

check:
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config *.h *.cc
	
clean:
	rm -rf *.o *.a test debug/debug.out *.out *.xml
	rm -rf *.gcno *gcda *.gcov gcov *.html *.css
	rm -rf report report.info
	@echo;echo "Clean complete";echo;
