#include <iostream>
#include <string>
using namespace std;
string charset(int key)
{
    switch(key)
    {
        case 2: return "abc";
        case 3: return "def";
        case 4: return "ghi";
        case 5: return "jkl";
        case 6: return "mno";
        case 7: return "pqrs";
        case 8: return "tuv";
        case 9: return "wxyz";
        default: return "";
    }
}
void keypad(int num, string output)
{
    if(num==0)
    {
        cout << output << endl;
        return;
    }
    string str = charset(num%10);
    for(int i=0;i<str.size();i++)
    	keypad(num/10,str[i]+output);
}
void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    keypad(num,"");
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
