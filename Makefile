CC = g++

CFLAGS= -g

SRCDIR = Source

OBJDIR = Object

SRCS = $(wildcard $(SRCDIR)/*.cpp)

OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

INCDIR = Include

EXEC = run


target:
	g++ $(SRCDIR)/*.cpp -I $(INCDIR) -g
	
all : clean $(EXEC)


$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCDIR) -g 
    
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ 
	
	
clean:
	rm -f $(OBJDIR)/*.o $(EXEC) $(output)
