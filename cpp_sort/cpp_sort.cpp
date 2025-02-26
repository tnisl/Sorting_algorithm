/*
OK!!  Test 0: 246
OK!!  Test 1: 248
OK!!  Test 2: 400
OK!!  Test 3: 405
OK!!  Test 4: 405
OK!!  Test 5: 413
OK!!  Test 6: 410
OK!!  Test 7: 403
OK!!  Test 8: 402
OK!!  Test 9: 414
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
vector<double> a;


string PATH = "D:/.suc_vat/Y2/IT003/Buoi_2/Sort/test/";




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
    sort(a.begin(),a.end());

    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(stop - start);

    cerr<<"Test "<<k<< ": "<<duration.count()<<endl;
    fi.close();
    for(const auto &x:a) cout<<x<<endl;
}



int32_t main(){
    freopen("hs.out", "w", stdout);
    for(int i=0;i<10;++i)
        execute_test(i);

    
    return 0;
}