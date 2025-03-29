#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define gg(i, m, n) for(i = m ; i < n ; i++)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

int main()
{
    // ifstream cin("input.txt"); ofstream cout("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<int> ar; ar.resize(3); for(auto &a: ar) cin >> a; sort(all(ar));
    int ans = ar[2] - ar[1] + 2 * (ar[2] - (ar[0] + ar[2] - ar[1]));
    cout << ans << "\n";

    return 0;
}
// CcrimsonAlice