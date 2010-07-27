// fitness evaluation function


#ifndef MY_FITNESS_H
#define MY_FITNESS_H

#include <iostream>
#include <vector>
#include <string>

#include <fstream>

#include <cstring>
#include <cstdlib>

using namespace std;
#include "tools/distance.h"
#include "tools/utils.h"
#include "tools/UnsharpConfigs.h"


//fit:3.72802 diff:196 max:364 min:97--76x5.8245+3+0.36276
//fit:3.80874 diff:169 max:366 min:99--31x3.3691+4+0.22789
//fit:3.85205 diff:152 max:365 min:98--53x3.3691+4+0.15165
//---
//-white-threshold 36252 -unsharp 0x1.22344+4+0.0498664    0.966165
//fit:0.278777 diff:802 max:1112 min:758  -white-threshold 40342 -unsharp 16x4.79885+1+0.171077
//uses the edit distance algorithm to test how well the text matches the real text
float my_fitness(string unknownTxt, string knownTxt)
{
	float fit=1;
	
	EditDistance e;
	float diff=e.CalEditDistance(knownTxt.c_str(),unknownTxt.c_str(),5000);
	float minDiff=max(knownTxt.length(),unknownTxt.length())-min(knownTxt.length(),unknownTxt.length());
	float maxDiff=max(knownTxt.length(),unknownTxt.length());
	//fit-=(diff-minDiff)/maxDiff;
	fit-=(diff)/maxDiff;
	
	//cout<<fit<<", "<<diff<<", "<<maxDiff<<", "<<minDiff<<endl;

	return fit;
	
}


#endif

