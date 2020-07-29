
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

Node* pairwiseswap(Node* head)
{
    int c;
    if(head->next==NULL)
        return head;
    if(head->next->next==NULL)
    {
        c=head->next->data;
        head->next->data=head->data;
        head->data=c;
        return head;
    }
    Node* temp=head,*ptr;
    ptr=temp;
    temp=temp->next;

    while(temp!=NULL)
    {
        c=temp->data;
        temp->data=ptr->data;
        ptr->data=c;

        if(temp->next!=NULL)
        {
            ptr=temp->next;
            temp=ptr->next;
        }
        else
            temp=temp->next;
    }
    return head;
}

void displaylist(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    SPEED;
    int test;
    cin>>test;
    while(test--)
    {
        int n,data;
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

        head=pairwiseswap(head);
        displaylist(head);
    }
return 0;
}

