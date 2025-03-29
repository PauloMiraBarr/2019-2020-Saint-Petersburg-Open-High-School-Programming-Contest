#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define gg(i, m, n) for(i = m ; i < n ; i++)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

vector<pair<int, int>> ar;

int main()
{
    // ifstream cin("input.txt"); ofstream cout("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, s; cin >> n >> m >> s;
    int i; gg(i, 0, n) {
        int c, a, b; cin >> c >> a >> b;
        if(c < 0) ar.pb({a, c});
        else ar.pb({b, c});
    }

    sort(all(ar), [&](pair<int, int> &A, pair<int, int> &B) {
        auto [d1, c1] = A;
        auto [d2, c2] = B;
        if(d1 < d2) return true;
        if(d1 == d2) return (c1 < c2);
        else return false;
    });

    bool Hina = true;
    for(auto [dy, deu]: ar) {
        s += deu;
        if(s < 0) Hina = false;
    }
    cout << ((Hina)? "NO" : "YES") << "\n";

    return 0;
}
// CcrimsonAlice
