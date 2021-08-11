#include<iostream>
#include<vector>
using namespace std;

//priority queue is implemented with heaps
class PriorityQueue
{
private:
    vector<int> pq;

public:
    PriorityQueue()
    {

    }

    bool isEmpty()
    {
        return pq.size()==0;
    }

    //return size of priority queue
    int getSize()
    {
        return pq.size();
    }

    //return the minimum element in heap
    int getMinimum()
    {
        if(isEmpty())
            return 0;
        else
            return pq[0];
    }

    //insert the elements and up-heapify
    void insert(int ele)
    {
        pq.push_back(ele);
        int childIndex=pq.size()-1;
        //this loop compares parent  and child  and swaps if child is greater than parent
        //this loop traverse upward since called up heapify
        while(childIndex>0 && pq[childIndex]<pq[((childIndex-1)/2)])
        {
            swap(pq[childIndex],pq[((childIndex-1)/2)]);
            childIndex=((childIndex-1)/2);
        }
    }

    //remove the min element which is at the top of heap
    void removeMin()
    {
        if(isEmpty())
        {
            cout<<"empty"<<endl;
            return;
        }

        //swap minimum element(at index 0) with the last element so we can remove minElement
        swap(pq[0],pq[getSize()-1]);
        pq.pop_back();
        int index=0;
        //to convert to min heap we down heapify
        //compare parent and child and swap if parent>child and take the min of 2 child
        while(((index*2)+1)<getSize())
        {
            int childIndex;
            int leftchild=((index*2)+1);
            int righchild=((index*2)+2);
            if(leftchild<getSize() && righchild<getSize())
            {
                childIndex=pq[(index*2)+1]>pq[(index*2)+2]?((index*2)+2):((index*2)+1);
            }
            if(leftchild<getSize() && righchild>getSize())
            {
                childIndex=leftchild;
            }
            if(leftchild>getSize() && righchild<getSize())
            {
                childIndex=righchild;
            }
            if(pq[index]>pq[childIndex])
            {
                swap(pq[index],pq[childIndex]);
                index=childIndex;
            }

        }

    }


    void print()
    {
        for(int i=0;i<pq.size();i++)
        {
            cout<<pq[i]<<"\t";
        }
        cout<<endl;
    }
};

int main()
{
    PriorityQueue p;
    p.insert(12);
    p.insert(6);
    p.insert(5);
    p.insert(100);
    p.insert(1);
    p.insert(9);
    p.insert(0);
    p.insert(14);
    p.print();
    p.removeMin();
    p.print();
    p.removeMin();
    p.print();
    p.removeMin();
    p.print();
    p.removeMin();
    p.print();
    p.removeMin();
    p.print();
    p.removeMin();
    p.print();
    p.removeMin();
    p.print();
    p.removeMin();
    p.print();
    p.removeMin();
    p.print();
    return 0;
}
