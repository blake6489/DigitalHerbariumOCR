// convert.cpp
//Blake Eggemeyer
//1-2-2010


#include <Magick++.h>
using namespace Magick;

#include "convert.h"

int convert(const char * file){

	try {

		Image image;

		image.read(file);

		image.threshold ( 36252 );
		//radius_,sigma_,amount_,threshold_
		image.unsharpmask(5,3.3,4,5);
		image.monochrome();
		image.depth (1);

		//should write to non-file type and passed to Tess API
		image.write("testthing.tif");

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


