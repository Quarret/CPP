#include  <bits/stdc++.h>

using  namespace  std;

class  heap
{
private:
        int  n;
        int  *elem;
        void  shiftdown(int  pos)
        {
              while (!isLeaf(pos)) {
                int j = leftChild(pos), rc = rightChild(pos);
                if((rc < n) && elem[rc] > elem[j]) {
                    j = rc;
                }

                if (elem[pos] > elem[j]) {
                    return;
                }

                swap(elem[pos], elem[j]);
                pos = j;
              }      

        }
public:
        heap(){}
        heap(int  m)
        {
                n=m;
                elem=new  int[n];
        }
        ~heap()
        {
                delete[]  elem;
        }
        void  initial()
        {
                for(int  i=0;  i<n;  i++)
                        cin>>elem[i];
        }

        void  out()
        {
                for(int  i=0;  i<n;  i++)
                {
                        cout<<elem[i];
                        if  (i<=n-2)
                                cout<<"  ";
                        else
                                cout<<endl;
                }
        }

        bool  isLeaf(int  pos)  const
        {
                return  ((pos>=n/2)  &&  pos<n);
        }

        int  leftChild(int  pos)
        {
                return  2*pos+1;
        }

        int  rightChild(int  pos)
        {
                return  2*pos+2;
        }

        void  arrange()
        {
                for(int  i=(n-1)/2;i>=0;  i--)
                {
                        shiftdown(i);
                }
        }

        void  insertElem(int  x)
        {
            int curr = n++;
            elem[curr] = x;
            while ((curr != 0) && elem[curr] > elem[(curr - 1) / 2]) {
                swap(elem[curr], elem[(curr - 1) / 2]);
                curr = (curr - 1) / 2;
            }  

        }
};

int  main()
{
        int  m;
        cin>>m;
        heap  *ex=new  heap(m);
        ex->initial();
        ex->arrange();
        ex->out();
        int  insData;
        cin>>insData;
        ex->insertElem(insData);
        ex->out();
        return  0;
}