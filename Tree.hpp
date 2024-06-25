#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include "Node.hpp"

template <typename T, int k=2>
class Tree{

        private:
        std::vector<Node<T>> nodes; // for build heap
        Node<T>* root;
        int max_children;

        void heapifyDown(Node<T>* node) {
            while (true) {
            Node<T>* smallestNode = node;
            
            for (int i = 0; i < node->childrenSize(); ++i) {
                if (node->getChildren()[i]->getKey() < smallestNode->getKey()) {
                    smallestNode = node->getChildren()[i];
                }
            }

            if (smallestNode == node) break;

            T temp = smallestNode->getKey();
            smallestNode->setKey(node->getKey());
            node->setKey(temp);

            node = smallestNode;
        }
    }


    public:
        Tree(): root(nullptr), max_children(k){}

        void add_root(Node<T>& node){
            root = &node;
        }

        Node<T>* getRoot() const{
            return root;
        }

        void add_sub_node(Node<T>& parent, Node<T>& child) {
            if (parent.childrenSize() < k) {
                parent.getChildren().push_back(&child);
            } else {
                std::cerr << "Cannot add more than " << k << " children to a node in this tree.\n";
            }
        }

        class inorderIterator{
            private:
                Node<T>* current_node;
                std::stack<Node<T>*> stk;

            public:
                inorderIterator(Node<T>* ptr): current_node(ptr) {
                    //go to the left node
                    while(current_node != nullptr){
                        stk.push(current_node);
                        if(current_node->childrenSize()){
                            current_node = current_node->getChildren()[0];
                        }
                        else{
                            current_node = nullptr;
                        }

                    }
                    if(!stk.empty()){
                    current_node = stk.top();
                    }

                }
        

        
            T& operator*() const {
                return (*current_node).getKey();
            }


            // ++i;
            inorderIterator& operator++() {
                if(stk.empty()){
                    std::cerr << "End traversal\n";
                    current_node = nullptr;
                    return *this;}
                if(current_node->childrenSize()==2){ 
                    //go to the left
                    stk.pop();
                    current_node = current_node->getChildren()[1];
                        while(current_node != nullptr){
                            stk.push(current_node);
                            if(current_node->childrenSize()){
                                current_node = current_node->getChildren()[0];
                            }
                            else{
                                current_node = nullptr;
                            }

                        }
                        current_node = stk.top();
                }
                else{
                    stk.pop();
                    if(stk.empty()){current_node = nullptr;}
                    else{current_node = stk.top();}         
                }
                return *this;
            }

            // i++;
            // Usually iterators are passed by value and not by const& as they are small.
            const inorderIterator operator++(int) {
                inorderIterator tmp = *this;
                ++tmp;
                return tmp;
            }

            bool operator==(const inorderIterator& it) const {
                return current_node == it.current_node;
            }

            bool operator!=(const inorderIterator& it) const {
                return current_node != it.current_node;;
            }

        };  // END OF CLASS ITERATOR

        class preorderIterator{ //root-left-right
            private:
                Node<T>* current_node;
                std::stack<Node<T>*> stk;


            public:
                preorderIterator(Node<T>* ptr): current_node(ptr) {
                    //start with root
                    if(current_node != nullptr){
                    stk.push(current_node);
                    }
                }
            

            T& operator*() const {
                return (*current_node).getKey();
            }


            // ++i;
            preorderIterator& operator++() {
                if(stk.empty()){
                    std::cerr << "End traversal\n";
                    current_node = nullptr;
                    return *this;}
                stk.pop();    
                if(current_node->childrenSize()==2){
                    stk.push(current_node->getChildren()[1]);
                    stk.push(current_node->getChildren()[0]);
                }
                if(current_node->childrenSize()==1){
                    stk.push(current_node->getChildren()[0]);
                }
                if(stk.empty()){current_node = nullptr; return *this;}
                current_node = stk.top(); 
                return *this;
            }

            // i++;
            const preorderIterator operator++(int) {
                preorderIterator tmp = *this;
                ++tmp;
                return tmp;
            }

            bool operator==(const preorderIterator& it) const {
                return current_node == it.current_node;
            }

            bool operator!=(const preorderIterator& it) const {
                return current_node != it.current_node;;
            }

        };  // END OF CLASS ITERATOR

         class postorderIterator{ //left-right-root
            private:
                Node<T>* current_node;
                std::stack<Node<T>*> stk1;
                std::stack<Node<T>*> stk2;


            public:
                	postorderIterator(Node<T>* ptr): current_node(ptr) {
                        
                       if(current_node != nullptr){
                        stk1.push(current_node);
                       }
                       //insert the nodes to the stack in reverse preorder
                       while(!stk1.empty()){
                            current_node = stk1.top();
                            stk1.pop();
                            stk2.push(current_node);
                            if(current_node->childrenSize()==2){
                                stk1.push(current_node->getChildren()[0]);
                                stk1.push(current_node->getChildren()[1]);
                            }
                            if(current_node->childrenSize()==1){
                                stk1.push(current_node->getChildren()[0]);
                            }
                       }
                       if(!stk2.empty()){current_node = stk2.top();}
                    }
            

        
            T& operator*() const {
                //return *current_node;
                return (*current_node).getKey();
            }


            // ++i;
            postorderIterator& operator++() {
                if(stk2.empty()){
                    std::cerr << "End traversal\n";
                    current_node = nullptr;
                    return *this;}
                stk2.pop();
                if(!stk2.empty()){current_node = stk2.top();}
                else{current_node = nullptr;}     
                return *this;
            }

