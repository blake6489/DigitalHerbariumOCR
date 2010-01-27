
#include <iostream>
#include <vector>
#include <string>

#include <fstream>

#include <cstring>
#include <cstdlib>

using namespace std;


#include "UnsharpConfigs.h"
#include "my_run.h"

int main(){
	srand(time(NULL));

	vector<string> f;
/*	f.push_back("H1023457.tiff");
	f.push_back("H1023465.tiff");
	f.push_back("H1026033.tiff");
	f.push_back("H1026043.tiff");
	f.push_back("H1026076.tiff");
	f.push_back("H1026090.tiff");*/
	f.push_back("H1026101.tiff");
	
	//center
	UnsharpConfigs c(16,4.7,1,.17,40000);
	my_run(c,f);



	return 0;

}
