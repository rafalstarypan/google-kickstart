#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Kickstart 2020 Round D
    Problem name: Beauty of tree
    Problem link: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000386edd
*/

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 5e5+5;
const int M = 1e6;
const ll INF = (ll)(1e18);
const int inf = 2e9;
const ll MOD = 1000000007LL;

int n;
int a, b;
vector<int> G[MAX_N];
int cntA[MAX_N], cntB[MAX_N];
int finalCntA[MAX_N], finalCntB[MAX_N];

void dfs(int v, int p, int dep) {
	ll beforeA = cntA[dep % a];
	ll beforeB = cntB[dep % b];
	
	cntA[dep % a]++;
	cntB[dep % b]++;
	
	for (int to: G[v]) {
		if (to == p) continue;
		dfs(to, v, dep + 1);
	}
	
	finalCntA[v] = cntA[dep % a] - beforeA;
	finalCntB[v] = cntB[dep % b] - beforeB;
}

long double probability(int v) {
	ll na = n - finalCntA[v];
	ll nb = n - finalCntB[v];
	
	long double pa = (long double)na / n;
	long double pb = (long double)nb / n;
	
	return 1.0 - pa*pb;
}

void solve() {
	cin >> n >> a >> b;
	
	memset(cntA, 0LL, sizeof(cntA));
	memset(cntB, 0LL, sizeof(cntB));
	
	for (int i = 1; i <= n; i++) {
		G[i].clear();
	}
	
	for (int i = 2; i <= n; i++) {
		int p; cin >> p;
		G[p].push_back(i);
		G[i].push_back(p);
	}
	
	dfs(1, -1, 0);
	
	long double ans = 0;
	
	for (int i = 1; i <= n; i++) {
		ans += probability(i);
	}
	
	
	cout << fixed << setprecision(8) << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		solve(); 
	}
	
	
	

    return 0;
}
