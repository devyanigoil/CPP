class Polynomial {
    public :
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    // Complete the class
    
    Polynomial()
    {
        degCoeff=new int[5]();
        capacity = 5;
    }
    Polynomial (Polynomial const &p)
    {
        degCoeff = new int[p.capacity];
        for(int i=0;i<p.capacity;i++)
            degCoeff[i]=p.degCoeff[i];
        capacity = p.capacity;
    }
    void setCoefficient(int d,int coeff)
    {
        while(capacity<=d)
        {
            int *newArray = new int[2*capacity]();
            for(int i=0;i<capacity;i++)
                newArray[i] = degCoeff[i];
            delete [] degCoeff;
            degCoeff = newArray;
            capacity *=2;
        }
        degCoeff[d] = coeff;
    }
    Polynomial operator+(Polynomial const &p2)
    {
        Polynomial fnew;
        int i;
        for(i=0;i<capacity && i<p2.capacity;i++)
        {
            int c = degCoeff[i]+p2.degCoeff[i];
            fnew.setCoefficient(i,c);
        }
        while(i<capacity)
        {
            fnew.setCoefficient(i,degCoeff[i]);
            i++;
        }
        while(i<p2.capacity)
        {
            fnew.setCoefficient(i,p2.degCoeff[i]);  
            i++;        
        }
        return fnew;
    }
    Polynomial operator-(Polynomial const &p2)
    {
        Polynomial fnew;
        int i;
        for(i=0;i<capacity && i<p2.capacity;i++)
        {
            int c = degCoeff[i]-p2.degCoeff[i];
            fnew.setCoefficient(i,c);
        }
        while(i<capacity)
        {
            fnew.setCoefficient(i,degCoeff[i]);
            i++;
        }
        while(i<p2.capacity)
        {
            fnew.setCoefficient(i,-1*p2.degCoeff[i]);  
            i++;        
        }
        return fnew;
    }
    Polynomial operator*(Polynomial const &p2)
    {
        Polynomial fnew;
        if(p2.capacity>capacity)
        {
            for(int i=0;i<p2.capacity;i++)
            {
                if(p2.degCoeff[i]==0)
                    continue;
                for(int j=0;j<capacity;j++)
                {
                    if(degCoeff[j]==0)
                        continue;
                    int mulc=degCoeff[j]*p2.degCoeff[i];
                    fnew.setCoefficient(i+j,mulc+fnew.degCoeff[i+j]);
                }
            }
        }
        else
        {
            for(int i=0;i<capacity;i++)
            {
                if(degCoeff[i]==0)
                    continue;
                for(int j=0;j<p2.capacity;j++)
                {
                    if(p2.degCoeff[j]==0)
                        continue;
                    int mulc=degCoeff[i]*p2.degCoeff[j];
                    fnew.setCoefficient(i+j,mulc+fnew.degCoeff[i+j]);
                }
            }
        }
        return fnew;
    }
    void operator=(Polynomial const &p2)
    {
        Polynomial pnew;
        for(int i=0;i<p2.capacity;i++)
            degCoeff[i]=p2.degCoeff[i];
        capacity = p2.capacity;
    }
    void print()
    {
        for(int i=0;i<capacity;i++)
        {
            if(degCoeff[i]==0)
                continue;
            cout << degCoeff[i] << "x" << i << " ";
        }   
        cout << endl;
    }
};