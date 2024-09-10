assignment=cipher

$(assignment):
		g++ $(CXXFLAGS) -o $(assignment) *.cpp

tar:
		tar -cf $(assignment).tar *.cpp Makefile

clean:
		rm -f $(assignment) $(assignment).tar *.o *.gch *.gcov a.out