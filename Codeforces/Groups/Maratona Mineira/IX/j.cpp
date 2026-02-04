/*
    Name: Um dia no museu
    Link: https://codeforces.com/group/YgJmumGtHD/contest/103794/problem/J
*/

#include <bits/stdc++.h>
using namespace std;

class Ponto{
    public: int x, y;
};

//Função para calcular o produto vetorial
double crossProduct(Ponto a, Ponto b){
    return a.x * b.y - a.y * b.x;
}

//Ponto p1 é uma aresta e p2 tambem
//Return true when the intersect happen
bool doIntersect(Ponto p1, Ponto p2, Ponto p3, Ponto p4){
    double d1 = crossProduct({p3.x - p1.x, p3.y - p1.y}, {p2.x - p1.x, p2.y - p1.y});
    double d2 = crossProduct({p4.x - p1.x, p4.y - p1.y}, {p2.x - p1.x, p2.y - p1.y});
    double d3 = crossProduct({p1.x - p3.x, p1.y - p3.y}, {p4.x - p3.x, p4.y - p3.y});
    double d4 = crossProduct({p2.x - p3.x, p2.y - p3.y}, {p4.x - p3.x, p4.y - p3.y});

    return (d1 * d2 <= 0) && (d3 * d4 <= 0);
}

int main(){
    int dots;
    int x, y, i;
    int posx, posy;
    vector<Ponto> all;

    cin >> dots;
    for(i = 0; i < dots; i++){
        cin >> x >> y;
        all.push_back({x, y});
    }

    cin >> posx >> posy;

    for(i = 0; i < dots; i++){
        if(doIntersect(all[i], all[(i + 1) % dots], Ponto{posx, posy}, all[(i - 1 + dots) % dots])){
            cout << "N" << endl;
            return 0;
        }
        if(doIntersect(all[i], all[(i + 1) % dots], Ponto{posx, posy}, all[(i + 2) % dots])){
            cout << "N" << endl;
            return 0;
        }  
    }

    cout << "S" << endl;

    return 0;
}