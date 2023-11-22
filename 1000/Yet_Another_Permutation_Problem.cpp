#include <bits/stdc++.h>
using namespace std;

#define fastio()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x)     \
	cerr << #x << " "; \
	_print(x);         \
	cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t)
{
	cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);

template <class T, class V>
void _print(pair<T, V> p)
{
	cerr << "{";
	_print(p.first);
	cerr << ",";
	_print(p.second);
	cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T>
void _print(set<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
	cerr << "[ ";
	for (T i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
	cerr << "[ ";
	for (auto i : v)
	{
		_print(i);
		cerr << " ";
	}
	cerr << "]";
}

void solve()
{
	int n;
	cin >> n;

	vector<vector<int>> v(2);
	v[0].push_back(n * 2);
	v[1].push_back(n * 2 - 1);

	int l = 1, r = n * 2 - 2;

	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 1)
			v[0].push_back(r), r--;
		else
			v[0].push_back(l), l++;
	}

	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 1)
			v[1].push_back(r), r--;
		else
			v[1].push_back(l), l++;
	}

	reverse(v[1].begin(), v[1].end());
	
	for(auto&i : v[0])cout<<i<<" ";
	cout<<nline;
	for(auto&i : v[1])cout<<i<<" ";
	cout<<nline;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/nazib/Desktop/cf/Error.txt", "w", stderr);
#endif
	fastio();
	int TC;
	cin >> TC;

	while (TC)
	{
		solve();
		TC--;
	}
}
