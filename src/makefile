gcc=g++ -std=c++14 -pg -g mathLib.cpp stddev.cpp -o stddev -lm
gtest=g++ test.cpp mathLib.cpp -lgtest -lgtest_main -pthread
del=rm -f
test_out=./a.out
gtest_url=https://codeload.github.com/google/googletest/zip/refs/heads/master
file=xhaury00_xrezni29_xsmisk00_xkarev00
all:	
	$(gcc)
	qmake src.pro
	mv makefile tmp
	make 
	rm Makefile
	mv tmp makefile
	
test:
	wget $(gtest_url)
	unzip master
	cd googletest-master && cmake .
	$(gtest)
	$(test_out)
run: 		
	./src
	
	 
pack: 
	cd .. && cd .. && cd .. && zip -r $(file).zip $(file)
	cd .. && cd .. && cd .. && mv $(file).zip $(file)


doc:	Doxyfile
	doxygen -g Doxyfile
	doxygen Doxyfile
	mv html ../../doc
	mv latex ../../doc
clean: 
	$(del) *.o
	$(del) *.zip
	$(del) *.txt
	$(del) *.out
	$(del) src
	$(del) stddev
	$(del) -r documentation
	$(del) moc*
	$(del) ui_*
	$(del) -r googletest-master
	$(del) master
	cd ../../doc && $(del) -r html
	cd ../../doc && $(del) -r latex
	$(del) *.bak
profile:
	$(gcc)
