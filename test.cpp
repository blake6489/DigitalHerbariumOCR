
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>

#include <Magick++.h>

using namespace std;
using namespace Magick;

#include "tools/UnsharpConfigs.h"


int main()
{
try {

Image image;

image.read("/home/blake/Desktop/OCR/img/H1023457.cr2" );

image.threshold ( 36252 );
//radius_,sigma_,amount_,threshold_ );
image.unsharpmask(5,3.3,4,5);
image.monochrome();
image.depth (1);

image.write("testthing.tif");

// Display the result
image.display( );
}
catch( exception &error_ )
{
cout << "Caught exception: " << error_.what() << endl;
return 1;
}

return 0;
}
