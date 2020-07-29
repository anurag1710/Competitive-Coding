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
        if(detectloop(head))
            cout<<"Loop is present\n";
        else
            cout<<"Loop isn't present\n";
    }
return 0;
}

