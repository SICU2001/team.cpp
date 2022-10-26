#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <string> p;

int main(){
    int N, K; cin>>N>>K;
    for(int i = 0; i<N; i++){
        string s; cin>>s;
        for(int j = 0; j<K; j++){
            if(s[j] == '*'){
                for(int k = 0; k<27; k++){
                    s[j] = ('a'+k);
                    p.push_back(s);
                }
                break;
            }
        }
    }
    sort(p.begin(), p.end());
    int ans = 0, c = 1;
    string s_ans = "";
    for(int i = 1; i<p.size(); i++){
        if(p[i-1] != p[i]){
            if(c > ans){
                s_ans = p[i-1];
                ans = c;
            }
            c = 0;
        }
        c++;
    }
    cout<<s_ans<<" "<<ans;
    return 0;
}
