CC = '/opt/intel/Compiler/11.1/064/bin/ia32/icc'
CPPFLAGS+= -w -O2 -I '/home/blake/Desktop/OCR/tesseract-2.04/'
CPPFLAGS+= `Magick++-config --cppflags --cxxflags --ldflags --libs`
CPPFLAGS+= -ltiffxx
OUT = -o main
COMPILE = $(CC) $(CPPFLAGS) $(OUT)

all: main

clean:
	rm main
		
cleantest:
	rm test

main: 
	$(COMPILE)  tools/distance.cpp tools/UnsharpConfigs.cpp main.cpp 
	
	#$(COMPILE) tools/distance.h tools/distance.cpp tools/UnsharpConfigs.h tools/UnsharpConfigs.cpp search.h my_fitness.h main.cpp

test: tools/distance.h tools/distance.cpp tools/UnsharpConfigs.h tools/UnsharpConfigs.cpp my_fitness.h test.cpp

run: tools/UnsharpConfigs.h tools/UnsharpConfigs.cpp my_run.h run.cpp
