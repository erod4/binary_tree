#include "tree.h"
#include <iostream>
using namespace std;

//predefined functions
int menu(int &);

void insert(Tree &);

void displayTree(Tree &);

void leafCount(Tree &);

void treeHeight(Tree &);

void treeWidth(Tree &);

void exitFunc();

void error();

int main() 
{
//class line with tree obj
Tree intTree;
int choice=0;
  //infinite menu loop while choice isn't 6
  while (choice != 6) 
  {
    choice = menu(choice);
    switch (choice) 
    {
      //menu functions with obj argument passed by reference
    case 1:
      insert(intTree);
      break;
    case 2:
      displayTree(intTree);
      break;
    case 3:
      leafCount(intTree);
      break;
    case 4:
      treeHeight(intTree);
      break;
    case 5:
      treeWidth(intTree);
      break;
    case 6:
      exitFunc();
    default:
      error();
      break;
    }

  }
}

int menu(int &choice) {
  
 //displays menu as long as choice isn't 6
  cout << "\n1. Insert Number\n";
  cout << "2. Display Tree\n";
  cout << "3. Leaf Count\n";
  cout << "4. Tree Height\n";
  cout << "5. Tree Width\n";
  cout << "6. Exit\n";

  
  cout << "\n\nPlease Enter an Option (1-6) and hit return: ";
  cin >> choice;
  return choice;
}

void insert(Tree &intTree)
{
  int num;
  cout<<"\nPlease enter number you'd like added to tree\n\nNumber: ";
  cin>>num;
  intTree.insertNode(num);//calls insert node func
  cout<<endl<<"The number "<<num<<" was added succesfully to tree.\n";
}

void displayTree(Tree &intTree)
{
  if(intTree.nodeCount()>=0)//only displays tree if the tree has nodes
  {
  cout<<"\n\nTree: \n\n";
  intTree.displayInOrder();
  cout<<endl;
  }
  
}

void leafCount(Tree &intTree)
{
  //leaf- node with no children
  cout<<"\nLeaf Count: "<<intTree.leafCount()<<endl;
}

void treeHeight(Tree &intTree)
{
    //displays tree height
  cout<<"\nTree Height: "<<intTree.treeHeight()<<endl;
}

void treeWidth(Tree &intTree)
{
    //displays tree width
  cout<<"\nTree Width: "<<intTree.treeWidth()<<endl;
}

void exitFunc() 
{

  cout<<"Exiting Application";
  for(int i=0;i<10;i++)
    {
      cout<<".";
    }
  exit(0);
}

void error() 
{
  cout << "\nSorry, incorrect option. Please try again.\n\n";
  
}
