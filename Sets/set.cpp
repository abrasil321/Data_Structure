#ifndef SET_CPP

namespace custom
{
    template <class T>
    set<T>::set()
    {
        numElements = 0;
        numCapacity = 0;
        buffer = NULL;
    }

    template <class T>
    set<T>::set(int numCapacity)
    {
        buffer = new T[numElements];
        this->numCapacity = numCapacity;
    }

    template <class T>
    set<T>::~set()
    {
        delete [] buffer;
    }


    template <class T>
    set<T>::set(const set<T> & rhs)
    {
        if(rhs.size() <= 0)
        {
            buffer = NULL;
            numCapacity = 0;
            numElements = 0;
        }
        else
        {
            buffer = new T[rhs.size()];
            numCapacity = rhs.size();
            numElements = rhs.size();
            for(int i = 0; i < rhs.size(); i++)
            {
                buffer[i] = rhs.buffer[i];
            }
        }
    }

    template <class T>
    set<T>& set<T>::operator = (const set<T> & rhs)
    {
        if(rhs.size() <= 0)
        {
            buffer = NULL;
            numCapacity = 0;
            numElements = 0; 
        }   
        else
        {
            buffer = new T[rhs.size()];
            numCapacity = rhs.size();
            numElements = rhs.size();
            for(int i = 0; i < rhs.size(); i++)
            {
                buffer[i] = rhs.buffer[i];
            }
        }

    }

    template <class T>
    T & set<T>::operator [] (int index) const
    {
        if((index > size()) || (index < 0) || (numCapacity == 0))
        {
            throw("Error: indices must be greater than zero and less than size().");
        }
        else
        {
            return buffer[index];
        }
    }

    template <class T>
    int set<T>::size() const
    {
        return numElements;
    }

    template <class T>
    bool set<T>::empty() const
    {
        return !numElements;
    }

    template <class T>
    void set<T>::clear()
    {
        numElements = 0;
    }

    template <class T>
    typename set<T>::iterator set<T>::find(const T & t)
    {
        iterator pos;
        int begin = 0;
        int end = (numElements -1);
        int mid = begin + (end) / 2; 
        //binary search through array
        while (buffer[mid] != t)
        {
            if (buffer[mid] == t)
            {
                    //found item
                pos = (buffer + mid);
                return pos;
            } 
            else if (buffer[mid] < t)
            {
                end = mid;

                //item is in the first half
            } 
            else
            {
                begin = mid;
            //item is in the second half
            }
            //check to make sure the array hasn't reached it's bounds
            if (mid == 0 || mid == numElements-1 || begin == end) 
            {
                //CHECK AND MAKE SURE THIS WORKS
                pos = (buffer + mid);
                return pos;
            }

            mid = begin + (end) / 2;
        }
        //this should be the only return, but im afraid that it will break the function.
        pos = (buffer + mid);
        return pos;
    }

    template <class T>
    void set<T>::insert(const T & t)
    {
        int iInsert = findIndex(t);
        if(buffer[iInsert] != t)
        {
            for(int i = numElements; i < iInsert; i--)
            {
                buffer[i+1] = buffer[i];
            }
            buffer[iInsert] = t;
            numElements++;
        }
    }

    template <class T>
    typename set<T>::iterator set<T>::erase(iterator & it)
    {
        find(it);
        if (buffer[find(it)] == it)
        {
            for(int i = find(it); i < numElements; i++)
            {
                buffer[i] = buffer[i + 1];
            }
            numElements--;
        }
    }

    template <class T>
    set<T> set<T>::operator || (const set<T> & rhs)
    {
        set temp(*this);
        for(int i = 0; i < rhs.size();i++)
        {
            temp.insert(rhs.buffer[i]);
        }
        return temp;
    }

    template <class T>
    set<T> set<T>::operator && (const set<T> & rhs)
    {
        set temp;
        for(int i = 0; i++; i++)
        {
            if(rhs.find(buffer[i]) != NULL)
            {
                temp.insert(buffer[i]);
            }
        }
        return temp;
    }

