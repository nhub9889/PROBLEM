//http://www.upcoder.xyz/'index.php/23c70dcf13302ca790596b4983d19d51d1eaf2b720d6fa48e1d5f1b8bc9570d7/nwuTF''4zx!wrcrLKv~4y7'jqKOx&SiT'rrrhmNBx'yxfpky'?E46%27-78C6_6~7PMg6g72F_5E7?dkE2M8k2lL%27?@XaqlBMtTmP!txtnnm6/f2943150cd98067eb1ba939193cfbd8f8ff0b82d71b9c637d8f3df82a76b27cc
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
int main()
{
    string arr;
    getline(cin,arr);
    stringstream s(arr);
    string input, q;

    while (s>>q)
    {
        input+=q;
    }

    string reduce;
    for (int i = 0 ;i <input.size();i++)
    {
        if((input[i]>=48&&input[i]<=57)||(input[i]>=97&&input[i]<=122))
        {
            reduce+=input[i];
        }
        else if (input[i]>=65&&input[i]<=90)
        {
            reduce += (char)(input[i]+32);
        }
    }

    for (int i= 0 ;i<reduce.size()/2;i++)
    {
        
        if(reduce[i]!=reduce[reduce.size() - i-1] )
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}