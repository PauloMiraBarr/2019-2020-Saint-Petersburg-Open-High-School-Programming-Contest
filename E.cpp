#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define gg(i, m, n) for(i = m ; i < n ; i++)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

vector<pair<int, int>> valPos;
vector<int> ans;

int main()
{
    // ifstream cin("input.txt"); ofstream cout("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n; ans.resize(n);
    int i; gg(i, 0, n) {
        int a; cin >> a;
        valPos.pb({a, i});
    }

    sort(all(valPos), [&](pair<int, int> &A, pair<int, int> &B) {
        auto [a, x] = A;
        auto [b, y] = B;
        if(!a and !b) return (x < y);
        else if(!a) return true;
        else if(!b) return false;
        else return (x < y);
    });

    int cur = 1;
    int m = (1 << n) - 1;
    gg(i, 0, n) {
        auto [val, pos] = valPos[i];
        if(!val) m -= cur;
        ans[pos] = cur;
        if(val) ans[pos] *= val;
        cur <<= 1;
    }

    cout << m << "\n";
    for(auto a: ans) cout << a << " "; cout << "\n";

    return 0;
}// CcrimsonAlice
