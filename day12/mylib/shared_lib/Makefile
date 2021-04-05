targetFile = add.o div.o sub.o mul.o

main: main.c
	gcc -o $@ $^ -I ./mathLib/include -L ./mathLib/lib -lmath 

deploy:$(targetFile)
	gcc -fPIC -c $^
%.o:%.c
	gcc -c  $<
.PHONY:clean
clean:
	rm -rf *.o *.a mathLib
