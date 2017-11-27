# Shlomy Trajber
# 305626962

a.out: compileAll
	g++ *.o 
	rm -f *.o

compileAll: *.h *.cpp
	g++ -c *.cpp
