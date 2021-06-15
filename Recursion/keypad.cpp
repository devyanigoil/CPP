#include <string>
#include <iostream>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num==0 || num==1)
    {
        output[0] = "";
        return 1;
    }
    int number = num%10;
    int count = keypad(num/10,output);
    int val;
    switch(number)
    {
        case 2: val=97;
            	break;
        case 3: val=100;
            	break;
        case 4: val=103;
            	break;
        case 5: val=106;
            	break;
        case 6: val=109;
            	break;
        case 7: val=112;
            	break;
        case 8: val=116;
            	break;
        case 9: val=119;
            	break;
    }
    if(number!=7 && number!=9)
    {
        char ch;
        int max = count*3;
        for(int i=0;i<3;i++)
        {
            ch=val;
            for(int j=count-1;j>=0;j--)
            {
                output[--max] = output[j] + ch; 
            }
            val++;
        }
        return 3*count;
    }
    else
    {
        char ch;
        int max = count*4;
        for(int i=0;i<4;i++)
        {
            ch=val;
            for(int j=count-1;j>=0;j--)
            {
                output[--max] = output[j] + ch; 
            }
            val++;
        }
        return 4*count;
    }
        
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}