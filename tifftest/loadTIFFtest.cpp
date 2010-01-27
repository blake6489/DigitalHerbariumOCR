#include <tiffio.h>
#include <iostream>
int main(){

 TIFF *tif=TIFFOpen("tiffTestImgBW1.tif", "r");
//Then you must get the size of the image from the opened file:
 // #define uint32 unsigned long
 uint32 width;
 uint32 height;
TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &width);           // uint32 width;
TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &height);        // uint32 height;
//You should use the LIBTIFF library memory allocation functions to get space to store the image:
uint32 npixels=width*height;
uint32* raster;
raster=(uint32 *) _TIFFmalloc(npixels *sizeof(uint32));
 
//[Note: Though it works under Win32, you should not use the C-"malloc/free" and the C++-"new/delete" functions/operators to do the memory management for the reading buffer]

//Now you are able to read the image from the TIFF file using the following function:
TIFFReadRGBAImage(tif, width, height, raster, 0);
//Note: You should always check the return value of the function to make sure that there is no error occurred in the reading process.  Returning 1 means read was successful, and if 0 is returned, some type of error occured.

//What you have now is an array (raster) of pixel values, one for each pixel in the image, and each pixel is a 4-byte value.  Each of the bytes represent a channel of the pixel value (RGBA).  Each channel is represented by an integer value from 0 to 255.

//To get each of the individual channel of a pixel use the function:
int i=3;
char r=(char )TIFFGetR(raster[i]);  // where X can be the channels R, G, B, and A.
char g=(char )TIFFGetG(raster[i]); 
char b=(char )TIFFGetB(raster[i]);
char a=(char )TIFFGetA(raster[i]); 
std::cout<<(int)r<<","<<(int)g<<","<<(int)b<<","<<(int)a<<std::endl;// i is the index of the pixel in the raster.

//Important: Remember that the origin of the raster is at the lower left corner.  You should be able to figure out the how the image is stored in the raster given that the pixel information is stored a row at a time!

//After you are finished with the raster you should destroy it and free up the memory:
_TIFFfree(raster);
//Always Close the File when you are done with it.
TIFFClose(tif);

}