            // i++;
            const postorderIterator operator++(int) {
                postorderIterator tmp = *this;
                ++tmp;
                return tmp;
            }

            bool operator==(const postorderIterator& it) const {
                return current_node == it.current_node;
            }

            bool operator!=(const postorderIterator& it) const {
                return current_node != it.current_node;;
            }

        };  // END OF CLASS ITERATOR

        class bfsIterator{
            private:
                Node<T>* current_node;
                std::queue<Node<T>*> Q; //for bfs
                std::queue<Node<T>*> myQ; //for iterate


            public:
                	bfsIterator(Node<T>* ptr): current_node(ptr) {
                        
                       if(current_node != nullptr){
                        Q.push(current_node);
                       }
                       //insert all nodes to myQ after bfs
                       while(!Q.empty()){
                            current_node = Q.front();
                            Q.pop();
                            myQ.push(current_node);
                            for(size_t i=0;i<current_node->childrenSize();i++){
                                Q.push(current_node->getChildren()[i]);
                            }
                       }
                       if(!myQ.empty()){current_node = myQ.front();}
                    }
                    
                         
        
            Node<T>* operator*() const {
                //return *current_node;
                return current_node;
            }


            // ++i;
            bfsIterator& operator++() {
                if(myQ.empty()){
                    std::cerr << "End traversal\n";
                    current_node = nullptr;
                    return *this;}
                myQ.pop();
                if(!myQ.empty()){current_node = myQ.front();}
                else{current_node = nullptr;}     
                return *this;
            }

            // i++;
            const bfsIterator operator++(int) {
                bfsIterator tmp = *this;
                ++tmp;
                return tmp;
            }

            bool operator==(const bfsIterator& it) const {
                return current_node == it.current_node;
            }

            bool operator!=(const bfsIterator& it) const {
                return current_node != it.current_node;;
            }

        };  // END OF CLASS ITERATOR

         class dfsIterator{
            private:
                Node<T>* current_node;
                std::queue<Node<T>*> myQ; //for iterate


            public:
                dfsIterator(Node<T>* ptr): current_node(ptr) {
                    
                    if(current_node != nullptr){
                    dfsVisit(current_node);
                    }
                }
            
            T& operator*() const {
                //return *current_node;
                return (*current_node).getKey();
            }


            // ++i;
            dfsIterator& operator++() {
                if(myQ.empty()){
                    std::cerr << "End traversal\n";
                    current_node = nullptr;
                    return *this;}
                myQ.pop();
                if(!myQ.empty()){current_node = myQ.front();}
                else{current_node = nullptr;}     
                return *this;
            }

            // i++;
            const dfsIterator operator++(int) {
                dfsIterator tmp = *this;
                ++tmp;
                return tmp;
            }

            bool operator==(const dfsIterator& it) const {
                return current_node == it.current_node;
            }

            bool operator!=(const dfsIterator& it) const {
                return current_node != it.current_node;;
            }

            void dfsVisit(Node<T>*& cur){
                myQ.push(cur);
                for(size_t i=0;i<cur->childrenSize();i++){
                    dfsVisit(cur->getChildren()[i]);
                }

            }

        };  // END OF CLASS ITERATOR
            
        inorderIterator begin_in_order(){
            if(k != 2){
                std::cerr << "this tree is not BT" << std::endl;
                return nullptr;}
            inorderIterator it(this->root);
            return it;
        }
            
        inorderIterator end_in_order(){
            inorderIterator it(nullptr);
            return it;

        }

        preorderIterator begin_pre_order(){
              if(k != 2){
                std::cerr << "this tree is not BT" << std::endl;
                return nullptr;}
            preorderIterator it(this->root);
            return it;
        }
            
        preorderIterator end_pre_order(){
            preorderIterator it(nullptr);
            return it;

        }

        postorderIterator begin_post_order(){
              if(k != 2){
                std::cerr << "this tree is not BT" << std::endl;
                return nullptr;}
            postorderIterator it(this->root);
            return it;
        }
            
        postorderIterator end_post_order(){
            postorderIterator it(nullptr);
            return it;

        }

        bfsIterator begin_bfs_scan(){
            bfsIterator it(this->root);
            return it;
        }
            
        bfsIterator end_bfs_scan(){
            bfsIterator it(nullptr);
            return it;

        }

        dfsIterator begin_dfs_scan(){
            dfsIterator it(this->root);
            return it;
        }
            
        dfsIterator end_dfs_scan(){
            dfsIterator it(nullptr);
            return it;

        }

    
    void myHeap() {

        if(k != 2){
                std::cout << "this tree is not BT" << std::endl;
                return;}
        if (root == nullptr) {return;}
        for (auto node = this->begin_bfs_scan(); node != this->end_bfs_scan(); ++node) {
            T t = (*node)->getKey();
            Node<T> n = Node<T>(t);
            nodes.push_back((n));
        }
        root = &nodes[0];
        for (size_t i=0;i<(nodes.size() / 2) ;i++){
            add_sub_node(nodes[i], nodes[(2*i)+1]);
            if(nodes.size()>(2*i)+2){
            add_sub_node(nodes[i], nodes[(2*i)+2]);
            }
        }


        // Start from the last non-leaf node
        for (int i = (nodes.size() / 2)-1 ; i >= 0; --i) {
            heapifyDown(&nodes[i]);       
    }
        
    }

};