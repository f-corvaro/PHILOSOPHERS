# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorvaro <fcorvaro@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 19:08:53 by f-corvaro         #+#    #+#              #
#    Updated: 2024/06/17 22:37:59 by fcorvaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -- Output: Appereance ------------------------------------------------------ #

# Start and end sequences for color codes -- REMEMBER (add ; and m)
START = \033[
END = \033[0m

# ------------  FOREGROUND COLORS  ------------------------------------------- #
# Black, Red, Green, Yellow, Blue, Magenta, Cyan, White #
BK = 30
R = 31
G = 32
Y = 33
BE = 34
M = 35
C = 36
W = 37

# ------------  BACKGROUND COLORS  ------------------------------------------- #
# Black, Red, Green, Yellow, Blue, Magenta, Cyan, White #
BKK = 40
RR = 41
GG = 42
YY = 43
BEE = 44
MM = 45
CC = 46
WW = 47

# ------------  TEXT STYLES  ------------------------------------------------- #
# Bold text, Faint text, Italic text, Underlined text, Blinking text ...#
#... Reverse colors, Hidden text, Strikethrough text #
BOLD = 1
FAINT = 2
ITALIC = 3
UNDERLINE = 4
BLINKING = 5
REVERSE =7
HIDDEN = 8
STRIKE = 9

# ------------  INCLUDE HEADER FILES COMMAND  -------------------------------- #
INCLUDE	= -I./include/ 

# ------------  COMPILER COMMAND  -------------------------------------------- #
CC = gcc

# ------------  COMPILER FLAGS  ---------------------------------------------- #
CFLAGS = -Wall -Wextra -Werror

# ------------  PTHREAD FLAG  ------------------------------------------------ #
PTHREAD = -pthread

# ------------  REMOVE COMMAND  ---------------------------------------------- #
RM = rm -f

# ------------  SOURCES DIRECTORY  ------------------------------------------- #
SRCS_DIR = srcs

# ------------  OBJECTS DIRECTORY  ------------------------------------------- #
OBJS_DIR = objs

# ------------  BUILD FILE NAME  --------------------------------------------- #
BUILD = philo

# ------------  FULL PATH TO THE BUILD FILE  --------------------------------- #
NAME = $(BUILD)

# ------------  SOURCES FILES  ----------------------------------------------- #
SRCS = $(shell find $(SRCS_DIR) -name "*.c")

# ------------  OBJECT FILES  ------------------------------------------------ #
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

# ------------  OBJECTS DIRECTORY CREATION TARGET  --------------------------- #
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	@echo "$(START)$(BOLD);$(ITALIC);$(Y)mCompiling $< ...$(END)"
	@$(CC) $(CFLAGS) $(PTHREAD) -c $< -o $@ $(INCLUDE)
	
# ------------  INCLUDE DEPENDENCY FILES  ------------------------------------ #
-include $(OBJS_DIR)/*.d

# ------------  PHILO CREATION TARGET  --------------------------------------- #
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(PTHREAD) $(OBJS) -o $(NAME) $(INCLUDE) 
	@echo "$(START)$(BOLD);$(ITALIC);$(G)m Compilation of $(NAME) completed successfully!$(END)"
	@echo "$(START)$(BOLD);$(ITALIC);$(BE)m To run the program, use: ./$(BUILD) <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]$(END)"
	@echo "  - $(START)$(BOLD);$(ITALIC);$(Y)mnumber_of_philosophers$(END): The number of philosophers and also the number of forks."
	@echo "  - $(START)$(BOLD);$(ITALIC);$(Y)mtime_to_die$(END) (in milliseconds): If a philosopher didn’t start eating 'time_to_die' milliseconds since the beginning of their last meal or the beginning of the simulation, they die."
	@echo "  - $(START)$(BOLD);$(ITALIC);$(Y)mtime_to_eat$(END) (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks."
	@echo "  - $(START)$(BOLD);$(ITALIC);$(Y)mtime_to_sleep$(END) (in milliseconds): The time a philosopher will spend sleeping."
	@echo "  - $(START)$(BOLD);$(ITALIC);$(Y)mnumber_of_times_each_philosopher_must_eat$(END) (optional argument): If all philosophers have eaten at least 'number_of_times_each_philosopher_must_eat' times, the simulation stops. If not specified, the simulation stops when a philosopher dies."
	@echo "$(START)$(BOLD);$(ITALIC);$(M)m Author: fcorvaro$(END)"

# ------------  PHONY TARGETS  ----------------------------------------------- #
.PHONY : all clean fclean re bonus norm help usage

# ------------  DEFAULT TARGET  ---------------------------------------------- #
all: 
	@$(MAKE) -s $(NAME)

# ------------  CLEAN TARGET  ------------------------------------------------ #
clean:
	@if [ -d "$(OBJS_DIR)" ]; then \
		$(RM) -r $(OBJS_DIR); \
		echo "$(START)$(BOLD);$(ITALIC);$(G)m Cleaned up object files. $(OBJS_DIR) has been removed. $(END)"; \
	fi

# ------------  FCLEAN TARGET  ----------------------------------------------- #
fclean: clean
	@if [ -f "$(BUILD)" ]; then \
		$(RM) $(BUILD); \
		echo "$(START)$(BOLD);$(ITALIC);$(G)m Cleaned up executable file. $(BUILD) has been removed. $(END)"; \
	fi
	@$(RM) -r $(BUILD)

# ------------  RE TARGET  --------------------------------------------------- #
re : fclean
	@make -s all

# ------------  BONUS TARGET  ------------------------------------------------ #
bonus:
	@echo "$(START)$(BOLD);$(ITALIC);$(R)m--> The bonus is located in the directory ../philo_bonus, as specified in the project requirements.$(END)"

# ------------  HELP TARGET  ------------------------------------------------- #
help:
	@echo "  $(START)$(BOLD);$(ITALIC);$(G)mAvailable targets:$(END)"
	@echo "  make [command]"
	@echo ""
	@echo "  $(START)$(BOLD);$(Y)mall\t\tCompile the project$(END)"
	@echo "  $(START)$(BOLD);$(Y)mbonus\t\tDisplay the location of the bonus$(END)"
	@echo "  $(START)$(BOLD);$(Y)mclean\t\tRemove object files$(END)"
	@echo "  $(START)$(BOLD);$(Y)mfclean\tRemove object files and the executable$(END)"
	@echo "  $(START)$(BOLD);$(Y)mnorm\t\tCheck the code with Norminette$(END)"
	@echo "  $(START)$(BOLD);$(Y)mre\t\tRecompile the project$(END)"
	@echo "  $(START)$(BOLD);$(Y)mhelp\t\tDisplay this help message$(END)"
	@echo ""
	@echo "  $(START)$(BOLD);$(M)mProject Description:$(END)"
	@echo "  This project, known as 'Philosophers', is a classic concurrency problem"
	@echo "  implemented in C. The program simulates a number of philosophers sitting"
	@echo "  around a round table, each philosopher has a fork between them and the"
	@echo "  philosopher next to them. Each philosopher alternates between thinking,"
	@echo "  eating, and sleeping. A philosopher needs both forks to eat, and must"
	@echo "  put them down after eating. The challenge is to avoid deadlock and ensure"
	@echo "  that no philosopher goes without eating and dies."
	@echo "  The project demonstrates understanding of multithreading, mutexes,"
	@echo "  and semaphores."

# ------------  NORM TARGET  ------------------------------------------------- #
norm:
	@OUTPUT="$(shell norminette $(SRCS_DIR) include/ | grep -v OK)"; \
	if [ -z "$$OUTPUT" ]; then \
		echo "$(START)$(BOLD);$(ITALIC);$(G)m Norminette check: $(END)$(START)$(BOLD);$(ITALIC);$(G)m All files are OK! $(END)"; \
	else \
		echo "$(START)$(BOLD);$(ITALIC);$(R)m Norminette check: $(END)$(START)$(BOLD);$(ITALIC);$(R)m Errors found: \n$$OUTPUT $(END)"; \
	fi

# ------------  USAGE TARGET  ------------------------------------------------ #
usage:
	@echo "$(START)$(BOLD);$(ITALIC);$(R)m To run the program, use: ./$(BUILD) <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]$(END)"
	@echo "  - $(START)$(BOLD);$(ITALIC);$(Y)mnumber_of_philosophers$(END): The number of philosophers and also the number of forks."
	@echo "  - $(START)$(BOLD);$(ITALIC);$(Y)mtime_to_die$(END) (in milliseconds): If a philosopher didn’t start eating 'time_to_die' milliseconds since the beginning of their last meal or the beginning of the simulation, they die."
	@echo "  - $(START)$(BOLD);$(ITALIC);$(Y)mtime_to_eat$(END) (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks."
	@echo "  - $(START)$(BOLD);$(ITALIC);$(Y)mtime_to_sleep$(END) (in milliseconds): The time a philosopher will spend sleeping."
	@echo "  - $(START)$(BOLD);$(ITALIC);$(Y)mnumber_of_times_each_philosopher_must_eat$(END) (optional argument): If all philosophers have eaten at least 'number_of_times_each_philosopher_must_eat' times, the simulation stops. If not specified, the simulation stops when a philosopher dies."
	