
template<typename Object>

class List
{
private :
    struct Node
    {
        Object data;
        Node *prev;
        Node *next;
    };

public :
    List(){}
    List(const List &rhs) {}
    ~List() {}
    const List& operator=(const List &rhs) {}

private:
    int theSize;
    Node *head;
    Node *tail;
};
