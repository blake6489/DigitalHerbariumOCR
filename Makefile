
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
	#linked to in README
	#DHOCR=$HOME
	#Path to tesseract binaries (on Ranger)
	#TESSPATH=
	#Path to ImageMagick binaries (on Ranger)
	#MPATH=$(HOME)/ImageMagick-6.6.2-10/utilities
	#Path to tesseract data files
	TESSDATA_PREFIX99=$(HOME)/tesseract-2.04/tessdata
	$(CC) $(CPPFLAGS) $(PREPROS)$(YESRANGER) $(OUTFILE) $(INFILE)

.EXPORT:

