
all: loops loopd recursived recursives mains maindloop maindrec

loops: libclassloops.a

libclassloops.a: advancedClassificationLoop.o basicClassification.o 
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o 
	
recursives: libclassrec.a

libclassrec.a: advancedClassificationRecursion.o basicClassification.o 
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o 

recursived: libclassrec.so

libclassrec.so: advancedClassificationRecursion.o basicClassification.o 
	gcc -shared -Wall -g -o libclassrec.so advancedClassificationRecursion.o basicClassification.o 

loopd: libclassloops.so

libclassloops.so: advancedClassificationLoop.o basicClassification.o 
	gcc -shared -Wall -g -o libclassloops.so advancedClassificationLoop.o basicClassification.o 
	
mains: main.o libclassrec.a
	gcc -Wall -g -o mains main.o libclassrec.a -lm

maindloop: main.o
	gcc -Wall -g -o maindloop main.o ./libclassloops.so -lm

maindrec: main.o
	gcc -Wall -g -o maindrec main.o ./libclassrec.so -lm

main.o: main.c NumClass.h
	gcc -Wall -g -c main.c 

basicClassification.o: basicClassification.c NumClass.h
	gcc -Wall -g -c -fPIC basicClassification.c 

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	gcc -Wall -g -c -fPIC advancedClassificationLoop.c 

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	gcc -Wall -g -c -fPIC advancedClassificationRecursion.c 

.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maindrec maindloop