#include <bits/stdc++.h>
using namespace std;

int main(){
    int p, v;
    queue<int> values;
    set<int> pres;
    map<int, int> who;

    cin >> p;
    for(int i = 1; i <= p; i++){
        cin >> v;
        who[v] = i;
        if(!pres.count(v)){
            pres.insert(v);
            values.push(v);
        } else{
            while(values.front() != v){
                pres.erase(values.front());
                values.pop();
            }
            values.pop();
            pres.insert(v);
            values.push(v);
        
        }
        cout << *pres.rbegin() << " " << who[*pres.rbegin()] << endl;
    }

    return 0;
}