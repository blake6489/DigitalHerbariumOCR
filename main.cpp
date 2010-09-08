

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

enum TLogLevel {logERROR, logWARNING, logINFO, logDEBUG, logDEBUG1, logDEBUG2, logDEBUG3, logDEBUG4};

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
	
	//Logging init
	//logERROR, logWARNING, logINFO, logDEBUG, logDEBUG1,logDEBUG2, logDEBUG3, logDEBUG4
	int LOGLEVEL=logDEBUG;

	FILE * logFile;
	//time for logging
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
  
	cout<<rawtime<<endl;
	
	//opening logfile with name yearmonthday
	char date[9];
	strftime(date,9,"%Y%m%d",timeinfo);
	string logFileName=string(date)+string(".log");
	//open in 'append' method
	logFile = fopen(logFileName.c_str(),"a");
	if (logFile==NULL){
		cout<<"!!!FAILED TO LOG!!!"<<endl;
	}else{
		cout<<"logging"<<endl;
		char tmp [80];
		strftime(tmp,80,"==========================\n======== %H:%M:%S ========\n",timeinfo);
		fprintf(logFile,tmp);
	}
	
	
	if(LOGLEVEL>=logERROR){
		time(&rawtime );
		string lString = "%d\tStarting DHOCR\n";
		fprintf(logFile,lString.c_str(),rawtime);
		fflush(logFile);
	}
	

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
	if(LOGLEVEL>=logDEBUG){
		time(&rawtime );
		string lString = "%d\tAll input arguments\n";
		for(int i=0;i<argc;++i){
			lString += "          \t"+string(argv[i])+"\n";
		}
		fprintf(logFile,lString.c_str(),rawtime);
		fflush(logFile);
	}
    for (int i = 1; i < argc; i++) { 
		/* We will iterate over argv[] to get the parameters stored inside.
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
                if(LOGLEVEL>=logERROR){
					time(&rawtime );
					string lString = "%d\tNot enough or invalid arguments\n";
					lString += "          \t%s not recognised\n";
					fprintf(logFile,lString.c_str(),rawtime,argv[i]);
					fflush(logFile);
				}
				sleep(2000); 
                exit(0);
        }
        cout << argv[i] << " ";
    }
	
	string Otype=".tif";
		
	for(int i=0;i<inFiles.size();++i){
		string img=inFiles[i];
		//cout<<ImgDirO+img.substr(0,img.length()-4)+".jpg"<<endl;
		string outI=(img.substr(0,img.find_last_of('.'))+Otype);
		//cout<<img<<" "<<img.find_last_of('.')-img.find_last_of('/')<<endl;
		string outT=(TxtDirO+img.substr(img.find_last_of('/'),img.find_last_of('.')-img.find_last_of('/')));
		
		//this preprocessor stuff makes it work on tacc and on my home computer
		#if RANGER==0
			if(LOGLEVEL>=logINFO){
				time(&rawtime );
				string lString = "%d\tConverting %s\n";
				fprintf(logFile,lString.c_str(),rawtime,img);
				fflush(logFile);
			}
			int ee=convert(img,outI);
			if(LOGLEVEL>=logINFO){
				time(&rawtime );
				string lString = "%d\tCalling Tesseract for %s\n";
				fprintf(logFile,lString.c_str(),rawtime,img);
				fflush(logFile);
			}
			string arg2="tesseract " + outI + " " + outT;
			system(arg2.c_str());
		#else
			if(LOGLEVEL>=logINFO){
				time(&rawtime );
				string lString = "%d\tConverting %s\n";
				fprintf(logFile,lString.c_str(),rawtime,img);
				fflush(logFile);
			}
			string arg1=ImPath + "/convert " + img + " -threshold 25000 -depth 1 " + outI;
			system(arg1.c_str());
			
			if(LOGLEVEL>=logINFO){
				time(&rawtime );
				string lString = "%d\tCalling Tesseract for %s\n";
				fprintf(logFile,lString.c_str(),rawtime,img);
				fflush(logFile);
			}
			//system call of tesseract to perform OCR on image
			//tesseract must be installed for this to work
			string arg2=TessPath + "/tesseract " + outI + " " + outT;
			//cout<<arg2<<endl;
			system(arg2.c_str());
		#endif
	}
	
	
	if(LOGLEVEL>=logERROR){
		time(&rawtime );
		string lString = "%d\tEnding DHOCR\n";
		fprintf(logFile,lString.c_str(),rawtime);
		fflush(logFile);
	}
	
	fclose (logFile);

	return 0;

}
