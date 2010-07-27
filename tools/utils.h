//used in the unsharp modifications of the images
//file opening and handleing

#include <fstream>

#include <sys/mman.h>  // for mmap, munmap
#include <sys/stat.h>		//getting filesize
#include <fcntl.h>     // for open, close, write

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

//returns string of file
//should be better that other read method
string fileReadMmap(string file)
{

//struct from sys/stat.h
	struct stat results;
	int len;
    if (stat(file.c_str(), &results) == 0)
        len=results.st_size;
    else
        cout<<"In fileRead: error getting file size"<<endl;

	// OPEN THE FILE
    int fd = open(file.c_str(), O_RDONLY );
    if (fd == -1){
    	cout<<"In fileRead: error opening file"<<endl;
        return "";
    }
   	// MAP THE FILE
    void * addr = mmap((void *)0, len, PROT_READ , MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED){
    	cout<<"In fileRead: error mapping file"<<endl;
		return "";
    }

    char * p = (char *)addr;  // Get the memory as a char array
	
	//return a string
	string out;
	out.resize(len);
	for (int i = 0; i < len; ++i)
		out[i]=p[i];
		
    munmap(addr, len);  // Unmap memory
    close(fd);          // Close file

	return out;
}

//takes string and delimiter
//returns vector of the chopped up strings 
vector<string> stringToVector(string s, string searchString){
	int length=s.length();
	int pos=0;
	int pos2=1;
	vector<string> vec;
	int linecount=0;
	int linelimit=10000;
	int stringlimit=linelimit*300;
	//string searchString =".txt";
	while(length>pos && linecount<linelimit){
		pos2=s.find(searchString,pos)+searchString.length();
		string line=s.substr(pos,pos2-pos);
		vec.push_back(line);
		//cout<<line<<" p:"<<pos<<" p2:"<<pos2<<" line:"<<linecount<<endl;
		pos=pos2;
		++linecount;
	}
	return vec;
}

vector<string> stringToVectorPair(string s, string searchString){
	int length=s.length();
	int pos=0;
	int pos2=1;
	vector<string> vec;
	int linecount=0;
	int linelimit=10000;
	int stringlimit=linelimit*300;
	//string searchString =".txt";
	while(length>pos && linecount<linelimit){
		pos2=s.find(searchString,pos)+searchString.length();
		string line=s.substr(pos,pos2-pos);
		vec.push_back(line);
		//cout<<line<<" p:"<<pos<<" p2:"<<pos2<<" line:"<<linecount<<endl;
		pos=pos2;
		++linecount;
	}
	return vec;
}

#endif

