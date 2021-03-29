targetFile = add.o div.o sub.o mul.o

main: main.c
	gcc -o $@ $^ -I ./mathLib/include -L ./mathLib/lib -lmath 

deploy:$(targetFile)
	rm -rf mathLib
	ar -rc libmath.a $^
	mkdir mathLib
	mkdir mathLib/lib
	mkdir mathLib/include
	mv *.a mathLib/lib
	cp myMath.h mathLib/include
	rm -rf *.o
%.o:%.c
	gcc -c  $<
.PHONY:clean
clean:
	rm -rf *.o *.a mathLib
