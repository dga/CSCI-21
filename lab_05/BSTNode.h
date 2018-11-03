#ifndef BSTNODE_H
#define BSTNODE_H

#include <cstdlib> // Included to allow use of the NULL value

/**
 * \author Daniel G. Arnold\n
 * A container for nodes to be stored in a binary search tree container
 */
template<class T>
class BSTNode
{
public:

    /**
     * Default constructor.
     * Initialize this instance's data members to
     * leftChild = NULL
     * rightChild = NULL
     */
    BSTNode()
    {
        leftChild = NULL;
        rightChild = NULL;
    }

    /**
     * Overloaded constructor.
     * Initialize this instance's data members to
     * data = newData
     * leftChild = NULL
     * rightChild = NULL
     */
    BSTNode(T newData)
    {
        data = newData;
        leftChild = NULL;
        rightChild = NULL;
    }

    /**
     * Destructor.
     * Does nothing
     */
    ~BSTNode()
    {
    }

    /**
     * Assigns a new value to this instance's 'data' variable.
     * @param newData the value for the 'data' variable
     */
    void setData(T newData)
    {
        data = newData
    }

    /**
     * Assigns a new value to this instance's 'leftChild' variable.
     * @param newLeftChild the value for the 'leftChild' variable
     */
    void setLeftChild(BSTNode* newLeftChild)
    {
        leftChild = newLeftChild;
    }

    /**
     * Assigns a new value to this instance's 'rightChild' variable.
     * @param newRightChild the value for the 'rightChild' variable
     */
    void setRightChild(BSTNode* newRightChild)
    {
        rightChild = newRightChild;
    }
    
    /**
     * Retrieve the value of this instance's 'data' variable.
     * @return a T containing the value 'data' variable
     */
    T getData() const
    {
        return data;
    }

    /**
     * Retrieve a reference to this instance's 'data' variable.
     * @return a T& containing the address to the 'data' variable
     */
    T& getData()
    {
        return data;
    }

    /**
     * Retrieve the value of this instance's 'leftChild' variable.
     * @return a BSTNode* containing the value of the 'leftChild' variable
     */
    BSTNode* getLeftChild() const
    {
        return leftChild;
    }

    /**
     * Retrieve a reference to this instance's 'leftChild' variable.
     * @return a BSTNode*& containing the address to the 'leftChild' variable
     */
    BSTNode*& getLeftChild()
    {
        return leftChild;
    }

    /**
     * Retrieve the value of this instance's 'rightChild' variable.
     * @return a BSTNode* containing the value of the 'rightChild' variable
     */
    BSTNode* getRightChild() const
    {
        return rightChild;
    }

    /**
     * Retrieve a reference to this instance's 'rightChild' variable.
     * @return a BSTNode*& containing the address to the 'rightChild' variable
     */
    BSTNode*& getRightChild()
    {
        return rightChild;
    }

private:
    
    T data;
    BSTNode* leftChild;
    BSTNode* rightChild;
};

#endif
