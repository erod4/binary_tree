

#ifndef TREE_H
#define TREE_H      
#include <iostream>

using namespace std;

class Tree
{
  private:
    struct TreeNode
      {
        int value; //holds value in node
        TreeNode *left;//pointer to left child node
        TreeNode *right;//pointer to the right child node
      };

    TreeNode *root;//root node pointer

    void insert(TreeNode *&, TreeNode *&);
    void destroySubTree(TreeNode *);
    void deleteNode(int, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void displayInOrder(TreeNode *) const;
    int nodeCount(TreeNode *&);
    int leafCount(TreeNode *&);
    int treeWidth(TreeNode *&, int level);
    int treeHeight(TreeNode *&);
  public:
  //constructor
  Tree()
  {root=nullptr; }
  //detructor
  ~Tree()
  { destroySubTree(root); }

  //operations
  int treeHeight()
{ return treeHeight(root); }
  int treeWidth();
  int leafCount()
{ return leafCount(root); }
  int nodeCount()
{ return nodeCount(root); }
  void insertNode(int);
  bool searchNode(int);
  void remove(int);
  void displayInOrder() const
{ displayInOrder(root); }
};



#endif