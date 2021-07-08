#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

//You are given an array of unique integers that contain numbers in random order. 
//You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
//You need to return the output array which contains starting and ending element. 
//If the length of the longest possible sequence is one, then the output array must contain only single element.
//input: 7 3 1 9 8 2 4
// output: 1 4
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    int maxlength=0,length;
    int start,end,startindex;
    vector<int> v;
    unordered_map<int,bool> ourmap;
    unordered_map<int,int> index;
    for(int i=0;i<n;i++)
    {
        ourmap[arr[i]]=true;
        index[arr[i]] = i;
    }
    for(int i=0;i<n;i++)
    {
        length = 1;
        if(ourmap[arr[i]]==false)
            continue;
        start = arr[i];
        end = arr[i];
        startindex=i;
        ourmap[arr[i]]=false;
        for(int j=arr[i]+1;;j++)
        {
            if(ourmap.count(j)>0)
            {
                length++;
                ourmap[j]=false;
                end=j;
            }
            else 
                break;
        }
        for(int k=arr[i]-1;;k--)
        {
            if(ourmap.count(k)>0)
            {
                length++;
                ourmap[k]=false;
                start = k;
                startindex = index[k];
                //cout << startindex << endl;
                //end = arr[i];
            }
            else
                break;
        }
        if(length>maxlength)
        {
            maxlength = length;
            while(!v.empty())
                v.pop_back();
            v.push_back(start);
            v.push_back(end);
        }
        else if(length==maxlength)
        {
            int tempindex = index[v[0]];
            if(startindex<tempindex)
            {
                while(!v.empty())
                    v.pop_back();
                v.push_back(start);
                v.push_back(end);
            }
        }
    }
    if(maxlength==1)
    {
        v.pop_back();
    }
    return v;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    cout << ans[0];
    if (ans.size() > 1) {
        cout << " " << ans[ans.size() - 1];
    }

    delete[] arr;
}