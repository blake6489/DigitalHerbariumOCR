//UnsharpConfigs.h
//Blake Eggemeyer
//8-07-2009
//

#ifndef UNSHARPCONFIGS_H
#define UNSHARPCONFIGS_H

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

//
class UnsharpConfigs{
private:
	int radMax;
	float devMax;
	int amountMax;
	float thresholdMax;
	int whiteThresholdMax;
	
	int radMin;
	float devMin;
	int amountMin;
	float thresholdMin;
	int whiteThresholdMin;
public:
	int radius;
	float dev;
	int amount;
	float threshold;
	int whiteThreshold;

public:
//public ctors
	UnsharpConfigs();
	UnsharpConfigs(int radius,float dev, int amount,float threshold, int white);

private:
//private ctrs

//CallIn (const CallIn & other);
//CallIn & operator=(const CallIn & rhs);



public:
//public functions

void setRadius(int num);
void setDev(float num);
void setAmount(int num);
void setThreshold(float num);
void setWhiteThreshold(float num);

void setRadius();
void setDev();
void setAmount();
void setThreshold();
void setWhiteThreshold();

string toString() const;

};//end class 


//bool operator==(const CallIn & a ,const CallIn & b);
//bool operator!=(const CallIn & a ,const CallIn & b);

//UnsharpConfigs operator * ( const UnsharpConfigs & a,const float & b);
std::ostream & operator<<(std::ostream & outStream,const UnsharpConfigs & num);

#endif


