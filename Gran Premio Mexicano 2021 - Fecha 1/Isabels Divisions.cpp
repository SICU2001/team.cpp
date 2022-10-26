
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long n2 = n;
    int len = log10(n)+1, digito, cont=0;

    for(int i=0;i<len;i++){
        digito = n2%10;
        n2 /= 10;
        if(digito !=0){
        if(n%digito==0){
            cont++;
        }
        }
    }

    cout << cont;
}
