

#include <tiffio.h>
#include <iostream>


#ifndef LOADTIFF_H
#define LOADTIFF_H

// Greyscale of 8 and color of 24 or 32 bits per pixel may be given.
// Palette color images will not work properly and must be converted to
// 24 bit.
// Binary images of 1 bit per pixel may also be given but they must be
// byte packed with the MSB of the first byte being the first pixel, and a
// one pixel is WHITE. For binary images set bytes_per_pixel=0.
int loadBWTiff(const char * file){

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

char  img[npixels/8];
for(unsigned int i=0;i<npixels;i+=8){
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
_TIFFfree(raster);
TIFFClose(tif);

return 0;

}

#endif

