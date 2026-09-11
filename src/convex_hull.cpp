#include "bits/stdc++.h"
using namespace std;
using ll = long long;

// trova il convex hull di un set di punti in O(n log n)
// con il graham scan algorithm

struct ch {

    struct point {
        int ix;
        ll x, y;
    };

    int n;
    point pivot;
    vector<int> hull;
    vector<point> pts;
    map<int, int> m;

    ll cross_product (point a, point b, point c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }

    ll ddist (point a, point b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }

    bool comp_coord (point a, point b) { // ordina per y e poi per x
        if (a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    }

    bool comp_angle (point a, point b) { // ordina per angolo orientato
        ll cp = cross_product(pivot, a, b);
        if (cp == 0)
            return ddist(pivot, a) < ddist(pivot, b);
        return cp > 0;
    }

    ch(int n, vector<pair<int, int>> p) : n(n) {
        pts.resize(n);
        for (int i = 0; i < n; i++)
            pts[i].x = p[i].first, pts[i].y = p[i].second, pts[i].ix = i;
        int ix = 0;
        for (int i = 1; i < n; i++)
            if (comp_coord(pts[i], pts[ix]))
                ix = i;
        swap(pts[0], pts[ix]);
        pivot = pts[0];
        sort(pts.begin() + 1, pts.end(), [&](point a, point b) { // comp_angle è rotto
            ll cp = cross_product(pivot, a, b);
            if (cp == 0)
                return ddist(pivot, a) < ddist(pivot, b);
            return cp > 0;
        });
        vector<point> no_collinear;
        no_collinear.emplace_back(pts[0]);
        for (int i = 1; i < n; i++) {
            while (i < n - 1 && cross_product(pivot, pts[i], pts[i + 1]) == 0)
                i++;
            no_collinear.emplace_back(pts[i]);
        }
        pts = no_collinear;
        n = pts.size();
        if (n <= 3) {
            for (int i = 0; i < n; i++)
                hull.emplace_back(pts[i].ix);
            return;
        }
        for (int i = 0; i < n; i++)
            m[pts[i].ix] = i;
        hull.emplace_back(pivot.ix);
        hull.emplace_back(pts[1].ix);
        for (int i = 2; i < n; i++) {
            while ((int)hull.size() >= 2 && cross_product(pts[m[hull[(int)hull.size() - 2]]], pts[m[hull.back()]], pts[i]) <= 0)
                hull.pop_back();
            hull.emplace_back(pts[i].ix);
        }
    }

};

int main() {
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    for (auto &[x, y]: p) cin >> x >> y;
    ch c = ch(n, p);
}
