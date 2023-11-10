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

	vector<vector<int>> v;
	vector<pair<string, int>> s(n);
	int sum = 0, sz = 0, temp = 0;
	ll ans = 0;

	for (int i = 0; i <= 5; i++)
	{
		vector<int> t(46, 0);
		v.push_back(t);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> s[i].first;
		sum = 0;
		sz = s[i].first.size();

		for (int j = 0; j < sz; j++)
			sum += int(s[i].first[j] - '0');

		v[sz][sum]++;
		s[i].second = sum;
	}

	for (int i = 0; i < n; i++)
	{
		sz = s[i].first.size();
		temp = 0;

		if (sz == 5)
		{
			ans += v[5][s[i].second];

			temp = int(s[i].first[sz - 1] - '0');
			ans += v[3][max(s[i].second - (temp * 2), 0)];

			temp += int(s[i].first[sz - 2] - '0');
			ans += v[1][max(s[i].second - (temp * 2), 0)];

			temp = int(s[i].first[0] - '0');
			ans += v[3][max(s[i].second - (temp * 2), 0)];

			temp += int(s[i].first[1] - '0');
			ans += v[1][max(s[i].second - (temp * 2), 0)];
		}
		else if (sz == 4)
		{
			ans += v[4][s[i].second];

			temp = int(s[i].first[sz - 1] - '0');
			ans += v[2][max(s[i].second - (temp * 2), 0)];

			temp = int(s[i].first[0] - '0');
			ans += v[2][max(s[i].second - (temp * 2), 0)];
		}
		else if (sz == 3)
		{
			ans += v[3][s[i].second];

			temp = int(s[i].first[sz - 1] - '0');
			ans += v[1][max(s[i].second - (temp * 2), 0)];

			temp = int(s[i].first[0] - '0');
			ans += v[1][max(s[i].second - (temp * 2), 0)];
		}
		else if (sz == 2)
		{
			ans += v[2][s[i].second];
		}
		else
		{
			ans += v[1][s[i].second];
		}
	}

	cout << (ans) << nline;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/nazib/Desktop/cf/Error.txt", "w", stderr);
#endif
	fastio();
	int TC = 1;
	// cin >> TC;

	while (TC)
	{
		solve();
		TC--;
	}
}
