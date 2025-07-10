#include <iostream>
#include <vector>
using namespace std;

void is_prime(){
    long long n;
    cin >> n;
    if(n<2){
        cout << "Out of bound\n";
        return;
    }

    for(long long i=2;i*i<n+1; ++i){
        if(n%i==0) {
            cout << n << " is not prime, divisable by: " << i << '\n';
            return;
        }
    }

    cout << "YES " << n << " is prime"<< '\n';
}

int main(){
    int t{1};
    cin >> t;
    while(t--) is_prime();
}