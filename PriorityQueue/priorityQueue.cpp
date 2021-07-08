#include<vector>
class PriorityQueue
{
	vector<int> pq;
public:
	PriorityQueue()
	{

	}

	bool isEmpty()
	{
		return pq.size()==0;
	}

	int getSize()
	{
		return pq.size();
	}

	int getMin()
	{
		if(isEmpty())
			return 0;
		return pq[0];
	}

	void insert(int data)
	{
		pq.push_back(data);

		int childindex = pq.size()-1;
		while(childindex>0)
		{
			int parentindex = (childindex-1)/2;
			if(pq[childindex]<pq[parentindex])
			{
				int temp = pq[childindex];
				pq[childindex] = pq[parentindex];
				pq[parentindex] = temp;
			}
			else
				break;
			childindex = parentindex;
		}
	}
	int removeMin() {
        // Write your code here
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        int parent = 0;
        while((2*parent+1)<pq.size() || (2*parent+2)<pq.size())
        {
            int lci = 2*parent + 1;
        	int rci = 2*parent + 2;
            int minno,minindex;
        	if(lci<pq.size() && rci<pq.size())
            {
                minno = min(pq[parent],min(pq[lci],pq[rci]));
        		if(minno==pq[parent])
        		    break;
        		minindex = (minno==pq[lci])?lci:rci;
            }
        	else if(lci<pq.size())
            {
                minno = min(pq[parent],pq[lci]);
                if(minno==pq[parent])
        		    break;
                minindex = lci;
            }
            else if(rci<pq.size())
            {
                minno = min(pq[parent],pq[rci]);
                if(minno==pq[parent])
        		    break;
                minindex = rci;
            }
        	int temp = pq[parent];
        	pq[parent] = pq[minindex];
        	pq[minindex] = temp;
        	
        	parent = minindex;
        }
        return ans;
    }
};