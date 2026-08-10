#include "bits/stdc++.h"
using namespace std;
constexpr static int mod = 1e9 + 7;
using ll = long long;

// potenza in tempo logaritmico
ll fast_pow(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e & 1) ans = (ans * b) % mod;
        b = (b * b) % mod;
        e >>= 1;
    }
    return ans;
}

// inverso in modulo mod
ll modular_inverse(ll n){
    return fast_pow(n, mod - 2);
}

// massimo comun divisore
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

// minimo comune multiplo
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

// lemma di burnside per collane su n perle e m colori
ll burnside(ll n, ll m){
    ll ans = 0;
    for(int i = 0; i < n; i++)
        ans = (ans + fast_pow(m, gcd(i, n))) % mod;
    ans = (ans * modular_inverse(n)) % mod;
    return ans;
}

// fattoriale
ll factorial(ll n){
    ll ans = 1;
    for(int i = 2; i <= n; i++)
        ans = (ans * i) % mod;
    return ans;
}

// binomiale
ll binomial(ll a, ll b){
    ll ans = 1;
    ans = (ans * factorial(a)) % mod;
    ans = (ans * modular_inverse(factorial(b))) % mod;
    ans = (ans * modular_inverse(factorial(a - b))) % mod;
    return ans;
}

// numeri di catalan
ll catalan(ll n){
    ll ans = 1;
    ans = (ans * modular_inverse(n + 1)) % mod;
    ans = (ans * binomial(2 * n, n)) % mod;
    return ans;
}

// \sum_{k = 1}^{n} d(k) con d(n) = numero di divisori di n
ll div(ll n){
    ll ans = 0;
    for(ll k = 1; k <= n;){
        ll v = n / k;
        ll r = n / v;
        ans = (ans + v * (r - k + 1)) % mod;
        k = r + 1;
    }
    return ans;
}

// crivello di eratostene
vector<bool> sieve(ll n){
    vector<bool> is_prime(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i <= n; i++){
        if(!is_prime[i]) continue;
        for(ll j = i * i; j <= n; j += i)
            is_prime[j] = 0;
    }
    return is_prime;
}

bool prime_check(ll n){
    for(ll i = 2; i * i <= n; i++)
        if(n % i == 0)
            return 0;
    return 1;
}

int main(){
    cout << "\n";
}
