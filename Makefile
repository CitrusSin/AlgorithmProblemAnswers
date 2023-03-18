CPP_FILES 	=	$(shell find . -name "*.cpp")
C_FILES		=	$(shell find . -name "*.c")

EXC_FILES	=	$(patsubst %.cpp, %, $(CPP_FILES)) $(patsubst %.c, %, $(C_FILES))

.PHONY: all clean

all: $(EXC_FILES)

clean:
	rm $(EXC_FILES)

%: %.cpp 
	g++ -O2 $^ -o $@

%: %.c
	gcc -O2 $^ -o $@ -lm