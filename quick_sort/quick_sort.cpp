/*
OK!!  Test 0: 358
OK!!  Test 1: 339
OK!!  Test 2: 548
OK!!  Test 3: 490
OK!!  Test 4: 454
OK!!  Test 5: 512
OK!!  Test 6: 468
OK!!  Test 7: 458
OK!!  Test 8: 456
OK!!  Test 9: 453
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
int Partition(vector<T> &v, int left, int right){
    int pivot = Rand(left, right);
    swap(v[pivot], v[right]);

    int l = left, r = right-1;
    while(1){
        while(l <= r && v[l] < v[right]) ++l;
        while(l <= r && v[r] >= v[right]) --r;
        if(l>=r) break;
        swap(v[l], v[r]);
        ++l;
        --r;
    }
    swap(v[right], v[l]);
    return l;
}

int cnt=0;
template <typename T>
void Quick_sort(vector<T> &v, int left, int right){

    if(left >= right) return;
    if(right - left ==  1){
        if(v[left] > v[right]) swap(v[left], v[right]);
        return;
    }
    int pos = Partition(v, left, right);

    //cout<<left<<" "<<right<<" "<<pos<<endl;
    Quick_sort(v, left, pos-1);
    Quick_sort(v, pos+1, right);
    
}




int32_t main(){


    
    return 0;
}