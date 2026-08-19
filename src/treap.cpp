#include "bits/stdc++.h"
using namespace std;

// treap con point query di spostamento e controllo
// rand() non è molto buono come random seed

struct treap{
    int v, p, sz;
    treap *L, *R;
    treap(){}
    treap(int x){
        L = R = nullptr;
        v = x;
        p = rand();
        sz = 1;
    }
    treap *join(treap *_L, treap *_R){
        L = _L;
        R = _R;
        sz = 1;
        if(L) sz += L->sz;
        if(R) sz += R->sz;
        return this;
    }
};

int t_sz(treap* T){
    if(T) return T->sz;
    return 0;
}

pair<treap*, treap*> split(treap *T, int x){
    if(!T) return {nullptr, nullptr};
    if(t_sz(T->L) < x){
        auto [RL, RR] = split(T->R, x - t_sz(T->L) - 1);
        return {T->join(T->L, RL), RR};
    } else {
        auto [LL, LR] = split(T->L, x);
        return {LL, T->join(LR, T->R)};
    }
}

treap *merge(treap *L, treap *R){
    if(!L) return R;
    if(!R) return L;
    if(L->p > R->p){
        return L->join(L->L, merge(L->R, R));
    } else {
        return R->join(merge(L, R->L), R->R);
    }
}

treap *prealloc;

treap *insert(treap *T, int x, int i){
    auto [L, R] = split(T, i);
    treap *X = prealloc++;
    *X = treap(x);
    return merge(L, merge(X, R));
}

treap *erase(treap *T, int i){
    auto [L, MR] = split(T, i);
    auto [M, R] = split(MR, 1);
    return merge(L, R);
}

int qfind(treap *&T, int i){
    auto [L, MR] = split(T, i);
    auto [M, R] = split(MR, 1);
    int ans = M->v;
    T = merge(L, merge(M, R));
    return ans;
}

void qswap(treap *&T, int i, int j){
    int x = qfind(T, i);
    T = erase(T, i);
    T = insert(T, x, j);
}

void heapify(treap *T){
    treap *mx = T;
    if(T->L && T->L->p > T->p) mx = T->L;
    if(T->R && T->R->p > mx->p) mx = T->R;
    if(mx == T) return;
    swap(T->p, mx->p);
    heapify(mx);
}

treap *build(int l, int r){
    if (l == r) return nullptr;
    int mid = (l + r) >> 1;
    treap *current = prealloc++;
    *current = treap(mid);
    current->join(build(l, mid), build(mid + 1, r));
    heapify(current);
    return current;
}

int main(){
    int n, m; cin >> n >> m;
    prealloc = new treap[n + m];
    treap *T = build(0, n);
}
