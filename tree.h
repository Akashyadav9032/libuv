#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>
#include <vector>

class Tree
{
private:
    struct Node
    {
        std::string _data = "";
        Node* _sibling = nullptr;
        Node* _child = nullptr;

        Node(std::string s = "");
        Node(const Node& that);
        ~Node();
        Node& operator=(const Node& that); // deep clone
        std::string get_data() const;
        void set_data(std::string s);
        Node* insert_sibling(Node* p);
        Node* insert_child(Node* p);
        bool operator==(const Node& that) const;
        bool operator!=(const Node& that) const;
        std::string to_string() const;

        // static helper
        static bool is_equal(const Node* p1, const Node* p2);
    };

private:
    Node* _root = nullptr;

    // static constants
    static const std::string _ROOT_NAME; 
    static const std::vector<std::string> _CONFIG_1;

public:
    Tree();
    Tree(const Tree& that);
    ~Tree();
    Tree& operator=(const Tree& that); // deep clone
    bool operator==(const Tree& that) const;
    bool operator!=(const Tree& that) const;
    std::string to_string() const;
    void make_special_config_1(const std::vector<std::string>& names = _CONFIG_1);

    // global friend overload
    friend std::ostream& operator<<(std::ostream& os, const Tree& tree);

    // don't remove this line
    friend class Tests;
};

#endif // TREE_H
