#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define gg(i, m, n) for(i = m ; i < n ; i++)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

const int nm = 2e5 + 5;
vector<pair<int, int>> Ninym[nm];
bool vis[nm] = {0};

void dfs(int u) {
    cout << u << " ";
    vis[u] = true;
    multiset<int> Hina;
    for(auto [a, b]: Ninym[u]) {
        Hina.insert(a); Hina.insert(b); }
    for(auto val: Hina) {
        if(Hina.count(val) < 2) continue;
        if(val == u) continue;
        if(vis[val]) continue;
        dfs(val);
        break;
    }
}

int main()
{
    // ifstream cin("input.txt"); ofstream cout("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    int i; gg(i, 0, n) {
        int a, b, c; cin >> a >> b >> c;
        Ninym[a].pb({b, c});
        Ninym[b].pb({a, c});
        Ninym[c].pb({a, b});
    }

    dfs(1); cout << "\n";

    return 0;
}
