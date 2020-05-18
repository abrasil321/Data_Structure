#ifndef QUEUE_CPP


namespace custom
{
    template <class T>
    deque<T>::deque()
    {
        buffer = NULL;
        iFront = 0;
        iBack = -1;
        numCapacity = 0;
    }


    template <class T>
    deque<T>::deque(int numCapacity)
    {
        buffer = new T[numCapacity];
        iFront = 0;
        iBack = -1;
        this->numCapacity = numCapacity;
        if (numCapacity < 0)
        {
            throw("Error: deque sizes must be greater than or equal to 0.");
        }
    }


    template <class T>
    deque<T>::~deque()
    {
        delete [] buffer;
    }


    template <class T>
    deque<T>::deque(const deque <T> & rhs)
    {
        if(rhs.size() == 0)
        {
            buffer = NULL;
            iFront = 0;
            iBack = -1;
            numCapacity = 0;
        }
        else 
        {
            buffer = new T[rhs.size()];
            iFront = 0;
            iBack = rhs.size() - 1;
            numCapacity = rhs.size();

            int i = 0;
            int point = rhs.iFrontNormalize();
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
    int deque<T>::size() const
    {
        return iBack - iFront + 1;
    }


    template <class T>
    bool deque<T>::empty() const
    {
        return (iBack == (iFront -1));
     
    }


    template <class T>
    void deque<T>::clear()
    {
        iFront = 0;
        iBack = -1;
    }


    template <class T>
    T & deque<T>::operator [] (int index) const
    {
        if((index > numCapacity) || (index < 0) || (numCapacity == 0))
        {
            throw("Error: Can not pop an empty deque.");
        }
        else
        {
            return buffer[index];
        }
    }



    template <class T>
    deque <T> & deque<T>::operator = (const deque <T> & rhs)
    {
        clear();
        if (capacity() < rhs.size())
        {
            resize(rhs.size());
        }
        for (int i = rhs.iFront; i < rhs.iBack; i++ )
        {
            push_back(rhs.buffer[iNormalize(i)]);
        }
    }



    template <class T>
    void deque<T>::push_front(const T & t)
    {
        if (size() == capacity())
        {
            if(capacity() == 0)
            {
                resize(1);
            }
            else
            {
            resize(capacity() * 2);
            }
        }
        iFront--;
        buffer[iFrontNormalize()] = t;
    
    }


    template <class T>
    void deque<T>::push_back(const T & t)
    {
        if (size() == capacity())
        {
            resize(capacity() * 2);
        }
        iBack++;
        buffer[iBackNormalize()] = t;
    }


    template <class T>
    void deque<T>::pop_front()
    {
        if (empty())
        {
            throw("Error: Can not pop an empty deque.");
        }
        
        iFront++;
    }


    template <class T>
    void deque<T>::pop_back()
    {
        if (empty())
        {
           throw("Error: Can not pop an empty deque.");
        }
        
        iBack--;
    }


    template <class T>
    T & deque<T>::front()
    {
        if(empty())
        {
            throw("Error: deque is empty.");
        }
        else
        {
            return buffer[iFrontNormalize()];
        }
        
    }


    template <class T>
    T & deque<T>::back()
    {
        if(empty())
        {
            throw("Error: deque is empty.");
        }
        else
        {
            return buffer[iBackNormalize()];
        }
    }


    template <class T>
    void deque<T>::resize(int numCapacity)
    {
        if(numCapacity <= 0)
        {
            if(buffer)
            {
            delete [] buffer;
            buffer = NULL;
            }
            this->numCapacity = 0;
            iBack = -1;
            iFront = 0;
        }
        else if(buffer == NULL)
        {
            buffer = new T[numCapacity];
            this->numCapacity = numCapacity;
            iBack = -1;
            iFront = 0;
        }
        else
        {
            deque<T> temp(*this);
            this->numCapacity = numCapacity;
            delete [] buffer;
            buffer = new T[numCapacity];

            iBack = -1;
            iFront = 0;
           
        //    std::cerr << "\n" << temp.iFront;
        //    std::cerr << "\n" << temp.iBack;
            for(int i = 0; (i < temp.size()) && (i < numCapacity); i++)
            {
                buffer[i] = temp.buffer[i];
                iBack++;

            }
            
        }
    }


    template <class T>
    int deque<T>::capacity()
    {
        return numCapacity;
    }


    template <class T>
    int deque<T>::iFrontNormalize() const
    {
        return iNormalize(iFront);
    }


    template <class T>
    int deque<T>::iBackNormalize() const
    {
        return iNormalize(iBack);
    }


    template <class T>
    int deque<T>::iNormalize(int index) const
    { 
        if (numCapacity > 0)
        {
            index = ((index % numCapacity) + numCapacity) % numCapacity;
        }
        else
        {
            throw("Error: Uninitialized deque.");
        }

        return index;
        
    }

}
#endif