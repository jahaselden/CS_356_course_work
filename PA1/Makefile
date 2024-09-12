assignment=cipher

$(assignment):
		g++ $(CXXFLAGS) -o $(assignment) *.cpp

tar:
		tar -cf $(assignment).tar *.h *.cpp Makefile

clean:
		rm -f $(assignment) $(assignment).tar *.o *.gch *.gcov a.out