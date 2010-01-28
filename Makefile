CPP   = gcc -c -I../engine
CPPFLAGS+= `Magick++-config --cppflags --cxxflags --ldflags --libs` -Wall -O2 -Iinclude -ltiffxx 

all: main

clean:
	rm main
	
cleantest:
	rm test

main: tools/distance.h tools/distance.cpp tools/UnsharpConfigs.h tools/UnsharpConfigs.cpp search.h my_fitness.h main.cpp

test: tools/distance.h tools/distance.cpp tools/UnsharpConfigs.h tools/UnsharpConfigs.cpp my_fitness.h test.cpp

run: tools/UnsharpConfigs.h tools/UnsharpConfigs.cpp my_run.h run.cpp
