template<typename Object>
class Vector
{
public:
    explicit Vector(int initSize = 0)
        : theSize(initSize), theCapacity(initSize + SPARE_CAPACITY)
    {
        objects = new Object[theCapacity];
    }

    ~Vector()
    {
        delete[] objects;
    }
    Vector(const Vector &rhs) : objects(NULL)
    {
        operator=(rhs);
    }
    const Vector & operator= (const Vector &rhs)
    {
        if (this != &rhs)
        {
            delete[] objects;
            theSize = rhs.size();
            theCapacity = rhs.capacity();

            objects = new Object[theCapacity];
            for (int k = 0; k < size(); k++)
            {
                objects[k] = rhs.objects[k];
            }
        }
        return *this;
    }
    int size() const
    {
        return theSize;
    }

    int capacity()const
    {
        return theCapacity; 
    }

    void reserve(int newCapacity)
    {
        Object *oldArray = objects;
        objects = new Object[newCapacity];
        for (int k = 0; k < theSize; k++)
        {
            objects[k] = oldArray[k];
        }
        theCapacity = newCapacity;
        delete[] oldArray;
    }

    void push_back(const Object &x)
    {
        if(theSize == theCapacity)
        {
            reserve(2 * theCapacity + 1);
        }
        objects[theSize++] = x;
    }

    void pop_back()
    {
        theSize--;
    }

    bool empty()const
    {
        return (size() == 0);
    }

    Object& operator[](int index)
    {
        return objects[index];
    }

    const Object& operator[](int index)const 
    {
        return objects[index];
    }
    const Object &back() const
    {
        return objects[theSize - 1];
    }
    void resize(int newSize)
    {
        if (newSize > theCapacity)
            reserve(newSize * 2 + 1);
        theSize = newSize;
    }

    typedef Object* iterator;
    typedef const Object* const_iterator;

    iterator begin()
    {
        return &objects[0];
    }
    const iterator begin() const
    {
        return &objects[0];
    }
    iterator end()
    {
        return &objects[size()];
    }
    const iterator end() const
    {
        return &objects[size()];
    }
    enum{SPARE_CAPACITY = 16};
private:
    int theSize;
    int theCapacity;
    Object *objects;
};
