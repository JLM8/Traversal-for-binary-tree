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
void BinaryTree<T>::CreateTree(BinaryTreeNode<T> *& t){ // ��������������ָ����� ���亯�������������new���¶���� �����µ�ַ�н��в��� �������᷵�ؾɵ�ַ��
	                                                                                   //���� Ҳ���Ǹ���û�ж���ʵ�ʵ�ַ�ڵĶ������иı� ������������з���ʱ���ڴ�й¶
	T ch;
	cin>>ch;
	if(ch == '#'){ //������Ϊ��#�������Ϊ��
		t = NULL;  //t=new BinaryTreeNode<T>(NULL) ����ɱ������ʱ�ѿ����� �� �� ���
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
	
	BinaryTreeNode<T> * stack[100]; //��������������ջ
	unsigned top; //���ö������

	top = 0; stack[0] = t;
	BinaryTreeNode<T> * p;
	
	do{
		while(stack[top] != NULL){//��ջ�Ķ��㲻Ϊ�� �����ν���������Ӷ���ջ
			cout<<stack[top]->data<<" "; //�����ǰ��������
		    p = stack[top];
			stack[++top] = p -> LeftChild;
		}
		if(top > 0){
			p = stack[--top]; //��ʱ��������㸳ֵΪջ����һ�������Һ���
			stack[top] = p -> RightChild;	//������ջ�Ķ����Ϊp���Һ���
		}
	}while(top>0 || stack[top] != NULL);	//ѭ������Ϊ �������top>0 ջ�Ķ��㲻Ϊ��
}

template <class T>
void BinaryTree<T>::InOrderStack(BinaryTreeNode<T> * t){
	BinaryTreeNode<T> * stack[100];  //��������������ջ
	unsigned top;  //���ö������
	top = 0;
	stack[0] = t;
	BinaryTreeNode<T> * p;
	do{
		while(stack[top] != NULL){ //����Ѱ�ҵ�ǰ��������
			p = stack[top];
			stack[++top] = p -> LeftChild;
		}
		if(top > 0){
			p = stack[--top];
			cout<<p -> data<<" ";  //�����ǰ���
			stack[top] = p->RightChild;  //ջ����һ�������Һ��Ӷ���ջ��
		}
	}while(top>0 || stack[top]!= NULL);  //ѭ������Ϊ �������top>0 ջ�Ķ��㲻Ϊ��
}

template<class T>
void BinaryTree<T>::PostOrderStack(BinaryTreeNode<T> * t){
	BinaryTreeNode<T> * stack[100];  //��������������ջ
	unsigned top, tag[100];  //���ö������ �� ����Ƿ񱻷��ʹ��ı�ǩ
	top=0; stack[0] = t; tag[0] = 0;
	BinaryTreeNode<T> * p;

	do{
		while(stack[top]!=NULL){//����Ѱ�ҵ�ǰ��������
			p = stack[top];
			stack[++top] = p->LeftChild;
			tag[top] = 0;
		}
		while(tag[top-1] == 1){ //���top-1 �ı�ǩΪ������ �������������
			p=stack[--top];
			cout<<p->data<<" ";
		}
		if(top>0){ //��ջ�Ķ����㸳ֵΪ�ϸ�����ĵ��Һ��� �ҽ���һ�������ǩ��Ϊ1�������ʣ�
			p=stack[top-1];
			stack[top] = p->RightChild;
			tag[top-1] = 1;
			tag[top] = 0;
		}
	}while(top!=0);//ѭ��������������Ų�Ϊ0
}
#endif