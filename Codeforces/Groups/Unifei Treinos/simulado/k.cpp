#include <bits/stdc++.h>
using namespace std;

int esquerda(long long x1 , long long y1, long long x2, long long y2, long long x3, long long y3){
    if(((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) == 0){
        return 0;
    }
    return (((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) > 0 ? 1 : -1);
}

int main(){
    vector<pair<long long, long long>> points;
    long long n, i, x, y;
    int eh = 0;

    cin >> n;

    for(i = 0; i < n; i++){
        cin >> x >> y;
        points.push_back({x, y});
    }

    eh = esquerda(points[0].first, points[0].second, 
        points[n - 1].first, points[n - 1].second, points[1].first, points[1].second);

    for(i = 1; i < n - 1; i++){
        if(esquerda(points[i].first, points[i].second, points[i - 1].first, 
            points[i - 1].second, points[i + 1].first, points[i + 1].second)){
            if(eh == 0){
                eh = esquerda(points[i].first, points[i].second, points[i - 1].first, 
                    points[i - 1].second, points[i + 1].first, points[i + 1].second);
            } else{
                if(eh != esquerda(points[i].first, points[i].second, points[i - 1].first, 
                    points[i - 1].second, points[i + 1].first, points[i + 1].second)){
                        cout << "No" << endl;
                        return 0;
                    }
            }
        }
    }

    cout << (esquerda(points[n - 1].first, points[n - 1].second, 
        points[n - 2].first, points[n - 2].second, points[0].first, 
        points[0].second) != eh ? "No" : "Yes") << endl;

    return 0;
}