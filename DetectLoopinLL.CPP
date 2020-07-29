
// ye vlaa karna baaki hai abhi




#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define SPEED ios::sync_with_stdio(false);cin.tie(NULL);

struct Node
{
    int data;
    Node* next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

bool detectloop(Node* head)
{
    if(head==NULL || head->next==NULL)
        return false;

     if(!head) return false;

    Node* fast = head->next;
    Node* slow = head;

    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    return true;
}

int main()
{
    SPEED;
    int test;
    cin>>test;
    while(test--)
    {
        int n,data,k;
        cin>>n;
        cin>>data;
        Node* head=new Node(data);
        Node* tail=head;

        for(int i=0;i<n-1;i++)
        {
                cin>>data;
                tail->next=new Node(data);
                tail=tail->next;
        }

        if(detectloop(head))
            cout<<"Loop Present\n";
        else
            cout<<"Loop isn't present\n";
    }
return 0;
}

