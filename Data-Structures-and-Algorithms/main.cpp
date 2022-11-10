#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;

#define N 2
#define REP(i, n) for(int i = 0; i < (n); i++)
struct Matrix {
	long long a[N][N];
	Matrix() {
		REP(i, N) {
			REP(j, N) {
				a[i][j] = 0;
			}
		}
	}
	Matrix operator *(Matrix other) {
		Matrix product = Matrix();
		REP(i, N) {
			REP(j, N) {
				REP(k, N) {
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
    long long n;
	cin >> n;
	Matrix single = Matrix();
	single.a[0][0] = 0;
	single.a[0][1] = 1;
	single.a[1][0] = 1;
	single.a[1][1] = 1;
	Matrix total = expo_power(single, n);
	cout << total.a[0][0] << endl;
}
