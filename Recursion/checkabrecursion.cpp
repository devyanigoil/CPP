#include <iostream>
using namespace std;

bool check(char input[])
{
    if(input[0]!='a' && input[0]!='b')
        return true;
    if(input[0]=='a')
    {
        if(input[1]=='b')
            return check(input+1);
        else
            return true;
    }
    if(input[0]=='b')
    {
        if(input[1]=='b')
            return check(input+2);
        else
             return false;   
    }
    return true;
}

bool checkAB(char input[]) {
    // Write your code here
    if(input[0]=='b')
        return false;
    else 
        return check(input);
}
int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}


