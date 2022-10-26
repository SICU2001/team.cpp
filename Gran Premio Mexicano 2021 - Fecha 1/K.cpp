#include <iostream>
#include <algorithm>


#define INF 5000005
using namespace std;

int k, p, P[50], q;
int crib[500005];

int main()
{
    cin>>k>>p;
    for(int i = 0; i<p; i++)
        cin>>P[i];
    sort(P, P+p);
    crib[0] = 0;
    for(int i = 1; i<500005; i++){
        crib[i] = INF;
        for(int j = 0; j < p; j++){
            if(i - P[j] < 0)
                crib[i] = min(crib[i], P[j] - i);
            else crib[i] = min(crib[i], crib[i-P[j]]);
        }
    }
    for(int i = 0; i<k; i++){
        cin>>q;
        cout<<crib[q]<<"\n";
    }
    return 0;
}