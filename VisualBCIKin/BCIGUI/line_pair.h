/*

*/

#pragma once
#include <iostream>
#include <string>

using namespace std;

class line_pair 
{
public:
    int line;
    int count;
    line_pair(int l = 0, int c = 0);

	friend bool operator> (const line_pair& A, const line_pair& B)
	{
		  return A.count > B.count;
	};

    bool operator> (const line_pair& C);	
    bool operator< (const line_pair& C);      
    bool operator==(const line_pair& C);
	    
    //friend ostream& operator<<(ostream&, line_pair&);
private:

};
