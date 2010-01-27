#include <tiffio.h>
#include <iostream>



char * loadTiff(string file){

TIFF *tif=TIFFOpen(file, "r");
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
//Note: You should always check the return value of the function to make sure that there is no error occurred in the reading process.  Returning 1 means read was successful, and if 0 is returned, some type of error occured.

//To get each of the individual channel of a pixel use the function:
int i=3;
char r=(char )TIFFGetR(raster[i]);  // where X can be the channels R, G, B, and A.
// i is the index of the pixel in the raster.
_TIFFfree(raster);
TIFFClose(tif);


}

