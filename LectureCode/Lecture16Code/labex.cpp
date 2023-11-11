#include <iostream>

struct node{
    int data;
    node* next;
};

node * copy_list(node* p){
    if(!p){
        return p;
    }
    return new node{p->data,copy_list(p->next)};
}

node * merge(node * p, node* q){
    
    if(!p){
        return copy_list(q);
    }
    if(!q){
        return copy_list(p);
    }

    if(p->data < q->data){
        return new node{p->data,merge(p->next,q)};
    }
    return new node{q->data,merge(p,q->next)};

}

int main(){
    node * p = new node{2,new node{4,new node{7,new node{9,nullptr}}}};
    node * q = new node{1,new node{6,new node{9,new node{91,nullptr}}}};
    node * m = merge(p,q);

    for(node* r = m; r ; r = r->next){
        std::cout << r->data << " ";
    }
}