

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
#if RANGER==0
#include "convert.h"
#endif

//input many many images and one output directory
int main(int argc, char **argv){
	//tell me some things about this version
	cout<<"DHOCR compiled on "<<__TIME__<<" "<<__DATE__<<" Rangerness="<<RANGER<<endl;

//setup systen envoroment variables...
//TODO this is hackish... wtf
#if RANGER==1
string TessPath="$HOME/tesseract-2.04/bin";
string ImPath="$HOME/ImageMagick-6.6.2-10/utilities";
//system("TESSDATA_PREFIX=$HOME/tesseract-2.04/tessdata");
#endif
	vector<string> inFiles;
	
	int ii=1;
	for(int i=1;i<argc-1;++i){
		string str=string(argv[i]);
		int lSlash=str.find_last_of('/');	//last slash
		int lDot=str.find_last_of('.');		//last dot
		string fileName=str.substr(lSlash+1,str.length()-lSlash-1);
		string fileExt=str.substr(lDot,str.length()-lDot);
		
		//cout<<fileName<<endl;
		//cout<<fileExt<<endl;
		inFiles.push_back(str);
	}
	
	ii=argc-1;
	string TxtDirO=string(argv[ii]);

	//cout<<"txt dir out"<<TxtDirO<<endl;
	
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
	
	//vector<string> fileArr;
	//fileArr.push_back("H1007818.cr2");
	//cout<<"stuff"<<inFiles.size()<<endl;
	
	for(int i=0;i<inFiles.size();++i){
		string img=inFiles[i];
		//cout<<ImgDirO+img.substr(0,img.length()-4)+".jpg"<<endl;
		string outI=(img.substr(0,img.find_last_of('.'))+Otype);
		cout<<img<<" "<<img.find_last_of('.')-img.find_last_of('/')<<endl;
		string outT=(TxtDirO+img.substr(img.find_last_of('/'),img.find_last_of('.')-img.find_last_of('/')));
		
		//this preprocessor stuff makes it work on tacc and on my home computer
		#if RANGER==0
			int ee=convert(img,outI);
			string arg2="tesseract " + outI + " " + outT;
			cout<<arg2<<endl;
			system(arg2.c_str());
		#else
			string arg1=ImPath + "/convert " + img + " -threshold 25000 -depth 1 " + outI;
			cout<<arg1<<endl;
			system(arg1.c_str());
			//system call of tesseract to perform OCR on image
			//tesseract must be installed for this to work
			string arg2=TessPath + "/tesseract " + outI + " " + outT;
			cout<<arg2<<endl;
			system(arg2.c_str());
		#endif
	}
	

	return 0;

}
