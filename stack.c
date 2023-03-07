#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *pnext;
};
typedef struct node NODE;

// khai bao cau truc cua stack
struct stack{
	NODE *pTop; // dung con tro de quan ly stack
};
typedef struct stack STACK;

// ham khoi tao stack
void initStack(STACK *s){
	s->pTop = NULL;
}

NODE *initNode(int x){
	NODE *p = calloc(sizeof(NODE),1);
	if(p == NULL){
		printf("\nKhong du bo nho cap phat");
		return NULL;
	}
	
	p->data = x;
	p->pnext = NULL;
	return p;
}

int IsEmpty(STACK s){
	
	if(s.pTop == NULL){
		return 0;// danh sach chua co phan tu
		}
	return 1;// danh scah co phan tu	
}

int Push(STACK *s, NODE *p){// them phan tu vao dau stack
	if(p == NULL)
		return 1;
	if(IsEmpty(*s) == 0){
		//printf("aaa");
		s->pTop = p; //
	}
	else {
		//printf("bbb");
		p->pnext = s->pTop; //tao lien ket
		s->pTop = p; // cap nhat lai node dau
	}
	return 0;
}

int Pop(STACK *s, int x){ // x la gia tri can lay trong node
	
	if(IsEmpty(*s) == 0){
		return 1;
	}
	else {
		
		NODE *p = s->pTop;
		x = p->data; // gan gia tri cua node dau stack vao x
		s->pTop = s->pTop->pnext; // cap nhat top la phan tu tiep theo
		free(p);
	}
	return 0;	
}

// xem thong tin cua stack
int Top(STACK *s, int *x){
	
	if(IsEmpty(*s) == 0){
		return 1;
	}
	
	*x = s->pTop->data; // lay gia tri dau stack de xem
	return 0;
}

void output(STACK s){
	while(IsEmpty(s) == 1){
		int x;
		Pop(&s, x);		
		printf("%d", x);
	}
	if(IsEmpty(s) == 0){
		printf("\nDanh sach dang rong");
	}
	else {
		printf("\nDanh sach dang co phan tu ");
	}
}
void Menu(STACK *s){
	int key, x;
	do{
		printf("\n1.Them phan tu vao stack");
		printf("\n2. Xuat danh sach ra stack");
		printf("\n3. Xuat thong tin phan tu dau stack");
		printf("\n0. Ket thuc");
		
		printf("\nNhap lua chon"); scanf("%d", &key);
		
		switch(key){
			case 0:
				return;
			case 1:
				printf("\nNhap phan tu can them = ");
				scanf("%d", &x);
				NODE *p = initNode(x);
				Push(&*s, p);
				break;
			case 2:
				printf("\nXuat danh sach ");
				output(*s);
				printf("\n");
				break;
			case 3:
				Top(&*s,&x);
				printf("\nPhan tu dau stack %d", x);
				break;
				
		}
	}while(key > 0 || key < 4);
}
int main(){
	STACK s;
	initStack(&s);
	Menu(&s);
	return 0;
}
