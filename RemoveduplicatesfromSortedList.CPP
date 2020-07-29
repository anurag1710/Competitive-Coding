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

Node* duplicatesremove(Node* head)
{
    Node* temp=head,*ptr,*temp1;

    while(temp!=NULL)
    {
        ptr=temp;
        temp=temp->next;

        if(temp==NULL)
            break;

        if(temp->data == ptr->data)
        {
            ptr->next=temp->next;
            temp1=temp;
            temp=ptr;
            delete temp1;
        }
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

        head=duplicatesremove(head);
        displaylist(head);
    }
return 0;
}

