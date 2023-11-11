#include <iostream>

struct node{
    node* prev;
    int data;
    node* next;
};
node * remove(int x, node * p){
    if(!p){
        return p;
    }
    node* q = p;
    while(q->next){
        if(q->data == x){
            if(!q->prev){
                q->next->prev = nullptr;
                p = p->next;
                delete q;
                q = p;
            }else{
                q->prev->next = q->next;
                q->next->prev = q->prev;
                node * tmp = q;
                q = q->next;
                delete tmp;
            }

        }else{
            q = q->next;
        }
     }
     if(q->data == x){
        q->prev->next = nullptr;
        delete q;
     }
     return p;

}
node * insert(int x,node * p ){
    if(!p){
        return new node{p,x,p};
    }
    node * q;
    for( q= p;q->next && q->data < x; q = q->next);
    if(!q->prev){
        p = new node{nullptr,x,p};
        p->next->prev = p;
    }
    else if(!q->next && q->data < x){
        q->next = new node{q,x,nullptr};
    }else{
       
        node* t = new node{q->prev,x,q};
        t->next->prev = t;
        t->prev->next = t;
    }

    return p;

}

int main(){
    node * p = nullptr;
    p = new node{nullptr,5,nullptr};
    p = new node{nullptr,3,p};
    p->next->prev = p;
    p->next = new node{p,4,p->next};
    p->next->next->prev = p->next;
    p = new node{nullptr,2,p};
    p->next->prev = p;
    p = new node{nullptr,-1,p};
    p->next->prev = p;
    p = insert(-10,p);
    p = insert(-10,p);
    p = insert(10,p);
    p = insert(9,p);
    p = insert(9,p);
    p = remove(5,p);
    p = remove(-10,p);

    node * q = p;
    while(q->next){
        std::cout << q->data << " ";
        q = q->next;
    }
    std::cout << q->data << std::endl;

    while(q){
        std::cout << q->data << " ";
        q = q->prev;
    }
    
    return 0;
}