#ifndef MAP_H
#define MAP_H

#include "BST.h"

#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif
namespace custom
{
   template <class K, class V>
   class map 
   {
      public:
         #ifdef UNIT_TESTING
            friend int ::main(int argc, const char* argv[]);
         #endif
         class iterator;
         class pair;
         map();
         map(const map <K, V>& map);
         ~map();
         map<K,V>& operator = (const map<K,V>& rhs);
         V& operator [] (const K& k);
         int size() const;
         bool empty() const;
         void clear();
         void insert(const K& k, const V& v);
         V access(K k);
         iterator find(const K& k);
         iterator begin();
         iterator end();
      private:
         BST<pair> bst;
   };
   template <class K, class V>
   class map<K,V>::pair
   {
      public:
         K first;
         V second;
         pair();
         pair(const K& k, const V& v);
         pair& operator = (const pair& rhs);
         bool operator == (const pair& rhs) const;
         bool operator != (const pair& rhs) const;
         bool operator >= (const pair& rhs) const;
         bool operator >  (const pair& rhs) const;
         bool operator <= (const pair& rhs) const;
         bool operator <  (const pair& rhs) const;
         
   };
   template <class K, class V>
   class map<K,V>::iterator
   {
      public:
         iterator();
         iterator(const typename BST<pair>::iterator& rhs);
         iterator(const iterator& rhs);
         iterator & operator = (const iterator& rhs);
         bool  operator == (const iterator& rhs) const;
         bool  operator != (const iterator& rhs) const;
         pair& operator * ();
         //THESE DONT SEEM TO WORK IF THEY ARE BY REFRANCE
         iterator operator ++ (); //&
         iterator operator ++ (int postfix);
         iterator operator -- (); //&
         iterator operator -- (int postfix);
         //IS THIS NOT PRIVATE??? <-N8 please
         typename BST<pair>:: iterator it;

   };

}
#include "map.cpp"
#endif 
