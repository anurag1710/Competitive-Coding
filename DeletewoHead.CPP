
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

void display(Node* head)
{
    Node*  temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* findnode(Node* head,int k)
{
   Node* temp=head;
   while(temp!=NULL)
   {
       if(temp->data==k)
       {
           break;
       }
       temp=temp->next;
   }
   return temp;
}

void deletenode(Node* node)
{
   Node* temp=node;
   node->data=node->next->data;
   temp=node->next;
   node->next=node->next->next;
   delete temp;
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
        Node* add=findnode(head,k);
        if(add!=NULL && add->next!=NULL)
            deletenode(add);

        display(head);
    }
return 0;
}

