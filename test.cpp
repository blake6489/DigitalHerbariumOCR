
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>

#include <Magick++.h>

using namespace std;
using namespace Magick;

#include "tools/UnsharpConfigs.h"


int main()
{
	try {

		Image image;

		image.read("/home/blake/Desktop/OCR/img/H1023457.cr2" );

		image.threshold ( 36252 );
		//radius_,sigma_,amount_,threshold_ );
		image.unsharpmask(5,3.3,4,5);
		image.monochrome();
		image.depth (1);

		//should write to non-file type and passed to Tess API
		image.write("testthing.tif");

		// Display the result
		image.display( );
	}
	catch( exception &error_ )
	{
		cout << "Caught exception: IM image read - " << error_.what() << endl;
		return 1;
	}

void SetImage(const unsigned char* imagedata, int width, int height,
                int bytes_per_pixel, int bytes_per_line);
                
//prefered, but requires Leptonica              
//void TessBaseAPI::SetImage(const Pix* pix) {

 int Recognize(ETEXT_STRUCT* monitor);
 
   // Returns all word confidences (between 0 and 100) in an array, terminated
  // by -1.  The calling function must delete [] after use.
  // The number of confidences should correspond to the number of space-
  // delimited words in GetUTF8Text.
  int* AllWordConfidences();
  
  
return 0;
}
