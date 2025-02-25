/*
OK!!  Test 0: 2110
OK!!  Test 1: 2093
OK!!  Test 2: 2648
OK!!  Test 3: 2404
OK!!  Test 4: 2397
OK!!  Test 5: 2397
OK!!  Test 6: 2423
OK!!  Test 7: 2394
OK!!  Test 8: 2400
OK!!  Test 9: 2396
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


string PATH = "D:/.suc_vat/Y2/IT003/Buoi_2/test/";


template <typename T>
void Merge_sort(vector<T> &a){
    if(a.size()<=1) return;
    vector<T> b;
    int n = a.size();
    int mid = n/2;
    while(a.size()>mid) b.push_back(a.back()), a.pop_back();
    Merge_sort(a);
    Merge_sort(b);
    vector<T> v(a.size() + b.size());
    merge(a.begin(),a.end(), b.begin(),b.end(),v.begin()); //sử dụng std::merge để merge 2 dãy đã sort
    a.clear();
    for(const auto &x:v) a.push_back(x);
    v.clear();
    
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
    Merge_sort(a);

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