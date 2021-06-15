#include<iostream>
using namespace std;

int main(){

    /* Read input as specified in the question.
     * Print output as specified in the question.
     */
    char c;
    int ci=0,cc=0,cs=0;
    c=cin.get();
    if(c>=97 && c<=122)
        {
            cc++;
        }
        else if(c>=48 && c<=56)
        {
            ci++;
        }
        else if(c==9 || c==10 || c==32)
        {
            cs++;
        }
    while(c!='$')
    {
        c=cin.get();
        if(c>=97 && c<=122)
        {
            cc++;
        }
        else if(c>=48 && c<=56)
        {
            ci++;
        }
        else if(c==9 || c==10 || c==32)
        {
            cs++;
        }
    }
    cout << cc << " " << ci << " " << cs;
    
}