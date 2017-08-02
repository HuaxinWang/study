FINAL:=project
OBJECT:=main.o fun.o login.o welcome_menu.o
CC:=gcc
OPTIONS:=-g -Wall

$(FINAL):$(OBJECT)
	$(CC) $^ -o $@ $(OPTIONS)
%.o:%.c
	$(CC) -c $< -o $@ $(options)
clean:
	rm -rvf $(OBJECT) $(FINAL)
