CC = g++ -std=c++17 
# FLAGS = -lgtest -lm -lsubunit -lstdc++ -ftest-coverage -fprofile-arcs

OS = $(shell uname)
ifeq ($(OS), Linux)
GTESTFLAGS=`pkg-config --cflags --libs gtest` -lm -g
else
GTESTFLAGS= -lm -lgtest -g
endif

FLAGS = -Wall -Werror -Wextra $(GTESTFLAGS)

all: test

# s21_containersplus.a:
# 	$(CC) $(FLAGS) -c *.cc
# 	ar -crs s21_containersplus.a *.o 
# удалить ar -crs s21_containersplus.a *.o  # архив

test: clean
	$(CC) tests/*.cc $(FLAGS) -o test
	./test

gcov_report:
	@$(MAKE) clean
	@$(MAKE) test FLAGS="--coverage $(FLAGS)"
	@gcovr --html-details ./gcov_report.html 
	@gcovr --xml ./cov.xml
	@xdg-open ./gcov_report.html

debug: clean
	$(CC) $(FLAGS) debug/*.cc -o debug/debug.out
	echo;debug/debug.out;echo;

val: clean
	$(CC) tests/*.cc $(FLAGS) -o test
	valgrind  --tool=memcheck --track-fds=yes --trace-children=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./test
# valgrind  --tool=memcheck --leak-check=yes ./test

style:
	cp ../materials/linters/.clang-format .
	find . \( -name '*.cc' -o -name '*.h' \) -exec clang-format -n {} \;
	find . \( -name '*.cc' -o -name '*.h' \) -exec clang-format -i {} \;
	rm -rf .clang-format

check:
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config *.h *.cc
	
clean:
	rm -rf *.o *.a test debug/debug.out *.out *.xml
	rm -rf *.gcno *gcda *.gcov gcov *.html *.css
	rm -rf report report.info
	@echo;echo "Clean complete";echo;
