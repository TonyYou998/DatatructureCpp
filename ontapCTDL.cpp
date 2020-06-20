
#include <iostream>
#include<string>
using namespace std;

struct node {
    //int data;
    int data;
    node* pNext;
   
};
struct list {
    node* pHead;
    node* pTail;
};
void createList(list&l) {
    l.pHead = l.pTail = NULL;
}
node* getNode(int x) {
    node* p = new node;
    if (p == NULL)
        return 0;
    p->data = x;
    p->pNext = NULL;
    return p;
}
void addTail(list&l,node*p) {
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        l.pTail->pNext = p;
       
        l.pTail = p;
    }
}

void output(list l) {
    node* p = l.pHead;
    while (p != NULL) {
        
        cout << (char)p->data<<" " ;
        p = p->pNext;
    }
    cout << endl;
   
}
void push(list& l, node* p) {
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
int pop(list&l) {
    node* p = l.pHead;
    if (l.pHead != NULL) {
        
        l.pHead = l.pHead->pNext;
        if (l.pHead == NULL)
            l.pTail = NULL;
        delete p;
        return 1;
    }
    return 0;
}
void input(list& l,int n) {
    createList(l);
    node* p = new node;
    int x;
    while (1) {
        cin >> x;
        if (x == 0)
            break;
        p = getNode(x);

        if (p != NULL) {
            /*if (p->data != n) {
                push(l, p);
               
               
            }*/
              
               
            

         /*   else {
                if (l.pHead == NULL)
                    cout << "stack rong" << endl;
                else
                pop(l);

            }*/
            addTail(l, p);
               

            
               
        }

        

    }
 
}
int top(list l) {
    node* p = l.pHead;
    int trave = 0;
    if (l.pHead != NULL)
        trave = p->data;
    return trave;
}
void xuLy(list&l,int x) {
    int temp=0;
    createList(l);
    while (x != 0) {
        temp = x % 2;
        push(l, getNode(temp));
        x = x / 2;
        
    }
}
void enqueue(list&l,node *temp) {
    
    
    if (l.pHead == NULL)
        l.pHead = l.pTail = temp;
    else {
        l.pTail->pNext = temp;
        l.pTail = temp;
    }
    
}
void dequeue(list&l,list&q){
    
    if (l.pHead != NULL) {
        node* p = l.pHead;
        int temp = p->data;
        enqueue(q, getNode(temp));
        
        l.pHead = p->pNext;
        if (l.pHead == NULL)
            l.pTail = NULL;
        delete p;


    }
    

}
void xuLy2(list &l){
    createList(l);
    int x=-1;

    while (1) {
        cin >> x;
        if (x == 0)
            break;
        enqueue(l, getNode(x));

    }
}
void xuLy3(list &l,list&q) {
    char x;
    createList(q);
    createList(l);
    string s;
    cin >> x;
    

    cin.ignore();
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        int temp = 0;
        temp = (int)s[i];
        
        if ((int)x != temp)
            enqueue(l, getNode(temp));
        else
            dequeue(l, q);
        


    }
  
}
int main()
{
    
    list l,q;
   // int x;
   //cin >> x;
    //xuLy(l, x);

    xuLy3(l,q);
    output(q);
   output(l);
   
    
    
}



