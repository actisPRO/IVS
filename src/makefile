
zipe_file=IVS-main.zip	
all:	
	g++ -std=c++14 -pg -g mathLib.cpp stddev.cpp -o stddev -lm
	qmake src.pro
	mv makefile tmp
	make 
	rm Makefile
	mv tmp makefile
	
test:
	wget https://codeload.github.com/google/googletest/zip/refs/heads/master
	unzip master && rm master
	cd googletest-master && cmake .
	g++ test.cpp mathLib.cpp -lgtest -lgtest_main -pthread	
	./a.out
	rm -r googletest-master
	rm a.out
run: 		
	./src
	
	 
pack: 
	cd .. && zip -r $(zipe_file) *
	cd .. && mv IVS-main.zip src


doc:	Doxyfile
	doxygen
clean: 
	rm -f *.o
	rm -f *.zip
	rm -f *.txt
	rm -f *.out
	rm -f src
	rm -f stddev
	rm -f -r documentation
	rm -f moc*
	rm -f ui_*
profile:
	g++ -std=c++14 -pg -g mathLib.cpp stddev.cpp -o stddev -lm
