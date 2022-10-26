
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <string> p;

int main(){
    int N, K; cin>>N>>K;
    for(int i = 0; i<N; i++){
        string s; cin>>s;
        for(int i = 0; i<K; i++){
            if(s[i] == '*'){
                for(int i = 0; i<27; i++){
                    s[i] = ('a'+i);
                    p.push_back(s);
                }
            }
            break;
        }
    }
    sort(p.begin(), p.end();
    return 0;
}
