
#include <iostream>
#include <string>
#include <vector>
//#include <fstream>
//#include <cstring>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

//#include "ccmain/baseapi.h"

#include "tools/distance.h"
//#include "tools/loadTiff.cpp"
#include "tools/UnsharpConfigs.h"
#include "tools/utils.h"
#include "convert.h"

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
}
*/
int main(){
	
	string ImgDirI="~/Desktop/OCR/input/";
	string ImgDirO="~/Desktop/OCR/input/";
	string TxtDirO="~/Desktop/OCR/output/";
	string ImgTyp=".cr2";
	string Otype=".tif";
	
	string fileList=fileRead("~/Desktop/OCR/files.txt");
	
	int length=fileList.length();
	int pos=0;
	int pos2=1;
	vector<string> fileArr;
	int nnn=0;
	while(5000>pos && nnn<1000000){
		pos2=fileList.find(",",pos);
		string file=fileList.substr(pos,pos2-pos);
		fileArr.push_back(file);
		//cout<<file<<" p:"<<pos<<" p2:"<<pos2<<endl;
		pos=pos2+1;
		++nnn;
	}
	
	
	for(int i=0;i<100;++i){
		string img=fileArr[i];
		//cout<<ImgDirO+img.substr(0,img.length()-4)+".jpg"<<endl;
		string outI=(ImgDirO+img.substr(0,img.length()-4)+Otype);
		int ee=convert(ImgDirI+img,outI);
		//system call of tesseract to perform OCR on image
		//tesseract must be installed for this to work
		string arg="tesseract " + outI + " " + outI;
		//cout<< arg<<endl;
		system(arg.c_str());
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
  
  // not in api.h
//AllTextConfidences(PAGE_RES* page_res)
//IsValidWord(egf)

	return 0;

}
