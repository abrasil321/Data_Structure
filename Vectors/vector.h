//
//
//


#ifndef VECTOR_H
#define VECTOR_H


#ifdef UNIT_TESTING // unit testing macro
int main(int argc, const char* argv[]);
#endif

namespace custom
{
    template <class T>
    class vector
    {

        private:
            T *buffer;
            int numElements;
            int numCapacity;
            void resize(int numCapacity);

        public:
            class iterator;

            friend int ::main(int argc, const char* argv[]);
            vector();
            vector(int numElements);
            vector(int numElements, T t);
            vector(vector <T> &rhs);
            ~vector();


            vector assign(vector <T> &rhs);


            int size() const;
            int capacity() const;
            bool empty();
            void clear();

            T & operator [] (int index) const;

            //FIXME: shouldnt this be void?
            vector <T> & operator = (const vector <T> & rhs);

            void push_back(const T & t);

            iterator begin();
            iterator end();
    };    

    template <class T>
    class vector<T> :: iterator 
    {
        private:
            T *ptr;

        public:
            friend int ::main(int argc, const char* argv[]);
            iterator();
            iterator(T * p);
            iterator(iterator *rhs);
            


            iterator & operator = ( iterator *rhs);
            bool operator == ( iterator &rhs);
            bool operator != ( iterator &rhs);

            iterator & operator ++ ();
            iterator operator ++ (int postfix);
            iterator & operator -- ();
            iterator operator -- (int postfix);
            T operator * ();
            
    };
}



#include "vector.cpp"
#endif