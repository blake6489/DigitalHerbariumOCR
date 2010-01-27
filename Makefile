CPPFLAGS+= -Wall -O2 -Iinclude -ltiffxx 

all: main

clean:
	rm main

main: tools/distance.h tools/distance.cpp tools/UnsharpConfigs.h tools/UnsharpConfigs.cpp search.h my_fitness.h main.cpp

test: tools/distance.h tools/distance.cpp tools/UnsharpConfigs.h tools/UnsharpConfigs.cpp my_fitness.h test.cpp

run: tools/UnsharpConfigs.h tools/UnsharpConfigs.cpp my_run.h run.cpp
