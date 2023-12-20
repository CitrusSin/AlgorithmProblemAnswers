CC			=	clang

CPP_FILES 	=	$(shell find . -name "*.cpp")
C_FILES		=	$(shell find . -name "*.c")

EXC_FILES	=	$(foreach f, $(patsubst %.cpp, %, $(CPP_FILES)) $(patsubst %.c, %, $(C_FILES)), ./build/$f)

.PHONY: all
all: $(EXC_FILES)

.PHONY: clean
clean:
	rm -r build/*

build/%: %.cpp
	- mkdir -p $@
	- rmdir $@
	$(CC) -O2 -std=gnu++20 $^ -o $@ -lm -lstdc++

build/%: %.c
	- mkdir -p $@
	- rmdir $@
	$(CC) -O2 $^ -o $@ -lm

.PHONY: run/%
run/%: build/%
	$^