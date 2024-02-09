.DEFAULT_GOAL := all
browser=open

.PHONY: build
build: clean
	@g++ --std=c++20 --coverage -c implementation.cpp
	@g++ --std=c++20 --coverage -o test_implementation test_implementation.cpp implementation.o

.PHONY: test
test: build
	@./test_implementation

.PHONY: testcov
testcov: test
	@echo "building coverage html"
	@gcovr -r . --exclude doctest --exclude test_ --html-details -o coverage/
	@$(browser) coverage/coverage_details.html 

.PHONY: all
all: build testcov

.PHONY: example
example: clean
	@g++ --std=c++20 -c implementation.cpp
	@g++ --std=c++20 -o example main.cpp implementation.o
	@echo "1 2 3" | ./example

.PHONY: clean
clean:
	@rm -f ./*.gc?? ./*.o example test_implementation 

.PHONY: distclean
distclean: clean
	@rm -fr coverage 
