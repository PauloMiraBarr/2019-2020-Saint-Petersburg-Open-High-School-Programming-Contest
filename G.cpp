#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define gg(i, m, n) for(i = m ; i < n ; i++)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

#define ones(x) __builtin_popcount(x)
int add(int &a, int &b, int &mod)
{ return (((a + b) < mod)? a + b : a + b - mod); }
int rem(int &a, int &b, int &mod)
{ return ((a < b)? a - b + mod : a - b); }

const int nm = 4e7 + 5;

int s[nm];
int lastMask[nm];

void print_answer(int mask1, int mask2, int &n) {
    if(mask1 == -1) mask1 = 0;
    cout << ones(mask1) << "\n";
    if(ones(mask1)) {
        int i; gg(i, 0, n) if(mask1 & (1 << i)) cout << i + 1 << " ";
    } cout << "\n";
    cout << ones(mask2) << "\n";
    if(ones(mask2)) {
        int i; gg(i, 0, n) if(mask2 & (1 << i)) cout << i + 1 << " ";
    } cout << "\n";
}

int main()
{
    // ifstream cin("input.txt"); ofstream cout("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, mod; cin >> n >> mod;
    int i; gg(i, 0, n) {
        int a; cin >> a;
        a %= mod;
        s[(1 << i)] = a;
    }
    lastMask[0] = -1;
    gg(i, 1, (1 << n)) {
        if(ones(i) == 1) {
            if(lastMask[s[i]]) {
                // primera mascara: lastMask[s[i]]
                // segunda mascara: i
                int mask1 = lastMask[s[i]];
                int mask2 = i;
                print_answer(mask1, mask2, n);
                return 0;
            }
            lastMask[s[i]] = i;
            continue;
        }
        int p = i & (i - 1);
        s[i] = add(s[p], s[i ^ p], mod);
        if(lastMask[s[i]]) {
            // primera mascara: lastMask[s[i]]
            // segunda mascara: i
            int mask1 = lastMask[s[i]];
            int mask2 = i;
            print_answer(mask1, mask2, n);
            return 0;
        }
        lastMask[s[i]] = i;
    }

    cout << "-1\n";

    return 0;
}// CcrimsonAlice
