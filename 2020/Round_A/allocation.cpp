#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Kickstart 2020 Round A
    Problem name: Allocation
    Problem link: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f56
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

int solve() {
    int n, b; cin >> n >> b;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int i = 0;
    int ans = 0;
    while (i < n) {
        if (b < a[i]) break;
        ans++;
        b -= a[i];
        i++;
    }

    return ans;
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
