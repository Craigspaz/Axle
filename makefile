#DEBUG=-D
SRCDIR=./src
OBJDIR=./obj
INCDIR=./include
BINDIR=./bin

CC=g++

SRCS=$(SRCDIR)/main.cpp 


INCLUDE = $(addprefix -I,$(INCDIR))
OBJS=${SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o}
CFLAGS = $(INCLUDE) -g$(DEBUG) -lSDL2 -lGL -lGLEW

TARGET = $(BINDIR)/Game

all: $(TARGET)

$(TARGET): $(OBJS) 
	$(CC) -o $@ $(OBJS) ${CFLAGS}

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)