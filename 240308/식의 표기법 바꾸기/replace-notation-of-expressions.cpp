#include <iostream>
#include <string>
#include <stack> 
#include <unordered_map> 

using namespace std; 

string str;
int n; 
stack<string> s; 
stack<char> s2;  


int main() {
    cin>>str;
    n = (int)str.size();

    for(int i=0; i<n; i++){
        char c = str[i];
        if(c>='A' && c<='Z'){
            string tmp = "";
            tmp += c;
            s.push(tmp); 
        }
        else{
            if(s2.empty()){
                s2.push(c); 
            }
            else{ 
                if(c=='('){
                    char c2  =str[i-1];
                    if(c2==')'){
                        while(!s2.empty() && (s2.top()!='(' && s2.top()!='+' && 
                                  s2.top()!='-')){
                            string op2 = s.top();
                            s.pop();
                            string op1 = s.top();
                            s.pop();
                            char op = s2.top();
                            s2.pop(); 
                            string res; 
                            if(op=='&')
                                res = op1 + op2;
                            else
                                res = op1 + op2 + op;
                            s.push(res);
                        }
                        s2.push('&');
                    }
                    s2.push(c);
                    continue; 
                }
                else if(c==')'){
                    while(s2.top()!='('){ // 
                        string op2 = s.top();
                        s.pop();
                        string op1 = s.top();
                        s.pop();
                        char op = s2.top();
                        s2.pop(); 
                        string res; 
                            if(op=='&')
                                res = op1 + op2;
                            else
                                res = op1 + op2 + op;
                        s.push(res); 
                    }
                    s2.pop(); 
                }
                else if(c=='+' || c=='-'){
                    
                    while(!s2.empty() && s2.top()!='('){
                        string op2 = s.top();
                        s.pop();
                        string op1 = s.top();
                        s.pop();
                        char op = s2.top(); 
                        s2.pop(); 
                        string res; 
                            if(op=='&')
                                res = op1 + op2;
                            else
                                res = op1 + op2 + op;
                        s.push(res); 
                    }

                    s2.push(c); 
                }
                else{ 
                    while(!s2.empty() && (s2.top()!='(' && s2.top()!='+' && 
                                  s2.top()!='-')){
                        string op2 = s.top();
                        s.pop();
                        string op1 = s.top();
                        s.pop();
                        char op = s2.top();
                        s2.pop(); 
                        string res; 
                            if(op=='&')
                                res = op1 + op2;
                            else
                                res = op1 + op2 + op;
                        s.push(res);
                    }
                    s2.push(c); 
                }   
            }
        }
    }

    while(!s2.empty()){
        string op2 = s.top();
        s.pop();
        string op1 = s.top();
        s.pop();
        
        char c = s2.top();
        s2.pop();
        string res; 
            if(c=='&')
                res = op1 + op2;
            else
                res = op1 + op2 + c;
        s.push(res); 
    } 

    string res = s.top(); 
    cout<<res; 
    
    return 0;
}