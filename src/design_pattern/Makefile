cc = g++ 
FLAG = -c -Wall -std=c++11 -O1 
LDFLAGS =  
SRCS = main.cpp character_weapon.cpp singleton.cpp \
       strategy.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = main 

all: $(SRCS) $(EXEC)

$(EXEC): $(OBJS)
	$(cc) $(LDFLAGS) $(OBJS) -o $@

.cpp.o:
	$(cc) $(LDFLAGS) $(FLAG) $< -o $@

clean:
	rm -rf $(OBJS) $(EXEC)
