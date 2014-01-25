cc = clang++ 
FLAG = -c -Wall -std=c++11 -fno-omit-frame-pointer -O1 \
       -g -fno-optimize-sibling-calls  
LDFLAGS = 
SRCS = main.cpp HashTest.cpp SearchTest.cpp ThreadTest.cpp \
       SortTest.cpp RandomTest.cpp SetTest.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = main 

all: $(SRCS) $(EXEC)

$(EXEC): $(OBJS)
	$(cc) $(LDFLAGS) $(OBJS) -o $@

.cpp.o:
	$(cc) $(LDFLAGS) $(FLAG) $< -o $@

clean:
	rm -rf $(OBJS) $(EXEC)
