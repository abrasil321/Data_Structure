
namespace custom
{
    template <class T>
    stack<T>::stack()
    {
        numElements = 0;
        numCapacity = 0;
        buffer = NULL;
    }


 
    template <class T>
    stack<T>::stack(int numCapacity)
    {
        if(numCapacity > 0)
        {
            buffer = new T[numCapacity];
            this->numCapacity = numCapacity;
            this->numElements = numCapacity;
            if(numCapacity != 0){
                for(int i = 0; i < numElements; i++)
                {
                    buffer[i] = T();
                }
            }
        }
        else 
        {
            throw("Error: asking for top of empty stack.");
        }
    }



    template <class T>
    stack<T>::stack(stack <T> & rhs)
    {
        this->buffer = rhs.buffer;
        this->numCapacity = rhs.numCapacity;

        resize(rhs.size());
        for(int i = 0; i < rhs.size(); i++)
        {
        buffer[i] = rhs.buffer[i];
        }

        numElements = rhs.size();
    }



    template <class T>
    stack<T>::~stack()
    {
        delete [] buffer;
    }


    
    template <class T>
    stack<T>& stack<T>::operator = (stack<T> & rhs)
    {
        if (numCapacity != rhs.capacity())
        {
            resize(rhs.size());
        }

        numElements = rhs.size();
        for(int i = 0; i < rhs.size(); i++)
        {
            buffer[i] = rhs.buffer[i];
        }

        return *this;
    }
        


    template <class T>
    T & stack<T>::operator [] (int index) const
    {
        if((index > numElements) || (index < 0) || (numCapacity == 0))
        {
            throw("Error: indices must be greater than zero and less than size().");

        }
        else
        {
            return buffer[index];
        }
    }



    template <class T>
    int stack<T>::size() const
    {
        return numElements;
    }



    template <class T>
    int stack<T>::capacity() const
    {
        return numCapacity;
    }



    template <class T>
    bool stack<T>::empty() const
    {
        return !numElements;
  
    }



    template <class T>
    void stack<T>::clear()
    {
        numElements = 0;
    }



    template <class T>
    void stack<T>::push(const T & t)
    {
        if (capacity() == 0)
        {
            resize(1);
        }
        else if (size() == capacity())
        {
            resize(capacity() * 2);
        }
    
        buffer[numElements++] = t;
    }



    template <class T>
    void stack<T>::pop()
    {
        if (!empty())
        {
            --numElements;
        }
    }



    template <class T>
    T& stack<T>::top()
    {
        if (!empty())
        {
            return buffer[size() - 1];
        }
        else
        {
            throw( "Error: asking for top of empty stack.");
        }
    
    }


  
    template <class T>
    void stack<T>::resize(int numCapacity)
    {   
        if( (this->numCapacity == 0) && numCapacity >0)
        {
            buffer = new T[numCapacity];
            this->numCapacity = numCapacity;
        }
        else if(numCapacity > 0)
        {
            T *temp = new T[numCapacity];
            for(int i = 0; i < numCapacity; i++)
            {
                temp[i] = buffer[i];
            }
            if(buffer)
            {
            delete [] buffer;
            }
            buffer = temp;

            this -> numCapacity = numCapacity;
            this -> numElements = numElements > numCapacity 
                                    ? numCapacity : numElements;
        }
        else
        {
            this -> numCapacity = 0;
            this -> numElements = 0;
            if(buffer)
            {
                delete [] buffer;
            }
            buffer = NULL;
        }

    }
}
