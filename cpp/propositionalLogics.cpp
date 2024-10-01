#include <iostream>
#include <vector>
using namespace std;

#define repti(a,b) for(int i=a;i<b;i++)
#define reptj(a,b) for(int j=a;j<b;j++)
#define reptRev(a,b) for(int k=a;k>=b;k--)
#define br cout << '\n'
#define INF __INT_MAX__

bool rptv[26];
bool values[26];
short var = 0;
int at=0;
vector <string> part;

void clearRptv(){
    repti(0,26) rptv[i] = false;
}

void makePart(string s){
    string tem = "";
    for(char c:s) {
        if(c=='=') {
            part.push_back(tem);
            tem = "";
        }else tem += c;
    }
    part.push_back(tem);
}

vector<char> getRptv(){
    vector <char> tem;
    repti(0,26) if(rptv[i]) tem.push_back((char)(i+'a'));
    return tem;
}

bool evaluateAnd(string z){
    if (z == "") return false;
    bool nt = false;
    bool f = true;
    for(char c:z)if(c!='&'){
        if(c!='!') f &= nt?!(c=='1'):(c=='1');
        nt = (c=='!');
    }
    return f;
}

char evaluate(string z){
    string x = "";
    for(char c:z) if('a'<=c && c<='z') x+=(char)('0'+values[c-'a']); else x+=c;

    string tem="";
    bool f = false;
    for(char c:x){
        if(c == '|') {
            f |= evaluateAnd(tem);
            tem = "";
        }
        else tem += c;
    }
    f |= evaluateAnd(tem);
    return f?'1':'0';
}

char evaluateBracket(string s, int len){
    string x = "";
    while(at<len){
        if(s[at]=='('){
            at++;
            x+=evaluateBracket(s,len);
        }
        else if(s[at]==')'){
            at++;
            return evaluate(x);
        }else{
            x+=s[at];
            at++;
        }
    }
    return evaluate(x);
}

bool status(vector<bool>& check){
    for(int i=1;i<check.size();i++){
        if(check[i-1] != check[i]) return false;
    }
    return true;
}

void tabel(string s){
    bool check,tem;
    vector <char> qn = getRptv();
    repti(0,var)  cout << qn[i] << ' ';
    cout << "   ";
    makePart(s);
    for(string &st:part) cout << st << "   ";
    br;br;
    int t = INF>>(31-var);
    bool flag;
    reptRev(t,0){
        reptj(0,var) {
            flag = k&(1<<j);
            values[(qn[j]-'a')] = flag;
            cout << flag << ' ';
        }
        vector<bool> check;
        for(string &ss:part){
            at=0;
            tem = (evaluateBracket(ss,ss.length())=='1'?true:false);
            check.push_back(tem);
            cout << "   " << tem;
            for(int sps=0;sps<ss.length()-1;sps++)cout << ' ';
        }
        cout << "   " << (status(check)?"ok":"unsatisfied");
        br;br;
    }
}

int main(){
    freopen("input.txt" , "r" , stdin);
    string s;
    cin >> s;
    clearRptv();
    for(char c:s) if('a' <= c && c <= 'z') if(!rptv[c -'a']) {
        var++;
        rptv[c -'a'] = true;
    }
    cout << "total variables: " << var;br;br;
    tabel(s);
}