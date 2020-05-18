#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>
#ifdef UNIT_TESTING // this is the unit testing macro
int main(int argc, const char* argv[]);
#endif

namespace custom
{
    template <class T>
    class deque
    {
        private:
        T *buffer;
        int iFront;
        int iBack;
        int numCapacity;

        public:
        friend int ::main(int argc, const char* argv[]);

        deque();
        deque(int numCapacity);
        deque(const deque <T> & rhs);
        ~deque();

        T & operator [] (int index) const;
        deque <T> & operator = (const deque <T> & rhs);
        // deque <T> & assign(deque <T> & rhs); 

        int size() const;
        bool empty() const;
        void clear();
        void push_front(const T & t);
        void push_back(const T & t);
        void pop_front();
        void pop_back();
        T & front();
        T & back();

        private:
        void resize(int numCapacity);
        int capacity();
        int iFrontNormalize()const;
        int iBackNormalize() const;
        int iNormalize(int index) const;
        


    };
}

#include "deque.cpp"
#endif