/*
OK!!  Test 0: 1429
OK!!  Test 1: 1471
OK!!  Test 2: 1488
OK!!  Test 3: 1462
OK!!  Test 4: 1550
OK!!  Test 5: 1477
OK!!  Test 6: 1398
OK!!  Test 7: 1420
OK!!  Test 8: 1455
OK!!  Test 9: 1481
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

template <typename T>
T Find_pivot(vector<T> &v, int left, int right){
    T mi = *min_element(v.begin()+left, v.begin()+right+1);
    T ma = *max_element(v.begin()+left, v.begin()+right+1);
    vector<T> id;
    for(int i=left; i<=right;++i)
        if(v[i]!=ma && v[i]!=mi) id.push_back(i);
    if(id.empty()) return ma;
    return v[id[Rand(0, (int)id.size()-1)]];
}

template <typename T>
int Partition(vector<T> &v, T pivot, int left, int right){
    int n = right - left + 1;
    while(1){
        while(left <= right && v[left] < pivot) ++left;
        while(left <= right && v[right] >= pivot) --right;
        if(left >=right) break;

        swap(v[left], v[right]);
        ++left;
        --right;
    }

    if(right == -1 ||left == n) return -1;
    return left;
}

int cnt=0;
template <typename T>
void Quick_sort(vector<T> &v, int left, int right){

    if(left >= right) return;
    if(right - left ==  1){
        if(v[left] > v[right]) swap(v[left], v[right]);
        return;
    }
    T pivot = Find_pivot(v, left, right);
    int pos = Partition(v, pivot, left, right);
    if(pos == -1) return;
   
    if(pos == left || pos == right) return;
    Quick_sort(v, left, pos-1);
    Quick_sort(v, pos, right);
    
}


string PATH = "D:/.suc_vat/Y2/IT003/Buoi_2/test/";


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
    Quick_sort(a, 0, n-1);

    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(stop - start);

    cerr<<"Test "<<k<< ": "<<duration.count()<<endl;
    fi.close();
    for(const auto &x:a) cout<<x<<endl;
}



int32_t main(){
    freopen("qs.out", "w", stdout);
    for(int i=0;i<10;++i)
        execute_test(i);
    return 0;
}