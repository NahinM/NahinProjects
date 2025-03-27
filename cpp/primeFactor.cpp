#include <stdio.h>
#include <vector>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define vpii vector<pii>
#define br printf("\n")

vpii primeFactor(ll n){
    vpii pf;
    for(int i=2; i<=n; i++){
        int total = 0;
        while (n%i==0) {
            n/=i;
            total++;
        }
        if(total!=0) pf.push_back({i,total});
    }
    return pf;
}

int main(){
    ll n;
    scanf("%lld",&n);
    vpii pf = primeFactor(n);
    for(pii p:pf) printf("%d^(%d) %c ",p.first,p.second,(pf.back()!=p?'+':' ')); br;
}
