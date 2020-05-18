#ifndef HASH_H
#define HASH_H
#include "list.h"


#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif

namespace custom {

   template <class T>
   class Hash 
   {
      public:
      #ifdef UNIT_TESTING
         friend int ::main(int argc, const char* argv[]);
      #endif
      Hash();
      Hash(int numBuckets);
      Hash(Hash<T>& rhs);
      ~Hash();

      Hash<T>& operator = (const Hash<T>& rhs);
      int size();
      bool empty();
      int capacity();
      bool find(T aValue,  long (*h)(const T& aValue, long theBucketCount));
      void insert(T aValue, long (*h)(const T& aValue, long theBucketCount));
      void erase(T t);

      private:
      list<T> ** table;
      int numElements;
      int numBuckets;

   };
}

#include "hash.cpp"
#endif