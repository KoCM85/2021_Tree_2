#ifndef TREE_H

#define TREE_H

#include <iostream>
#include <memory>
#include <deque>

template<class type1>
class tree {

    template<class type2>
    class node {
    public:
        type2 data;

        node * left = nullptr;
        node * right = nullptr;

        node(type2 data_in) : data(data_in) {}
    };

    node<type1>* root = nullptr;

    std::deque<node<type1>> nodes;

public:
    tree() = default;
    tree(const tree&) = delete;
    tree(tree&&) = delete;

    tree& operator=(const tree&) = delete;
    tree& operator=(tree&&) = delete;

    void add(type1 data_in) {
        node<type1>** node_cur = &root;

        while (*node_cur) {
            if (data_in > (*node_cur)->data)
                node_cur = &(*node_cur)->right;
            else
                node_cur = &(*node_cur)->left;
        }

        nodes.emplace_back(data_in);
        *node_cur = &nodes.back();
    }

    void cout_data() {
        for (auto&& node_1 : nodes)
            std::cout << node_1.data << ' ';
    }
};

#endif // TREE_H