#include <iostream>

using namespace std;

int main() {
    
    int N, K;
    cin>>N>>K;
    if(N%K)
        cout<<N/K+1;
    else cout<<N/K;
    return 0;
}