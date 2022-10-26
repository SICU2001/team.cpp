#include <iostream>

using namespace std;

int N, side, side2;;

int main()
{
    cin>>N;
    side = N/4;
    if(side * 4 == N)
        cout<<side*side<<"\n";
    else {
        N-=side*2;
        side2 = N/2;
        cout<<side*side2<<"\n";
    }
    return 0;
}
