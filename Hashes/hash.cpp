#include "hash.h"
#include "list.h"
#include <iostream>

namespace custom {
   template <class T>
   Hash<T>::Hash()
   {
      numBuckets = 0;
      numElements = 0;
      table = NULL;
   }

   template <class T>
   Hash<T>::Hash(int numBuckets)
   {
      if(numBuckets <= 0) 
      {
         throw "Error: Hashes must have at least 1 bucket.";
      }
      this->numBuckets = numBuckets;
      this->numElements = 0;
      table = new list<T>*[numBuckets];
      for(int i = 0; i < numBuckets; i++)
      {
         table[i] = new list<T>;
      }
   }

   template <class T>
   Hash<T>::Hash(Hash<T>& rhs)
   {
      numBuckets = rhs.numBuckets;
      numElements = rhs.numElements;
      table = rhs.table;
   }

   template <class T>
   Hash<T>::~Hash()
   {
      for(int i = 0; i <numBuckets; i++)
      {
         delete table[i];
         table[i] = NULL;
      }
      delete[] table;
   }

   template <class T>
   Hash<T>& Hash<T> :: operator= (const Hash<T>& rhs)
   {
      numBuckets = rhs.numBuckets;
      numElements = rhs.numElements;
      table = rhs.table;

      return *this;
   }

   template <class T>
   int Hash<T>::size()
   {
      return numElements;
   }

   template <class T>
   bool Hash<T>::empty()
   {
      return !numElements;
   }

   template <class T>
   int Hash<T>::capacity()
   {
      return numBuckets;
   }

   template <class T>
   bool Hash <T> :: find(T aValue, long (*h)(const T& aValue, long theBucketcount)) 
   {
      long bucket = (*h)(aValue, numBuckets);
      typename list<T> :: iterator found = table[bucket]->find(aValue);
      return (found !=NULL);
   }

   template <class T>
   void Hash <T> :: insert(T aValue, long (*h)(const T& aValue, long bucketCount))
   {
      long bucket = (*h)(aValue, numBuckets);
      table[bucket]->push_back(aValue);
      numElements++;
   }

   template <class T>
   void Hash<T>::erase(T t)
   {

   }

}