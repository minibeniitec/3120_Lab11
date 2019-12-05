all: run clean

compile: msp.cpp
	g++ -Wall msp.cpp -o msp.out

run: compile
	./msp.out

clean: 
	rm -rf *.o *.out

push: .git
	git add .
	git commit -m "auto"
	git push origin master
