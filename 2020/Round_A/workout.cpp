#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Kickstart 2020 Round A
    Problem name: Workout
    Problem link: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f5b
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
const int inf = 1e9;
const ll MOD = 1000000007LL;

int n, k;
vector<int> a;

bool ok(int x) {
    int needed = 0;
    for (int d: a) {
        if (d <= x) continue;
        needed += d/x;
        if (d%x == 0) needed--;
    }

    return needed <= k;
}

int solve() {
    cin >> n >> k;
    vector<int> x(n);
    a.clear();

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i < n; i++) {
        a.push_back(x[i] - x[i-1]);
    }

    int lo = 1;
    int hi = 1e9;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (ok(mid)) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }

    return lo;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << "\n";
    }






    return 0;
}
