#include <iostream>
#include <cstring>
using namespace std;

//input: abc
// ouput: abc acb bac bca cab cba
//Approach: get all permutations of bc then a can be added in 3 places in permutaions of bc: _b_c_
//                                                                                           _c_b_
int returnPermutations(string input, string output[]){
    if(input.size()==0)
    {
        return 0;
    }
    else if(input.size()==1)
    {
        output[0]=input[0];
        return 1;
    }
    string temp[5000]="";
    int c = returnPermutations(input.substr(1),temp);
    int k=0;
    for(int i=0;i<c;i++)
    {
        string s = temp[i];
        for(int j=0;j<=s.length();j++)
        {
            output[k++]=s.substr(0,j)+input[0]+s.substr(j);
        }
    }
    return k;
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
