#include<iostream>
using namespace std;
#include"BinaryTree.h"
#include"BinaryTreeNode.h"
//BinaryTree<int> a;
BinaryTree<char> b;  //创建二叉树

//BinaryTreeNode<int> *b1, *b2, *b3, *b4, *b5, *b6;
int main(){
	/*
	b1 = a.MakeTree(6,NULL,NULL);
	b2 = a.MakeTree(5,NULL,NULL);
	b3 = a.MakeTree(4,NULL,NULL);
	b4 = a.MakeTree(3,b1,NULL);
	b5 = a.MakeTree(2,b3,b2);
	b6 = a.MakeTree(1,b5,b4);

	cout<<"The PreOrder is:"<<endl;
	a.PreOrder(a.root);
	cout<<endl;
	cout<<"The InOrder is:"<<endl;
	a.InOrder(a.root);
	cout<<endl;
	cout<<"The PostOrder is:"<<endl;
	a.PostOrder(a.root);
	cout<<endl;
	cout<<"The PreOrderstack is"<<endl;
	a.PreOrderStack(a.root);
	cout<<endl;
	cout<<"The InOrderStack is"<<endl;
	a.InOrderStack(a.root);
	cout<<endl;
	cout<<"The PostOrderStack is"<<endl;
	a.PostOrderStack(a.root);
	cout<<endl;
	*/
	//提示并用户先序输入二叉树 ‘#’代表空树
	cout<<"Please input the BinaryTree as PreOrder..."<<endl;
	b.CreateTree(b.root);
	//先序递归遍历
	cout<<"The PreOrder is:"<<endl;
	b.PreOrder(b.root);
	cout<<endl;
	//中序递归遍历
	cout<<"The InOrder is:"<<endl;
	b.InOrder(b.root);
	cout<<endl;
	//后序递归遍历
	cout<<"The PostOrder is:"<<endl;
	b.PostOrder(b.root);
	cout<<endl;
	//先序堆栈遍历
	cout<<"The PreOrderstack is"<<endl;
	b.PreOrderStack(b.root);
	cout<<endl;
	//中序堆栈遍历
	cout<<"The InOrderStack is"<<endl;
	b.InOrderStack(b.root);
	cout<<endl;
	//后序堆栈遍历
	cout<<"The PostOrderStack is"<<endl;
	b.PostOrderStack(b.root);
	cout<<endl;
	
	
	system("pause");
	return 0;
}