#include <bits/stdc++.h>
using namespace std;

char vet[2001];
int pos[2001];

int main(){
    int i,n,x,l,r,j,maior_l,maior_r,soma;
    memset(pos,0,sizeof(pos));
    cin>>n;
    for(i=0;i<n;i++){
        cin>>x;
        if(x&0x1)vet[i]='I';
        else vet[i]='P';
    }
    x=0;
    for(i=0;i<n;i++){
        if(vet[i]=='I')x++;
        else x--;
        pos[i]=x;
    }
    maior_l=0;
    maior_r=n;
    for(i=0;i<n;i++){
        if(!pos[i]){
            l=r=j=i;
            j++;
            while(j<n&&pos[j]){
                if(pos[r] < pos[j]){
                    r = j;
                }
                j++;
            }
            if(pos[r]>pos[maior_r]){
                maior_r=r;
                maior_l=l;
            }
        }
    }
    for(i=maior_l;i<=maior_r;i++){
        if(vet[i]=='I')vet[i]='P';
        else vet[i]='I';
    }
    soma=0;
    for(i=0;i<n;i++){
        if(vet[i]=='P')soma++;
    }
    cout<<soma<<endl;
    return 0;
}