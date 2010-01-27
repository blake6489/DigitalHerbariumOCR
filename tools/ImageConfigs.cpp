//ImageConfigs.cpp
//Blake Eggemeyer
//8-13-2009
//ImageConfigs class file

#include <cstdlib>

#include "ImageConfigs.h"
#include "UnsharpConfigs.h"

//sets random parameters
ImageConfigs::ImageConfigs()
:whiteThreshBool(0),whiteThresh(0),magnify(0),unsharpBool(0),unsharp(0)
{
	
}

ImageConfigs::ImageConfigs(bool w, int wt, bool m, bool u, UnsharpConfigs us)
:whiteThreshBool(w),whiteThresh(wt),magnify(m),unsharpBool(u),unsharp(us)
{
	
}


string ImageConfigs::toString() const
{
	string out="";
	stringstream con;
	
	// place -unsharp int string
	con <<" -unsharp "<<this->unsharp.radius<<'x'<<this->unsharp.dev<<'+'<<this->unsharp.amount<<'+'<<this->unsharp.threshold;
		
	out+=con.str();
	return out;
}

/*bool operator==(const CallIn & a,const CallIn & b)
{
	if(a.getName()==b.getName() 
	&& a.getAreaCode()==b.getAreaCode() 
	&& a.getPhoneNumber()==b.getPhoneNumber() )
	{
		return true;
	}
	return false;
}

bool operator!=(const CallIn & a,const CallIn & b)
{
	if(a==b){return false;}
	return true;
}*/

/*ImageConfigs operator * ( const ImageConfigs & a,const float & b)
{
	a.setRadius((int)((float)a.radius*b));
	a.setDev=a.dev*b;
	a.setAmount=(int)((float)a.amount*b);
	a.setThreshold=a.threshold*b;
	return a;
}*/

std::ostream & operator<<( std::ostream & outStream,const ImageConfigs & num)
{
	return outStream<<num.toString();
}

