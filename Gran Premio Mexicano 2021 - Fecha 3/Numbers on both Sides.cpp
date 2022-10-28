#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N, K, L;
long long in, suma=0, resp=0;
vector<long long> A, B;
multiset<long long> g;
multiset<long long, greater<long long>> p;

int main()
{
    cin >> N;
    for(int i=0;i<N;i++){
        cin>> in;
        A.push_back(in);
    }

    for(int i=0;i<N;i++){
        cin>> in;
        B.push_back(in);
    }
    cin >> K >> L;

    for(int i=0;i<K;i++){
        suma+=A[i];
        if(g.size()<L){
            g.insert(B[i]);
            suma+=B[i];
        }
        else if(B[i]>*g.begin()){
            p.insert(*g.begin());
            suma-=*g.begin();
            g.erase(g.begin());
            g.insert(B[i]);
            suma+=B[i];
        }
        else{
            p.insert(B[i]);
        }
    }
    resp=max(resp,suma);

    for(int i=1;i<N;i++){
        suma-=A[i-1];
        suma+=A[(i+K-1)%N];
        if(B[i-1]>=*g.begin()){
            suma-=B[i-1];
            g.erase(g.find(B[i-1]));

            if(B[(i+K-1)%N]>=*g.begin() || B[(i+K-1)%N]>=*p.begin()){
                g.insert(B[(i+K-1)%N]);
                suma+=B[(i+K-1)%N];
            }
            else{
                p.insert(B[(i+K-1)%N]);
                g.insert(*p.begin());
                suma+=*p.begin();
                p.erase(p.begin());
            }
        }
        else{
            p.erase(p.find(B[i-1]));

            if(B[(i+K-1)%N]>*g.begin()){
                p.insert(*g.begin());
                suma-=*g.begin();
                g.erase(g.begin());
                g.insert(B[(i+K-1)%N]);
                suma+=B[(i+K-1)%N];
            }
            else{
                p.insert(B[(i+K-1)%N]);
            }
        }
        resp=max(resp,suma);
    }
    cout << resp;
}
