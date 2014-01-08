cc = clang++ 
FLAG = -c -Wall -std=c++11 -fno-omit-frame-pointer -O1 \
       -g -fno-optimize-sibling-calls  
LDFLAGS = 
SRCS = main.cpp parenthesis.cpp n_sum.cpp \
       zero_subsequence_sum.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = main 

all: $(SRCS) $(EXEC)

$(EXEC): $(OBJS)
	$(cc) $(LDFLAGS) $(OBJS) -o $@

.cpp.o:
	$(cc) $(LDFLAGS) $(FLAG) $< -o $@

clean:
	rm -rf $(OBJS)
