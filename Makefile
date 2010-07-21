#export LD_LIBRARY_PATH=/home/blake/Desktop/OCR/xerces-c-3.1.1-x86-linux-gcc-3.4/lib:$LD_LIBRARY_PATH 
#export PATH="$PATH:/home/blake/Desktop/OCR/xerces-c-3.1.1-x86-linux-gcc-3.4/bin"

#CC = '/opt/intel/Compiler/11.1/064/bin/ia32/icc'
CC = g++
CPPFLAGS+= -w -O2 
CPPFLAGS+= -I '/home/blake/Desktop/OCR/tesseract-2.04/'
CPPFLAGS+= `Magick++-config --cppflags --cxxflags --ldflags --libs`
CPPFLAGS+= -ltiffxx

OUT = -o main
COMPILE = $(CC) $(CPPFLAGS) $(OUT)

all: main

clean:
	rm main
		
cleantest:
	rm test
	
new:
	rm main
	make main

main: 
	$(COMPILE) convert.cpp tools/distance.cpp tools/UnsharpConfigs.cpp main.cpp 
	
	#$(COMPILE) tools/distance.h tools/distance.cpp tools/UnsharpConfigs.h tools/UnsharpConfigs.cpp search.h my_fitness.h main.cpp

test: 
	$(COMPILE) -o test tools/distance.h tools/distance.cpp my_fitness.h test.cpp

run: tools/UnsharpConfigs.h tools/UnsharpConfigs.cpp my_run.h run.cpp
