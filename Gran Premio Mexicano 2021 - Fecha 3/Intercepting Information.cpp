
#include <iostream>

using namespace std;

int main(){
    char ans = 'S';
    for(int i = 0; i<8; i++){
        int t; cin>>t;
        if(t == 9)
            ans = 'F';
    }
    cout<<ans;
    return 0;
}
