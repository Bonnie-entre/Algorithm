#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int L;
    cin >> L;
    vector<pair<int, bool>> sizing(L);
    for(int i = 0; i < L; i++){
        cin >> sizing[i].first;
        sizing[i].second = false;
    }
    sort(sizing.begin(), sizing.end());
    pair<int, bool> x{ (-1), true};
    sizing.push_back(x);
    int isused = 0, i = 0, previous = -1;
    while(isused != L){
        if(i == L){
            cout << endl;
            i = 0;
            previous = -1;
        }
        if(sizing[i].second){
            i += 1;
            continue;
        }
        if(previous == sizing[i].first){
            i += 1;
            continue;
        }
        previous = sizing[i].first;
        sizing[i].second = true;
        cout << sizing[i].first << " ";
        isused++;
    }
    return 0;
}