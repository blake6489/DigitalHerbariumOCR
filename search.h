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
#include "my_fitness.h"

UnsharpConfigs search(UnsharpConfigs center, vec5 bound, vector <string> & f);
//returns the new center of the search pattern
//recursive
//given the center, and the range of the outer search shell, which will shrink
UnsharpConfigs search(UnsharpConfigs center, vec5 bound, vector <string> & f)
{
	static int cycle=0;
	int cycleLimit =6;
	++cycle;
	vector<UnsharpConfigs> grid;
	vector<float> score;
	//fill a 3x3x3x3 x3 grid for -unsharp settings and the -white-threshold setting
	for(int r=-1;r<=1;++r){
		for(int d=-1;d<=1;++d){
			for(int a=-1;a<=1;++a){
				for(int t=-1;t<=1;++t){
					for(int w=-1;w<=1;++w){
						grid.push_back(UnsharpConfigs(
							center.radius+r*bound.radius,
							center.dev+d*bound.dev,
							center.amount+a*bound.amount,
							center.threshold+t*bound.threshold,
							center.whiteThreshold+w*bound.whiteThreshold
							));
						score.push_back(0);
					}
				}
			}
		}
	}
	float bestScore=0;
	float oldBest=0;
	int bestIndex=0;
	for(int i=0;i<(int)grid.size();++i){
		score[i]=my_fitness(grid[i], f);
		oldBest=bestScore;
		bestScore=max(bestScore,score[i]);
		if(oldBest!=bestScore){
			bestIndex=i;
		}
	}
	cout<<grid[bestIndex]<<" "<<bestScore<<endl;
	
	//clamp ratio by which new bounds will change
	float shrinkBound=1-bestScore;
	if (shrinkBound > 0.9)
	shrinkBound = 0.9;
	if (shrinkBound < 0.49)
	shrinkBound = 0.49;

	vec5 newBound = bound*shrinkBound;

	if(bestScore<0.95 && cycle<cycleLimit)
	{
		return search(grid[bestIndex],newBound,f);
	}else{
		return grid[bestIndex];
	}

}

