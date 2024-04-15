// clear()- To clear the stream.
// str()- To get and set string object whose content is present in the stream. 
// operator <<- Add a string to the stringstream object. 
// operator >>- Read something from the stringstream object.

#include <string>
#include <sstream>
#include <iostream>
#include <map>


using namespace std;
void main()
{
    string s = "vgdfv hfvhdvj  vdvdv vdvdk v";
    stringstream str(s);
    string n;
    map <string, int> fw;
    int count = 0;
    while (str>>n)
    {
        count ++;
        fw[n]++;
    }
    int n = 123445;
    stringstream m;
    m << n;
    string f;
    m >> f;
    cout<<f;
//---------------------------------------------//
}
