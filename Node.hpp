// tzvirechel@gmail.com
#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <QString>

template <typename T>
class Node{

    private:
    T key;
    std::vector<Node<T>*> children;
    
    public:
    Node(T key) : key(key){}
   
    

    T& getKey(){
        return key;
    }

    size_t childrenSize(){
        return children.size();
    }

    void setKey(T key2){
        this->key = key2;
    }

    std::vector<Node<T>*>& getChildren(){
        return children;
    }

     QString toString() const {
        std::stringstream ss;
        ss << key;
        return QString::fromStdString(ss.str());
    }

};