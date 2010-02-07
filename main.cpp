
#include <iostream>
#include <string>
#include <vector>
//#include <fstream>
//#include <cstring>
//#include <cstdlib>
using namespace std;

#include "ccmain/baseapi.h"

#include "tools/distance.h"
//#include "tools/loadTiff.cpp"
#include "tools/UnsharpConfigs.h"
#include "tools/utils.h"
//#include "convert.h"

char* run_tesseract(const char* language,
                    const unsigned char* imagedata,
                    int bytes_per_pixel, int bytes_per_line,
                    int width, int height) {
  TessBaseAPI::InitWithLanguage(NULL, NULL, language, NULL, false, 0, NULL);
  char* text =
    TessBaseAPI::TesseractRect(imagedata, bytes_per_pixel, bytes_per_line,
                               0, 0, width, height);
  TessBaseAPI::End();

  return text;
}

int main(){
	
	UnsharpConfigs us;
	
	//int i=convert("/home/blake/Desktop/OCR/input/H1008013.dng");
//void SetImage(const unsigned char* imagedata, int width, int height, int bytes_per_pixel, int bytes_per_line);
                
//prefered, but requires Leptonica              
//void TessBaseAPI::SetImage(const Pix* pix) {

// int Recognize(ETEXT_STRUCT* monitor);
 
   // Returns all word confidences (between 0 and 100) in an array, terminated
  // by -1.  The calling function must delete [] after use.
  // The number of confidences should correspond to the number of space-
  // delimited words in GetUTF8Text.
//  int* AllWordConfidences();
  
  

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
