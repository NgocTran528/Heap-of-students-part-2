heap_student: main.o address.o date.o student.o
	g++ -g main.o address.o date.o student.o -o heap_student

main.o: main.cpp address.h date.h student.h
	g++ -g -c main.cpp

address.o: address.cpp address.h
	g++ -g -c address.cpp

date.o: date.cpp date.h
	g++ -g -c date.cpp

student.o: student.cpp student.h address.h date.h
	g++ -g -c student.cpp

run: heap_student
	./heap_student

debug: heap_student
	gdb ./heap_student

clean:
	rm -f *.o heap_student

valgrind: heap_student
	valgrind --leak-check=full ./heap_student
