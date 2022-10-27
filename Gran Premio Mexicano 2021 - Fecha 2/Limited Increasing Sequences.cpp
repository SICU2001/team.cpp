#include <iostream>

using namespace std;

int DP[1000006], K;

int calc(int i){
	if(i == 1 || i == 2)
		DP[i] = 1;

	if(!DP[i])
		DP[i] = calc(i-1)*2 - (i%2?calc(i/2):0);

	DP[i] %= 1000000007;
	if(DP[i] < 0) DP[i] += 1000000007;

	return DP[i];
}

int main(){

	cin >> K;
	cout << calc(K);
		
	return 0;
}
