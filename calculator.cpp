#include <iostream>

using namespace std;

int at = 0;

bool valid(string eq){
    char stack[20];
    int i = -1;
    for(char c:eq){
        if(c=='(' || c=='{' || c=='['){
            stack[++i]=c;
        }
        if(i<-1 || (i==-1 && c==')' || c=='}' || c==']')) return false;
        if(c==')' && stack[i]=='(') i--;
        if(c=='}' && stack[i]=='{') i--;
        if(c==']' && stack[i]=='[') i--;
    }
    return i==-1;
}

long multiply(char sign,string chunk){
    string number="";
    long tem = 1;
    for(char c:chunk){
        if(c>='0' && c<='9') number+=c;
        else {
            tem*= stoi(number);
            number = "";
        }
    }
    tem*=stoi(number);

    return (sign=='+'?tem:-tem);
}

string solve(string eq){
    string chunk = "";
    char pre = '+';
    long result = 0;
    for(char c:eq){
        if(c=='+' || c=='-') {
            result+= multiply(pre,chunk);
            pre = c;
            chunk = "";
        }
        else chunk+=c;
    }
    result+= multiply(pre,chunk);
    return to_string(result);
}

string stepDown(string eq,int len){
    string chunk = "";
    while(at<len){
        if(eq[at]=='('){
            at++;
            chunk+=stepDown(eq,len);
        }
        else if(eq[at]==')'){
            at++;
            return solve(chunk);
        }
        else{
            chunk+=eq[at];
            at++;
        }
    }
    return solve(chunk);
}

int main(){
    freopen("input.txt","r",stdin);

    string eq;
    while(cin >> eq){
        at = 0;
        if(valid(eq))
            cout << stepDown(eq,eq.length()) << '\n';
        else 
            cout << "Please enter a valid eqation.\n";
    }

    return 0;
}