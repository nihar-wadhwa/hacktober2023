#include<iostream>
#include<conio.h>
using namespace std;

class Node
{
  public:
    int val;
    Node *next;

    Node()
    {
        val = 0;
        next = NULL;
    }
};

class Linked_list
{
  public:
    Node *first;
    Linked_list(){first = NULL;}
    void display();
    int count();
    void insert(int x, int pos);
    void insert_end(int x);
    bool is_sorted();
    void insert_sort(int x);
    int sum();
    int max();
    bool search(int x);
    void delete_node(int x);
    void remove_duplicates();
    void reverse();
    void concatenate(Linked_list temp);
    void merge(Linked_list temp);
};

void Linked_list::display()
{
    Node *p=first;
    while(p)
    {
        cout<<p->val<<", ";
        p=p->next;
    }
    cout<<endl;
}

int Linked_list::count()
{
    Node *p=first;
    int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
}

void Linked_list::insert(int x, int pos)
{
    if(pos<0 || pos>count())
    {
        cout<<"Invalid Index"<<endl;
        return;
    }

    Node *p = first;
    Node *t = new Node;
    t->val = x;

    if(p==NULL)
        first = t;
    else
    {
        for(int i=0; i<pos-1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

void Linked_list::insert_end(int x)
{
    Node *p = first;
    Node *t = new Node;
    t->val = x;

    if(first==NULL)
        first=t;
    else
    {
        while(p->next)
        {
            p=p->next;
        }
        p->next = t;
    }
}

bool Linked_list::is_sorted()
{
    int x=INT32_MIN;
    Node *p=first;
    while(p)
    {
        if(p->val<x)
            return false;
        x=p->val;
        p=p->next;
    }
    return true;
}

void Linked_list::insert_sort(int x)
{
    Node *p=first, *q=NULL;
    Node *t=new Node;
    t->val=x;

    if(first == NULL)
    {
        first = t;
        return;
    }
    while(p && p->val<x)
    {
        q=p;
        p=p->next;
    }

    if(p==first)
    {
        t->next = p;
        first = t;
    }
    else
    {
        t->next = q->next;
        q->next = t;
    }
}

int Linked_list::sum()
{
    int s=0;
    Node *p=first;
    while(p)
    {
        s+=p->val;
        p=p->next;
    }
    return s;
}

int Linked_list::max()
{
    Node *p=first;
    int m=p->val;
    while(p)
    {
        if(p->val>m)
            m=p->val;
        p=p->next;
    }
    return m;
}

bool Linked_list::search(int x)
{
    Node *p=first;
    if(p==NULL) return false;
    while(p)
    {
        if(p->val==x)
            return true;
        p=p->next;
    }
    return false;
}

void Linked_list::delete_node(int x)
{
    Node *p=first, *q=NULL;
    
    if(p==NULL)
    {
        cout<<"Nothing to delete"<<endl;
        return;
    }
    if(first->val == x)
    {
        first=p->next;
        return;
    }
    while(p->val!=x)
    {
        q=p;
        p=p->next;
    }
    
    if(p->val == x)
    {
        q->next=p->next;
        delete p;
        cout<<"Node deleted"<<endl;
    }
    else
    {
        cout<<"No nodes found"<<endl;
    }
}

void Linked_list::remove_duplicates()
{
    Node *p=first, *q=first->next;
    while(q)
    {
        if(p->val != q->val)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}

void Linked_list::reverse()
{
    Node *p=first, *q=NULL, *r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    first = q;
}

void Linked_list::concatenate(Linked_list temp)
{
    Node *p=first;
    if(p==NULL)
        first=temp.first;
    
    else
    {
        while(p->next)
            p=p->next;
        p->next = temp.first;
    }
}

void Linked_list::merge(Linked_list temp)
{
    Linked_list res;
    Node *last = NULL;
    if(!is_sorted() && !temp.is_sorted())
    {
        cout<<"Lists must be sorted"<<endl;
        return;
    }

    if(first==NULL || temp.first==NULL)
    {
        cout<<"One of the list is empty"<<endl;
        return;
    }

    if(first->val <= temp.first->val)
    {
        res.first = first;
        first = first->next;
        res.first->next = NULL;
    }
    else
    {
        res.first = temp.first;
        temp.first = temp.first->next;
        res.first->next = NULL;
    }

    last = res.first;
    while(first!=NULL && temp.first!=NULL)
    {
        if(first->val <= temp.first->val)
        {
            last->next = first;
            first = first->next;
        }
        else
        {
            last->next = temp.first;
            temp.first = temp.first->next;
        }
        last = last->next;
        last->next = NULL;
    }

    if(first!=NULL) 
        last->next = first;
    else
        last->next = temp.first;

    first = res.first;
}

int main()
{
    Linked_list l, temp;
    int ch, x, pos, n;
    do
    {
        cout<<"1. Display"<<endl;
        cout<<"2. Insert node"<<endl;
        cout<<"3. Insert node at end"<<endl;
        cout<<"4. Insert nodes"<<endl;
        cout<<"5. Insert in sorted position"<<endl;
        cout<<"6. Count Nodes"<<endl;
        cout<<"7. Sum of elements"<<endl;
        cout<<"8. Maximum"<<endl;
        cout<<"9. Search"<<endl;
        cout<<"10. is sorted?"<<endl;
        cout<<"11. Delete"<<endl;
        cout<<"12. Remove duplicates"<<endl;
        cout<<"13. Reverse"<<endl;
        cout<<"14. Concatenate"<<endl;
        cout<<"15. Merge"<<endl;
        cout<<"16. Exit"<<endl;
        cout<<"\nEnter option:- ";
        cin>>ch;

        switch(ch)
        {
            case 1: l.display();
                    break;
            case 2: cout<<"Enter element: ";
                    cin>>x;
                    cout<<"Enter position: ";
                    cin>>pos;
                    l.insert(x, pos);
                    break;
            case 3: cout<<"Enter element: ";
                    cin>>x;
                    l.insert_end(x);
                    break;
            case 4: cout<<"Enter number of nodes: ";
                    cin>>n;
                    cout<<"Enter elements: "<<endl;
                    for(int i=0; i<n; i++)
                    {
                        cin>>x;
                        l.insert_end(x);
                    }
                    break;
            case 5: if(l.is_sorted())
                    {
                        cout<<"Enter element: ";
                        cin>>x;
                        l.insert_sort(x);
                    }
                    else
                    {
                        cout<<"List is not sorted"<<endl;
                    }
            case 6: cout<<"Number of nodes: "<<l.count()<<endl;
                    break;
            case 7: cout<<"Sum of elemets is "<<l.sum()<<endl;
                    break;
            case 8: cout<<"Maximum element is "<<l.max()<<endl;
                    break;
            case 9: cout<<"Enter element to search: ";
                    cin>>x;
                    if(l.search(x)) cout<<"Element is found"<<endl;
                    else cout<<"Element does not exist"<<endl;
                    break;
            case 10:if(l.is_sorted()) cout<<"List is sorted"<<endl;
                    else cout<<"List is not sorted"<<endl;
                    break;
            case 11:cout<<"Enter element to delete: ";
                    cin>>x;
                    l.delete_node(x);
                    break;
            case 12:l.remove_duplicates();
                    break;
            case 13:l.reverse();
                    break;
            case 14:cout<<"Enter number of nodes in second linked list: ";
                    cin>>n;
                    cout<<"Enter elements: "<<endl;
                    for(int i=0; i<n; i++)
                    {
                        cin>>x;
                        temp.insert_end(x);
                    }
                    l.concatenate(temp);
                    temp.first = NULL;
                    break;
            case 15:cout<<"Enter number of nodes in second linked list: ";
                    cin>>n;
                    cout<<"Enter elements: "<<endl;
                    for(int i=0; i<n; i++)
                    {
                        cin>>x;
                        temp.insert_end(x);
                    }
                    l.merge(temp);
                    temp.first = NULL;
                    break;
            case 16:return 0;
        }
        cout<<"Enter to continue ...";
        getch();
        cout<<endl<<endl;
    } while (true);
    
    return 0;
}