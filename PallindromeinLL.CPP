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

bool palindrome(Node* head)
{
    stack<int> S;
    Node* temp=head;
    while(temp!=NULL)
    {
        S.push(temp->data);
        temp=temp->next;
    }
    while(!S.empty())
    {
        if(head->data!=S.top())
        {
            return false;
        }
            S.pop();
            head=head->next;
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
        if(palindrome(head))
        {
            cout<<"It is Palindrome.\n";
        }
        else
            cout<<"It is not.\n";
    }
return 0;
}