    template <class T>
    set<T> set<T>::operator - (const set<T> & rhs)
    {
        
        set temp(*this);
        for(int i = 0; i < rhs.size();i++)
        {
            temp.insert(rhs.buffer[i]);
        }
        return temp;
    }

    template <class T>
    typename set<T>::iterator set<T>::begin()
    {
        if(buffer == NULL)
        {
            iterator tempIterator;
            return tempIterator;
        }
        else
        {
            iterator tempIterator(buffer);
            return tempIterator;
        }
    }

    template <class T>
    typename set<T>::iterator set<T>::end()
    {
        if(buffer == NULL)
        {
            iterator tempIterator;
            return tempIterator;
        }
        else
        {
            iterator tempIterator(&buffer[numElements]);
            return tempIterator;
        }
    }

    template <class T>
    int set<T>::findIndex(const T & t)
    {
        int iBegin = 0;
        int iEnd = numElements - 1;

        while(iBegin <= iEnd)
        {
            int iMiddle = ((iBegin + iEnd) / 2);
            if(t == buffer[iMiddle])
            {
                return iMiddle;
            }
            else if (t < buffer[iMiddle])
            {
                iEnd = iMiddle - 1;
            }
            else
            {
                iBegin = iMiddle + 1;
            }
        }
        return numElements;
    }

    template <class T>
    void set<T>::resize(int numCapacity)
    {
        if( (this->numCapacity == 0) && numCapacity > 0)
        {
            buffer = new T[numCapacity];
            this -> numCapacity = numCapacity;
        } // resize the array according to the new capacity
        else if((numCapacity > 0) && (numCapacity >= this->numElements))
        {
            T temp[numCapacity];
            //the array should already be sorted...
            for(int i = 0; (i < this->numElements) && (i < numCapacity); i++)
            {
                temp[i] = buffer[i];
            }

            //delete array to buffer and point temp to buffer
            delete [] buffer;
            buffer = temp;
        
            this -> numCapacity = numCapacity;
            this -> numElements = numElements;
        } // They gave us a negative or non-int value
        else
        {
            this -> numCapacity = 0;
            this -> numElements = 0;
            delete buffer;
            buffer = NULL;
        }
        return;
    }

    template <class T>
    set<T>::iterator::iterator()
    {
        ptr = NULL;
    }



    template <class T>
    set<T>::iterator::iterator(T * p)
    {
        ptr = p;
    }



    template <class T>
    set<T>::iterator::iterator(iterator *rhs)
    {
        ptr = rhs;
    }



    template <class T>
    typename set<T>::iterator & set<T>::iterator::operator = (iterator *rhs)
    {
        ptr = rhs;
    }


    template <class T>
    bool set<T>::iterator::operator == (const iterator &rhs)
    {
        return ptr == rhs.ptr;
    }



    template <class T>
    bool set<T>::iterator::operator != (const iterator &rhs)
    {
        return ptr != rhs.ptr;
    }


    template <class T>
    typename set<T>::iterator& set<T>::iterator::operator ++ ()
    {
        if(ptr != NULL)
        {
            ++ptr;
        }
        return *this;
    }



    template <class T>
    typename set<T>::iterator set<T>::iterator::operator ++ (int postfix)
    {
        iterator temp;
        if(ptr != NULL)
        {
            temp = ptr++;
        }
        return temp;
    }



    template <class T>
    typename set<T>::iterator& set<T>::iterator::operator -- ()
    {
        if(ptr != NULL)
        {
            ptr--;
        }
        return *this;
    }



    template <class T>
    typename set<T>::iterator set<T>::iterator::operator -- (int postfix)
    {
        iterator temp;
        if(ptr != NULL)
        {
            temp = ptr--;
        }
        return temp;
    }

    template <class T>
    T set<T>::iterator::operator * ()
    {
        return *ptr;
    }
}

#endif