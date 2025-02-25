#include<iostream>
#include<vector>
#include<chrono>
#include<random>
#include<algorithm>
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



int32_t main(){
    freopen("./test/0.inp", "r", stdin);
    freopen("qs0.out", "w", stdout);
    int n;
    cin>>n;
    cout<<n<<endl;
    a.resize(n);
    for(auto &x:a) cin>>x;


    
    auto start = high_resolution_clock::now();
    
    cerr<<"OK!!"<<endl;
    Quick_sort(a, 0, n-1);

    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(stop - start);

    cerr<<"TIME: "<<duration.count();
    
    return 0;
}