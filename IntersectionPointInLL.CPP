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

int intersectingpoint(Node* head1,Node* head2)
{
   Node* one=head1,*two=head2;
    int c=-1;
    int a=0,b=0;
    while(one!=NULL)
    {
        a++;
        one=one->next;
    }

    while(two!=NULL)
    {
        b++;
        two=two->next;
    }
    int diff=abs(a-b);
    if(a>b)
    {
        while(diff--)
        {
            head1=head1->next;
        }
    }
    else
    {
        while(diff--)
        {
            head2=head2->next;
        }
    }

    while(head1!=NULL && head2!=NULL)
    {
        if(head1==head2)
            return head1->data;
        head1=head1->next;
        head2=head2->next;
    }

    return -1;
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

Node* inputlist(int n)
{
    if(n==0)
        return NULL;
    int val;
    cin>>val;

    Node* head=new Node(val);
    Node* tail=head;

    for(int i=0;i<n-1;i++)
    {
        cin>>val;
        tail->next=new Node(val);
        tail=tail->next;
    }
    return head;
}

int main()
{
    SPEED;
    int test;
    cin>>test;
    while(test--)
    {
        int n1,n2,n3;
        cin>>n1>>n2>>n3;

        Node* head1=inputlist(n1);
        Node* head2=inputlist(n2);
        Node* common= inputlist(n3);

        Node* temp=head1;
        while(temp!=NULL && temp->next!=NULL)
            temp=temp->next;
        if(temp!=NULL)
            temp->next=common;

        temp=head2;
        while(temp!=NULL && temp->next!=NULL)
            temp=temp->next;
        if(temp!=NULL)
            temp->next=common;

        cout<<intersectingpoint(head1,head2)<<endl;
    }
return 0;
}

