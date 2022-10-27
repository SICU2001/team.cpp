#include <iostream>
#include <cmath>

using namespace std;

int x, y, N;

int main(){

	cin >> N >> x >> y;
	cout << N-1-(int)min(log2((~x+1)&x), log2((~y+1)&y));

	return 0;
}
