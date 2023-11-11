#ifndef LL_H
#define LL_H
#include <iostream>

template <typename T>
class ll{
    public:
        ll();
        void add(T);

        template <typename U>
        friend std::ostream & operator<<(std::ostream&, const ll<U> &);
        
        void append(T);
        ~ll();
        ll(const ll&);
        const ll & operator=(const ll&);

    private:
        struct node{
            T data;
            node* next;
        };
        node * copy_list(node*);
        node * delete_list(node*);
        node * append(node *,T);
        node * head;

};

template <typename T>
typename ll<T>::node * ll<T>::delete_list(node * p){
    if(p){
        delete_list(p->next);
        delete p;
    }
    return nullptr;
}
template <typename T>
typename ll<T>::node  * ll<T>::copy_list(node* p){
    if(!p){
        return p;
    }
    return new node{p->data,copy_list(p->next)};
}
template <typename T>
typename ll<T>::node * ll<T>::append(node* p,T x){
    if(!p){
        return new node{x,p};
    }
    p->next = append(p->next,x);
    return p;
}

template <typename T>
void ll<T>::append(T x){
    head = append(head,x);
}
template <typename T>
ll<T>::ll(){
    head = nullptr;
}

template <typename T>
void ll<T>::add(T x){
    head = new node{x,head};
}

template <typename T>
std::ostream & operator<<(std::ostream& out , const ll<T> & rhs){
    typename ll<T>::node * p = rhs.head;
    while(p){
        out << p->data << " ";
        p = p->next;
    }
    return out;
}

template <typename T>
ll<T>::~ll(){
    head = delete_list(head);
}
template <typename T>
ll<T>::ll(const ll& rhs){
    head = copy_list(rhs.head);
}
template <typename T>
const ll<T> & ll<T>::operator=(const ll& rhs){
    if(this != &rhs){
        head = delete_list(head);
        head = copy_list(rhs.head);
    }
    return *this;
}



#endif