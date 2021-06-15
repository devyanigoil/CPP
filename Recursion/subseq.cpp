#include <iostream>
using namespace std;
int subseq(string input,string output[])
{
    if (input.empty())
    {
        output[0]="";
        return 1;
    }
    string small = input.substr(1);
    int smallsize = subseq(small,output);
    for (int i = 0; i < smallsize; ++i)
     {
         output[i+smallsize] = input[0]+output[i];
     }
     return 2*smallsize;
}

int main()
{
    string input;
    cin >> input;
    string* output = new string[1000];
    int count = subseq(input,output);
    for (int i = 0; i < count; ++i)
    {
        cout << output[i] << endl;
    }
}