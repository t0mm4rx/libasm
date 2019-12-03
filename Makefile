OS = $(shell uname)

TARGET = libasm.a
TEST_BIN = test_bin

COMP = nasm -fmacho64
ifeq ($(OS), Linux)
COMP = nasm -felf64
endif

SRCS = $(wildcard ./src/*)
OBJS_TEMP = $(subst ./src/,./obj/,$(SRCS))
OBJS = $(OBJS_TEMP:.s=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	ar rcs $(TARGET) $(OBJS)

./obj/%.o: ./src/%.s
	mkdir -p ./obj
	$(COMP) $< -o $@

clean:
	rm -rf obj/*

fclean: clean
	rm -rf $(TARGET) $(TEST_BIN)

re: fclean all

test: $(TARGET)
	gcc -g3 -fsanitize=address -L. -lasm main.c -o $(TEST_BIN)
	./$(TEST_BIN)
