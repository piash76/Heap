
///https://www.youtube.com/watch?v=HqPJF2L5h9U
///https://www.youtube.com/watch?v=NEtwJASLU8Q


///max heap root is the largest among two childs and in min heap it is the lowest


#include<bits/stdc++.h>

using namespace std;

///max heap

int a[100005],sz;



void Insert(int data)
{
    sz++;

    a[sz]=data;

    int idx=sz;

    while(idx>1 and a[idx]>=a[idx/2])   ///as long as child is greater than root
    {
        swap(a[idx],a[idx/2]);
        idx=idx/2;
    }

}

int get_top()
{
    return a[1];
}


void delete_top()
{
    a[1]=a[sz];
    sz--;

    int idx=1;

    while( ((2*idx)<=sz) and ((2*idx)+1<=sz) )
    {
        int lft=2*idx;
        int rt=(2*idx)+1;

        int mx=max(a[lft],a[rt]);

        if(a[idx]<=mx)
        {
            ///either left or right
            if(mx==a[lft])
            {
                swap(a[lft],a[idx]);
                idx=2*idx;

            }
            else
            {
                swap(a[rt],a[idx]);
                idx=(2*idx)+1;

            }
        }
        else
        {
            break;
        }
    }
}

int main()
{

    while(1)
    {
        int data;cin>>data;

        if(data==-1) break;

        Insert(data);

    }

    int top_element=get_top();

    cout<<top_element<<endl;



    delete_top();


    top_element=get_top();

    cout<<top_element<<endl;



    delete_top();


    top_element=get_top();

    cout<<top_element<<endl;




    return 0;

}

/*


50 45 35 33 16 25 34 12 10 -1

10 20 30 50 -1


*/
