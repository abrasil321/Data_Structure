#include <iostream>
namespace custom
{
   template <class T>
   BST<T>::BST() 
   {
      numElements = 0;
      root = NULL;
      
   }

   template <class T>
   BST<T>::BST(BST &rhs) 
   {
      numElements = rhs.numElements;
      root = rhs.root;
   }

   template <class T>
   BST<T>::~BST()
   {
      //FREE MEMORY
      //TODO
   }

   template <class T>
   BST<T>& BST<T>::operator=(BST<T> &rhs)
   {
      //copy root of rhs to lefthand side
      this->root = rhs->root;
      this->numElements = rhs->numElements;
      return *this;
   }

   template <class T>
   int BST<T>::size()
   {
      return numElements;
   }

   template <class T>
   bool BST<T>::empty()
   {
      return numElements == 0;
   }

   template <class T>
   void BST<T>::clear()
   {
      //REMOVE EVERYTHING FROM TREE
      //TODO
   }

   template <class T>
   void BST<T>::insert(T t)
   {
         std::cerr << "Call insert";

      //There isn't a node
      if (numElements == 0)
      {
         BNode * newNode = new BNode(t);
         root = newNode;
         numElements = 1;
         std::cerr << "new node";

         return;
      }

      //TODO add new node
      //if t is bigger than root, add node to left side
      // I have the right Idea here but it is implemented incorrectly
      BNode* temproot = root;
      bool found = false;
      while(!found)
      {
         if (t > temproot->data)
         {
            if(temproot->pRight == NULL)
            {
               BNode * newNode = new BNode(t);
               temproot->pRight = newNode;
               numElements++;
               return;
            }
            temproot = temproot->pRight;
         }
         if (t < temproot->data)
         {
            if(temproot->pLeft == NULL)
            {
               BNode * newNode = new BNode(t);
               temproot->pLeft = newNode;
               numElements++;
               return;
            }
            temproot = temproot->pLeft;
         }
         if (t == temproot->data)
         {
            return;
         }
      }
      return;
  }

   template <class T>
   void BST<T>::erase(BST<T>::iterator & it)
   {
      BNode * temp = it.ptr;
      // # case 1 has no children
      // # - no reconecting of child nodes, possible that there is a parent node
      if((temp->pLeft == NULL) && (temp->pRight == NULL))
      {
         //am I left child?
         if (temp->pParent != NULL && temp->pParent->pLeft == temp)
         {
            temp->pParent->pLeft = NULL;
         }

         //am I right child?
         if (temp->pParent != NULL && temp->pParent->pRight == temp)
         {
            temp->pParent->pRight = NULL;
         }
         //Free memory
         if (temp->pParent !=NULL)
         {
            numElements--;
         }
         delete temp;
         return;

      }
      // # case 2 had left only
      // #  - connect left child to currect location
      if((temp->pLeft != NULL) && (temp->pRight == NULL))
      {
         //am I left child?
         if (temp->pParent != NULL && temp->pParent->pLeft == temp)
         {
            temp->pParent->pLeft = temp->pLeft;
         }

         //am I right child?
         if (temp->pParent != NULL && temp->pParent->pRight == temp)
         {
            temp->pParent->pRight = temp->pLeft;
         }
         //Free memory
         numElements--;
         delete temp;
         return;

      }
      // # case 4 has right child only
      if((temp->pLeft == NULL) && (temp->pRight != NULL))
      {
         //am I left child?
         if (temp->pParent != NULL && temp->pParent->pLeft == temp)
         {
            temp->pParent->pLeft = temp->pRight;
         }

         //am I right child?
         if (temp->pParent != NULL && temp->pParent->pRight == temp)
         {
            temp->pParent->pRight = temp->pRight;
         }
         //Free memory
         numElements--;
         delete temp;
         return;

      }
      // # has both left and right
      if((temp->pLeft != NULL) && (temp->pRight != NULL))
      {
         //connect the left node with the left child of the right child
         //TODO DO
         std::cerr << "REMOVING NODES WITH 2 CHILDREN ISNT BUILT YET.";
         numElements--;
         delete temp;
         return;
      }
   }

   template <class T>
   typename BST<T>::iterator BST<T>::find(T t)
   {

   }

   template <class T>
   typename BST<T>::iterator BST<T>::begin()
   {

   }

   template <class T>
   typename BST<T>::iterator BST<T>::end()
   {

   }

   template <class T>
   void BST<T>::moveNode()
   {

   }
   //---------------------------------nodes------------------------------------------

   template <class T>
   BST<T>::BNode::BNode()
   {
      pParent = NULL;
      pLeft = NULL;
      pRight = NULL;
   }

   template <class T>
   BST<T>::BNode::BNode(T t)
   {
      data = t;
      pParent = NULL;
      pLeft = NULL;
      pRight = NULL;

   }

   template <class T>
   BST<T>::BNode::~BNode()
   {

   }

   //---------------------------------iterator---------------------------------------
   template <class T>
   BST<T>::iterator::iterator()
   {
      ptr = NULL;
   }

   template <class T>
   BST<T>::iterator::iterator(BNode * aNode)
   {
      ptr = aNode;
   }

   template <class T>
   BST<T>::iterator::iterator(iterator *rhs)
   {
      ptr = rhs->ptr;
   }

   template <class T>
   BST<T>::iterator::~iterator()
   {

   }

   template <class T>
   typename BST<T>::iterator& BST<T>::iterator::operator = (const iterator *rhs)
   {
      return ptr = rhs->ptr;
   }

   template <class T>
   bool BST<T>::iterator::operator == (const iterator &rhs)
   {
      return rhs.ptr == this->ptr;
   }

   template <class T>
   bool BST<T>::iterator::operator != (const iterator &rhs)
   {
      return rhs.ptr != this->ptr;
   }

   template <class T>
   typename BST<T>::iterator& BST<T>::iterator::operator ++ ()
   {
      this->ptr = this->ptr->pRight;
      return *this;
   }

   template <class T>
   typename BST<T>::iterator BST<T>::iterator::operator ++ (int postfix)
   {
      this->ptr = this->ptr->pRight;
      return *this;
   }

   template <class T>
   typename BST<T>::iterator& BST<T>::iterator::operator -- ()
   {
      this->ptr = this->ptr->pLeft;
      return *this;
   }

   template <class T>
   typename BST<T>::iterator BST<T>::iterator::operator -- (int postfix)
   {
      this->ptr = this->ptr->pLeft;
      return *this;
   }

   template <class T>
   T BST<T>::iterator::operator * ()
   {
      if (this->ptr == NULL)
      {
         throw ("Error: dereferencing null node.");
      }
      return this->ptr->data;
   }
}
