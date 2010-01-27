//imageconfigs.h
//Blake Eggemeyer
//8-13-2009
//

#ifndef IMAGECONFIGS_H
#define IMAGECONFIGS_H

#include <iostream>  // for std::cout
using std::cout;

#include <sstream>
using std::stringstream;

#include <iomanip>
using std::setprecision;
using std::setw;
using std::setfill;

#include <string>
using std::string;
//using std::substr;

#include "UnsharpConfigs.h"
//
class ImageConfigs{


public:
	
	bool whiteThreshBool;
	int whiteThresh;
	bool magnify;
	bool unsharpBool;
	UnsharpConfigs unsharp;

public:
//public ctors
	ImageConfigs();
	ImageConfigs(bool w, int wt, bool m, bool u, UnsharpConfigs us);

private:
//private ctrs

public:
//public functions

string toString() const;

};//end class 


//bool operator==(const CallIn & a ,const CallIn & b);
//bool operator!=(const CallIn & a ,const CallIn & b);

//ImageConfigs operator * ( const ImageConfigs & a,const float & b);
std::ostream & operator<<(std::ostream & outStream,const ImageConfigs & num);

#endif


