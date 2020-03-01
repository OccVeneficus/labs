﻿#pragma once
#include "TreapNode.h"
#include "DataInOutLab5.h"
class Treap
{
private:
	TreapNode *_root;
public:
	Treap();
	TreapNode *GetRoot();
	TreapNode *Merge(TreapNode *left, TreapNode *right);
	void Split(TreapNode *node, int key, TreapNode *&left, TreapNode *&right);
	TreapNode *Add(int key);
	void OptimisedAdd(TreapNode *&current, TreapNode *newNode); //TODO: зачем перенес на другую строку?
	TreapNode *Remove(int key);
	TreapNode *OptimisedRemove(int key, TreapNode *&current);
	TreapNode *Search(int key, TreapNode *toCheck);
	void DeleteTreap(TreapNode *toDelete);
	~Treap();
};
