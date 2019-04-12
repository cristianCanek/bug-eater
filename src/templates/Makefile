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
#   make all     : Builds all the binaries for the code in this path.
#   make target1 : Builds the "target1" binary.
#   make target12: Builds the "target2" binary.
#   ...
#   make clean   : Deletes all the binaries on this path.

# List all the known targets.
TARGETS = target1 target2 ...

# Compiler to use.
CC = gcc

# Compiler flags.
CFLAGS = -Wall -g

# Build everything by default.
all : $(TARGETS)

# Build the target1 binary.
target1 : target1.c
	@echo "Building \"target1\" binary..."
	$(CC) $(CFLAGS) target1.c -o target1

# Build the target2 binary.
target2 : target2.c
	@echo "Building \"target2\" binary..."
	$(CC) $(CFLAGS) target2.c -o target2

# Delete all the binaries on this path.
clean :
	@echo "Removing binaries..."
	@rm -v $(TARGETS)
