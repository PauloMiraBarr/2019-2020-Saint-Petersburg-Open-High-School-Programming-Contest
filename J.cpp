#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define gg(i, m, n) for(i = m ; i < n ; i++)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

const int nm = 6e5 + 5;
const int nm1 = 4 * nm;
const int mod = 1e9 + 7;

int add(int a, int b) { return ((a + b < mod)? a + b : a + b - mod); }
int mul(int a, int b) { return (1LL * a * b % mod); }

struct SegmentTree {
    int sg[nm1];
    int N;
    SegmentTree(){}
    void build(int id, int l, int r) {
        if(l + 1 == r) { sg[id] = 1; return; }
        int i = (id << 1), mid = ((r + l) >> 1);
        build(i, l, mid); build(i^1, mid, r);
        sg[id] = sg[i] + sg[i^1];
    }

    int query(int id, int l, int r, int &L, int &R) {
        if(r <= L or R <= l) return (int)0;
        if(L <= l and r <= R) return sg[id];
        int i = (id << 1), mid = ((r + l) >> 1);
        int a = query(i, l, mid, L, R);
        int b = query(i^1, mid, r, L, R);
        return (a + b);
    }

    void modify(int id, int l, int r, int &var) {
        if(var + 1 <= l or r <= var) return;
        if(l + 1 == r) { sg[id] = 0; return; }
        int i = (id << 1), mid = ((r + l) >> 1);
        modify(i, l, mid, var); modify(i^1, mid, r, var);
        sg[id] = sg[i] + sg[i^1];
    }

    int Que(int l, int r) {
        return query(1, 0, N, l, r); }
    void Upd(int pos) {
        modify(1, 0, N, pos); }
} st;

int Delta[nm];
int Order[nm];
int Index[nm];
pair<int, int> pos[nm];

int main()
{
    // ifstream cin("input.txt"); ofstream cout("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vector<int> ar; ar.resize(n); ar.pb(n + 1);
    for(auto &a: ar) cin >> a;
    for(int i = 0 ; i < n + 1 ; i++) {
        ar.pb(ar[i]);
        pos[ar[i]] = {i, i + n + 1};
        // cout << ar[i] << ": " << i << " - " << n + i + 1 << "\n";
    }

    st.N = sz(ar);
    st.build(1, 0, st.N);

    for(int i = n ; i > 1 ; i--) {
        int l, r;
        l = pos[i].first;
        r = ((pos[i].first < pos[i + 1].first)? pos[i + 1].first : pos[i + 1].second);
        l++;
        Delta[i] = st.Que(l, r);
        st.Upd(pos[i].first); st.Upd(pos[i].second);
        st.Upd(pos[i + 1].first); st.Upd(pos[i + 1].second);
    }

    for(int i = 2 ; i <= n ; i++) {
        Order[i] = add(mul(Order[i - 1], i), Delta[i]);
        Index[i] = add(Index[i - 1], Order[i]);
    }

    cout << add(Index[n], 1) << "\n";

    return 0;
}// CcrimsonAlice
