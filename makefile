# 1. Compiler and Flags
CC = gcc
CFLAGS = -g -Wall -Wextra
# Tell the compiler to look for headers in the 'include' directory
CPPFLAGS = -Iinclude
# Add any libraries you need to link, e.g., -lm for math
LDFLAGS = 

# 2. Directories
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

# 3. Project Files
# The name of your final executable
TARGET = eco

# Use 'wildcard' to automatically find all .c files in the src dir
SRCS = $(wildcard $(SRC_DIR)/*.c)

# This is a cool substitution rule.
# It takes the list of .c files (e.g., "src/main.c src/helper.c")
# and replaces their names to point to the .o files in the obj dir
# (e.g., "obj/main.o obj/helper.o")
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# 4. The Rules

# The default 'all' rule
all: $(TARGET)

# Link the final program
# '$^' is an automatic variable for "all dependencies" (all the .o files)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# This is the new pattern rule.
# It says "to make a file like 'obj/%.o', you need the file 'src/%.c'"
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# 5. Clean-Up Rule
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
	rm -f $(TARGET)