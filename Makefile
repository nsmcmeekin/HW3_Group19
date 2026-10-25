CCF = -std=c++20
OBJ = address.o credit_card.o person.o product.o store.o transaction.o main.o

all: hw3_group19

run: hw3_group19
	./hw3_group19

hw3_group19: $(OBJ)
	g++ $(CCF) -o hw3_group19 $(OBJ)

address.o: address.cpp address.h
	g++ $(CCF) -c address.cpp -o address.o

credit_card.o: credit_card.cpp credit_card.h
	g++ $(CCF) -c credit_card.cpp -o credit_card.o

person.o: person.cpp person.h
	g++ $(CCF) -c person.cpp -o person.o

store.o: store.cpp store.h
	g++ $(CCF) -c store.cpp -o store.o

product.o: product.cpp product.h
	g++ $(CCF) -c product.cpp -o product.o

transaction.o: transaction.cpp transaction.h
	g++ $(CCF) -c transaction.cpp -o transaction.o

main.o: main.cpp address.h credit_card.h store.h product.h transaction.h person.h
	g++ $(CCF) -c main.cpp -o main.o

clean:
	rm -f $(OBJ) hw3_group19
