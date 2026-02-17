/*
    Name: Interactive Graph (Simple Version)
    Link: https://codeforces.com/contest/2197/problem/E1
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    set<pair<int, int>> edges;
    set<pair<int, int>>::iterator it;
    vector<long long int> path;
    int t, n, i, size, j, value, amount;

    cin >> t;

    while(t--){
        cin >> n;
        edges.clear();
        i = 1;
        while(true){  
            path.clear(); 
            amount = 0;  
            cout << "? " << i << endl;
            cin >> size;
            for(j = 0; j < size; j++){
                cin >> value;
                path.push_back(value);
                cout << path[j] << " ";
            }
            cout << endl;

            if((size == 1 && value == n) || size == 0){
                break;
            }

            for(j = 1; j < path.size(); j++){
                if(edges.find({path[j - 1], path[j]}) == edges.end()){
                    edges.insert({path[j - 1], path[j]});
                    cout << path.size() << endl;
                    cout << "debug " << path[j - 1] << " " << path[j] << endl;
                    amount++;
                }
            }

            i += amount;
        }
        
        cout << "!" << edges.size() << endl;
        it = edges.begin();
        while(it != edges.end()){
            cout << it->first << " " << it->second << endl;
            it++;
        }
    }

    return 0;
}