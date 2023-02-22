CC		= cc
AR		= ar
ARFLAGS	= crs
CFLAGS	= -Wall -Wextra -Werror

NAME = 		libftprintf.a

SRCS =		srcs/ft_atoi.c \
			srcs/ft_memset.c \
			srcs/ft_printf.c \
			srcs/ft_putnbr_fd.c \
			srcs/ft_strlen.c \
			srcs/print_char.c \
			srcs/print_dec.c \
			srcs/print_hex.c \
			srcs/print_int.c \
			srcs/print_ptr.c \
			srcs/print_str.c \
			srcs/print_uint.c \
			srcs/printf_utils.c \
			srcs/printf_utils2.c \
			srcs/printf_utils3.c \
			srcs/putaddress.c \
			srcs/puthex.c \
			srcs/putuint.c

B_SRCS =	bonus/ft_atoi_bonus.c \
			bonus/ft_memset_bonus.c \
			bonus/ft_printf_bonus.c \
			bonus/ft_putnbr_fd_bonus.c \
			bonus/ft_strlen_bonus.c \
			bonus/print_char_bonus.c \
			bonus/print_dec_bonus.c \
			bonus/print_hex_bonus.c \
			bonus/print_int_bonus.c \
			bonus/print_ptr_bonus.c \
			bonus/print_str_bonus.c \
			bonus/print_uint_bonus.c \
			bonus/printf_utils_bonus.c \
			bonus/printf_utils2_bonus.c \
			bonus/printf_utils3_bonus.c \
			bonus/putaddress_bonus.c \
			bonus/puthex_bonus.c \
			bonus/putuint_bonus.c

OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)

ifdef BONUS
	TARGET_OBJS = $(B_OBJS)
else
	TARGET_OBJS = $(OBJS)
endif

.PHONY: all
all : $(NAME)

$(NAME) : $(TARGET_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(TARGET_OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean :
	rm -f $(OBJS) $(B_OBJS)

.PHONY: fclean
fclean : clean
	rm -f $(NAME)

.PHONY: re
re :
	make fclean
	make all

.PHONY: bonus
bonus :
	make BONUS=0 all
