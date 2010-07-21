// convert.cpp
//Blake Eggemeyer
//1-2-2010

#include <iostream>
using std::cout;
using std::endl;
#include <cstdlib>
using std::exception;
#include <string>
using std::string;

#include <Magick++.h>
using namespace Magick;


#include "convert.h"

int convert(string ifile,string ofile){

	try {

		Image image;

		image.read(ifile);

		//radius_,sigma_,amount_,threshold_
		image.unsharpmask(4,1.1,4,0.05);

		image.threshold ( 32000 );
		
		//image.monochrome();
		image.depth (1);

		//should write to non-file type and passed to Tess API
		image.write(ofile);

		// Display the result
		//image.display( );
	}
	catch( exception &error_ )
	{
		cout << "Caught exception: IM image read - " << error_.what() << endl;
		return 1;
	}

	return 0;

}


