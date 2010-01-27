//used in the unsharp modifications of the images

#ifndef UTILS_H_INCLUDE
#define UTILS_H_INCLUDE

struct vec5 {
	public:
	int radius;
	float dev;
	int amount;
	float threshold;
	int whiteThreshold;

	vec5(int r, float d, int a, float t, int w)
	:radius(r), dev(d), amount(a), threshold(t), whiteThreshold(w)
	{
	
	}
};

vec5 operator * (  vec5  a,const float & b)
{
	a.radius=(int)((float)a.radius*b);
	a.dev=a.dev*b;
	a.amount=(int)((float)a.amount*b);
	a.threshold=a.threshold*b;
	a.whiteThreshold=(int)((float)a.whiteThreshold*b);
	return a;
}



//returns string of file
string fileRead(string file)
{
	string line;
	string out;
	ifstream myfile (file.c_str());
	if (myfile.is_open())
	{
		while (! myfile.eof() )
		{
			getline (myfile,line);
			out+=line;
		}
		myfile.close();
	}

	else cout << "Unable to open file:"<< file; 
	
	return out;
}
#endif

