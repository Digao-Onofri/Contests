#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll vet[2000000];
ll memo[2000000];

ll fat(ll x){
    if(x<=1)return 1;
    if(memo[x])return memo[x];
    memo[x]=x*fat(x-1);
    return memo[x];
}

ll comb(ll n,ll p){
    return fat(n)/(fat(p)*fat(n-p));
}

int main(){
    ll n,x,i;
    cin>>n;
    memset(vet,0,sizeof(vet));
    memset(memo,0,sizeof(memo));
    for(i=0;i<n;i++){
        cin>>x;
        vet[x]++;
    }
    x=0;
    for(i=1;i<=n;i++){
        if(vet[i]>1)x+=comb(vet[i],2);
    }
    cout<<x<<endl;
    return 0;
}