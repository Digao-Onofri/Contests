#include <bits/stdc++.h>
using namespace std;

int main(){
    multiset<int> values;
    int n, a;
    long long calc;
    char op;

    cin >> n;
    calc = 1;
    while(n--){
        cin >> op; 
        if(op == 'Q'){
            if(values.size() == 0 || values.count(0)){
                cout << 0 << endl;
            }else{
                cout << calc << endl;
            }
        } else{
            if(op == '+'){
                cin >> a;
                if(a != 0){
                    calc *= a;
                }
                values.insert(a);
            } else{
                cin >> a;
                if(a != 0){
                    calc /= a;
                }
                auto it = values.find(a);
                values.erase(it);
            }
        }
    }

    return 0;
}