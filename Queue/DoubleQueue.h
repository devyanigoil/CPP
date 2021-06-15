//this is a double circular queue
//insertions and deletions can be made from both the ends

class Dequeue
{
    int front,rear;
    int size;
    int a[10];

public:
    Dequeue(int capacity)
    {
        front=-1;
        rear=0;
        size=capacity;
    }

    bool isFull()
    {
        return front==(rear+1)%size;
    }

    bool isEmpty()
    {
        return front==-1;
    }
    //while inserting an element from front, the front variable move from right to left
    void insertFront(int ele)
    {
        if(isFull())
        {
            cout << "-1" << endl;
            return;
        }
        if(front==-1)
        {
            front=0;
            rear=0;
        }
        else
        {
            front=((front-1)%size+size)%size;
        }
        a[front]=ele;
    }
    // Inserting rear element: rear variable ould move from left to right
    void insertRear(int ele)
    {
        if(isFull())
        {
            cout << "-1" << endl;
            return;
        }
        if(front==-1)
        {
            front=0;
            rear=0;
        }
        else
        {
            rear=(rear+1)%size;
        }
        a[rear]=ele;
    }

    void deleteFront()
    {
        if(isEmpty())
        {
            cout << "-1" << endl;
            return;
        }
        if(front==rear)
        {
            front==-1;
            rear==-1;
        }
        else
        {
            front=(front+1)%size;
        }
    }

    void deleteRear()
    {
        if(isEmpty())
        {
            cout << "-1" << endl;
            return;
        }
        if(front==rear)
        {
            front==-1;
            rear==-1;
        }
        else
        {
            rear=((rear-1)%size+size)%size;
        }
    }

    int getFront()
    {
        if(isEmpty())
        {
            return -1;
        }
        return a[front];
    }

    int getRear()
    {
        if(isEmpty() || rear<0)
            return -1;
        return a[rear];
    }
};