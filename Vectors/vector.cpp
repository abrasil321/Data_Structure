
namespace custom{

template <class T>
vector<T>::vector()
{
    numElements = 0;
    numCapacity = 0;
    buffer = NULL;
}

template <class T>
vector<T>::vector(int numElements)
{
    if(numElements > 0){
        buffer = new T[numElements];
        this -> numElements = numElements;
        this -> numCapacity = numElements;
        if(numElements != 0){
            for(int i = 0; i < numElements; i++)
            {
                buffer[i] = T();
            }
        }
    }
    else{
        throw("Error: vector sizes must be greater than 0.");
    }
}

template <class T>
vector<T>::vector(int numElements, T t)
{
    if(numElements > 0){
        buffer = new T[numElements];
        this -> numElements = numElements;
        this -> numCapacity = numElements;
        if(numElements != 0){
            for(int i = 0; i < numElements; i++)
            {
                buffer[i] = t;
            }
        }
    }else
    {
        throw("Error: vector sizes must be greater than 0.");
    }
}

template <class T>
vector<T>::vector(vector<T> &rhs)
{
    buffer = rhs.buffer;
    this->numElements = rhs.numElements;

    resize(rhs.size());
    for(int i = 0; i < size(); i++)
    {
        buffer[i] = rhs[i];
    }
    
    numElements = rhs.size();

}

template <class T>
vector<T>::~vector()
{
delete [] buffer;
}

template <class T>
int vector<T>::size() const
{
    return numElements;
}

template <class T>
int vector<T>::capacity() const
{
     return numCapacity;
}

template <class T>
bool vector<T>::empty()
{
    return !numElements;
}

template <class T>
void vector<T>::clear()
{
    numElements = 0;
}

template <class T>
T& vector<T>::operator[] (int index) const
{
    //FIXME: needs second look
    if((index > numElements) || (index < 0) || (numCapacity == 0))
    {
        throw("Error: indices must be greater than zero and less than size().");
    }else{
        return buffer[index];
    }
}


template <class T>
vector<T>& vector<T>::operator = (const vector<T> & rhs)
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
void vector<T>::resize(int numCapacity)
{
    if( (this->numCapacity == 0) && numCapacity >0)
    {
        buffer = new T[numCapacity];
        this->numCapacity = numCapacity;
    }
    else if(numCapacity > 0){
        T temp[this->numElements];
        for(int i = 0; i < this->numElements; i++)
        {
            temp[i] = buffer[i];
        }
        if (buffer != NULL)
          delete [] buffer;
        
        buffer = new T[numCapacity];

        int i = 0;
        while((i < this->numElements) && (i<numCapacity))
        {
            buffer[i] = temp[i];
            i++;
        }

        this -> numCapacity = numCapacity;
        this -> numElements = i;
    }else{
        this -> numCapacity = 0;
        this -> numElements = 0;
        if(buffer)
            {
                delete [] buffer;
            }
        buffer = NULL;
    }


}

template <class T>
void vector<T>::push_back(const T & t)
{
    if(numElements < numCapacity)
    {
        buffer[numElements] = t;
        numElements++;
    }else if(numCapacity != 0){
        resize(numCapacity*2);
        buffer[numElements] = t;
        numElements++;
    }else{
        resize(1);
        buffer[0] = t;
        numElements = 1;
    }
}

template <class T>
typename vector<T>::iterator vector<T>::begin()
{
    if(buffer == NULL)
    {
        iterator tempIterator;
        return tempIterator;
    }else{
        iterator tempIterator(buffer);
        return tempIterator;
    }

}

template <class T>
typename vector<T>::iterator vector<T>::end()
{
    if(buffer == NULL)
    {
        iterator tempIterator;
        return tempIterator;
    }else{
        iterator tempIterator(&buffer[numElements]);
        return tempIterator;
    }
}


template <class T>
vector<T>::iterator::iterator()
{
    ptr = NULL;
}

template <class T>
vector<T>::iterator::iterator(T * p)
{
    ptr = p;
}

template <class T>
vector<T>::iterator::iterator(iterator *rhs)
{
    ptr = rhs;
}

template <class T>
typename vector<T>::iterator& vector<T>::iterator::operator = ( iterator *rhs)
{
    ptr = rhs;
}

template <class T>
bool vector<T>::iterator::operator == ( iterator &rhs)
{
    return ptr == rhs.ptr;
}

template <class T>
bool vector<T>::iterator::operator != ( iterator &rhs)
{
    //FIXME: this needs a second look
    return ptr != rhs.ptr;
}

template <class T>
typename vector<T>::iterator& vector<T>::iterator::operator ++ ()
{
    if(ptr != NULL)
    {
    ++ptr;
    }
    return *this;
}

template <class T>
typename vector<T>::iterator vector<T>::iterator::operator ++ (int postfix)
{
    iterator temp;
    if(ptr != NULL)
    {
    temp = ptr++;
    }
    return temp;
}

template <class T>
typename vector<T>::iterator& vector<T>::iterator::operator -- ()
{
    if(ptr != NULL)
    {
    ptr--;
    }
    return *this;
}

template <class T>
typename vector<T>::iterator vector<T>::iterator::operator -- (int postfix)
{
    iterator temp;
    if(ptr != NULL)
    {
    temp = ptr--;
    }
    return temp;
}

template <class T>
T vector<T>::iterator::operator * ()
{
    return *ptr;
}
}