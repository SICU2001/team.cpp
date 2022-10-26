#include <iostream>

using namespace std;

int main(){
    int C[] = {0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4}, ms, js;
    int N; cin>>N;
    int m1, m2; cin>>m1>>m2;
    C[m1]--;
    C[m2]--;
    ms += (m1 >= 10)?10:m1 + (m2 >= 10)?10:m2;
    cin>>m1>>m2;
    C[m1]--;
    C[m2]--;
    js += (m1 >= 10)?10:m1 + (m2 >= 10)?10:m2;

    while(N--){
        cin>>m1;
        C[m1]--;
        ms += (m1 >= 10)?10:m1;
        js += (m1 >= 10)?10:m1;
    }
    int ans = -1;
    for(int i = 1; i<=13; i++){
        if(C[i] == 0) continue;
        if((ms + (i>=10)?10:i) == 23){
            ans = i;
            break;
        }
        else if((js +(i>=10)?10:i) > 23){
            ans = i;
            break;
        }
        else if((ms + (i>=10)?10:i) > 23)
            break;
    }
    cout<<ans;
    return 0;
}