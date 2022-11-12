all: 

mains: 

maindloop:

maindrec:


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