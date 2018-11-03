#ifndef BSTREE_H
#define BSTREE_H

#include "BSTNode.h"

/**
 * \author Daniel G. Arnold\n
 * A container for a binary search tree
 */
template<class T>
class BSTree
{
public:

    /**
     * Default constructor.
     * Initialize this instance's data members to
     * nodeCount = 0
     * root = NULL
     */
    BSTree()
    {
        nodeCount = 0;
        root = NULL;
    }

    /**
     * Destructor.
     * Deallocate the nodes from the heap if the user hasn't already done so
     */
    ~BSTree()
    {
        if (root != NULL)
            clear(root);
    }
    
    /**
     * Inserts a new node to the tree.
     * @param newData the data to be contained by the node
     * @param compare the function pointer to the compare function which will dictate the direction in which
     * the tree will recurse
     */
    void insert(T newData, int (*compare)(T,T))
    {
        insert(root, newData, compare);
    }

    /**
     * Removes a node from the tree.
     * @param newData the data contained by the node to be removed
     * @param compare the function pointer to the compare function which will dictate the direction in which
     * the tree will recurse
     */
    void remove(T newData, int (*compare)(T,T))
    {
        remove(root, newData, compare);
    }

    /**
     * Finds the node that contains the target data.
     * @return a T containing the node that contains the target data
     * @param target the data to search for
     * @param compare the function pointer to the compare function which will dictate the direction in which
     * the tree will recurse
     */
    T find(T target, int (*compare)(T,T))
    {
        return find(root, target, compare);
    }

    /**
     * Traverses the tree in order.
     * @param f a function pointer to a void function that takes in a parameter of type T
     */
    void inorder (void (*f)(T))
    {
        inorder(root, f);
    }

    /**
     * Allows the user to deallocate the nodes from the heap.
     */
    void clear()
    {
        clear(root);
    }

    /**
     * Retrieve the value of this instance's 'nodeCount' variable.
     * @return an unsigned int containing the value of the 'nodeCount' variable
     */
    unsigned int getNodeCount()
    {
        return nodeCount;
    }

private:

    BSTNode<T>* root;
    unsigned int nodeCount;

    void clear(BSTNode<T>*& subRoot)
    {
        if (subRoot) {
            clear(subRoot->getLeftChild());
            clear(subRoot->getRightChild());
            delete subRoot;
            subRoot = NULL;
            nodeCount--;
        }
    }
    
    void insert(BSTNode<T>*& subRoot, T newData, int (*compare)(T,T)) // Use of compare function inspired by Mateo Gomez
    {
        if (subRoot == NULL) {
            subRoot = new BSTNode<T>(newData);
            nodeCount++;
        } else {
            int result = compare(subRoot->getData(), newData);

            if (result == 1)
                insert(subRoot->getLeftChild(), newData, compare);
            else if (result == -1)
                insert(subRoot->getRightChild(), newData, compare);
        }
    }

    void remove(BSTNode<T>*& subRoot, T newData, int (*compare)(T,T))
    {
        if (subRoot == NULL)
            ;
        else {
            int result = compare(subRoot->getData(), newData);
            T temp = subRoot->getData();

            if (result == 1)
                remove(subRoot->getLeftChild(), newData, compare);
            else if (result == -1)
                remove(subRoot->getRightChild(), newData, compare);
            else if (result == 0) {
                if (subRoot->getLeftChild() == NULL) {
                    BSTNode<T>* tempnode = subRoot;
                    subRoot = subRoot->getRightChild();
                    delete tempnode;
                } else
                    removeMax(subRoot->getLeftChild(), subRoot->getData());
                nodeCount--;
            }
        }
    }

    void removeMax(BSTNode<T>*& subRoot, T& newData)
    {
        if (subRoot->getRightChild() == NULL) {
            newData = subRoot->getData();
            BSTNode<T>* tnode = subRoot;
            subRoot = subRoot->getLeftChild();
            delete tnode;
        } else
            removeMax(subRoot->getRightChild(), newData);
    }

    T find(BSTNode<T>*& subRoot, T target, int (*compare)(T,T))
    {
        if (subRoot != NULL) {
            int result = compare(subRoot->getData(), target);

            if (result == 1)
                return find(subRoot->getLeftChild(), target, compare);
            else if (result == -1)
                return find (subRoot->getRightChild(), target, compare);
            else
                return subRoot->getData();
        } else
            return NULL;
    }
    
    void inorder (BSTNode<T>*& subRoot, void(*f)(T))
    {
        if (subRoot != NULL)
        {
            inorder(subRoot->getLeftChild(), f);
            f(subRoot->getData());
            inorder(subRoot->getRightChild(), f);
        }
    }
};

#endif
