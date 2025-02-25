#include "bits/stdc++.h"
#define int long long
using namespace std;


signed main() {

    srand(time(NULL));
    vector <string> testnames;

    for (int numtest = 0 ; numtest <= 9 ; numtest++) {
        string tmp;
        tmp += (numtest + '0');
        testnames.push_back(tmp);
    }


    
    for (int numtest = 0 ; numtest <= 9 ; numtest++) {
        const string output = testnames[numtest] + ".inp";
        ofstream fileout(output);

        int n = 1e6;

        fileout << n << "\n";
        vector <double> arr;
        for (int i = 1 ; i <= n ; i++)    
            arr.push_back(1.9 * rand() / 100);         

        if (numtest == 0) sort(arr.begin(), arr.end());
        else if (numtest == 1) sort(arr.begin(), arr.end(), greater <double> ());

        for (double x : arr) fileout << x << " ";

        fileout.close();
    }
    return 0;
}