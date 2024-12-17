obj:=$(patsubst %.c,%.o,$(wildcard *.c))
Slist.exe: $(obj)
	gcc -o $@ $^
clean:
	rm *.exe *.o