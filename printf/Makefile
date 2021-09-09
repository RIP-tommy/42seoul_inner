NAME		:= libftprintf.a

INC_DIR 	:= ./inc
SRCS_DIR 	:= ./src
BUILD_DIR 	:= ./build

CC 			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

AR			:= ar -cr
RM			:= rm -rf

SRCS		:= $(shell find $(SRCS_DIR) -name \*.c)

FILES		:= $(notdir $(SRCS))
OBJS		:= $(patsubst %.c,$(BUILD_DIR)/%.o,$(FILES))

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
