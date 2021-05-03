#include <iostream>
using namespace std;

void reverseStringWordWise(char input[]) {
    // Write your code here
    int len=0;
    for(int i=0;input[i]!='\0';i++)
        len++;
    for(int i=0;i<len/2;i++)
    {
        int temp = input[i];
        input[i] = input[len-i-1];
        input[len-i-1] = temp;
    }
    cout << input << endl;
    int word=0;
    for(int i=0;i<=len;i++)
    {
        word++;
        if(input[i]==' ' || input[i]=='\0')
        {
            --word;
            for(int j=0;j<word/2;j++)
            {
                int temp = input[i-word+j];
                input[i-word+j] = input[i-1-j];
                input[i-1-j] = temp;
            }
            word = 0;
        }
    }
    cout << input;
}

int main()
 {
    char str[100];
    cin.getline(str,99);
    reverseStringWordWise(str);
 }