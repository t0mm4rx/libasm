OS = $(shell uname)

TARGET = libasm.a
TEST_BIN = test_bin
TEST_BIN_BONUS = test_bin_bonus

COMP = nasm -fmacho64
ifeq ($(OS), Linux)
COMP = nasm -felf64
endif

SRCS =	./src/ft_read.s \
	./src/ft_strcmp.s \
	./src/ft_strcpy.s \
	./src/ft_strdup.s \
	./src/ft_strlen.s \
	./src/ft_write.s
OBJS_TEMP = $(subst ./src/,./obj/,$(SRCS))
OBJS = $(OBJS_TEMP:.s=.o)

SRCS_BONUS =	./src/ft_list_size.s \
		./src/ft_atoi_base.s \
		./src/ft_list_push_front.s \
		./src/ft_list_sort.s \
		./src/ft_list_remove_if.s
OBJS_TEMP_BONUS = $(subst ./src/,./obj/,$(SRCS_BONUS))
OBJS_BONUS = $(OBJS_TEMP_BONUS:.s=.o)

all: $(TARGET)

bonus: target_bonus

$(TARGET): $(OBJS)
	ar rcs $(TARGET) $(OBJS)

target_bonus: $(OBJS) $(OBJS_BONUS)
	ar rcs $(TARGET) $(OBJS) $(OBJS_BONUS)


./obj/%.o: ./src/%.s
	mkdir -p ./obj
	$(COMP) $< -o $@

clean:
	rm -rf obj/*

fclean: clean
	rm -rf $(TARGET) $(TEST_BIN) $(TEST_BIN_BONUS)

re: fclean all

test: $(TARGET)
	gcc -Wall -Wextra -Werror -c main.c -o main.o
	gcc -Wall -Wextra -Werror -g3 -fsanitize=address main.o -L. -lasm -o $(TEST_BIN)
	rm -rf main.o
	./$(TEST_BIN) < .gitignore

testb: bonus
	gcc -Wall -Wextra -Werror -c main_bonus.c -o main_bonus.o
	gcc -Wall -Wextra -Werror -g3 -fsanitize=address main_bonus.o -L. -lasm -o $(TEST_BIN_BONUS)
	rm -rf main_bonus.o
	./$(TEST_BIN_BONUS)
