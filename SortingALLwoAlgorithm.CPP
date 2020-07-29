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

Node* segregate(Node* head)
{
    if(head->next==NULL)
        return head;

    int zero=0,one=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==0)
        {
            zero++;
        }
        else if(temp->data==1)
        { one++; }

        temp=temp->next;
    }
        temp=head;
        while(temp!=NULL)
        {
            if(zero!=0)
            {
                temp->data=0;
                zero--;
            }
            else if(zero==0 && one!=0)
            {
                temp->data=1;
                one--;
            }
            else
            {
                temp->data=2;
            }
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

        head=segregate(head);
        displaylist(head);
    }
return 0;
}

