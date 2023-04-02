#include "Queue.h"
Queue::Queue() : head(NULL), tail(NULL), track(0) {}

Queue::~Queue(){
	while(!empty()){
	   popFirst();
	}
}

bool Queue::empty(){
	if(track == 0){
		return true;
	}
	else{
		return false;
	}
}

int Queue::size() const{
	return track;
}

Order* Queue::peekFirst(){
/*
	Node* curr = head;
	if(curr != nullptr){
		return curr;
	}
	else{
		return nullptr;
	}
	*/
	if (empty()) {
            return nullptr;
        }
        return head->data;
}

Order* Queue::popFirst(){
/*
	if (head == nullptr)return nullptr;
   	Node* curr = head;
   	Node* prev = nullptr;

   	while(curr != nullptr){
   		return curr;
   		prev = curr;
      		curr= curr->next;
   	}
   	*/
   	if(empty()) return nullptr;
   	Node* curr = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        track--;
        Order* result = curr->data;
        delete curr;
        return result;
}

void Queue::addLast(Order* order){
	Node* newNode = new Node{order, nullptr}; 
	if (empty()) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
        track++;
}
