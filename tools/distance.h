#ifndef DISTANCE_H
#define DISTANCE_H
 
 #include <vector>
typedef std::vector<int> ints; 

class EditDistance {
private:
    ints d;
    /*Gets the minimum of three values */
    static inline int minimum( const int a, const int b, const int c )
    {
        int min = a;
        if ( b < min )
              min = b;
        if ( c < min )
              min = c;
          return min;
    };
public:
    EditDistance(  );
    int CalEditDistance( const char *s, const char *t, int limit );
};

#endif
