#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Kickstart 2020 Round C
    Problem name: Candies
    Problem link: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/0000000000337b4d
*/

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> PII;
typedef pair<ll, ll> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 2e5+5;
const int M = 1e6;
const ll INF = (ll)(1e18);
const int inf = 1e9;
const ll MOD = 998244353LL;

ll n, Q;
ll a[MAX_N][6];

// 0 -> basic sum of values
// 1 -> sum of values on odd positions
// 2 -> sum of values on even positions
// 3 -> sum of values on odd positions mul
// 4 -> sum of values on even positions mul
// 5 -> sum of values mul by coefficient

ll fen[MAX_N][6];

void reset() {
    for (ll i = 1LL; i <= n; i++) {
        for (ll j = 0LL; j < 6; j++) {
            fen[i][j] = 0LL;
        }
    }
}

void build(ll whoFen, ll whoA) {                      // function to build a fenwick tree in O(n) time
    for (ll i = 1LL; i <= n; i++) {
        fen[i][whoFen] += a[i][whoA];
        ll lsb = i & (-i);
        if (i+lsb <= n) fen[i+lsb][whoFen] += fen[i][whoFen];
    }
}

long long query(ll pos, ll whoFen) {
    long long ret = 0LL;
    while (pos > 0) {
        ret += fen[pos][whoFen];
        ll lsb = pos & (-pos);
        pos -= lsb;
    }
    return ret;
}

long long getSum(ll l, ll r, ll whoFen) {
    l--;
    return query(r, whoFen) - query(l, whoFen);
}

void update(ll pos, long long val, ll whoFen) {
    while (pos <= n) {
        fen[pos][whoFen] += val;
        ll lsb = pos & (-pos);
        pos += lsb;
    }
}

void solve() {
    cin >> n >> Q;
    reset();
    for (ll i = 1; i <= n; i++) {
        cin >> a[i][0];
        if (i%2) {
            a[i][1] = a[i][0];
            a[i][3] = a[i][0] * (i-1);
        } else {
            a[i][2] = a[i][0];
            a[i][4] = a[i][0] * i;
        }
        a[i][5] = a[i][0] * i;
    }

    build(0, 0);
    build(1, 1);
    build(2, 2);
    build(3, 3);
    build(4, 4);
    build(5, 5);


    ll ans = 0LL;
    for (ll q = 0; q < Q; q++) {
        char t; cin >> t;
        if (t == 'U') {
            ll x; ll val;
            cin >> x >> val;

            update(x, -a[x][0], 0);
            a[x][0] = val;
            update(x, a[x][0], 0);
            ll which = 1;
            if (x%2 == 0) which = 2;

            update(x, -a[x][which], which);
            a[x][which] = val;
            update(x, a[x][which], which);

            ll y = x;
            if (y%2) y--;
            update(x, -a[x][which+2], which+2);
            a[x][which+2] = val * y;
            update(x, a[x][which+2], which+2);

            update(x, -a[x][5], 5);
            a[x][5] = val*x;
            update(x, a[x][5], 5);

        } else {
            ll l, r;
            cin >> l >> r;
            ll xd = (ll)(l-1);

            ll sumOfMul = getSum(l, r, 5);
            ll sumOfBasic = getSum(l, r, 0);

            sumOfBasic *= xd;
            sumOfMul -= sumOfBasic;

            ll mult, basic;
            if (l%2) {
                mult = getSum(l, r, 4);
                basic = getSum(l, r, 2);
                ll tmp = l-1;
                basic *= tmp;
            } else {
                mult = getSum(l, r, 3);
                basic = getSum(l, r, 1);
                basic *= (l-2);
            }

            mult -= basic;
            sumOfMul -= 2*mult;
            ans += sumOfMul;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T; cin >> T;
    for (ll i = 1LL; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }


    return 0;
}
