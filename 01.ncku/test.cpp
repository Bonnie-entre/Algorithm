#include<iostream>
#include<vector>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

struct cmp{
    bool operator() (pair<string,int> &a, pair<string,int> &b)const
    {
        if(a.second > b.second)
            return true;
        if(a.second < b.second)
            return false;
        return a.first < b.first;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num, ind;
    string name;
    map<string,int,less<string>> m;

    cin >> num >> ind;
    for(int i=0; i<num; i++) {
        cin >> name;
        m[name]++;
    }

    vector<pair<string,int>> v(num);
    auto it = m.begin();

    for(int i=0; it!=m.end(); it++)
    {
        v[i].first = it->first;
        v[i++].second = it->second;
    }

    sort(v.begin(),v.end(),cmp());
    
    cout << v[ind-1].first;
    return 0;
}