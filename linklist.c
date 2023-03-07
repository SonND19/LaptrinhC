#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *pNext;
} NODE;

typedef struct list{
	NODE *pHead;
	NODE *pLast;
}LIST;

// khai bao nguyen mau ham
void init_list(LIST *l);
NODE *init_node(int x);
void add_head(LIST *l, NODE *n);
void add_last(LIST *l, NODE *n);
void add_any(LIST *l, NODE *n, int position);
void print(LIST l);
void free_list(LIST *l);


void init_list(LIST *l){
	l->pHead = NULL;
	l->pLast = NULL;
}

//  khoi tao node
NODE *init_node(int x){
    NODE *n = calloc(sizeof(NODE), 1);
    if(n == NULL){
        printf("\nKhong du bo nho de cap phat");
        return NULL;
    }
    n->data = x;
    n->pNext = NULL;
    return n;
}

// khoi tao node dau trong danh sach
void add_head(LIST *l, NODE *n){
    if(l->pHead == NULL){ // chua co phan tu nao trong danh sach
        l->pHead = l->pLast = n;// phan tu dau tien
    }
    else
    {
        n->pNext = l->pHead; // phan tu ke tiep
        l->pHead = n; // cap nhat lai n
    }
}

// khoi tao node cuoi trong danh sach
void add_last(LIST *l, NODE *n){
    if(l->pHead == NULL){
        l->pHead = l->pLast = n;
    }
    else
    {
        l->pLast->pNext = n;
        l->pLast = n;
    }   
} 
void add_any(LIST *l, NODE *n, int position){
    int c = 0;
    if(l->pHead == NULL || position == 1){
        add_head(&*l,&*n);
    }
    else if(position == c + 1){
        add_last(&*l, &*n);
    }
    else{
        int count = 0;
        NODE *a = calloc(sizeof(NODE), 1);
            for(NODE *i = l->pHead; i != NULL; i = i->pNext){
                count++; 
                if(count == position){
                    NODE *b = init_node(n->data);
                    b->pNext = i;
                    a->pNext = b;
                    break;
                }
                a = i;
            }
    }
    
}  
void print(LIST l){
    for(NODE *i = l.pHead; i != NULL; i = i->pNext){
		printf(" %d ", i->data);
	}
}
void free_list(LIST *l){
    NODE *i = NULL;
	while(l->pHead != NULL){
		i = l->pHead;
		l->pHead = l->pHead->pNext;
		free(i);
        printf("\nGiai phong thanh cong\n");
	}
}
void menu(LIST *l){
    int key, x;
    int count = 0;
    do{
        printf("\n\t\t Menu ");
        printf("\n1. Them phan tu vao dau ");
        printf("\n2. Them phan tu vao cuoi");
        printf("\n3. Xuat cac phan tu trong danh sach ");
        printf("\n4. Them phan tu vao vi tri bat ki");
        printf("\n0. Ket thuc chuong trinh ");

        printf("\n\nNhap su lua chon cua ban = "); scanf("%d", &key);
        switch(key){
            case 0:
                printf("\nChuong trinh da ket thuc");
                return;
            case 1:
                printf("\nNhap phan tu can them vao dau = "); scanf("%d", &x);
                NODE *p1 = init_node(x);
                add_head(&*l, p1);
                break;
            case 2:
                printf("\nNhap phan tu can them vao dau = "); scanf("%d", &x);
                NODE *p2 = init_node(x);
                add_last(&*l, p2);
                break;
            case 3:
                printf("\nXuat phan tu trong danh sach ");
                print(*l);
                break;
            case 4:
                for(NODE *i = l->pHead; i != NULL; i = i->pNext){
                    count++;  
	            }
                printf("count = %d", count);
                printf("\nNhap gia tri x =  "); 
				scanf("%d", &x);
				NODE *p3 = init_node(x);
				int vt;
				do{
					printf("\nNhap vi tri can them = ");
					scanf("%d", &vt);
					if(vt < 1 || vt > count + 1){
						printf("\nVi tri can them nam trong doan tu[1; %d]", count + 1);
					}
				}while(vt < 1 || vt > count + 1);
                add_any(&*l, p3, vt);
                count++;
                break;

        }
    }while(key >= 0 || key < 4);
}

int main(){
    LIST l;
    init_list(&l);
    menu(&l);
    free_list(&l);

    printf("\nXuat danh sach "); 
    print(l);
    printf("\n");
    return 0;
}