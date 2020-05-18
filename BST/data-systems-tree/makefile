  # the compiler: gcc for C program, define as g++ for C++
  CC = g++

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -g -Wall

  INCLUDES = -I../

  # the build target executable:
  TARGET = main

  all: $(TARGET)

  $(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS)  $(INCLUDES) -o tester.out $(TARGET).cpp
  clean:
	$(RM) -rf *.o *.out *.dSYM
#

# case 1 has no children
# - no reconecting of child nodes, possible that there is a parent node
# case 2 had left only
#  - connect left child to currect location
# case 4 has right child only
# has both left and right