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
	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> v(n);
	ll sum = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first;
		sum += v[i].first;
		v[i].second = -1;
	}

	int type, index, value;
	int mask = -1, maskIdx = -1;
	vector<ll> ans(q);

	for (int i = 0; i < q; i++)
	{
		cin >> type;

		if (type == 1)
		{
			cin >> index >> value;

			if (v[index - 1].second < maskIdx)
			{
				v[index - 1].first = mask;
				v[index - 1].second = i;
			}

			sum -= v[index - 1].first;
			sum += value;

			v[index - 1].first = value;
			v[index - 1].second = i;
		}
		else
		{
			cin >> value;
			mask = value;
			maskIdx = i;
			sum = n * 1ll * mask;
		}

		ans[i] = sum;
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] << nline;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("/home/nazib/Desktop/cf/Error.txt", "w", stderr);
#endif
	fastio();
	// int TC;
	// cin >> TC;

	// while (TC)
	// {
	solve();
	// TC--;
	// }
}
