// fitness evaluation function


#ifndef MY_FITNESS_H
#define MY_FITNESS_H

#include <iostream>
#include <vector>
#include <string>

#include <fstream>

#include <cstring>
#include <cstdlib>

using namespace std;
#include "tools/distance.h"
#include "tools/utils.h"
#include "tools/UnsharpConfigs.h"



//fit:3.72802 diff:196 max:364 min:97--76x5.8245+3+0.36276
//fit:3.80874 diff:169 max:366 min:99--31x3.3691+4+0.22789
//fit:3.85205 diff:152 max:365 min:98--53x3.3691+4+0.15165
//---
//-white-threshold 36252 -unsharp 0x1.22344+4+0.0498664    0.966165
//fit:0.278777 diff:802 max:1112 min:758  -white-threshold 40342 -unsharp 16x4.79885+1+0.171077
void my_run(UnsharpConfigs img, vector <string> & inFiles)
{
	string directory="/home/blake/Desktop/OCR/main/";
	//float average=0;
	for(int f=0;f<(int)inFiles.size();++f){
		//float fit=1;
	
		string inFile=directory+inFiles[f];
		string outFile=inFile.substr().insert(inFile.length()-5,"bw").erase(inFile.length()+1);
		//cout<<"out "<<outFile<<endl;
		string OcrFile=outFile.substr().erase(outFile.length()-4);
		//cout<<"ocr "<<OcrFile<<endl;
		string config=img.toString();
		string cmd1="convert "+inFile+" "+config+" -monochrome -depth 1 "+outFile;
		
		//cout<<"cmd1"<<cmd1<<endl;
		int sys=system(cmd1.c_str());
		if(sys==0)
		{
			string cmd2="tesseract "+outFile+" "+OcrFile;
			sys=system(cmd2.c_str());
		}else{
			cout<<"system:"<<sys<<endl;
			if(sys==2) exit(0);
		}
	
		string correctTextFile=inFile.substr().erase(inFile.length()-5).append("known.txt");
		OcrFile=outFile.substr().erase(outFile.length()-3).append("txt");
	
	}
	
	
}



#endif

