//stack.h 
#ifndef STACK_H
#define STACK_H

#ifdef UNIT_TESTING // this is the unit testing macro
int main(int argc, const char* argv[]);
#endif

namespace custom
{
    template <class T>
    class stack
    {
        private:
        T *buffer;
        int numElements;
        int numCapacity;



        public:
        friend int ::main(int argc, const char* argv[]);

        stack();
        stack(int numCapacity);
        stack(stack <T> & rhs);
        ~stack();

        stack <T> & operator = (stack<T> & rhs);
        T & operator [] (int index) const;

        int size() const;
        int capacity() const;
        bool empty() const;
        void clear();
        void push(const T & t);
        void pop();
        T& top();
       
        

        private:
        void resize(int numCapacity);
    };


};

#include "stack.cpp"
#endif
