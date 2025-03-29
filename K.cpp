#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define gg(i, m, n) for(i = m ; i < n ; i++)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

#define ff first
#define ss second
#define ter(x) cout << #x << " : " << x << "\n"
#define close(x) cout << x << "\n"; return 0
const int nm = 3e5 + 5;
const int nm2 = 1005;

int Ar[nm];
ll dp[nm];
bool Ninym[nm];

struct DSU {
    int idu[nm];
    DSU(){}
    int findDsu(int x) {
        while(x != idu[x]) {
            idu[x] = idu[idu[x]];
            x = idu[x];
        } return x;
    }
    bool unionDsu(int a, int b) {
        int x = findDsu(a);
        int y = findDsu(b);
        if(x == y) return false;
        idu[x] = idu[y];
        return true;
    }
} grpLrg, grpBru;

struct SqueQ {
    int N, blq, blc, ty;
    vector<pair<int, int>> Q[nm2];
    vector<pair<int, int>> ar;
    SqueQ(){}
    void init(int n, int i) {
        ty = i; N = n;
        blq = sqrt(n);
        blc = (n + blq - 1) / blq;
    }
    void show_init() {
        ter(N); ter(blq); ter(blc); ter(ty);
    }
    void sortQue(int id) {
        sort(all(Q[id]), [&](pair<int, int> &A, pair<int, int> &B) {
            return (A.ss < B.ss);
        });
    }
    int ArToId(int i) {
        return (2 * (i - ty) + ty);
    }
    bool bruteSolve(int l, int r) {
        int i; gg(i, l, r) {
            grpBru.idu[grpLrg.findDsu(ar[i].ff)] = grpLrg.findDsu(ar[i].ff);
            grpBru.idu[grpLrg.findDsu(ar[i].ss)] = grpLrg.findDsu(ar[i].ss); }
        gg(i, l, r) {
            if(!grpBru.unionDsu(grpLrg.findDsu(ar[i].ff), grpLrg.findDsu(ar[i].ss))) return false; }
        return true;
    }
    void solveBlock(int id) {
        sortQue(id);
        int fixedPoint = blq * (id + 1);
        int i; gg(i, 0, N + 1) grpLrg.idu[i] = i;
        int p = fixedPoint;
        bool lrgSol = true;
        for(auto [l, r]: Q[id]) {
            if(!lrgSol) {
                Ninym[ArToId(l)] = lrgSol;
                continue;
            }
            if(r <= fixedPoint) {
                Ninym[ArToId(l)] = bruteSolve(l, r);
            }
            else {
                while(p < r) {
                    auto [a, b] = ar[p++];
                    if(!grpLrg.unionDsu(a, b)) { lrgSol = false; break; }
                }
                if(!lrgSol) { Ninym[ArToId(l)] = lrgSol; continue; }
                Ninym[ArToId(l)] = bruteSolve(l, fixedPoint);
            }
        }
    }
    void solveQuerys() {
        int i; gg(i, 0, blc) {
            solveBlock(i);
        }
    }
} ArTy[2];

int main()
{
    // ifstream cin("input.txt"); ofstream cout("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    map<int, int> my;
    set<int> num;
    int n; cin >> n;
    int i; gg(i, 0, n) {
        cin >> Ar[i];
        num.insert(Ar[i]);
    }
    int p = 0;
    for(auto a: num) {
        my[a] = ++p;
    }

    ArTy[0].init(n, 1); ArTy[1].init(n, 0);
    
    gg(i, 0, n - 1) {
        int a = my[Ar[i]];
        int b = my[Ar[i + 1]];
        if(i & 1) ArTy[i & 1].ar.pb({a, b});
        else ArTy[i & 1].ar.pb({a, b});
    }
    
    gg(i, 0, n) {
        if(i & 1) {
            int l = (i + 1) / 2;
            int r = l + Ar[i];
            if(i + 2 * Ar[i] >= n) continue;
            if(!Ar[i]) Ninym[i] = true;
            else ArTy[0].Q[l / ArTy[0].blq].pb({l, r});
        } else {
            int l = i / 2;
            int r = l + Ar[i];
            if(i + 2 * Ar[i] >= n) continue;
            if(!Ar[i]) Ninym[i] = true;
            else ArTy[1].Q[l / ArTy[1].blq].pb({l, r});
        }
    }

    ArTy[0].solveQuerys();
    ArTy[1].solveQuerys();

    for(i = n - 1 ; i >= 0 ; i--) {
        if(Ninym[i]) dp[i] = 1;
        else { dp[i] = 0; continue; }
        int nex = i + 2 * Ar[i] + 1;
        if(nex >= n) continue;
        dp[i] += 1LL * dp[nex];
    }

    ll ans = 0;
    gg(i, 0, n) ans += dp[i];
    cout << ans << "\n";

    return 0;
}// CcrimsonAlice
