#include <string>
class M_BST // Modified BST Class for use in part 2
{
public:
    class node
    {
    public:
        node *left;
        node *right;
        node *parent;
        int key;
        std::string data;
    };
    node *root;
    M_BST();
    ~M_BST();
    void insert(int, std::string); // Will now assign a string along with a key value to inserted nodes
    void pre_order_traversal(node *);
    void in_order_traversal(node *);
    void in_order_traversal_no_print(node *); // To traverse tree without outputting nodes
    void post_order_traversal(node *);
    node *find_max(node *);
    node *find_min(node *);
    node *find_node(node *, int);
    node *find_parent(node *, int);
    void delete_max(node *);
    void remove_max();
    node *find_successor(node *);
    node *delete_node(node *);
    bool is_empty();
    bool validate_time_gap(node *, int, int); // Validates the K time constraint
};