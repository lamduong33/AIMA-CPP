##
# AI: A Modern Approach- C++
# Author: Lam Duong
#
# Compiler setup
CXXFLAGS = -std=c++20 -g -Wall -I $(INCDIR)
GUIFLAGS = `pkg-config --cflags --libs Qt5Widgets` -fPIC
CXX = clang++

# Directory setup
INCDIR := include
SRCDIR := src
BINDIR := bin
GUIDIR := gui
TESTDIR := tests

TARGET = AIMA
TESTS = AIMATests
SRCFILES = $(SRCDIR)/*.cpp
GUIFILES = $(GUIDIR)/*.cpp
INCFILES = $(INCDIR)/*.hpp

all: $(TARGET)
$(TARGET): $(GUIDIR)/$(TARGET).cpp
	$(CXX) $(GUIFLAGS) $(CXXFLAGS) -o $(TARGET) $(GUIFILES) $(SRCFILES)
tests: $(TESTS)
$(TESTS): $(TESTDIR)/$(TESTS).cpp
	$(CXX) $(CXXFLAGS) $(TESTDIR)/$(TESTS).cpp -o $(TESTS) $(SRCDIR)/*.cpp
clean:
	$(RM) $(TARGET)
	$(RM) $(TESTS)

# end
