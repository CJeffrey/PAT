#include <iostream>

//#define LB	2
#define LH	1
#define EQ	0
#define RH	-1
//#define RB	-2

typedef struct Node{
	Node()
		:lSon(NULL),rSon(NULL),balance(EQ){}
	~Node(){
		if (!lSon)
			delete lSon;
		if (!rSon)
			delete rSon;
	}
	int value;
	int balance;

	Node * lSon;
	Node * rSon;
}*NodePtr;

void rightRotate(NodePtr & np){
	NodePtr ls = np->lSon;
	np->lSon = ls->rSon;
	ls->rSon = np;
	np = ls;
}

void leftRotate(NodePtr & np){
	NodePtr rs = np->rSon;
	np->rSon = rs->lSon;
	rs->lSon = np;
	np = rs;
}

void leftBalance(NodePtr & np){
	NodePtr ls = np->lSon;
	switch (ls->balance){
		case LH:
			np->balance = EQ;
			ls->balance = EQ;
			rightRotate(np);
			break;
		/*case EQ:
			np->balance = LH;
			ls->balance = RH;
			rightRotate(np);
			break;*/
		case RH:
			switch(ls->rSon->balance){
				case LH:
					ls->balance=EQ;
					np->balance=RH;
					break;
				case EQ:
					ls->balance=EQ;
					np->balance=EQ;
					break;
				case RH:
					ls->balance=LH;
					np->balance=EQ;
					break;
			}
			ls->rSon->balance=EQ;
			
			leftRotate(np->lSon);
			rightRotate(np);
	}
}

void rightBalance(NodePtr & np){
	NodePtr rs = np->rSon;
	switch(rs->balance){
		case LH:
			switch(rs->lSon->balance){
				case LH:
					np->balance=EQ;
					rs->balance=RH;
					break;
				case EQ:
					np->balance=EQ;
					rs->balance=EQ;
					break;
				case RH:
					np->balance=LH;
					rs->balance=EQ;
					break;
			}
			rs->lSon->balance=EQ;
			rightRotate(np->rSon);
			leftRotate(np);
			break;
		/*case EQ:
			np->balance=RH;
			rs->balance=LH;*/
		case RH:
			rs->balance=EQ;
			np->balance=EQ;
			leftRotate(np);
			break;

	}
}

void insertValue(NodePtr & np,int value,bool & higher){
	if (np == NULL){
		np = new Node;
		np->value = value;
		higher = 1;
		return;
	} else {
		if (value < np->value){
			insertValue(np->lSon,value,higher);
			
			if (higher){
				switch (np->balance){
					case LH:
						leftBalance(np);
						higher=false;
						break;
					case EQ:
						np->balance = LH;
						higher = true;
						break;
					case RH:
						np->balance = EQ;
						higher = false;
						break;
				}
			}
		} else {
			insertValue(np->rSon,value,higher);

			if (higher){
				switch(np->balance){
					case LH:
						np->balance=EQ;
						higher=false;
						break;
					case EQ:
						np->balance=RH;
						higher=true;
						break;
					case RH:
						rightBalance(np);
						higher=false;
						break;
				}
			}
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int tmpValue;
	NodePtr root(NULL);
	bool higher;
	for(int i = 0;i<n;i++){
		scanf("%d",&tmpValue);
		insertValue(root,tmpValue,higher);
	}

	printf("%d",root->value);
	return 0;
}