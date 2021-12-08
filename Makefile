##
# AI: A Modern Approach- C++
# Author: Lam Duong
#
# Compiler setup
CXXFLAGS = `pkg-config --cflags --libs Qt5Widgets` -std=c++20 -g -Wall -fPIC -I $(INCDIR)
CXX = clang++

# Directory setup
INCDIR := include
SRCDIR := src
BINDIR := bin
GUIDIR := gui
TESTDIR := test

TARGET = AIMA
TESTS = Tests
SRCFILES = $(SRCDIR)/*.cpp
GUIFILES = $(GUIDIR)/*.cpp
INCFILES = $(INCDIR)/*.hpp

all: $(TARGET)
$(TARGET): $(GUIDIR)/$(TARGET).cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(GUIFILES) $(SRCFILES)
test: $(TESTS)
$(TESTS): $(TESTDIR)/$(TESTS).cpp
	$(CXX) $(TESTDIR)/$(TESTS).cpp -o $(TESTS) $(SRCDIR)/*.cpp
clean:
	$(RM) $(TARGET)
	$(RM) $(TESTS)

# end
