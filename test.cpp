// test.cpp
// Used to compair the tesseract text output with the known text of a few files for testing and verification using and edit distance algorithm
//compile with make test
//
#include <iostream>
#include <string>
#include <vector>
#include <utility>		// pair
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


//takes text file listing files of known text, and another listing text to be compared 
int main(int argc, char **argv){

	string file=argv[1];
	
	string fileList=fileReadMmap(file);

	vector< pair <string, string> > fileArr=stringToVectorPair(fileList,",","\n");
	//need to actually check that output is any good and not empty
	cout<<fileArr[0].first<<", "<<fileArr[0].second<<endl;
		
	/*float avg=0;
	
	for(int i=0;i<kFileArr.size();++i){		
		avg+=(my_fitness(fileRead(uFileArr[i]),fileRead(kFileArr[i])))/kFileArr.size();
		//cout<<"===\n"<<i<<endl;
	}
	cout<<avg<<endl;
*/

	return 0;

}
