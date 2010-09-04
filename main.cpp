

//#include <xercesc/util/PlatformUtils.hpp>
// Other include files, declarations, and non-Xerces-C++ initializations.

//using namespace xercesc;

#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <ctime>
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

enum TLogLevel {logERROR, logWARNING, logINFO, logDEBUG, logDEBUG1,
logDEBUG2, logDEBUG3, logDEBUG4};

string NowTime(){
	return "not a time";
}

string ToString(TLogLevel level){
	string str;
	switch(level){
		case 1:
			str="logERROR";
			break;
		case 2:
			str="logWARNING";
			break;
		case 3:
			str="logINFO";
			break;
		case 4:
			str="logDEBUG";
			break;
		case 5:
			str="logDEBUG1";
			break;
		case 6:
			str="logDEBUG2";
			break;
		case 7:
			str="logDEBUG3";
			break;
		case 8:
			str="logDEBUG4";
			break;
		default:
			str="INVALID LEVEL";
			break;
	}
	return str;
}



//input many many images and one output directory
int main(int argc, char **argv){
	//tell me some things about this version
	cout<<"DHOCR compiled on "<<__TIME__<<" "<<__DATE__<<" Rangerness="<<RANGER<<endl;
	int LOGLEVEL=logINFO;

	FILE * logFile;
	
	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
  
	cout<<rawtime<<endl;
	
	char date[9];
	strftime(date,9,"%Y%m%d",timeinfo);
	string logFileName=string(date)+string(".log");
	logFile = fopen(logFileName.c_str(),"a");
	if (logFile==NULL){
		cout<<"!!!FAILED TO LOG!!!"<<endl;
	}else{
		cout<<"logging"<<endl;
		char tmp [80];
		strftime(tmp,80,"\n==========================\n======== %H:%M:%S ========\n",timeinfo);
		fprintf(logFile,tmp);
	}
	
	
	if(LOGLEVEL>=logINFO){
		time(&rawtime );
		fprintf(logFile,"%d\tStarting DHOCR\n",rawtime);
		
	}
	fclose (logFile);

	//setup systen envoroment variables...
	//TODO this is hackish... 
	#if RANGER==1
	string TessPath="$HOME/tesseract-2.04/bin";
	string ImPath="$HOME/ImageMagick-6.6.2-10/utilities";
	//system("TESSDATA_PREFIX=$HOME/tesseract-2.04/tessdata");
	#endif

	vector<string> inFiles;
	//parsing command input
	bool convertYN=true;
	bool verboseYN=false;
	bool recYN=true;
	string TxtDirO;
    cout << argv[0];
    for (int i = 1; i < argc; i++) { /* We will iterate over argv[] to get the parameters stored inside.
                                      * Note that we're starting on 1 because we don't need to know the 
                                      * path of the program, which is stored in argv[0] */
        if (i + 1 != argc) // Check that we haven't finished parsing already
            if (string(argv[i]) == "-i") {
                // We know the next argument *should* be the filenames:
                //while i<argc and next string dosnt start with minus sign
                while(i<argc && string(argv[i+1]).substr(0,1)!="-"){
                	++i;
                	string str=string(argv[i]);
					inFiles.push_back(str);
                }
            } else if (string(argv[i]) == "-o") {
            	//output directory
                TxtDirO = argv[i + 1];
            } else if (string(argv[i]) == "-c") {
                convertYN = true;
            } else if (string(argv[i]) == "-r") {
                recYN = true;
            } else if (string(argv[i]) == "-v") {
                verboseYN = true;
            } else {
                cout << "Not enough or invalid arguments, please try again.\n";
                cout<< argv[i]<< " not recognised"<<endl;
                sleep(2000); 
                exit(0);
        }
        cout << argv[i] << " ";
    }
	

	
	/*
	
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
	
	*/
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
