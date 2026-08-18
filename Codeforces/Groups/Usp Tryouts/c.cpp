#include <bits/stdc++.h>
using namespace std;

int vet[128];

int main(){
    string s;
    char c;
    int i;
    memset(vet,0,sizeof(vet));
    cin>>s;
    c=s[0];
    for(i=0;i<s.length();i++){
        vet[s[i]]++;
        if(c!=s[i]){//trocou
            cout<<c;
            if(vet[c]>1)cout<<vet[c];
            vet[c]=0;
        }
        c=s[i];
    }
    cout<<c;
    if(vet[c]>1)cout<<vet[c];
    vet[c]=0;
    cout<<endl;
    return 0;
}