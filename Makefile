
#CC = '/opt/intel/Compiler/11.1/064/bin/ia32/icc'
CC = g++
CPPFLAGS+= -w -O2
MLIBS = `Magick++-config --cppflags --cxxflags --ldflags --libs`
TIFFLIBS=-ltiffxx
#Rangerness
NORANGER=0
YESRANGER=1

PREPROS=-D RANGER=

OUTFILE=-o main
INFILE=convert.cpp tools/distance.cpp tools/UnsharpConfigs.cpp main.cpp

home:  
	$(CC) $(CPPFLAGS) $(PREPROS)$(NORANGER) $(MLIBS) $(TIFFLIBS) $(OUTFILE) $(INFILE)

ranger: 
	$(CC) $(CPPFLAGS) $(PREPROS)$(YESRANGER) $(OUTFILE) $(INFILE)

.EXPORT:

