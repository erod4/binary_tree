
# include<iostream>
# include "tree.h"
# include <cmath>

using namespace std;

//inserting new nodes
void Tree::insertNode(int num)
{
  TreeNode *newNode = nullptr;//pointer to new node
  //create new node 
  newNode=new TreeNode;
  //store number in node
  newNode->value=num;
  newNode->left=newNode->right=nullptr;

  //pass new node to insert func
  insert(root, newNode);
}
void Tree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
  //if no nodes
  if(nodePtr==nullptr)
    nodePtr = newNode;
  //if node being inserted is less than root node it inserts on left sub tree, repeats until it hits null
  else if (newNode->value<nodePtr->value)
    insert(nodePtr->left, newNode);
  //if node being inserted is greater than root node it inserts on right sub tree, repeats until it hits null
  else
    insert(nodePtr->right, newNode);
}
//displaying nodes
void Tree::displayInOrder(TreeNode *nodePtr) const
{
  if(nodePtr)//if nodes exist
  {
    displayInOrder(nodePtr->left);                                   
    cout<< nodePtr->value<<" ";
    displayInOrder(nodePtr->right);
  }
}
//search nodes
bool Tree::searchNode(int num)
{
  //starts at root
  TreeNode *nodePtr=root;
  //while not nullptr
  while(nodePtr)
  {
    if(nodePtr->value==num)
    {
      return true;
    }
      //if num<current node it traverses left
    else if(num<nodePtr->value)
    {
      nodePtr=nodePtr->left;
    }
      //if num>current node it traverses right
    else
      nodePtr=nodePtr->right;
  }
 return false;
}

//remove nodes
void Tree::remove(int num)
{
  deleteNode(num, root);
}
void Tree::deleteNode(int num, TreeNode *&nodePtr)
{
  if(num<nodePtr->value)
    deleteNode(num, nodePtr->left);
  else if(num>nodePtr->value)
    deleteNode(num,nodePtr->right);
  else
    makeDeletion(nodePtr);
}
void Tree::makeDeletion(TreeNode *&nodePtr)
{
  //tempt pointer to reattach left subtree
  TreeNode *tempNodePtr = nullptr;
  if(nodePtr==nullptr)
  {
    cout<<"Tree is empty\n";
  }
  else if(nodePtr->right==nullptr)
  {
    tempNodePtr=nodePtr;
    nodePtr=nodePtr->left;
    delete tempNodePtr;
  }
  else if(nodePtr->left==nullptr)//one child node
  {
    tempNodePtr=nodePtr;
    nodePtr =nodePtr->right;
    delete tempNodePtr;
  }
  else//two child nodes
  {
    //move node to the right
    tempNodePtr=nodePtr->right;
    //traverse to end of left node
    while(tempNodePtr->left)
      {
        tempNodePtr=tempNodePtr->left;
        //reattach l-subtree
        tempNodePtr->left=nodePtr->left;
        tempNodePtr=nodePtr;
        //reattach r-subtree
        nodePtr=nodePtr->right;
        delete tempNodePtr;
      }
  }
}
void Tree::destroySubTree(TreeNode *nodePtr)
{
  if(nodePtr)
  {
    if(nodePtr->left)
      destroySubTree(nodePtr->left);
    if(nodePtr->right)
      destroySubTree(nodePtr->right);
    delete nodePtr;
  }
}
//count nodes
int Tree::nodeCount(TreeNode *&nodePtr)
{
  if(nodePtr==nullptr)//no nodes makes count 0
  {
    return 0;
  }
  else //counts nodes on left and right and adds them together
  {
    return 1+nodeCount(nodePtr->left)+nodeCount(nodePtr->right);
  }
}
int Tree::leafCount(TreeNode *&nodePtr)
{
  if(nodePtr==nullptr)
  {
    return 0;
  }
  if(nodePtr->left==nullptr&&nodePtr->right==nullptr)
  {
    return 1;
  }
   return leafCount(nodePtr->left)+leafCount(nodePtr->right);
}
int Tree::treeHeight(TreeNode *&nodePtr)
{
  if(nodePtr==nullptr)//if no nodes there is no height;
  {
    return -1;
  }
  else//count nodes on the left and right
  {
    int left=treeHeight(nodePtr->left);
    int right=treeHeight(nodePtr->right);
    //returns max of right or left and adds 1 for root
      return max(left, right)+1;
  }
  
}
int Tree::treeWidth(TreeNode *&nodePtr, int level)
{
  if (nodePtr == nullptr) //checks for emptyness
  {
    return 0;
  }
    
    if (level == 1) //if only root then width is 1
    {
        return 1;
    }
    else if (level > 1) //checks each level and counts nodes at that level
    {
        int left = treeWidth(nodePtr->left, level - 1);
        int right= treeWidth(nodePtr->right, level - 1);
        
        return left + right;
    }
    
    return 0;
}
int Tree::treeWidth()
{
  if (root == nullptr) //returns 0 if empty
  {
    return 0;
  }
    
    int maxWidth = 0;//initialize maxWidth
    int height = treeHeight(root);//height is the last level that is checked
    
    for (int level = 1; level <= height; ++level) 
    {
      int levelWidth = treeWidth(root, level);//checks width of level
      maxWidth = max(maxWidth, levelWidth);//compares width of level with max width and max width becomes the greater of the two
    }
    
    return maxWidth;
}