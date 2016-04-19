//
//  CTECBinaryTree.hpp
//  NodesInXCe
//
//  Created by Magallanes, Alejandro on 4/11/16.
//  Copyright © 2016 CTEC. All rights reserved.
//

#ifndef CTECBinaryTree_h
#define CTECBinaryTree_h

#include "TreeNode.cpp"

template <class Type>
class CTECBinaryTree
{
private:
    TreeNode<Type> * root;
    int height;
    int size;
    bool balanced;
    bool contains(Type value, CTECBinaryTree<Type> * currentTree);
    void calculateSize(TreeNode<Type> * currentNode);
    void insert(const Type& value, CTECBinaryTree<Type> * currentTree);
    TreeNode<Type> * getRightMostChild(CTECBinaryTree * leftSubTree);
    TreeNode<Type> * getLeftMostChild(CTECBinaryTree * rightSubdTree);
    
public:
    CTECBinaryTree();
    ~CTECBinaryTree();
    bool insert(const Type& value);
    bool contains(Type value);
    Type remove(const Type& value);
    int getHeight();
    int getSize();
    bool isBalanced();
    TreeNode<Type> * getRoot();
    void inorderTraversal(TreeNode<Type> * currentNode);
    void postorderTraversal(TreeNode<Type> * currentNode);
    void preorderTraversal(TreeNode<Type> * currentNode);
    
};

#endif /* CTECBinaryTree_h */
