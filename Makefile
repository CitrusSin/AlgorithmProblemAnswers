CPP_FILES 	=	$(shell find . -name "*.cpp")
C_FILES		=	$(shell find . -name "*.c")

EXC_FILES	=	$(foreach f, $(patsubst %.cpp, %, $(CPP_FILES)) $(patsubst %.c, %, $(C_FILES)), ./build/$f)

.PHONY: all clean

all: $(EXC_FILES)

clean:
	rm -r build/*

build/%: %.cpp
	- mkdir -p $@
	- rmdir $@
	gcc -O2 $^ -o $@ -lm -lstdc++

build/%: %.c
	- mkdir -p $@
	- rmdir $@
	gcc -O2 $^ -o $@ -lm