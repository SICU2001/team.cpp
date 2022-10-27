#include <iostream>
#include <set>

using namespace std;

multiset<int>ballons;
int N;

int main(){

	cin >> N;
	while(N--){
		int ballon; cin >> ballon;
		multiset<int>::iterator it = ballons.find(ballon);
		if(it!=ballons.end()) ballons.erase(it);
		ballons.insert(ballon-1);
	}


	cout << ballons.size();
	return 0;
}
