#ifndef SET_H
#define SET_H

#ifdef UNIT_TESTING // this is the unit testing macro
int main(int argc, const char* argv[]);
#endif

namespace custom
{
    template <class T>
    class set
    {
        private:
        T *buffer;
        int numElements;
        int numCapacity;

        public:
        class iterator;

        friend int ::main(int argc, const char* argv[]);

        set();
        set(int numCapacity);
        set(const set<T> & rhs);
        ~set();

        set<T>& operator = (const set<T> & rhs);
        T & operator [] (int index) const;
    

        int size() const;
        bool empty() const;

        void clear();
        void insert(const T & t);

        iterator find(const T & t);
        iterator erase(iterator & it);
        iterator begin();
        iterator end();

        set<T> operator || (const set<T> & rhs);
        set<T> operator && (const set<T> & rhs);
        set<T> operator - (const set<T> & rhs);
        

        private:
        int findIndex(const T & t);
        void resize(int numCapacity); 

    };

    template <class T>
    class set<T> :: iterator
    {
        private:
        T *ptr;

        public:
        friend int ::main(int argc, const char* argv[]);

        iterator();
        iterator(T * p);
        iterator(iterator *rhs);

        iterator & operator = (iterator *rhs);
        bool operator == (const iterator & rhs);
        bool operator != (const iterator & rhs);

        iterator & operator ++();
        iterator operator ++ (int postfix);
        iterator & operator -- ();
        iterator operator -- (int postfix);
        T operator * ();

    };
};

#include "set.cpp"
#endif