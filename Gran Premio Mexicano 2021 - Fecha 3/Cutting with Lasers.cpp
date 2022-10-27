#include <iostream>
#include <queue>

using namespace std;

#define MX 1000
#define n 1<<0
#define s 1<<1
#define e 1<<2
#define o 1<<3

int M[MX+5][MX+5], t[] = {n, s, e, o}, t2[][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
bool vis[MX+5][MX+5];

void pintaLinea(int x1, int y1, int x2, int y2){
    if(x1 != x2){
        for(int i = min(x1, x2); i<max(x1, x2); i++){
            M[y1][i] |= n;
            M[y1-1][i] |= s;
        }
    }
    else {
        for(int i = min(y1, y2); i<max(y1, y2); i++){
            M[i][x1-1] |= e;
            M[i][x1] |= o;
        }
    }
}

int bfs(int x, int y){
    queue <pair<int, int>> Q;
    pair<int, int> c(y, x);
    while(!Q.empty()) Q.pop();
    Q.push(c);
    int a = 0;
    while(!Q.empty()){
        c = Q.front();
        Q.pop();
        a++;
        for(int i = 0; i<4; i++){
            pair<int, int> te(c.first+t2[i][1], c.second+t2[i][0]);
            if(te.first < 0 || te.first > MX || te.second < 0 || te.second > MX || M[c.first][c.second]&t[i] || vis[te.first][te.second])
                continue;
            vis[te.first][te.second] = 1;
            Q.push(te);
        }
    }
    return a;
}

int main()
{
    int N; cin>>N;
    int fx, fy;
    cin>>fx>>fy;
    for(int i = 1; i<=N; i++){
        int tx, ty; cin>>tx>>ty;
        pintaLinea(fx, fy, tx, ty);
        fx = tx;
        fy = ty;
    }
    vis[0][0] = 1;
    bfs(0, 0);
    int ans = 0;
    for(int i = 0; i<=MX; i++){
        for(int j = 0; j<=MX; j++){
            if(!vis[i][j]){
                vis[i][j] = 1;
                int temp = bfs(j, i);
                ans = max(ans, temp);
            }
        }
    }
    cout<<ans;
}
