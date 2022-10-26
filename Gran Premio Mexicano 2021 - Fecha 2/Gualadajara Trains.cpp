#include <iostream>

using namespace std;

int rail[2000006];
int t1 = 0, t2;


int main(){
	cin >> t2;

	for(int i = 1; i < t2*2-1; i+=2) cin >> rail[i];
	for(int i = 0; i < t2*2-1; i+=2) cin >> rail[i];

	t2 = t2*2-2;
	while(t1 < t2)
		if(rail[t1] > rail[t2])
			rail[t1] -= rail[t2--];
		else
		if(rail[t1] < rail[t2])
			rail[t2] -= rail[t1++];
		else
			(t1++, t2--);
		

	cout << (t1==t2 && t1%2==0?rail[t1]:0);


	return 0;
}
