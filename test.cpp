// test.cpp
// Used to compair the tesseract text output with the known text of a few files for testing and verification using and edit distance algorithm
//compile with make test
//
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
#include "my_fitness.h"
#include "tools/UnsharpConfigs.h"
#include "tools/utils.h"
#include "convert.h"

int main(){
	
	//find PATH > files.txt
	string kFileList=fileRead("/home/blake/Desktop/OCR/knownFiles.txt");
	string uFileList=fileRead("/home/blake/Desktop/OCR/unknownFiles.txt");
	
	vector<string> kFileArr=stringToVector(kFileList,".txt");
	vector<string> uFileArr=stringToVector(uFileList,".txt");
		
	float avg=0;
	for(int i=0;i<kFileArr.size();++i){		
		avg+=(my_fitness(fileRead(uFileArr[i]),fileRead(kFileArr[i])))/kFileArr.size();
	}
	cout<<avg<<endl;


	return 0;

}
