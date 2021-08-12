#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

int main()
{
    string f;
    f.reserve(100);
    cin >> f;
    int l = f.length();
    string s;
    s.reserve(100);
    for(int i=0;i<l;i++){
        switch(f[i]){
        case '.':
            s[i]='d';
            break;
        case '+':
            s[i]='p';
            break;
        case '-':
            s[i]='m';
            break;
        case '*':
            s[i]='x';
            break;
        case '/':
            s[i]='y';
            break;
        default:
            s[i]='n';
            }
    }
    int n = 0;
    int num_of_dots = 0;
    for(int i=0;i<l;i++){
        if(s[i]!='n'){
            n++;
        }
        if(s[i]=='d'){
            num_of_dots++;
        }
    }
    int num_of_operators = n - num_of_dots;
    int num_of_operands = num_of_operators + 1;
    char operators[num_of_operators];
    string operands[num_of_operands];
    int i=0, j=0, k=0, c=0;
        while(i<l){
        while(s[i]=='n'){
            i++;
        }
        if(s[i]=='d'){
            i++;
            while(s[i]=='n'){
                i++;
            }
        }
        operands[k] = f.substr(c,i-c);
        k++;
        operators[j] = s[i];
        j++;
        i++;
        c = i;
        }
    double brojevi[num_of_operands];
    for(int i=0;i<num_of_operands;i++){
    brojevi[i] = atof(operands[i].c_str());
    }
    for(int i=0;i<num_of_operators;i++){
        if(operators[i]=='y'){
            brojevi[i]=brojevi[i]/brojevi[i+1];
            for(int j=i;j<num_of_operators;j++){
                brojevi[j+1]=brojevi[j+2];
                operators[j]=operators[j+1];
            }
            num_of_operators--;
            i--;
        }
    }
    for(int i=0;i<num_of_operators;i++){
        if(operators[i]=='x'){
            brojevi[i]=brojevi[i]*brojevi[i+1];
            for(int j=i;j<num_of_operators;j++){
                brojevi[j+1]=brojevi[j+2];
                operators[j]=operators[j+1];
            }
            num_of_operators--;
            i--;
        }
    }
    for(int i=0;i<num_of_operators;i++){
        if(operators[i]=='m'){
            brojevi[i]=brojevi[i]-brojevi[i+1];
            for(int j=i;j<num_of_operators;j++){
                brojevi[j+1]=brojevi[j+2];
                operators[j]=operators[j+1];
            }
            num_of_operators--;
            i--;
        }
    }
    for(int i=0;i<num_of_operators;i++){
        if(operators[i]=='p'){
            brojevi[i]=brojevi[i]+brojevi[i+1];
            for(int j=i;j<num_of_operators;j++){
                brojevi[j+1]=brojevi[j+2];
                operators[j]=operators[j+1];
            }
            num_of_operators--;
            i--;
        }
    }
    cout<<brojevi[0];
    return 0;
}
