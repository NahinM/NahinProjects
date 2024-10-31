#include <iostream>
using namespace std;

#define br cout << '\n'

class Number
{
private:
    char charSet[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','c','D','E','F'};
    int getNum(char c){
        if('0'<=c && c<='9') return c-'0';
        return c-'A'+10;
    }
public:
    string num;
    int base = 10;
    Number(string s,int b=10){
        num = s;
        base = b;
    }
    int operator[](int a){
        return getNum(num[a]);
    }
    string operator+(Number &num2);
    string operator-(Number &num2);
};

string Number::operator+(Number &num2){
    int p1 = num2.num.length()-1;
    int p2 = num.length()-1;
    int c = 0;
    string result="";
    while (p1>=0 || p2>=0)
    {
        int a = p1>=0?(num2[p1--]):0;//num2
        int b = p2>=0?(getNum(num[p2--])):0;//num
        int x = (a+b+c)%base;
        result = charSet[x] + result;
        c = (a+b+c-x)/base;
    }
    if(c!=0) result = charSet[c] + result;
    return result;
}

string Number::operator-(Number &num2){
    string result;
    bool neg = false;
    if(num<num2.num){
        result = num;
        num = num2.num;
        num2.num = result;
        neg = true;
    }
    result = "";
    int p1 = num2.num.length()-1;
    int p2 = num.length()-1;
    int c = 0;
    result="";
    while (p1>=0 || p2>=0)
    {
        int a = p1>=0?(getNum(num[p1--])):0;//num2
        int b = p2>=0?(num2[p2--]):0;//num
        int x = a-b-c;
        if(x<0){
            c=1;
            x+=base;
        }else c=0;
        result = charSet[x] + result;
    }
    if(neg) return '-'+result;
    return result;
}

int main(){
    // freopen("input.txt","r",stdin);
    int base;
    string s1,s2;
    // cin  >> base >> s1 >> s2;
    base = 16;
    s1 = "AA";
    s2 = "11";
    Number n1 = Number(s1,base);
    Number n2 = Number(s2,base);
    cout << n1 - n2;br;
    cout << n1 + n2;br;
}
