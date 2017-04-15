#pragma once
#ifndef BINARYTREENODE_CLASS
#define BINARTTREENODE_CLASS
/*
#ifndef NULL
const int NULL = 0;
#endif*/
template <class T>
class BinaryTreeNode{
public:
	T data; //结点数据
	BinaryTreeNode<T> *LeftChild, *RightChild; //该结点的左右孩子
	//构造函数
	BinaryTreeNode(void){
		LeftChild = RightChild = NULL;
	}
	BinaryTreeNode(const T& e){
		data = e;
		LeftChild = RightChild = NULL;
	}
	BinaryTreeNode(const T& e, BinaryTreeNode<T> * l, BinaryTreeNode<T> * r){
		data = e;
		LeftChild = l;
		RightChild = r;
	}
	//析构函数
	~BinaryTreeNode(){
		if(LeftChild)
			delete LeftChild;
		if(rightChild)
			delete RightChild;
	}
	//展示数据
	void display(){
		if(data!=NULL)
			cout<<"data="<<data<<endl;
		else
			cout<<"data=NULL"<<endl;
			
		if(LeftChild)
			cout<<"LeftChild->data="<<LeftChild->data<<endl;
		else
			cout<<"LeftChild->data=NULL"<<endl;

		if(RightChild)
			cout<<"RightChild->data="<<RightChild->data<<endl;
		else
			cout<<"RightChild->data=NULL"<<endl;
	}
	BinaryTreeNode<T> * GetBTreeNode(T item, BinaryTreeNode<T> * lptr = NULL, BinaryTreeNode<T> * rptr = NULL);
};

template<class T>
BinaryTreeNode<T> * BinaryTreeNode<T>::GetBTreeNode(T item, BinaryTreeNode<T> * lptr, BinaryTreeNode<T>* rptr){
	BinaryTreeNode<T> * p;
	p = new BinaryTreeNode<T>(item, lptr, rptr);
	if(p == NULL)
		cerr<<"Memory allocation failure!\n";
	return p;
}
#endif