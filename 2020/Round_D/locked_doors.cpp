#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Kickstart 2020 Round D
    Problem name: Locked doors
    Problem link: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000386d5c
*/

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 1e5+5;
const int M = 1e6;
const ll INF = (ll)(1e18);
const int inf = 2e9;
const ll MOD = 1000000007LL;

void solve() {
	int n, Q; cin >> n >> Q;
	vector<int> a(n+1);
	for (int i = 1; i < n; i++) {
		cin >> a[i];
	}
	
	for (int q = 0; q < Q; q++) {
		int s, k;
		cin >> s >> k;
		if (k == 1) {
			cout << s << " ";
			continue;
		}
		k--;
		
		deque<PII> l, r;
		for (int i = 1; i < s; i++) {
			l.emplace_back(i, a[i]);
		}
		for (int i = s+1; i <= n; i++) {
			r.emplace_back(i, a[i-1]);
		}
		
		while (true) {
			int room;
			if (l.empty()) {
				room = r.front().first;
				r.pop_front();
			} else if (r.empty()) {
				room = l.back().first;
				l.pop_back();
			} else {
				if (l.back().second < r.front().second) {
					room = l.back().first;
					l.pop_back();
				} else {
					room = r.front().first;
					r.pop_front();
				}		
			}
			
			k--;
			if (k == 0) {
				cout << room << " ";
				break;
			}
			
		}
	}
	
	cout << "\n";
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
