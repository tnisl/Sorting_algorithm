/*
OK!! Test 0: 691
OK!! Test 1: 591
OK!! Test 2: 821
OK!! Test 3: 818
OK!! Test 4: 827
OK!! Test 5: 822
OK!! Test 6: 825
OK!! Test 7: 825
OK!! Test 8: 815
OK!! Test 9: 823
*/

#include<iostream>
#include<vector>
#include<chrono>
#include<random>
#include<algorithm>
#include<string>
#include<fstream>
#include<queue>
using namespace std;
using namespace std::chrono;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long l, long long r){
    return l + rd() % (r - l + 1);
}



template <typename T>
void Heap_sort(vector<T> &a){

    int n = a.size();
    --n;

    for(int i = 1, x; i <= n; ++i){
        x = i;
        while(x>1){
            if(a[x] > a[x>>1])
                swap(a[x], a[x>>1]),
                x>>=1;
            else break;
        }
    }
    int sz = n, next1, next2, x;
    while(sz>1){
        x = 1;
        swap(a[x], a[sz]);
        --sz;
        while(x < sz){
            
            next1 = (x<<1), next2 = (x<<1|1);
            if(next1 > sz) break;
            if(next2 <=sz && a[next1] < a[next2]) swap(next1, next2);

            if(next1 <= sz && a[x] < a[next1]){
                swap(a[x], a[next1]),
                x = next1;
                continue;
            }
            break;
        }
    }

}

int32_t main(){
    


    return 0;
}