#export LD_LIBRARY_PATH=/home/blake/Desktop/OCR/xerces-c-3.1.1-x86-linux-gcc-3.4/lib:$LD_LIBRARY_PATH 
#export PATH="$PATH:/home/blake/Desktop/OCR/xerces-c-3.1.1-x86-linux-gcc-3.4/bin"

#CC = '/opt/intel/Compiler/11.1/064/bin/ia32/icc'
CC = g++
MLIBS = `Magick++-config --cppflags --cxxflags --ldflags --libs`
TIFFLIBS=-ltiffxx
CPPFLAGS+= -w -O2 
NORANGER=0
YESRANGER=1
PREPROS=-D RANGER=
OUTFILE=-o main
INFILE=convert.cpp tools/distance.cpp tools/UnsharpConfigs.cpp main.cpp
#CPPFLAGS+= -I '/home/blake/Desktop/OCR/tesseract-2.04/'


home:  
	$(CC) $(CPPFLAGS) $(PREPROS)$(NORANGER) $(MLIBS) $(TIFFLIBS) $(OUTFILE) $(INFILE)

ranger: 
	$(CC) $(CPPFLAGS) $(PREPROS)$(YESRANGER) $(MLIBS) $(TIFFLIBS) $(OUTFILE) $(INFILE)

