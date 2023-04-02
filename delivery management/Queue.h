#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include "Order.h"

using namespace std;

class Queue {
    public:
        Queue();
        ~Queue();
        bool empty();
        int size() const;
        Order* peekFirst();
        Order* popFirst();
        void addLast(Order* order);
    private:
    	class Node{
    		public:
    		Order* data;
    		Node* next;
    	};
        Node* head;
        Node* tail;
        int track;
        
};

#endif
