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
vector<double> a;


string PATH = "D:/.suc_vat/Y2/IT003/Buoi_2/Sort/test/";


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

void execute_test(int k){
    string t = "..inp";
    t[0] = '0' + k;
    ifstream fi(PATH + t);
    
    int n;
    fi>>n;
    a.resize(n);
    for(auto &x:a) fi>>x;
    
  



    auto start = high_resolution_clock::now();
    
    cerr<<"OK!!  ";
    Merge_sort(a, 0, n-1);

    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(stop - start);

    cerr<<"Test "<<k<< ": "<<duration.count()<<endl;
    fi.close();
    for(const auto &x:a) cout<<x<<endl;
}



int32_t main(){
    freopen("ms.out", "w", stdout);
    for(int i=0;i<10;++i)
        execute_test(i);

    
    return 0;
}