#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

#define ll long long
#define vb vector<bool>
#define br cout << '\n'

void prime_factorize(){
    ll n;
    cin >> n;

    if(n<2){
        cout << "out of bounds\n";
        return;
    }

    int sq_rt = sqrt(n+1)+1;
    vb filter(sq_rt,true);

    for(int i=2; i<sq_rt; ++i) if(filter[i]){
        for(int j=i+i; j<sq_rt; j+=i) filter[j] = false;

        // in this section we have all the primes that can divide n aad i<sqrt(n);
        int p=0;
        while(n%i==0){
            ++p;
            n=n/i;
        }
        if(p!=0) cout << i << '^' << p << (n!=1?" + ":"");
    }

    if(n!=1) cout << n << '^' << 1;br;
}

int main(){
    int t{1};
    cin >> t;
    while(t--) prime_factorize();
}