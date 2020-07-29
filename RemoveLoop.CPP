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

void looping(Node* head,Node* tail,int pos)
{
    if(pos==0)
        return;
    Node* temp=head;
    for(int i=1;i<pos;i++)
        temp=temp->next;
    tail->next=temp;
}

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

void removeloop(Node* head)
{
     Node* slow=head,*fast=head,*temp;
    while(slow && fast&& fast->next)
    {
        temp=slow;
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
            break;
    }
    if(slow==fast)
    {
        slow=head;
        while(fast!=slow)
        {
            slow=slow->next;
            temp=fast;
            fast=fast->next;
        }
            temp->next=NULL;
    }
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
        cin>>k;
        looping(head,tail,k);
        removeloop(head);

        if(detectloop(head))
            cout<<"Loop isn't removed\n";
        else
            cout<<"Loop has been removed\n";
    }
return 0;
}

