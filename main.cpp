
#include <iostream>
#include <string>
#include <vector>

//#include <fstream>

//#include <cstring>
//#include <cstdlib>

#include <Magick++.h>
using namespace Magick;
//#include <tiffio.h>

using namespace std;

#include "tools/distance.h"
#include "tools/loadTiff.cpp"
#include "tools/UnsharpConfigs.h"
#include "tools/utils.h"
//#include "search.h"

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
	
	try {

		Image image;

		image.read("/home/blake/Desktop/OCR/input/H1023457.cr2" );

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

//void SetImage(const unsigned char* imagedata, int width, int height, int bytes_per_pixel, int bytes_per_line);
                
//prefered, but requires Leptonica              
//void TessBaseAPI::SetImage(const Pix* pix) {

// int Recognize(ETEXT_STRUCT* monitor);
 
   // Returns all word confidences (between 0 and 100) in an array, terminated
  // by -1.  The calling function must delete [] after use.
  // The number of confidences should correspond to the number of space-
  // delimited words in GetUTF8Text.
//  int* AllWordConfidences();
  
  
return 0;	
	//srand(time(NULL));


//box off text
//unsharp text
//tess api get words and scores
//use scores?
//post prosess 

//dosnt return correctly yet
//int length=loadBWTiff("/home/blake/Desktop/OCR/input/H1023465.tiff");

// not in api.h
//AllTextConfidences(PAGE_RES* page_res)
//IsValidWord(egf)

	//vector<string> f;
	//f.push_back("H1023457.tiff");
	//f.push_back("H1023465.tiff");
	//center
	//UnsharpConfigs c(53,2.5,4,0.4,45000);
	// bound is the amount that will be added to and subtracted from center
	//vec5 b(50,2.5,50,0.4,44000);
	//b=b*0.9;
	//c=search(c,b,f);
	//cout<<my_fitness(c,f);

	return 0;

}
