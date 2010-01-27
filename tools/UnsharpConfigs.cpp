//UnsharpConfigs.cpp
//Blake Eggemeyer
//8-07-2009
//UnsharpConfigs class file

#include <cstdlib>

#include "UnsharpConfigs.h"

//sets random parameters
UnsharpConfigs::UnsharpConfigs()
	:radMax(200),devMax(5.0),amountMax(100),thresholdMax(5.0),whiteThresholdMax(100000),
	radMin(0),devMin(0.0),amountMin(0),thresholdMin(0.0),whiteThresholdMin(0)
{
	this->setRadius();
	this->setDev();
	this->setAmount();
	this->setAmount();
	this->setWhiteThreshold();
}

UnsharpConfigs::UnsharpConfigs(int radius,float dev, int amount,float threshold, int white)
	:radMax(200),devMax(5.0),amountMax(100),thresholdMax(5.0),whiteThresholdMax(100000),
	radMin(0),devMin(0.0),amountMin(0),thresholdMin(0.0),whiteThresholdMin(0)
{
	this->setRadius(radius);
	this->setDev(dev);
	this->setAmount(amount);
	this->setThreshold(threshold);
	this->setWhiteThreshold(white);
}


//if inputs are out of range they are set to within bounds
void UnsharpConfigs::setRadius(int num)
{
	if(num>radMax){
		//cout<<"rad too high\n";
		radius=radMax;
	}else if(num<radMin){
		//cout<<"rad too low\n";
		radius=radMin;
	}else{
		radius=num;
	}
}

void UnsharpConfigs::setRadius()
{
	int num=(rand()+radMin)%radMax;
	if(num>radMax){
		//cout<<"rad too high\n";
		radius=radMax;
	}else if(num<radMin){
		//cout<<"rad too low\n";
		radius=radMin;
	}else{
		radius=num;
	}
}

//if inputs are out of range they are set to within bounds
void UnsharpConfigs::setDev(float num)
{
	if(num>devMax){
		//cout<<"dev too high\n";
		dev=devMax;
	}else if(num<devMin){
		//cout<<"dev too low\n";
		dev=devMin;
	}else{
		dev=num;
	}
}

void UnsharpConfigs::setDev()
{
	float num=((float)rand()/RAND_MAX)*(devMax)+devMin;
	if(num>devMax){
		//cout<<"dev too high\n";
		dev=devMax;
	}else if(num<devMin){
		//cout<<"dev too low\n";
		dev=devMin;
	}else{
		dev=num;
	}
}

//if inputs are out of range they are set to within bounds
void UnsharpConfigs::setAmount(int num)
{
	if(num>amountMax){
		//cout<<"amount too high\n";
		amount=amountMax;
	}else if(num<amountMin){
		//cout<<"amount too low\n";
		amount=amountMin;
	}else{
		amount=num;
	}
}

void UnsharpConfigs::setAmount()
{
	int num=(rand()+amountMin)%amountMax;
	if(num>amountMax){
		//cout<<"amount too high\n";
		amount=amountMax;
	}else if(num<amountMin){
		//cout<<"amount too low\n";
		amount=amountMin;
	}else{
		amount=num;
	}
}


//if inputs are out of range they are set to within bounds
void UnsharpConfigs::setThreshold(float num)
{
	if(num>thresholdMax){
		//cout<<"threshold too high\n";
		threshold=thresholdMax;
	}else if(num<thresholdMin){
		//cout<<"threshold too low\n";
		threshold=thresholdMin;
	}else{
		threshold=num;
	}
}

void UnsharpConfigs::setThreshold()
{
	float num=((float)rand()/RAND_MAX)*(thresholdMax)+thresholdMin;
	if(num>thresholdMax){
		//cout<<"threshold too high\n";
		threshold=thresholdMax;
	}else if(num<thresholdMin){
		//cout<<"threshold too low\n";
		threshold=thresholdMin;
	}else{
		threshold=num;
	}
}

//if inputs are out of range they are set to within bounds
void UnsharpConfigs::setWhiteThreshold(float num)
{
	if(num>whiteThresholdMax){
		//cout<<"threshold too high\n";
		whiteThreshold=thresholdMax;
	}else if(num<whiteThresholdMin){
		//cout<<"threshold too low\n";
		whiteThreshold=thresholdMin;
	}else{
		whiteThreshold=num;
	}
}

void UnsharpConfigs::setWhiteThreshold()
{
	float num=((float)rand()/RAND_MAX)*(whiteThresholdMax)+whiteThresholdMin;
	if(num>whiteThresholdMax){
		//cout<<"threshold too high\n";
		whiteThreshold=whiteThresholdMax;
	}else if(num<whiteThresholdMin){
		//cout<<"threshold too low\n";
		whiteThreshold=whiteThresholdMin;
	}else{
		whiteThreshold=num;
	}
}


string UnsharpConfigs::toString() const
{
	string out="";
	stringstream con;
	
	// place entire setting in string, un less that setting is zeroed
	if(whiteThreshold!=0)
		con <<" -white-threshold "<<whiteThreshold;
	if(radius!=0 || dev!=0 || amount!=0 || threshold!=0)
		con<<" -unsharp "<<radius<<'x'<<dev<<'+'<<amount<<'+'<<threshold;
		
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

/*UnsharpConfigs operator * ( const UnsharpConfigs & a,const float & b)
{
	a.setRadius((int)((float)a.radius*b));
	a.setDev=a.dev*b;
	a.setAmount=(int)((float)a.amount*b);
	a.setThreshold=a.threshold*b;
	return a;
}*/

std::ostream & operator<<( std::ostream & outStream,const UnsharpConfigs & num)
{
	return outStream<<num.toString();
}

