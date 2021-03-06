#include "map.h"
#include "bst.h"
#include <iostream>

namespace custom
{
   template <class K, class V>
   map<K, V>::map() {
      BST<pair> bst;
      
   }

   template <class K, class V>
   map<K, V>::map(const map<K,V>&  rhs)
   {
      bst = rhs.bst;

   }

   template <class K, class V>
   map<K, V>::~map()
   {
      
   }   

   template <class K, class V>
   map<K, V>& map<K, V>::operator= (const map<K,V>& rhs)
   {
      bst = rhs.bst;
      return *this;

   }

   template <class K, class V>
   V& map<K,V>::operator[] (const K& k)
   {
      pair item(k, V());
      typename BST<map<K, V>::pair> :: iterator it = bst.find(item);
      if(it == NULL)
      {
         bst.insert(item);
         it = bst.find(item);
      }
      return (*it).second;
   }

   template <class K, class V>
   int map<K, V>::size() const 
   {
    return bst.size();

   }

   template <class K, class V>
   bool map<K, V>::empty() const
   {
      return bst.empty();

   }

   template <class K, class V>
   void map<K, V>::clear()
   {
      bst.clear();
   }

      template <class K, class V>
   void map<K, V>::insert(const K& k, const V& v)
   {
      pair item (k, v);
      iterator it = bst.find(item);
      if(it == NULL) 
      {
         bst.insert(item);
      }
   }


   template <class K, class V>
   V map<K, V>::access(K k)
   {
   // JACK
   }

   template <class K, class V>
   typename map<K,V>::iterator map<K, V>::find(const K& k)
   {
      pair item (k, V());
      iterator it = bst.find(item);
      return iterator(it);
   }

   template <class K, class V>
   typename map<K,V>::iterator map<K, V>::begin()
   {
      iterator it = bst.begin();
      return it;
   }

   template <class K, class V>
   typename map<K,V>::iterator map<K, V>::end()
   {
      iterator it = bst.end();
      return it;
   }


   // --------------------------------------PAIR CLASS----------------------------------------
   // N8
   template <class K, class V>
   map<K, V>::pair::pair()
   {
      first = NULL;
      second = NULL;
   }

   template <class K, class V>
   map<K, V>::pair::pair(const K& k, const V& v)
   {
    first = k;
    second = v;
   }

   template <class K, class V>
   typename map<K, V>::pair& map<K, V>::pair::operator = (const pair& rhs)
   {
      first = rhs.first;
      second = rhs.second;
      return *this;
   }

   template <class K, class V>
   bool map<K, V>::pair::operator == (const pair& rhs) const
   {
      return first == rhs.first;
   }

   template <class K, class V>
   bool map<K, V>::pair::operator != (const pair& rhs) const
   {
      return first == rhs.first;
   }

   template <class K, class V>
   bool map<K, V>::pair::operator >= (const pair& rhs) const
   {
      return first >= rhs.first;
   }

   template <class K, class V>
   bool map<K, V>::pair::operator > (const pair& rhs) const
   {
      return first > rhs.first;
   }

   template <class K, class V>
   bool map<K, V>::pair::operator <= (const pair& rhs) const
   {
      return first <= rhs.first;
   }

   template <class K, class V>
   bool map<K, V>::pair::operator < (const pair& rhs) const
   {
      return first < rhs.first;
   }

// --------------------------------------IT CLASS ---------------------------
   template <class K, class V>
   map<K, V>::iterator::iterator()
   {

   }

   template <class K, class V>
   map<K, V>::iterator::iterator(const typename BST<pair>::iterator& rhs)
   {
      it = rhs;
   }

   template <class K, class V>
   map<K, V>::iterator::iterator(const iterator& rhs)
   {
// JACK
      it = rhs.it;
   }

   template <class K, class V>
   typename map<K, V>::iterator& map<K, V>::iterator::operator = (const iterator& rhs)
   {
// JACK
      it = rhs.it;
      return *this;
   }

   template <class K, class V>
   bool map<K, V>::iterator::operator == (const iterator& rhs) const
   {
      return it == rhs.it;    
   }

   template <class K, class V>
   bool map<K, V>::iterator::operator != (const iterator& rhs) const
   {
      return it != rhs.it;    
   }

   template <class K, class V>
   typename map<K, V>::pair& map<K,V>::iterator::operator * ()
   {
// JACK
      if(it == NULL)
         throw "Error: Dereferencing null node.";
	   return *it;

   }

   template <class K, class V>
   typename map<K,V>::iterator map<K,V>::iterator::operator ++ ()
   {
// JACK
      if(it == NULL)
      {
        throw "Error: Incrementing null node.";
      }
      ++it;
    return *this;
   }

   template <class K, class V>
   typename map<K,V>::iterator map<K,V>::iterator::operator ++ (int postfix)
   {
      if(it == NULL)
        throw "Error: Incrementing null node.";
      return iterator(it++);
   }

   template <class K, class V>
   typename map<K,V>::iterator map<K,V>::iterator::operator -- ()
   {
      if(it == NULL)
        throw "Error: Decrementing null node.";
      --it;
      return *this;
   }

   template <class K, class V>
   typename map<K,V>::iterator map<K,V>::iterator::operator -- (int postfix)
   {
      if(it == NULL)
        throw "Error: Decrementing null node.";
      return iterator(it--);
   }



}