
#include <iostream>
#include <vector>
#include <string>

#include <fstream>

#include <cstring>
#include <cstdlib>
#include <tiffio.h>
using namespace std;
#include "tools/distance.h"
//#include "tesseract-2.04/ccmain/baseapi.h"
#include "tools/UnsharpConfigs.h"

#include "search.h"

/*char* run_tesseract(const char* language,
                    const unsigned char* imagedata,
                    int bytes_per_pixel, int bytes_per_line,
                    int width, int height) {
  TessBaseAPI::InitWithLanguage(NULL, NULL, language, NULL, false, 0, NULL);
  char* text =
    TessBaseAPI::TesseractRect(imagedata, bytes_per_pixel, bytes_per_line,
                               0, 0, width, height);
  TessBaseAPI::End();

  return text;
}*/

int main(){
	srand(time(NULL));


//box off text
//unsharp text
//tess api get words and scores
//use scores?
//post prosess 


TIFF *tif=TIFFOpen("/home/blake/Desktop/OCR/input/H1023465.tiff", "r");
//Then you must get the size of the image from the opened file:
 // #define uint32 unsigned long
 uint32 width;
 uint32 height;
TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &width);           // uint32 width;
TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &height);        // uint32 height;

uint32 npixels=width*height;
uint32* raster;
raster=(uint32 *) _TIFFmalloc(npixels *sizeof(uint32));

//Now you are able to read the image from the TIFF file using the following function:
TIFFReadRGBAImage(tif, width, height, raster, 0);

char  img[npixels/8];
for(uint i=0;i<npixels;i+=8){
	char a=(char)((TIFFGetR(raster[++i])+1)<<7);
	a+=(char)((TIFFGetR(raster[++i])+1)<<6);
	a+=(char)((TIFFGetR(raster[++i])+1)<<5);
	a+=(char)((TIFFGetR(raster[++i])+1)<<4);
	
	a+=(char)((TIFFGetR(raster[++i])+1)<<3);
	a+=(char)((TIFFGetR(raster[++i])+1)<<2);
	a+=(char)((TIFFGetR(raster[++i])+1)<<1);
	a+=(char)((TIFFGetR(raster[++i])+1)<<0);
	img[((int)i/8)-1]=a;//byte packed MSV char array for BW image
}
//cout<<(unsigned int) img[0]<<endl;

_TIFFfree(raster);
TIFFClose(tif);

// Greyscale of 8 and color of 24 or 32 bits per pixel may be given.
// Palette color images will not work properly and must be converted to
// 24 bit.
// Binary images of 1 bit per pixel may also be given but they must be
// byte packed with the MSB of the first byte being the first pixel, and a
// one pixel is WHITE. For binary images set bytes_per_pixel=0.

// not in api.h
//AllTextConfidences(PAGE_RES* page_res)
//IsValidWord(egf)

	vector<string> f;
	//f.push_back("H1023457.tiff");
	f.push_back("H1023465.tiff");
	//f.push_back("H1026033.tiff");
	//f.push_back("H1026043.tiff");
	//f.push_back("H1026076.tiff");
	//f.push_back("H1026090.tiff");
	//f.push_back("H1026101.tiff");
	//center
	UnsharpConfigs c(53,2.5,4,0.4,45000);
	// bound is the amount that will be added to and subtracted from center
	vec5 b(50,2.5,50,0.4,44000);
	b=b*0.9;
	//c=search(c,b,f);
	//cout<<my_fitness(c,f);

	return 0;

}
