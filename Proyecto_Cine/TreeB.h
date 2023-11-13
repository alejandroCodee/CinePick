#ifndef TREEB_H
#define TREEB_H

#include <functional>
#include <iostream>
#include <vector>

class TreeB {
public:
    TreeB(int t);
    ~TreeB();
    void insert(const std::string &movieName);

    struct Node {
        std::vector<std::string> keys;
        std::vector<Node*> children;
        bool isLeaf;
    };

    Node* root;
    int t;


    void splitNode(Node* parentNode, int index, Node* childNode);
    void insertNonFull(Node* node, const std::string &movieName);
    void traverse(Node* node, std::function<void(const std::string&)> callback);

    Node* search(Node* node, const std::string &movieName);


private:

};

#endif // TREEB_H
