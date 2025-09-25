#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, int> m;
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << fixed;
    cout.precision(4);
    string str;
    int N=0;
    while (getline(cin,str))
    {
        N++;
        m[str]++;
    }
    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        cout << iter->first << " "<<(double)iter->second/N*100<<"\n";
    }
}