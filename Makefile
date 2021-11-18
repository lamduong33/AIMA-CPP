##
# AI: A Modern Approach- C++
# Author: Lam Duong
#
# Compiler setup
CXXFLAGS = -std=c++20 -g -Wall -I $(INCDIR)
CXX = clang++

# Directory setup
INCDIR := include
SRCDIR := src
BINDIR := bin
TESTDIR := test

TARGET = AIMACPP
TESTS = Tests
SRCFILES = $(SRCDIR)/*.cpp
INCFILES = $(INCDIR)/*.hpp

all: $(TARGET)
$(TARGET): $(SRCDIR)/$(TARGET).cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCFILES)
test: $(TESTS)
$(TESTS): $(TESTDIR)/$(TESTS).cpp
	$(CXX) $(TESTDIR)/$(TESTS).cpp -o $(TESTS) $(SRCDIR)/*.cpp
clean:
	$(RM) $(TARGET)
	$(RM) $(TESTS)

# end
