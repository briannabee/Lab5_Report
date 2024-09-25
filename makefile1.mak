a.exe: shape_c.o
	g++ shape_c.o

shape_c.o: shape_c.cpp
	g++ -c -g shape_c.cpp

clean:
	del *.o a.exe
