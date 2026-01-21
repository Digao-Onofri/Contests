/*
    Name: Laércio
    Link: https://judge.beecrowd.com/en/problems/view/2812
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases, size, value, half, i, j;
    vector<int> values;
    vector<int>::iterator it;
    bool first;

    cin >> cases;

    while(cases--){
        values.clear();
        cin >> size;
        for(i = 0; i < size; i++){
            cin >> value;
            if(value & 0x1){
                values.push_back(value);
            }
        }

        it = values.begin();
        if(it != values.end()){
            sort(values.begin(), values.end());
            first = true;
            half = values.size() / 2;
            for(i = 0, j = values.size() - 1; i < half; i++, j--){
                if(i == j){
                    if(first){
                        cout << values[j];
                    } else{
                        cout << " " << values[j];
                    }

                    break;
                } 

                if(first){
                    first = false;
                    cout << values[j] << " " << values[i];
                } else{
                    cout << " " << values[j] << " " << values[i];
                }
            }

            if(values.size() & 0x1){
                if(first){
                    cout << values[j];
                } else{
                    cout << " " << values[j];
                }
            }
        }

        cout << endl;
    }

    return 0;
}