#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;

int n,m,k,A,B;
long long resp=0;
#define N 100
#define REP(i, n) for(int i = 0; i < (n); i++)
struct Matrix {
	long long a[N][N];
	Matrix() {
		REP(i, n) {
			REP(j, n) {
				a[i][j] = 0;
			}
		}
	}
	Matrix operator *(Matrix other) {
		Matrix product = Matrix();
		REP(i, n) {
			REP(j, n) {
				REP(k, n) {
					product.a[i][k] += a[i][j] * other.a[j][k];
					product.a[i][k] %= mod;
				}
			}
		}
		return product;
	}
};

Matrix expo_power(Matrix a, long long n) {
	Matrix res = Matrix();
	REP(i, N) {
	    res.a[i][i] = 1;
	}
	while(n) {
		if(n % 2) {
			res = res * a;
		}
		n /= 2;
		a = a * a;
	}
	return res;
}

int main()
{
	cin >> n >> m >> k;

	Matrix single = Matrix();

	REP(i, m) {
	    cin >> A >> B;
	    single.a[A-1][B-1]++;
	    single.a[B-1][A-1]++;
	}

	Matrix total = expo_power(single, k);

	REP(i, n){
	    resp+=(total.a[0][i]%mod);
	    resp%=mod;
	}
	cout << resp << endl;
	return 0;
}
