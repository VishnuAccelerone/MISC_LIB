//Doubly Linked List
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

public:
    //iterator class and functionalities
    class const_iterator
    {
    public:
        const_iterator() : current(NULL) {}
        const Object& operator*()const
        {
            return retreive();
        }
        const_iterator &  operator++()
        {
            current = current->next;
            return *this;
        }

        const_iterator operator++(int)
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator== (const const_iterator &rhs)const
        {
            return current == rhs.current;
        }
        bool operator!=(const const_iterator &rhs)const
        {
            return!(current == rhs.current);
        }
    protected:
        Node* current;

        Object & retreive() const
        {
            return current->data;
        }

        const_iterator(Node* p) : current(p) {}
        friend class List<Object>;
    };


public :
    //Big three plus constructor

    List() { init(); }
    List(const List &rhs) { init(); *this = rhs; }
    ~List() {}
    const List& operator=(const List &rhs) {}

    //init
    void init()
    {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }

    //functionalities



private:
    int theSize;
    Node *head;
    Node *tail;
};
