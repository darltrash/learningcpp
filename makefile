CPP := g++

hello:
	$(CPP) hello.cpp -o hello.out
	./hello.out
	rm hello.out

fib:
	$(CPP) fib.cpp -o fib.out
	./fib.out
	rm fib.out

guess:
	$(CPP) guess.cpp -o guess.out
	./guess.out
	rm guess.out

file:
	$(CPP) file.cpp -o file.out
	./file.out
	rm file.out

bfunk:
	$(CPP) bfunk.cpp -o bfunk.out
	./bfunk.out
	rm bfunk.out

win:
	$(CPP) win.cpp -o win.out `sdl2-config --libs --cflags` -lm
	./win.out
	rm win.out

thred:
	$(CPP) thred.cpp -o thred.out -pthread
	./thred.out
	rm thred.out