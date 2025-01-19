#include <iostream>
#include <vector>
using namespace std;

#define ll long long

ll limit = 1000;
vector<ll> primeList;


bool prime(ll n){
    if(n<3) return false;
    for(int i:primeList){
        if(n%i==0){
            return false;
        }
    }
    primeList.push_back(n);
    return true;
}

ll nextPrime(){
    if(primeList.empty()){
        primeList.push_back(2);
        return 2;
    }
    for(ll i=primeList.back()+1;i<=limit;i++){
        if(prime(i)) return primeList.back();
    }
    return -1;
}

string factor(ll number){
    int d,n;
    string result = "";
    while(number != 1){
        d = nextPrime();

        if(number%d==0){
            n = 0;
            while(number%d==0){
                number = number/d;
                limit = number;
                n++;
            }
            result += to_string(d)+"^(" + to_string(n) + ')';
            if(number!=1) result+=" * ";
        }
    }
    return result;
}

int main(){
    ll number;
    cin >> number;
    limit = number;
    cout << factor(number) << '\n';
}
