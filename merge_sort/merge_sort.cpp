/*
OK!!  Test 0: 836
OK!!  Test 1: 847
OK!!  Test 2: 1156
OK!!  Test 3: 1156
OK!!  Test 4: 1164
OK!!  Test 5: 1157
OK!!  Test 6: 1153
OK!!  Test 7: 1165
OK!!  Test 8: 1155
OK!!  Test 9: 1152
*/

#include<iostream>
#include<vector>
#include<chrono>
#include<random>
#include<algorithm>
#include<string>
#include<fstream>
using namespace std;
using namespace std::chrono;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long l, long long r){
    return l + rd() % (r - l + 1);
}



template <typename T>
void Merge_sort(vector<T> &a, int left, int right){
    if(right-left<=0) return;
    int mid = left + right >> 1;
    
    Merge_sort(a, left, mid);
    Merge_sort(a, mid+1, right);

    vector<T> c(right-left+1);
    //sử dụng std::merge để gộp 2 dãy
    merge(a.begin()+left, a.begin()+mid+1, a.begin()+mid+1, a.begin()+right+1, c.begin());
    for(int i=left;i<=right;++i)
        a[i] = c[i-left];
}


int32_t main(){

    
    return 0;
}