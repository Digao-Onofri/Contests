/*
    Name: All-in-one Gun
    Link: https://codeforces.com/contest/2192/problem/C
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases, n, i, j, count, aux, time;
    long long int h, k, value, bigger;
    vector<long long int> values;
    cin >> cases;

    while(cases--){
        values.clear();
        
        cin >> n >> h >> k;
        for(i = 0; i < n; i++){
            cin >> value;            
            if(i == 0){
                bigger = value;
                j = i;    
            } else{
                if(bigger < value){
                    bigger = value;
                    j = i;
                }
            }
            values.push_back(value);
        }

        if(n == 2){
            if(values[0] < values[1]){
                aux = values[1];
                values[1] = values[0];
                values[0] = aux;
            }
        } else{
            if(values[0] > values[1]){
                aux = values[1];
                values[1] = bigger;
                values[j] = aux;
            } else{
                aux = values[0];
                values[0] = bigger;
                values[j] = aux;
            }
        }

        count = i = time = 0;
        while(count < h){
            if(i == n){
                i = 0;
                time += k;
            }
            count += values[i];
            i++;
            time++;
        }
        
        cout << time << endl;
    }



    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases, n, i, j, count, aux, time;
    long long int h, k, value, bigger;
    vector<long long int> values;
    cin >> cases;

    while(cases--){
        values.clear();
        
        cin >> n >> h >> k;
        for(i = 0; i < n; i++){
            cin >> value;            
            if(i == 0){
                bigger = value;
                j = i;    
            } else{
                if(bigger < value){
                    bigger = value;
                    j = i;
                }
            }
            values.push_back(value);
        }

        if(n == 2){
            if(values[0] < values[1]){
                aux = values[1];
                values[1] = values[0];
                values[0] = aux;
            }
        } else{
            if(values[0] > values[1]){
                aux = values[1];
                values[1] = bigger;
                values[j] = aux;
            } else{
                aux = values[0];
                values[0] = bigger;
                values[j] = aux;
            }
        }

        count = i = time = 0;
        while(count < h){
            if(i == n){
                i = 0;
                time += k;
            }
            count += values[i];
            i++;
            time++;
        }
        
        cout << time << endl;
    }

    return 0;
}