#include <iostream>
#include <vector>
using namespace std;


int limit = 1000;
vector<int> primeList;


bool prime(int n){
    if(n<3) return false;
    for(int i:primeList){
        if(n%i==0){
            return false;
        }
    }
    primeList.push_back(n);
    return true;
}

int nextPrime(){
    if(primeList.empty()){
        primeList.push_back(2);
        return 2;
    }
    for(int i=primeList.back()+1;i<=limit;i++){
        if(prime(i)) return primeList.back();
    }
    return -1;
}

string factor(int number){
    int d,n;
    string result = "";
    while(number != 1){
        d = nextPrime();

        if(number%d==0){
            n = 0;
            while(number%d==0){
                number = number/d;
                n++;
            }
            result += to_string(d)+"^(" + to_string(n) + ')';
            if(number!=1) result+=" + ";
        }
    }
    return result;
}

int main(){
    int number;
    cin >> number;
    cout << factor(number) << '\n';
}