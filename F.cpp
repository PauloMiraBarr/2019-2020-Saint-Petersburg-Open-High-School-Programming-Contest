#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define gg(i, m, n) for(i = m ; i < n ; i++)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

#define ter(x) cout << #x << " : " << x << "\n"
#define Hina cout << "Simp de Furina\n"

ll d;

struct Line {
    ll t, lm, tm;
    Line(){}
    Line(ll t, ll lm, ll tm) : t(t), lm(lm), tm(tm) {}
    void Show() {
        ter(t); ter(lm);
        cout << "----------\n"; 
    } 
} Line[4];

struct Point {
    int ty, pos;
    Point(){}
    Point(int ty, int pos) : ty(ty), pos(pos) {}
    void Show() {
        ter(ty); ter(pos);
        cout << "----------\n"; 
    }
};

ll fal(Point A, Point B) {
    if(A.ty + 1 == B.ty or (A.ty + 1) % 3 == B.ty) return d;
    return min(2 * d + Line[6 - A.ty - B.ty].t,
        Line[A.ty].t + d + Line[B.ty].t);
}

ll ver(Point A, Point B) {
    return min(d + Line[B.ty].t,
        3 * d + Line[A.ty].t + Line[6 - A.ty - B.ty].t);
}

ll foc(Point A, Point B) {
    return min(Line[A.ty].t + d, 
        2 * d + Line[6 - A.ty - B.ty].t + Line[B.ty].t);
}

ll PtoP(Point A, Point B) {
    if(A.ty == B.ty) {
        ll sum = Line[1].t + Line[2].t + Line[3].t;
        return min(Line[A.ty].t, 3 * d + sum - Line[A.ty].t);
    }
    else {
        if(A.pos == Line[A.ty].lm)
            if(B.pos == Line[B.ty].lm) return ver(A, B);
            else return fal(A, B);
        else
            if(B.pos == Line[B.ty].lm) return fal(B, A);
            else return foc(A, B);
    }
}

int main()
{
    // ifstream cin("input.txt"); ofstream cout("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int x, y, z; cin >> x >> y >> z;
    int a, b, c; cin >> a >> b >> c;
    int t1, t2, t3; cin >> t1 >> t2 >> t3 >> d;

    Line[1].t = t1; Line[1].lm = a; Line[1].tm = x;
    Line[2].t = t2; Line[2].lm = b; Line[2].tm = y;
    Line[3].t = t3; Line[3].lm = c; Line[3].tm = z;

    int k, i, l, j; cin >> k >> i >> l >> j;
    Point A, B;
    A = Point(k, i);
    B = Point(l, j);

    if(A.ty == B.ty) {
        if(A.pos <= Line[A.ty].lm and B.pos <= Line[B.ty].lm) {
            cout << Line[A.ty].t * abs(A.pos - B.pos) << "\n";
            return 0;
        }
        if(A.pos > Line[A.ty].lm and B.pos > Line[B.ty].lm) {
            cout << Line[A.ty].t * abs(A.pos - B.pos) << "\n";
            return 0;
        }
    }

    ll ans = 0;

    if(A.pos <= Line[A.ty].lm) {
        ans += Line[A.ty].t * (Line[A.ty].lm - A.pos);
        A = Point(A.ty, Line[A.ty].lm); }
    else {
        ans += Line[A.ty].t * (A.pos - Line[A.ty].lm - 1);
        A = Point(A.ty, Line[A.ty].lm + 1); }

    if(B.pos <= Line[B.ty].lm) {
        ans += Line[B.ty].t * (Line[B.ty].lm - B.pos);
        B = Point(B.ty, Line[B.ty].lm); }
    else {
        ans += Line[B.ty].t * (B.pos - Line[B.ty].lm - 1);
        B = Point(B.ty, Line[B.ty].lm + 1); }

    // ter(ans);
    // A.Show(); B.Show();

    ans += PtoP(A, B);
    cout << ans << "\n";

    return 0;
}// CcrimsonAlice
