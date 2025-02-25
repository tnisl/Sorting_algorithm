/*
OK!!  Test 0: 1669
OK!!  Test 1: 1681
OK!!  Test 2: 1992
OK!!  Test 3: 1997
OK!!  Test 4: 1988
OK!!  Test 5: 1984
OK!!  Test 6: 1981
OK!!  Test 7: 1978
OK!!  Test 8: 1977
OK!!  Test 9: 1969
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
    vector<T> left, right;
    int n = a.size();
    int mid = n/2;
    for(int i=0;i<mid;++i)
        left.push_back(a[i]);
    for(int i=mid;i<n;++i)
        right.push_back(a[i]);
    
    Merge_sort(left);
    Merge_sort(right);
    merge(left.begin(),left.end(), right.begin(),right.end(), a.begin());//sử dụng std::merge để gộp 2 dãy

    
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