#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> bit ;


void update(int idx, int val) {
    while (idx < bit.size()) {
        bit[idx] += val;
        idx += (idx & (-idx));
    }
}

int query(int idx) {
    int ans = 0;
    while (idx > 0) {
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr) ;

    int n , m , c ;
    cin >> n >> m >> c;
    bit.resize(n+1) ;

    for (int i = 1; i <= m; i++) {
        char op;
        cin >> op;
        if (op == 'S') {
            int u, v, k;
            cin >> u >> v >> k;
            update(u, k);
            update(v + 1, -k);
        } else {
            int p;
            cin >> p;
            cout << query(p)+c << "\n";
        }
    }

    return 0;
}
