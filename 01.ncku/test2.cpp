#include<iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int num, tmp;
    cin >> num;
    map<int,int> m;

    for(;num; num--) {
        cin >> tmp;
        m[tmp]++;
    }

    while (!m.empty())
    {
        vector<int> v;
        auto it = m.begin();

        for(auto it=m.begin(); it != m.end();)
        {
            v.emplace_back((*it).first);
            if(--(*it).second == 0) {
                auto it2 = it++;
                m.erase(it2);
            }
            else it++;
        }

        for(int t : v)
            cout << t << ' ';
        cout << '\n';
    }

    return 0;
}