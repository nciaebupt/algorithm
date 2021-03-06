#if 0
/*
copyright@nciaebupt 转载请注明出处
题目：二叉树的结点定义如下：
struct TreeNode
{
     int m_nvalue;
     TreeNode* m_pLeft;
     TreeNode* m_pRight;
};
输入二叉树中的两个结点，输出这两个结点在数中最低的共同父结点。
分析：求数中两个结点的最低共同结点是面试中经常出现的一个问题。这个问题至少有两个
变种。
第一变种是二叉树是一种特殊的二叉树：查找二叉树。也就是树是排序过的，位于左子树上
的结点都比父结点小，而位于右子树的结点都比父结点大。我们只需要从根结点开始和两个
结点进行比较。如果当前结点的值比两个结点都大，则最低的共同父结点一定在当前结点的
左子树中。如果当前结点的值比两个结点都小，则最低的共同父结点一定在当前结点的右子
树中。
第二个变种是树不一定是二叉树，每个结点都有一个指针指向它的父结点。于是我们可以从
任何一个结点出发，得到一个到达树根结点的单向链表。因此这个问题转换为两个单向链表
的第一个公共结点。
所谓共同的父结点，就是两个结点都出现在这个结点的子树中。
因此我们可以定义一函数，来判断一个结点的子树中是不是包含了另外一个结点。
我们可以从根结点开始，判断以当前结点为根的树中左右子树是不是包含我们要找的两个结
点。如果两个结点都出现在它的左子树中，那最低的共同父结点也出现在它的左子树中。如
果两个结点都出现在它的右子树中，那最低的共同父结点也出现在它的右子树中。如果两个
结点一个出现在左子树中，一个出现在右子树中，那当前的结点就是最低的共同父结点。
*/
#include <cstdlib>
#include <iostream>

struct TreeNode
{
  int value;
  TreeNode * left;
  TreeNode * right;
};

void insertBTNode(TreeNode ** & root, int value)
{
  TreeNode * newnode = new TreeNode;
  newnode->value = value;
  newnode->left = NULL;
  newnode->right = NULL;
  if(*root == NULL){
    *root = newnode;
  }
  else{
    TreeNode * cur = *root;
    TreeNode * parent = *root;
    while(cur != NULL){
      parent = cur;
      if(value < cur->value){
        cur = cur->left;
      }
      else{
        cur = cur->right;
      }
    }
    if(value < parent->value){
      parent->left = newnode;
    }
    else{
      parent->right = newnode;
    }
  }
}

void createBTree(int * arr, int len, TreeNode ** root)
{
  if(arr == NULL || len < 1){
    return;
  }
  for(int i = 0; i < len; ++i){
    insertBTNode(root, arr[i]);
  }
}

void inorderTravel(TreeNode ** root){
  if(*root == NULL){
    return;
  }
  else{
    inorderTravel(&((*root)->left));
    std::cout<<(*root)->value<<std::endl;
    inorderTravel((&(*root)->right));
  }
}

TreeNode * findNode(TreeNode ** root, int value)
{
  if(*root == NULL){
    return NULL;
  }
  if((*root)->value == value){
    return *root;
  }
  else if(value > (*root)->value){
    findNode(&(*root)->right, value);
  }
  else{
    findNode(&(*root)->left, value);
  }
}

bool hasNode(TreeNode ** root, TreeNode * pcur){
  if(*root == NULL){
    return false;
  }
  if(pcur == *root){
    return true;
  }
  else if(pcur->value < (*root)->value){
    hasNode(&(*root)->left, pcur);
  }
  else{
    hasNode(&(*root)->right, pcur);
  }
}

TreeNode * lowestParentOfTwoNode(TreeNode ** root, TreeNode * pcur1, TreeNode * pcur2)
{
  if(*root == NULL || pcur1 == NULL || pcur2 == NULL){
    return NULL;
  }
  //judge if the two node all in left
  bool leftHasNode1 = false;
  bool leftHasNode2 = false;
  if((*root)->left != NULL){
    leftHasNode1 = hasNode(&(*root)->left, pcur1);
    leftHasNode2 = hasNode(&(*root)->left, pcur2);
  }
  if(leftHasNode1 == true && leftHasNode2 == true){
    if((*root)->left == pcur1 ||(*root)->right == pcur2){
      return *root;
    }
    return lowestParentOfTwoNode(&(*root)->left, pcur1, pcur2);
  }
  //judge if the two node all in right
  bool rightHasNode1 = false;
  bool rightHasNode2 = false;
  if(&(*root)->right != NULL){
    if(leftHasNode1 == false){
      rightHasNode1 = hasNode(&(*root)->right, pcur1);
    }
    if(leftHasNode2 == false){
      rightHasNode2 = hasNode(&(*root)->right, pcur2);
    }
  }
  if(rightHasNode1 == true && rightHasNode2 == true){
    if((*root)->right == pcur1 || (*root)->right == pcur2){
      return (*root);
    }
    return lowestParentOfTwoNode(&(*root)->right, pcur1, pcur2);
  }
  //the two node one in left one in right
  if((leftHasNode1 && rightHasNode2) || (leftHasNode2 && rightHasNode1)){
    return *root;
  }
  //others
  return NULL;
}

int main(int argc, char ** argv)
{
  int arr[] = {2,4,1,6,9,5,7};
  int len = sizeof(arr)/sizeof(arr[0]);
  TreeNode * root = NULL;
  createBTree(arr, len, &root);
  //inorderTravel(&root);
  TreeNode * node1 = findNode(&root, 7);
  TreeNode * node2 = findNode(&root, 5);
  if(node1 != NULL && node2 != NULL){
    std::cout<<node1->value<<std::endl;
    std::cout<<node2->value<<std::endl;
  }

  TreeNode * res = lowestParentOfTwoNode(&root, node1, node2);
  std::cout<<res->value<<std::endl;

  system("pause");
  return 0;
}
#endif
