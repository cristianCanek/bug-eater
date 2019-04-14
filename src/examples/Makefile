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
#   make       : Builds all the binaries for the code in this path.
#   make all   : Builds all the binaries for the code in this path.
#   make clean : Deletes all the binaries on this path.

# Shell to use.
SHELL = /bin/sh

# Compiler to use.
CC = gcc

# User defined compiler settings.
CFLAGS = -Wall -g

# Output binary filenames.
TARGET = $(subst .c,,$(shell echo *.c))

# Build the target by default.
all : $(TARGET)

# Delete all the binaries on this path.
clean :
	@echo "Removing binaries..."
	@rm -f $(TARGET)
