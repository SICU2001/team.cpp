#include <iostream>

using namespace std;

int cont, len;
bool nt;
string sec;

int main()
{
    cin >> cont >> sec;
    cont =0;
    for(int i=0; i<sec.size(); i++){
        len++;
        if(sec[i]!='a') len=0;
        if(len>1) cont++;
        if(len==2) cont++;
    }
    cout << cont;
}
