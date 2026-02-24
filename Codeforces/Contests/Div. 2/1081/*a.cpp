/*
    Name: String Rotation Game
    Link: https://codeforces.com/contest/2192/problem/A
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases, size, i, count;
    map<char, int> chars;
    map<char, int>::iterator it, aux;
    char character, word[150];

    cin >> cases;

    while(cases--){
        cin >> size;
        for(i = 0; i < size; i++){
            cin >> character;
            chars[character]++;
        }

        it = chars.begin();
        i = 0;
        while(i < size){
            if(it == chars.end()){
                it = chars.begin();
            }
            word[i] = it->first;
            chars[it->first]--;

            if(it->second == 0){
                aux = ++it;
                chars.erase(it->first);
            } else{
                aux = ++it;
            }
            it = aux;
            i++;
        }
        
        count = 0;
        for(i = 1; i < size; i++){
            if(word[i - 1] != word[i]){
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}