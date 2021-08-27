#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Kickstart 2020 Round C
    Problem name: Stable Wall
    Problem link: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/00000000003379bb
*/

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 2e5+5;
const int M = 1e6;
const ll INF = (ll)(1e18);
const int inf = 1e9;
const ll MOD = 998244353LL;

int n, m;
string a[35];
set<int> G[26];
int inDeg[26];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 26; i++) {
        G[i].clear();
        inDeg[i] = inf;
    }
    set<char> letters;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            letters.insert(a[i][j]);
            inDeg[a[i][j]-'A'] = 0;
        }
    }

    int cnt = letters.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = a[i][j] - 'A';
            for (int k = i+1; k < n; k++) {
                int v = a[k][j] - 'A';
                if (u != v && !G[v].count(u)) {
                    G[v].insert(u);
                    inDeg[u]++;
                }
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (inDeg[i] == 0) q.push(i);
    }

    string ans = "";
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        char tmp = (char)(v+'A');
        ans += tmp;
        for (auto to: G[v]) {
            inDeg[to]--;
            if (inDeg[to] == 0) {
                q.push(to);
            }
        }
    }

    if (ans.size() < cnt) {
        cout << "-1\n";
        return;
    }

    cout << ans << "\n";
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
