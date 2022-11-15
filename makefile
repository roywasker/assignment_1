all: loop loopd recursived recursives mains maindrec maindloop

mains: main.o libclassrec.a
	gcc -Wall -g -o mains main.o libclassrec.a -lm

maindloop: main.o
	gcc -Wall -g -o maindloop main.o ./libclassloops.so -lm

maindrec: main.o
	gcc -Wall -g -o maindrec main.o ./libclassrec.so -lm

loop: advancedClassificationLoop.o basicClassification.o NumClass.h
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o

recursives: advancedClassificationRecursion.o basicClassification.o NumClass.h
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o

recursived: advancedClassificationRecursion.o basicClassification.o NumClass.h
	gcc -shared -o libclassrec.so advancedClassificationRecursion.o basicClassification.o

loopd: advancedClassificationLoop.o basicClassification.o NumClass.h
	gcc -shared -o libclassloops.so advancedClassificationLoop.o basicClassification.o -lm

main.o: main.c NumClass.h
	gcc -Wall -g -c main.c 

basicClassification.o: basicClassification.c NumClass.h
	gcc -Wall -g -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	gcc -Wall -g -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	gcc -Wall -g -c advancedClassificationRecursion.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maindrec maindloop