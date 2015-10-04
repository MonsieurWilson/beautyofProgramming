#ifndef VECTOR_H
#define VECTOR_H
template <typename Object>
class Vector {
public:
    explicit Vector (const int initSize = 0);
    Vector (const Vector &v);
    ~Vector ();
    Vector &operator = (const Vector &v);
    
    void resize(const int newSize);
    void reserve(const int newCapacity);

    Object &operator [] (const int index);
    const Object &operator [] (const int index) const;
    inline bool empty() const;
    inline int size() const;
    inline int capacity() const;
    void push_back(const Object &x);
    void pop_back();
    const Object &back() const;
    Object &back();

    void print(ostream &o) const;

private:
    int theSize;
    int theCapacity;
    Object *objects;
};

template <typename Object>
Vector<Object>::Vector(const int initSize): theSize(initSize), theCapacity(initSize) {
    objects = new Object[theCapacity];
}

template <typename Object>
Vector<Object>::Vector(const Vector<Object> &v): objects(nullptr) {
    operator = (v);
}

template <typename Object>
Vector<Object>::~Vector() {
    delete[] objects;
}

template <typename Object>
Vector<Object> &Vector<Object>::operator = (const Vector<Object> &v) {
    if (this != v) {
        delete[] objects;
        theSize = v.size();
        theCapacity = v.capacity();
        objects = new Object[theCapacity];
        for (int i = 0; i < theSize; ++i) {
            objects[i] = v.objects[i];
        }
    }
    return *this;
}

template <typename Object>
void Vector<Object>::resize(const int newSize) {
    if (newSize > theCapacity) {
        reserve(newSize * 2 + 1);
    }
    theSize = newSize;
}

template <typename Object>
void Vector<Object>::reserve(const int newCapacity) {
    if (newCapacity < theSize) {
        return;
    }
    Object *old = objects;
    objects = new Object[newCapacity];
    for (int i = 0; i < theSize; ++i) {
        objects[i] = old[i];
    }
    theCapacity = newCapacity;
    delete[] old;
}

template <typename Object>
Object &Vector<Object>::operator [] (const int index) {
    return objects[index];
}

template <typename Object>
const Object &Vector<Object>::operator [] (const int index) const {
    return objects[index];
}

template <typename Object>
bool Vector<Object>::empty() const {
    return theSize == 0;
}

template <typename Object>
int Vector<Object>::size() const {
    return theSize;
}

template <typename Object>
int Vector<Object>::capacity() const {
    return theCapacity;
}

template <typename Object>
void Vector<Object>::push_back(const Object &o) {
    if (theSize == theCapacity) {
        reserve(2 * theCapacity + 1);
    }
    objects[theSize++] = o;
}

template <typename Object>
void Vector<Object>::pop_back() {
    --theSize;
}

template <typename Object>
Object &Vector<Object>::back() {
    return objects[theSize - 1];
}

template <typename Object>
const Object &Vector<Object>::back() const {
    return objects[theSize - 1];
}

template <typename Object>
void Vector<Object>::print(ostream &o) const {
    o << "[";
    for (int i = 0; i < theSize; ++i) {
        o << objects[i];
        if (i != theSize - 1) {
            o << ", ";
        }
    }
    o << "]";
}

template <typename Object>
ostream &operator << (ostream &o, const Vector<Object> &v) {
    v.print(o);
    return o;
}

#endif
