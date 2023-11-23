#ifndef Q_H
#define Q_H

template <typename T>
class queue{
    public:
        queue();
        void enqueue(T);
        T dequeue();
        T front();
        bool isEmpty();

        //also should have the memory functions too but too lazy for that

    private:
        struct node{
            T data;
            node* next;
        };
        node * head;
        node *tail;
};
template <typename T>
queue<T>::queue(){
    head = tail = nullptr;
}
template <typename T>
void queue<T>::enqueue(T x){
    if(!head){
        head = new node{x , head};
        tail = head;
    }else{
        tail->next = new node{x, nullptr};
        tail = tail->next;
    }
}
template <typename T>
T queue<T>::dequeue(){
    T ret_val = front();
    node * tmp = head;
    head = head->next;
    if(!head){
        tail = nullptr;
    }
    delete tmp;
    return ret_val;
    
}
template <typename T>
T queue<T>::front(){
    if(isEmpty()){
        std::cerr << "QUEUE IS EMPTY";
        exit(1);
    }
    return head->data;
}
template <typename T>
bool queue<T>::isEmpty(){
    return !head;
}

#endif