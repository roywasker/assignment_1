all: libclassrec.so libclassloops.so libclassrec.a libclassloops.a loop loopd recursived recursives

mains: main.o libclassrec.a
	gcc -wall -g -o mains main.o libclassrec.a

maindloop: main.o
	gcc -wall -g -o maindloop main.o ./libclassloops.so

maindrec: main.o
	gcc -wall -g -o maindrec main.o ./libclassrec.so

loop: advancedClassificationLoop.o
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o

recursives: advancedClassificationRecursion.o
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o

recursived: advancedClassificationRecursion.o
	gcc -shared -o libclassrec.so advancedClassificationRecursion.o basicClassification.o

loopd: advancedClassificationLoop.o
	gcc -shared -o libclassloops.so advancedClassificationLoop.o basicClassification.o

main.o: main.c NumClass.h
	gcc -wall -g -c main.c

basicClassification.o: basicClassification.c NumClass.h
	gcc -wall -g -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	gcc -wall -g -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	gcc -wall -g -c advancedClassificationRecursion.c


.PHONY: clean all

clean:
	rm -f *.o *.a *.so