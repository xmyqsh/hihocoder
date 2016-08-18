#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <math.h>
using namespace std;

int getFactorNum(long long n){
   if(n <= 1)  return 1;
   int ret = 2;
   for(int i = 2; i <= sqrt(n); ++ i){
        if(n % i == 0){
            if(i*i == n){
                ++ ret;
            }else{
                ret += 2;
            }
        }
   }
   return ret;
}

long long gcd(long long n, long long m){
    long long r;
    while(m){
        r = n % m;
        n = m;
        m = r;
    }
    return n;
}

int main(){
    long long n,m;
    int a,b;
    cin >> n >> m;
    int ln = getFactorNum(n);
    int lm = getFactorNum(m);
    int lr = getFactorNum(gcd(n,m));
    int d = gcd(ln*lm,lr);
    a = ln*lm/d;
    b = lr/d;
    cout << a << " " << b << endl;
    
    return 0;
}
