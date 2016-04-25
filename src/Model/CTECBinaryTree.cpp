//
//  CTECBinaryTree.cpp
//  NodesInXCe
//
//  Created by Magallanes, Alejandro on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#include "CTECBinaryTree.h"

using namespace std;

template <class Type>
CTECBinaryTree<Type> :: CTECBinaryTree()
{
    root = nullptr;
    height = 0;
    balanced = true;
    size = 0;
}

template <class Type>
CTECBinaryTree<Type> :: ~CTECBinaryTree()
{
    while(root != nullptr)
    {
        remove(root);
    }
}

template <class Type>
bool CTECBinaryTree<Type> :: insert(const Type& value)
{
    TreeNode<Type> * insertedNode(value);
    TreeNode<Type> * current;
    TreeNode<Type> * trailingCurrent;
    assert(insertedNode != nullptr);
    if(contains(value))
    {
        return false;
    }
    else
    {
        if(root == nullptr)
        {
            root = insertedNode;
        }
        else
        {
            current = root;
            
            while(current != nullptr)
            {
                trailingCurrent = current;
                
                if(current->getValue() > value)
                {
                    current = current->getLeftChild();
                }
                else
                {
                    current = current->getRightChild();
                }
            }
            if(trailingCurrent->getValue() > value)
            {
                trailingCurrent->setLeftChild(insertedNode);
            }
            else
            {
                trailingCurrent->setRightChild(insertedNode);
            }
            insertedNode->setParent(trailingCurrent);
        }
        return true;
    }
}

template <class Type>
void CTECBinaryTree<Type> :: remove(const Type& value)
{
    TreeNode<Type> * current = root;
    TreeNode<Type> * trailing = current;
    if(!contains(value))
    {
        return;
    }
    else
    {
        while(current != nullptr && current->getValue() != value)
        {
            trailing = current;
            if(current->getValue() > value)
            {
                current = current->getLeftChild();
            }
            else
            {
                current = current->geRightChild();
            }
        }
        
        if(current == root)
        {
            remove(root);
        }
        else if (trailing->getValue() > value)
        {
            remove(trailing->getLeftChild);
        }
        else
        {
            remove(trailing->getRightChild);
        }
        
        /*
         Find the node.
         
         Check to see how many child nodes:
            if 0
                delete that node
            else if only left
         replace with left
         delete the old one
            else if only right
         replace with right
         delete the old one
            else both
         find LMC/RMC
         Swap with
         do - left only/right only
        */
    }
}

template <class Type>
void CTECBinaryTree<Type> :: remove(TreeNode<Type> * nodeToRemove)
{
    TreeNode<Type> * current;
    TreeNode<Type> * trailing;
    TreeNode<Type> temp;
    
    if(nodeToRemove == nullptr)
    {
        cerr << "You can't remove an empty non-existent thing" <<endl;
    }
    else if(nodeToRemove->getRightChild() == nullptr && nodeToRemove->getLeftChild() == nullptr) //Leaf node
    {
        temp = nodeToRemove;
        nodeToRemove = nullptr;
        delete temp;
    }
    else if(nodeToRemove->getRightChild() == nullptr)
    {
        temp = nodeToRemove;
        nodeToRemove = temp->getLeftChild();
        delete temp;
    }
    else if(nodeToRemove->getLeftChild() == nullptr)
    {
        temp = nodeToRemove;
        nodeToRemove = temp->getRightChild();
        delete temp;
    }
    else
    {
        current = nodeToRemove->getLeftChild();
        trailing = nullptr;
        
        while(current->getRightChild != nullptr)
        {
            trailing = current;
            current = current->getRightChild();
        }
        
        nodeToRemove->setValue(current->getValue());
        
        if(trailing == nullptr)
        {
            nodeToRemove->setLeftChild(current->getLeftChild());
        }
        else
        {
            trailing->setRightChild(current->getLeftChild());
        }
        
        delete current;
    }
}

template <class Type>
void CTECBinaryTree<Type> :: insert(const Type& value, CTECBinaryTree<Type> * curentTree)
{
    
}

template <class Type>
void CTECBinaryTree<Type> :: inorderTraversal(TreeNode<Type> * currentNode);
{
    if (currentNode != nullptr)
    {
        inorderTraversal(currentNode->getLeftChild());
        cout << currentNode->getValue() << " " ;
        inorderTraversal(currentNode->getRightChild());
    }
}

    template <class Type>
    void CTECBinaryTree<Type> :: preorderTraversal(TreeNode<Type> * currentNode);
    {
        if (currentNode != nullptr)
        {
            cout << currentNode->getValue() << " " ;
            preorderTraversal(currentNode->getLeftChild());
            preorderTraversal(currentNode->getRightChild());
        }
    }

    template <class Type>
    void CTECBinaryTree<Type> :: postorderTraversal(TreeNode<Type> * currentNode);
    {
        if (currentNode != nullptr)
        {
            inorderTraversal(currentNode->getLeftChild());
            inorderTraversal(currentNode->getRightChild());
            cout << currentNode->getValue() << " " ;
        }
    }

template <class Type>
int CTECBinaryTree<Type> :: getSize()
{
    size = 0;
    calculateSize(root);
    return size;
}

template <class Type>
void CTECBinaryTree<Type> :: calculateSize(TreeNode<Type> * currentNode)
{
    if (currentNode != nullptr)
        {
            calculateSize(currentNode->getLeftChild());
            calculateSize(currentNode->getRightChild());
            size++;
        }
}
        
template <class Type>
bool CTECBinaryTree<Type> :: contains(Type value)
{
    /*
     Is the value in root? - return true else
     If the value is not in the root and is less than root - call contains on left child
     Else if the value is not in the root and is greater than root - call contains on right child.
     */
    bool isInTree = false;
    if(root->getValue == value)
    {
        isInTree = false;
    }
    else if(root->getValue() == value)
    {
        isInTree = true;
    }
    else if(value < root->getValue())
    {
        isInTree = contains(value, root->getLeftChild());
    }
    else
    {
        isInTree = contains(contains(value, root->getightChild()));
    }
    return isInTree;
}

template <class Type>
bool CTECBinaryTree<Type> :: contains(Type value, CTECBinaryTree<Type> * currentTree)
{
    /*
        Is the value in root? - return true else
        If the value is not in the root and is less than root - call contains on left child
        Else if the value is not in the root and is greater than root - call contains on right child.
        */
    if(currentTree == nullptr)
    {
        return false;
    }
    
    if(currentTree->getRoot()->getValue() == value)
    {
        return true;
    }
    else if(value < currentTree->getRoot->getValue())
    {
        return contains(value, currentTree->getRoot->getLeftChild());
    }
    else
    {
        return contains(value, currentTree->getRoot->getRightChild());
    }
    return false;
}
        
template <class Type>
TreeNode<Type> * CTECBinaryTree<Type> :: getRightMostChild(CTECBinaryTree<Type> * leftSubTree)
{
    TreeNode<Type> * rightNode = leftSubTree->getRoot();
    while(rightNode->getRightChild() != nullptr)
    {
        rightNode = rightNode->getRightChild();
    }
    
    return rightNode;
}
        
template <class Type>
TreeNode<Type> * CTECBinaryTree<Type> :: getLeftMostChild(CTECBinaryTree<Type> * rightSubTree)
{
    TreeNode<Type> * leftNode = rightSubTree->getRoot();
    while(leftNode->getLeftChild() != nullptr)
    {
        leftNode = leftNode->getLeftChild();
    }
    
    return leftNode;
}

