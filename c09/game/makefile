FINAL:=game
OBJECT:=Menu.o loginRegiste.o gameRules.o function.o main.o
CC:=gcc
OPTIONS:=-g -Wall

$(FINAL):$(OBJECT)
	$(CC) $^ -o $@ $(OPTIONS)
%.o:%.c
	$(CC) -c $< -o $@ $(options)
clean:
	rm -rvf $(OBJECT) $(FINAL)
