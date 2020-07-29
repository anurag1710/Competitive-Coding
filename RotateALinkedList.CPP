
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

Node* rotatell(Node* head,int k)
{
    if(head->next==NULL)
        return head;
    Node* ptr=head,*preptr,*temp;
    while(k--)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    if(ptr==NULL)
        return head;

    preptr->next=NULL;
    temp=ptr;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=head;
    head=temp;

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
        head=rotatell(head,k);
        displaylist(head);
    }
return 0;
}

