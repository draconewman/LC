#include <bits/stdc++.h>
#include<iostream>
using namespace std;
#ifndef ONLINE_JUDGE
#include "fio.h"
#endif

#define ll long long
#define el "\n"
#define input(v)	for (auto& x: v) cin >> x
#define print(v)	for (auto& x: v) cout << x <<" "
//ll p=999998727899999;
ll prime=1000000007;
ll INF=1000000000000000000;
//void google(int t) {cout<<"Case #"<<t<<": ";}

////
// int op(vector<ll> v, int n) {
//     unordered_set<ll> s;
//     int res = 0;
//     for (int i = 0; i < n; i++) {
//         if (s.find(v[i]) == s.end()) {
//             s.insert(v[i]);
//             res++;
//         }
//     }
//     return res;
// }

void test_case() {
    ll n; cin>>n;
    vector<ll> v; input(v);
    ll even=0, odd=0;
    for(ll i=0; i<n; i++) {
        if(v[i]%2 == 0) even++;
        else odd++;
    }
    if(even==0 || odd==0) cout<<0<<el;
    else if(odd%2 == 0) cout<<odd/2<<el;
    else cout<<(odd/2)+1<<el;
}

signed main()
{
    FIO();
    ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); //cout<<"#hey";
    ll T; cin>>T;
    for(ll i=1; i<=T; i++) {
        //google(i);
        test_case();
    }
    //test_case();
    return 0;
}
