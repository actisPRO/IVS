gcc=g++ -std=c++14 -pg -g mathLib.cpp stddev.cpp -o stddev -lm
gtest=g++ test.cpp mathLib.cpp -lgtest -lgtest_main -pthread
del=rm -f
test_out=./a.out
gtest_url=https://codeload.github.com/google/googletest/zip/refs/heads/master
zipe_file=IVS-main.zip	
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
	cd .. && zip -r $(zipe_file) *
	cd .. && mv $(zipe_file) src


doc:	Doxyfile
	doxygen
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
profile:
	$(gcc)
