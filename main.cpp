

//#include <xercesc/util/PlatformUtils.hpp>
// Other include files, declarations, and non-Xerces-C++ initializations.

//using namespace xercesc;

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

int main(){
	
	
	string ImgDirI="/home/blake/Desktop/OCR/input/";
	string ImgDirO="/home/blake/Desktop/OCR/input/";
	string TxtDirO="/home/blake/Desktop/OCR/output/";
	string ImgTyp=".cr2";
	string Otype=".tif";
	
	//string fileList=fileRead("/home/blake/Desktop/OCR/files.txt");
	
	/*int length=fileList.length();
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
	}*/
	
	vector<string> fileArr;
	fileArr.push_back("H1007818.cr2");
	fileArr.push_back("H1007819.cr2");
	fileArr.push_back("H1023455.cr2");
	fileArr.push_back("H1023456.cr2");
	fileArr.push_back("H1023457.cr2");
	fileArr.push_back("H1023458.cr2");
	fileArr.push_back("H1023459.cr2");
	fileArr.push_back("H1023460.cr2");
	fileArr.push_back("H1023461.cr2");
	fileArr.push_back("H1023462.cr2");
	fileArr.push_back("H1023463.cr2");
	fileArr.push_back("H1023464.cr2");
	fileArr.push_back("H1023465.cr2");
	fileArr.push_back("H1023466.cr2");
	fileArr.push_back("H1023467.cr2");
	fileArr.push_back("H1023468.cr2");
	fileArr.push_back("H1023469.cr2");
	fileArr.push_back("H1023470.cr2");
	fileArr.push_back("H1024001.cr2");
	fileArr.push_back("H1026012.cr2");
	fileArr.push_back("H1026013.cr2");
	fileArr.push_back("H1026014.cr2");
	fileArr.push_back("H1026015.cr2");
	fileArr.push_back("H1026016.cr2");
	fileArr.push_back("H1026017.cr2");
	fileArr.push_back("H1026019.cr2");
	fileArr.push_back("H1026020.cr2");
	fileArr.push_back("H1026021.cr2");
	fileArr.push_back("H1026022.cr2");
	fileArr.push_back("H1026023.cr2");
	fileArr.push_back("H1026024.cr2");
	fileArr.push_back("H1026025.cr2");
	fileArr.push_back("H1026026.cr2");
	fileArr.push_back("H1026027.cr2");
	fileArr.push_back("H1026028.cr2");
	fileArr.push_back("H1026029.cr2");
	fileArr.push_back("H1026030.cr2");
	fileArr.push_back("H1026031.cr2");
	fileArr.push_back("H1026032.cr2");
	fileArr.push_back("H1026033.cr2");
	fileArr.push_back("H1026034.cr2");
	fileArr.push_back("H1026035.cr2");
	fileArr.push_back("H1026036.cr2");
	fileArr.push_back("H1026037.cr2");
	fileArr.push_back("H1026038.cr2");
	fileArr.push_back("H1026039.cr2");
	fileArr.push_back("H1026040.cr2");
	fileArr.push_back("H1026042.cr2");
	fileArr.push_back("H1026043.cr2");
	fileArr.push_back("H1026044.cr2");
	fileArr.push_back("H1026045.cr2");
	fileArr.push_back("H1026046.cr2");
	fileArr.push_back("H1026047.cr2");
	fileArr.push_back("H1026048.cr2");
	fileArr.push_back("H1026049.cr2");
	fileArr.push_back("H1026050.cr2");
	fileArr.push_back("H1026051.cr2");
	fileArr.push_back("H1026052.cr2");
	fileArr.push_back("H1026053.cr2");
	fileArr.push_back("H1026054.cr2");
	fileArr.push_back("H1026055.cr2");
	fileArr.push_back("H1026056.cr2");
	fileArr.push_back("H1026057.cr2");
	fileArr.push_back("H1026058.cr2");
	fileArr.push_back("H1026059.cr2");
	fileArr.push_back("H1026060.cr2");
	fileArr.push_back("H1026061.cr2");
	fileArr.push_back("H1026062.cr2");
	fileArr.push_back("H1026063.cr2");
	fileArr.push_back("H1026064.cr2");
	fileArr.push_back("H1026065.cr2");
	fileArr.push_back("H1026066.cr2");
	fileArr.push_back("H1026067.cr2");
	fileArr.push_back("H1026068.cr2");
	fileArr.push_back("H1026069.cr2");
	fileArr.push_back("H1026070.cr2");
	fileArr.push_back("H1026071.cr2");
	fileArr.push_back("H1026072.cr2");
	fileArr.push_back("H1026073.cr2");
	fileArr.push_back("H1026074.cr2");
	fileArr.push_back("H1026075.cr2");
	fileArr.push_back("H1026076.cr2");
	fileArr.push_back("H1026077.cr2");
	
	/*fileArr.push_back("H1007818.cr2");
	fileArr.push_back("H1007819.cr2");
	fileArr.push_back("H1026046.cr2");
	fileArr.push_back("H1161054.cr2");
	fileArr.push_back("H1096149.dng");
	fileArr.push_back("H1210328.dng");
	fileArr.push_back("H1096149.dng");
	fileArr.push_back("H1122553.dng");
	fileArr.push_back("H1123091.dng");
	fileArr.push_back("H1123529.dng");
	fileArr.push_back("H1144479.dng");
	fileArr.push_back("H1145000.dng");
	fileArr.push_back("H1145476.dng");
	fileArr.push_back("H1145519.dng");
	fileArr.push_back("H1158090.dng");
	fileArr.push_back("H1178718.dng");
	fileArr.push_back("H1179612.dng");
	fileArr.push_back("H1210328.dng");*/

	
	for(int i=0;i<fileArr.size();++i){
		string img=fileArr[i];
		//cout<<ImgDirO+img.substr(0,img.length()-4)+".jpg"<<endl;
		string outI=(ImgDirO+img.substr(0,img.length()-4)+Otype);
		string outT=(TxtDirO+img.substr(0,img.length()-4));
		cout<<"convert"<<endl;
		int ee=convert(ImgDirI+img,outI);
		
		//system call of tesseract to perform OCR on image
		//tesseract must be installed for this to work
		string arg="tesseract " + outI + " " + outT;
		cout<< arg<<endl;
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
