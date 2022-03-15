#include<iostream>
#include <vector>
// #include <stack>
// #include <set> 
// #include <map>
// #include <string>
// #include <stdbool.h>
using namespace std;

void CountRank(long long numbers[][2], long long *counter, long long *arr_index, long long front, long long mid, long long end){
    vector<int> temp;
    long long l = front, r = mid;
    while(l < mid && r <= end){
        if( numbers[*(arr_index+l)][0] <= numbers[*(arr_index+r)][0]){
            if(numbers[*(arr_index+l)][1] <= numbers[*(arr_index+r)][1]){
                *(counter + (*(arr_index+r)) )+=1;
            }
            temp.push_back( *(arr_index+l) );
            l++;
        }
        else{
            if(numbers[*(arr_index+l)][1] >= numbers[*(arr_index+r)][1]){
                *(counter+ (*(arr_index+l)) )+=1;
            }
            temp.push_back( *(arr_index+r) );
            r++;
        }
    }
    while(l < mid){
        temp.push_back( *(arr_index+l) ); 
        l++;
    }
    while(r <= end){
        temp.push_back( *(arr_index+r) );
        r++;
    }
    for(int i=0; i<temp.size(); i++){
        *(arr_index+front+i) = temp.at(i);
    }

}

void MergeSort(long long numbers[][2], long long *counter, long long *arr_index, long long front, long long end){
    if(front<end){
        long long mid = (front+end) / 2;
        MergeSort(numbers, counter, arr_index, front, mid);
        MergeSort(numbers, counter, arr_index, mid+1, end);
        CountRank(numbers, counter, arr_index, front, mid+1, end);
    }
}

int main(){
    int num;
    cin >> num;

    long long arr[num][2];
    long long counter[num], arr_index[num];
    for(int i=0; i<num; i++){
        cin >> arr[i][0] >> arr[i][1];
        counter[i] = 0;
        arr_index[i] = i;
    }

    MergeSort(arr, &counter[0], &arr_index[0], 0, num-1);

    //Output
    for(int i=0; i<num; i++){
        cout << counter[i] << " ";
    }
    return 0;
}