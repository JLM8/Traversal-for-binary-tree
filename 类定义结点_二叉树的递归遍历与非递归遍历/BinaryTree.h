#pragma once
#ifndef BinaryTree_class
#define BinaryTree_class
#include<stack>
/*
#ifndef NULL
const int NULL = 0;
#endif
*/
#include"BinaryTreeNode.h"
template<class T>
class BinaryTree{
public:
	BinaryTreeNode<T> * root;

	BinaryTree(void){
		root = NULL;
	}

	~BinaryTree(void){}

	bool isEmpty(void)const{
		return ((root)?false:true);
	}
	bool Root(T&x) const;
	BinaryTreeNode<T> * MakeTree(const T& element, BinaryTreeNode<T> * left, BinaryTreeNode<T> * right);
	void CreateTree(BinaryTreeNode<T> * &root);
	void PreOrder(BinaryTreeNode<T> * root);
	void InOrder(BinaryTreeNode<T> * root);
	void PostOrder(BinaryTreeNode<T> * root);
	void PreOrderStack(BinaryTreeNode<T> * root);
	void InOrderStack(BinaryTreeNode<T> * root);
	void PostOrderStack(BinaryTreeNode<T> * root);
};

template<class T>
bool BinaryTree<T>::Root(T& x) const{
	if(root){
		x = root->data;
		return true;
	}else
		return false;
}

template<class T>
BinaryTreeNode<T> * BinaryTree<T>::MakeTree(const T& element, BinaryTreeNode<T> * left, BinaryTreeNode<T> * right){
	root = new BinaryTreeNode<T>(element,left,right);
	//root->display();
	if(root == NULL){
		cerr<<"Memory allocation failure!\n";
		//return 0;
	}
	return root;
}

template<class T>
void BinaryTree<T>::CreateTree(BinaryTreeNode<T> *& t){ // 在括号中声明的指针变量 在其函数定义中如果有new重新定义后 会在新地址中进行操作 但在最后会返回旧地址的
	                                                                                   //内容 也就是根本没有对其实际地址内的东西进行改变 造成在主函数中访问时的内存泄露
	T ch;
	cin>>ch;
	if(ch == '#'){ //若输入为‘#’则此树为空
		t = NULL;  //t=new BinaryTreeNode<T>(NULL) 会造成遍历输出时把空树用 “ ” 输出
	}else{
		t = new BinaryTreeNode<T>(ch);
		if(t == NULL){
		cerr<<"Memory allocation failure!\n";
		}
		CreateTree(t->LeftChild);
		CreateTree(t->RightChild);
	}	
}

template<class T>
void BinaryTree<T>::PreOrder(BinaryTreeNode<T> * t){
	if(t){
		cout<<t->data<<" ";
		PreOrder(t->LeftChild);
		PreOrder(t->RightChild);
	}
}

template<class T>
void BinaryTree<T>::InOrder(BinaryTreeNode<T> * t){
	if(t){
		InOrder(t->LeftChild);
		cout<<t->data<<" ";
		InOrder(t->RightChild);
	}
}

template<class T>
void BinaryTree<T>::PostOrder(BinaryTreeNode<T> * t){
	if(t){
		PostOrder(t->LeftChild);
		PostOrder(t->RightChild);
		cout<<t->data<<" ";
	}
}

template<class T>
void BinaryTree<T>::PreOrderStack(BinaryTreeNode<T> * t){
	
	BinaryTreeNode<T> * stack[100]; //创建二叉树结点的栈
	unsigned top; //设置顶点序号

	top = 0; stack[0] = t;
	BinaryTreeNode<T> * p;
	
	do{
		while(stack[top] != NULL){//若栈的顶点不为空 则依次将顶点的左孩子堆入栈
			cout<<stack[top]->data<<" "; //输出当前结点的数据
		    p = stack[top];
			stack[++top] = p -> LeftChild;
		}
		if(top > 0){
			p = stack[--top]; //临时二叉树结点赋值为栈的上一个结点的右孩子
			stack[top] = p -> RightChild;	//将现在栈的顶点存为p的右孩子
		}
	}while(top>0 || stack[top] != NULL);	//循环条件为 顶点序号top>0 栈的顶点不为空
}

template <class T>
void BinaryTree<T>::InOrderStack(BinaryTreeNode<T> * t){
	BinaryTreeNode<T> * stack[100];  //创建二叉树结点的栈
	unsigned top;  //设置顶点序号
	top = 0;
	stack[0] = t;
	BinaryTreeNode<T> * p;
	do{
		while(stack[top] != NULL){ //依次寻找当前结点的左孩子
			p = stack[top];
			stack[++top] = p -> LeftChild;
		}
		if(top > 0){
			p = stack[--top];
			cout<<p -> data<<" ";  //输出当前结点
			stack[top] = p->RightChild;  //栈中上一个结点的右孩子堆入栈顶
		}
	}while(top>0 || stack[top]!= NULL);  //循环条件为 顶点序号top>0 栈的顶点不为空
}

template<class T>
void BinaryTree<T>::PostOrderStack(BinaryTreeNode<T> * t){
	BinaryTreeNode<T> * stack[100];  //创建二叉树结点的栈
	unsigned top, tag[100];  //设置顶点序号 和 结点是否被访问过的标签
	top=0; stack[0] = t; tag[0] = 0;
	BinaryTreeNode<T> * p;

	do{
		while(stack[top]!=NULL){//依次寻找当前结点的左孩子
			p = stack[top];
			stack[++top] = p->LeftChild;
			tag[top] = 0;
		}
		while(tag[top-1] == 1){ //如果top-1 的标签为待访问 则访问其结点数据
			p=stack[--top];
			cout<<p->data<<" ";
		}
		if(top>0){ //将栈的顶点结点赋值为上个顶点的的右孩子 且将上一个顶点标签标为1（待访问）
			p=stack[top-1];
			stack[top] = p->RightChild;
			tag[top-1] = 1;
			tag[top] = 0;
		}
	}while(top!=0);//循环条件：顶点序号不为0
}
#endif