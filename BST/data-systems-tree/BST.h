#define BST_H
#ifdef BST_H
#ifdef UNIT_TESTING // unit testing macro
int main(int argc, const char* argv[]);
#endif
namespace custom
{
    template <class T>
    class BST
    {


        public:

            class BNode;
            class iterator;
            friend int ::main(int argc, const char * argv[]);

            BST();
            BST(BST &rhs);
            ~BST();

            BST& operator =(BST &rhs);
    
            int size();
            bool empty();

            void clear();
            void insert(T t);
            void erase(iterator & it);

            iterator find(T t);
            iterator begin();
            iterator end();

            void moveNode();

            private:
            BNode * root;
            int numElements;
     
    };


    template <class T>
    class BST<T> :: BNode
    {
        private:
            T data;
            BNode * pParent;
            BNode * pLeft;
            BNode * pRight;

        public:
        friend int ::main(int argc, const char* argv[]);
        friend BST;
            BNode();
            BNode(T t);
            ~BNode();

    };

    template <class T>
    class BST<T> :: iterator 
    {
        private:
           BST<T>::BNode *ptr;

        public:
            friend int ::main(int argc, const char* argv[]);
            friend BST;
            iterator();
            iterator(BNode * aNode);
            iterator(iterator *rhs);
            ~iterator();
            


            iterator & operator = (const iterator *rhs);
            bool operator == (const iterator &rhs);
            bool operator != (const iterator &rhs);

            iterator & operator ++ ();
            iterator operator ++ (int postfix);
            iterator & operator -- ();
            iterator operator -- (int postfix);
            T operator * ();
            
    };


}
    #include "bst.cpp"


#endif