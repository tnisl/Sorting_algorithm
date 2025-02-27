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



int32_t main(){

    
    return 0;
}