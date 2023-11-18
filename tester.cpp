/// In the name of Allah the most beneficent the most merciful

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#include "radix_sort.h"

using namespace std;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rnd(RANDOM);
#define rand() rnd()
inline unsigned long long randll(){return (((unsigned long long)rand())<<32)+rand();}

clock_t START;
#define Start START = clock();
#define Time cout << "takes "<< 1000.0L*(clock() - START)/CLOCKS_PER_SEC << " ms time." << endl;

int main()
{
	for(auto n: {1000, 1'000'000, 100'000'000} )
	{
		vector<long long> A(n), B(n);
		for(int i = 0; i < n; i++)A[i] = B[i] = randll();
		Start
		cout << "for array of size " << n << " of 64-bit integers" << endl;
		cout << "radix sort: ";
		radix_sort<true, 9>(A.begin(), A.end());
		Time
		Start
		cout << "cpp sort: ";
		sort(B.begin(), B.end());
		Time
		cout << endl;
		assert(A == B);
	}

	for(auto n: {1000, 1'000'000, 100'000'000} )
	{
		vector<int> A(n), B(n);
		for(int i = 0; i < n; i++)A[i] = B[i] = rand();
		Start
		cout << "for array of size " << n << " of 32-bit integers" << endl;
		cout << "radix sort: ";
		radix_sort<true, 9>(A.begin(), A.end());
		Time
		Start
		cout << "cpp sort: ";
		sort(B.begin(), B.end());
		Time
		cout << endl;
		assert(A == B);
	}

	for(auto n: {1000, 1'000'000, 100'000'000} )
	{
		vector<int> A(n), B(n);
		for(int i = 0; i < n; i++)A[i] = B[i] = rand()%1'000'000;
		Start
		cout << "for array of size " << n << " of integers in range [0, 1e6)" << endl;
		cout << "radix sort: ";
		radix_sort<false, 7>(A.begin(), A.end());
		Time
		Start
		cout << "cpp sort: ";
		sort(B.begin(), B.end());
		Time
		cout << endl;
		assert(A == B);
	}
	

	return 0;
}

/// Thank God . . .
