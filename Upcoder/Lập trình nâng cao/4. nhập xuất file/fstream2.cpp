//http://www.upcoder.xyz/index.php/problems/submit/114/5ad91f0232b5da10ad56a11847b62ac4/Nh%C3%A2%CC%A3p_file_&_xu%C3%A2%CC%81t_file
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main()
{
    int m,n;
    ifstream in ("input.txt");
    ofstream out ("output.txt");
    in>>m>>n;
    out<<m+n;
    in.close();
    out.close();
    return 0;
}