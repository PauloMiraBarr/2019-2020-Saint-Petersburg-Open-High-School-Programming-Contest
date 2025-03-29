#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define gg(i, m, n) for(i = m ; i < n ; i++)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

const int nm = 1e5 + 5;
const int nm1 = 2e5 + 100;

set<int> cmpDsu[nm];
int idDsu[nm];
int ans[nm];
pair<int, int> Que[nm1];

void Ralei() {
    int i; gg(i, 0, nm) {
        idDsu[i] = i;
    }
}

int findDsu(int x) {
    while(x != idDsu[x]) {
        idDsu[x] = idDsu[idDsu[x]];
        x = idDsu[x];
    } return x;
}

void unionDsu(int a, int b) {
    int x = findDsu(a), y = findDsu(b);
    if(sz(cmpDsu[y]) < sz(cmpDsu[x])) swap(x, y);
    for(auto ty: cmpDsu[x]) {
        if(cmpDsu[y].count(ty)) {
            cmpDsu[y].erase(ty);
            ans[Que[ty].first]++;
            ans[Que[ty].second]++;
        }
        else cmpDsu[y].insert(ty);
    }
    idDsu[x] = idDsu[y];
    cmpDsu[x].clear();
}

int main()
{
    // ifstream cin("input.txt"); ofstream cout("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    Ralei();

    int n, m, k; cin >> n >> m >> k;
    int i = 0; while(m--) {
        int a, b; cin >> a >> b;
        Que[i] = {a, b};
        cmpDsu[a].insert(i); cmpDsu[b].insert(i);
        i++;
    }

    while(k--) {
        int a, b; cin >> a >> b;
        int x = findDsu(a), y = findDsu(b);
        if(x != y) unionDsu(x, y);
    }

    int q; cin >> q;
    while(q--) {
        char ty; cin >> ty;
        if(ty == '?') {
            int x; cin >> x;
            cout << ans[x] << "\n";
            continue;
        }

        int a, b; cin >> a >> b;
        if(ty == 'F') {
            int x = findDsu(a), y = findDsu(b);
            if(x == y) {
                ans[a]++; ans[b]++;
            }
            else {
                Que[i] = {a, b};
                cmpDsu[x].insert(i);
                cmpDsu[y].insert(i);
                i++;
            }
        }
        else {
            int x = findDsu(a), y = findDsu(b);
            if(x != y) unionDsu(x, y);
        }
    }

    return 0;
}
