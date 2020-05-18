#ifndef QUEUE_CPP


namespace custom
{
    template <class T>
    queue<T>::queue()
    {
        buffer = NULL;
        numPush = 0;
        numPop = 0;
        numCapacity = 0;
    }



    template <class T>
    queue<T>::queue(int numCapacity)
    {
        buffer = new T[numCapacity];
        numPush = 0;
        numPop = 0;
        this->numCapacity = numCapacity;

    }



    template <class T>
    queue<T>::queue(queue <T> &rhs)
    {
        if(rhs.size() == 0)
        {
            buffer = NULL;
            numPush = 0;
            numPop = 0;
            numCapacity = 0;
        } 
        else {
            buffer = new T[rhs.size()];
            numPop = 0;
            numPush = rhs.size();
            numCapacity = rhs.size();

            int i = 0;
            int point = rhs.iHead();
            while(i != rhs.size())
            {

                this -> buffer[i] = rhs.buffer[point];


                if(point == (rhs.numCapacity - 1))
                {

                    point = 0;
                }
                else{
                    point++;
                }
                i++;
            }
        }
    }



    template <class T>
    queue<T>::~queue()
    {
        delete [] buffer;
    }



    template <class T>
    T & queue<T>::operator [] (int index) const
    {
        if((index > numCapacity) || (index < 0) || (numCapacity == 0))
        {
            throw("Error: asking for front of empty queue.");
        }
        else
        {
            return buffer[index];
        }
    }


    
    template <class T>
    queue <T> & queue<T>::operator = (const queue<T> & rhs)
    {
        delete [] buffer;
            if(rhs.size() == 0){
                buffer = NULL;
                numPush = 0;
                numPop = 0;
                numCapacity = 0;
            } else {
                buffer = new T[rhs.size()];
                numPop = 0;
                numPush = rhs.size();
                numCapacity = rhs.size();

                int i = 0;
                int point = rhs.iHead();
                while(i != rhs.size())
                {

                    this -> buffer[i] = rhs.buffer[point];


                    if(point == (rhs.numCapacity - 1))
                    {

                        point = 0;
                    }else{
                        point++;
                    }
                    i++;
                }
            }
        return *this; 
    }


    template <class T>
    int queue<T>::capacity() const
    {
        return numCapacity;
    }



    template <class T>
    int queue<T>::size() const
    {
        return numPush - numPop;
    }

    template <class T>
    bool queue<T>::empty() const
    {
        return (numPush == numPop);
    }



    template <class T>
    void queue<T>::clear()
    {
        
        numPop = 0;
        numPush = 0;

    }



    template <class T>
    void queue<T>::push(const T & t)
    {
        if(size() == 0)
        {
            resize(1);
        }
        else if(size() == capacity())
        {
            resize(capacity() * 2);
        }
        numPush++;

        buffer[iTail()] = t;
    }



    template <class T>
    void queue<T>::pop()
    {
        if(!empty())
        {
            numPop++;
        }
    }



    template <class T>
    T& queue<T>::front()
    {
        if(empty())
        {
            throw("Error: asking for front of empty queue.");
        }
        else
        {
            return buffer[iHead()];
        }
    }



    template <class T>
    T& queue<T>::back()
    {
        if(empty())
        {
            throw("Error: asking for back of empty queue.");
        }
        else
        {
            return buffer[iTail()];
        }
    }



    template <class T>
    void queue<T>::resize(int numCapacity)
    {
        if(numCapacity <= 0)
        {
            delete [] buffer;
            buffer = NULL;
            this->numCapacity = 0;
            numPop = 0;
            numPush = 0;
        }
        else if(buffer == NULL)
        {
            buffer = new T[numCapacity];
            this->numCapacity = numCapacity;
            numPop = 0;
            numPush = 0;
        }
        else
        {
            queue<T> temp(*this);
            this->numCapacity = numCapacity;
            delete [] buffer;
            buffer = new T[numCapacity];

            numPush = 0;
            numPop = 0;
            for(int i = 0; (i < temp.size()) && (i < numCapacity); i++)
            {
                buffer[i] = temp.buffer[i];
                numPush++;
            }
        }
    }


    template <class T>
    int queue<T>::iHead() const
    {
        return numPop % numCapacity;
    }

    template <class T>
    int queue<T>::iTail() const
    {
        return ((numPush-1) % numCapacity);
    }

}
#endif
