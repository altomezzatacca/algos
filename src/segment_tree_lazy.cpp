#include "bits/stdc++.h"
using namespace std;
using ll = long long;
constexpr static ll inf = 1e16;

// template per segment tree lazy con query somma e minimo e update set e add

struct segtree{
    int sz = 1;
    struct node{
        int l, r;
        ll v_sum, v_min;
        bool sum_update, set_update;
        ll u_sum, u_set;
    };
    vector<node> t;
    segtree(){}
    segtree(int n, vector<ll> v){
        while(sz < n) sz <<= 1;
        t.resize(2 * sz);
        for(int i = 0; i < n; i++){
            t[sz + i].v_sum = v[i];
            t[sz + i].v_min = v[i];
            t[sz + i].l = i;
            t[sz + i].r = i + 1;
        }
        for(int i = n; i < sz; i++){
            t[sz + i].v_sum = 0;
            t[sz + i].v_min = inf;
            t[sz + i].l = i;
            t[sz + i].r = i + 1;
        }
        for(int i = sz - 1; i > 0; i--){
            t[i].v_sum = t[2 * i].v_sum + t[2 * i + 1].v_sum;
            t[i].v_min = min(t[2 * i].v_min, t[2 * i + 1].v_min);
            t[i].l = t[2 * i].l;
            t[i].r = t[2 * i + 1].r;
        }
    }
    void propagate(int node){
        if(t[node].set_update){
            t[node].v_sum = t[node].u_set * (t[node].r - t[node].l);
            t[node].v_min = t[node].u_set;
            if(node < sz){
                t[2 * node].set_update = 1;
                t[2 * node].sum_update = 0;
                t[2 * node].u_set = t[node].u_set;
                t[2 * node].u_sum = 0;
                t[2 * node + 1].set_update = 1;
                t[2 * node + 1].sum_update = 0;
                t[2 * node + 1].u_set = t[node].u_set;
                t[2 * node + 1].u_sum = 0;
            }
            t[node].u_set = 0;
            t[node].set_update = 0;
        }
        if(t[node].sum_update){
            t[node].v_sum += t[node].u_sum * (t[node].r - t[node].l);
            t[node].v_min += t[node].u_sum;
            if(node < sz){
                t[2 * node].sum_update = 1;
                t[2 * node].u_sum += t[node].u_sum;
                t[2 * node + 1].sum_update = 1;
                t[2 * node + 1].u_sum += t[node].u_sum;
            }
            t[node].u_sum = 0;
            t[node].sum_update = 0;
        }
    }
    ll get_sum(int node, int ql, int qr){
        ll ans = 0;
        propagate(node);
        if(qr <= t[node].l || t[node].r <= ql) return ans;
        if(ql <= t[node].l && t[node].r <= qr){
            ans = t[node].v_sum;
        } else if(node < sz){
            ans += get_sum(2 * node, ql, qr);
            ans += get_sum(2 * node + 1, ql , qr);
        }
        return ans;
    }
    ll get_min(int node, int ql, int qr){
        ll ans = inf;
        propagate(node);
        if(qr <= t[node].l || t[node].r <= ql) return ans;
        if(ql <= t[node].l && t[node].r <= qr){
            ans = t[node].v_min;
        } else if(node < sz){
            ans = min(ans, get_min(2 * node, ql, qr));
            ans = min(ans, get_min(2 * node + 1, ql , qr));
        }
        return ans;
    }
    void add_range(int node, int ql, int qr, ll x){
        propagate(node);
        if(qr <= t[node].l || t[node].r <= ql) return;
        if(ql <= t[node].l && t[node].r <= qr){
            t[node].sum_update = 1;
            t[node].u_sum += x;
            propagate(node);
        } else if(node < sz){
            add_range(2 * node, ql, qr, x);
            add_range(2 * node + 1, ql, qr, x);
            t[node].v_sum = t[2 * node].v_sum + t[2 * node + 1].v_sum;
            t[node].v_min = min(t[2 * node].v_min, t[2 * node + 1].v_min);
        }
    }
    void set_range(int node, int ql, int qr, ll x){
        propagate(node);
        if(qr <= t[node].l || t[node].r <= ql) return;
        if(ql <= t[node].l && t[node].r <= qr){
            t[node].sum_update = 0;
            t[node].u_sum = 0;
            t[node].set_update = 1;
            t[node].u_set = x;
            propagate(node);
        } else if(node < sz){
            set_range(2 * node, ql, qr, x);
            set_range(2 * node + 1, ql, qr, x);
            t[node].v_sum = t[2 * node].v_sum + t[2 * node + 1].v_sum;
            t[node].v_min = min(t[2 * node].v_min, t[2 * node + 1].v_min);
        }
    }
};

int main(){
    int n; cin >> n;
    vector<ll> v(n);
    for(auto &u: v) cin >> u;
    segtree seg = segtree(n, v);
}
