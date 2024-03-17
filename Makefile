binary:
	clang++ -stdlib=libc++ src/Game.cpp src/main.cpp -w -lSDL2 -o bin/main

run: binary
	./bin/main