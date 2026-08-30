CXX      ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra
LDFLAGS  ?=

TARGET    = bin/craxxlauncher
SRCDIR    = src
BINDIR    = bin

SRCS     := $(wildcard $(SRCDIR)/*.cpp)
OBJS     := $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%.o,$(SRCS))

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(BINDIR)/%.o: $(SRCDIR)/%.cpp | $(BINDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BINDIR):
	@mkdir -p $(BINDIR)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BINDIR)
