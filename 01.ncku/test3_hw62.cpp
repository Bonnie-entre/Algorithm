#include<iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int num, stones, len;
    cin >> num;
    
    for(;num; num--) {
        int go, back;

        cin >> stones >> len;
        int pos = 0, Max = -1, tmp;  //新增的石頭位置 Max為輸出
        char c;

        for(;stones; stones--) {
            cin >> c >> pos;
            if(c == 'b') {
                tmp = min(go, back);
                Max = max(Max, pos-tmp);
                go = back = pos;
            }
            else {
                if(go < back) {
                    Max = max(Max, pos-go);
                    go = pos;
                }
                else {
                    Max = max(Max, pos-back);
                    back = pos;
                }
            }
        }

        tmp = min(go, back);
        Max = max(Max, len-tmp);

        cout << Max << '\n';
    }
    
    return 0;
}