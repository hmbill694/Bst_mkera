CC =g++ # CC is a variable containing the complier we are using.


CFLAGS = -g -c -Wall # -c means compile and -wall is a necessary warning, -g is debug data.

all:	run

run:	main.o BST.o M_BST.o Part_1.o Part_2.o #dependencies
	$(CC) -o run main.o BST.o M_BST.o Part_1.o Part_2.o

main.o: BST.h main.cpp 
	$(CC) $(CFLAGS) main.cpp

BST.o: BST.h BST.cpp
	$(CC) $(CFLAGS) BST.cpp

M_BST.o: M_BST.h M_BST.cpp
	$(CC) $(CFLAGS) M_BST.cpp

Part_1.o:	Part_1.cpp Part_1.h
	$(CC) $(CFLAGS) Part_1.cpp

Part_2.o:	Part_2.cpp Part_2.h
	$(CC) $(CFLAGS) Part_2.cpp

clean:
	rm *.o run	