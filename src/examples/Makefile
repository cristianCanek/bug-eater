################################################################################
#
# Copyright (c) 2019
# Bug Eater Development Team.
# All rights reserved.
#
# Developed by Cristian Campuzano (cristian_canek@hotmail.com).
#
################################################################################

# Usage:
#   make all         : Builds all the binaries for the code in this path.
#   make hello_world : Builds the "hello_world" binary.
#   make clean       : Deletes all the binaries on this path.

# List all the known targets.
TARGETS = hello_world

# Compiler to use.
CC = gcc

# Compiler flags.
CFLAGS = -Wall -g

# Build everything by default.
all : $(TARGETS)

# Build the "hello_world" binary.
hello_world : hello_world.c
	@echo "Building \"hello_world\" binary..."
	$(CC) $(CFLAGS) hello_world.c -o hello_world

# Delete all the binaries on this path.
clean :
	@echo "Removing binaries..."
	@rm -v $(TARGETS)
