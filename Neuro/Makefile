CC  = g++
CXX = g++
LD  = g++

RM = rm -rf

STANDART_FLAG = -std=c++17
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

FLAGS  = $(STANDART_FLAG)
FLAGS += $(SFML_FLAGS)

CFLAGS   = $(FLAGS)
CXXFLAGS = $(FLAGS)
LDFLAGS  = $(FLAGS)

OBJS = ConsoleApplication4.o Data/data.o

TARGET = sfml-app.out

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) $(OBJS) $(TARGET)