/*
    Name: Interactive Sorting 
    Link: https://atcoder.jp/contests/practice/tasks/practice_2
*/

#include <bits/stdc++.h>
using namespace std;

bool lessThan(char a, char b){
    string ans;

    cout << "? " << a << " " << b << endl;
    cout.flush();
    
    cin >> ans;
    return ans == "<";
}

int findPos(string &s, char c){
    int l = 0;
    int r = s.size();

    while(l < r){
        int mid = (l + r) / 2;

        if(lessThan(c, s[mid])) r = mid;
        else l = mid + 1;
    }

    return l;
}

int main(){
    int n, q, pos;
    string order;

    cin >> n >> q;
    order += 'A';

    for(char c = 'B'; c < 'A' + n; c++){
        pos = findPos(order, c);
        order.insert(order.begin() + pos, c);
    }

    cout << "! " << order << endl;

    return 0;
}