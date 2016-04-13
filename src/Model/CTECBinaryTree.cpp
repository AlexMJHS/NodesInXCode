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