

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
	
	string fileList=fileRead("/home/blake/Desktop/OCR/files.txt");
	
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
	
	for(int i=0;i<fileArr.size();++i){
		string img=fileArr[i];
		//cout<<ImgDirO+img.substr(0,img.length()-4)+".jpg"<<endl;
		string outI=(ImgDirO+img.substr(0,img.length()-4)+Otype);
		//string arg="dcraw -T "+ImgDirI+img;
		//system(arg.c_str());
		//arg="convert " + outI + 
		int ee=convert(,outI);
		
		//system call of tesseract to perform OCR on image
		//tesseract must be installed for this to work
		//arg="tesseract " + outI + " " + outI;
		//cout<< arg<<endl;
		//system(arg.c_str());
	}

	return 0;

}
