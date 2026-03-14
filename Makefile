LIB_NAME = libasm.a
NAME = libasm_test

NA = nasm
NA_FLAGS = -f elf64
AR = ar
AR_FLAGS = rcs
GCC = gcc
GCC_FLAGS = -Wall -Wextra -Werror

SRCS = ft_strlen.s
OBJS = $(SRCS:.s=.o)


all: $(SRCS)
	@echo "                                     "
	@echo "# - - - - - - - - - - - - - - - - - #"
	@echo "# - - - - - - - A L L - - - - - - - #"
	@echo "# - - - - - - - - - - - - - - - - - #"
	@echo "                                     "

	$(NA) $(NA_FLAGS) $(SRCS)
	$(AR) $(AR_FLAGS) $(LIB_NAME) $(OBJS)
	ranlib $(LIB_NAME)


test: $(LIB_NAME)
	@echo "                                     "
	@echo "# - - - - - - - - - - - - - - - - - #"
	@echo "# - - - - - - T E S T - - - - - - - #"
	@echo "# - - - - - - - - - - - - - - - - - #"
	@echo "                                     "

	$(GCC) $(GCC_FLAGS) -L. -lasm -o $(NAME) main.c
	
	@echo "./$(NAME)"
	@echo "                                     "
	@echo "                                     "
	@./$(NAME)

clean:
	@echo "                                     "
	@echo "# - - - - - - - - - - - - - - - - - #"
	@echo "# - - - - - - C L E A N - - - - - - #"
	@echo "# - - - - - - - - - - - - - - - - - #"
	@echo "                                     "
	@echo "rm -f $(LIB_NAME)"
	@rm -f $(LIB_NAME)
	@echo "rm -f $(NAME)"
	@rm -f $(NAME)
	@echo "rm -f $(OBJS)"
	@rm -f $(OBJS)

re: clean all
