#ifndef QUEUE_H
#define QUEUE_H

#ifdef UNIT_TESTING // this is the unit testing macro
int main(int argc, const char* argv[]);
#endif

namespace custom
{
    template <class T>
    class queue
    {
        private:
        T *buffer;
        int numPush;
        int numPop;
        int numCapacity;

        public:
        friend int ::main(int argc, const char* argv[]);

        queue();
        queue(int numCapacity);
        queue(queue <T> &rhs);
        ~queue();

        T & operator [] (int index) const;
        queue <T> & operator = (const queue<T> & rhs);

        int capacity() const;
        int size() const;
        bool empty() const;
        void clear();
        void push(const T & t);
        void pop();
        T& front();
        T& back();


        void resize(int numCapacity);
        int iHead() const;
        int iTail() const;
    };
}


#include "queue.cpp"
#endif