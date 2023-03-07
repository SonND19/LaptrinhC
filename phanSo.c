#include "phanSo.h"
#include <stdlib.h>

void init_list(lists *l)
{
    l->pHead = NULL;
    l->pLast = NULL;
}

nodes *init_node(fractions ps)
{
    nodes *p = calloc(sizeof(nodes), 1);
    if(p == NULL)
    {
        printf("\nKhong du bo nho de cap phat");
        return NULL;
    }

    p->data = ps;
    p->pNext = NULL;
    return p;
}

void add_head(lists *l, nodes *n)
{
    if(l->pHead == NULL){
        //printf("\n1");
        l->pHead = l->pLast = n;
    }
    else
    {
        //printf("\n2");
        n->pNext = l->pHead;
        l->pHead = n;
    }
}

void add_last(lists *l, nodes *n)
{
    if(l->pHead == NULL)
    {   //printf("\n11");
        l->pHead= l->pLast = n;
    }
    else
    {   //printf("\n22");
        l->pLast->pNext = n;
        l->pLast = n;
    }
}

void add_fraction(fractions *ps)
{
    printf("\nNhap tu so "); 
    scanf("%d", &ps->numerator);
    printf("\nNhap mau so "); 
    scanf("%d", &ps->denominator);
    //printf("\n3");
}
void add_any(lists *l, nodes *n, int position, int count)
{
    if(l->pHead == NULL || position == 1){
        add_head(&*l, &*n);
    }
    else if(position == count + 1){
        add_last(&*l, &*n);
    }
    else
    {
        int count1;
        nodes *a = calloc(sizeof(nodes), 1);
        for(nodes *i = l->pHead; i != NULL; i= i->pNext)
        {
            count1++;
            if(count1 == position)
            {
                nodes *b = init_node(n->data);
                b->pNext = i;
                a->pNext = b;
            }
            a = i;
        }
    }
}
void output(fractions ps)
{
    printf("\n %d : %d", ps.numerator, ps.denominator);
}
void print(lists *l)
{
    for(nodes *i = l->pHead; i != NULL; i = i->pNext)
    {
		output(i->data);
	}
}

void free_list(lists *l)
{
    nodes *n = NULL;
	while(l->pHead != NULL)
    {
		n = l->pHead;
		l->pHead = l->pHead->pNext;
		free(n);
        printf("\nGiai phong thanh cong\n");
	}
}
void free_head(lists *l)
{
    if(l->pHead == NULL)
    {
        return;
    }
    else
    {
        nodes *a = l->pHead;
        l->pHead = l->pHead->pNext;
        free(a);
    }
}

void free_last(lists *l)
{
    if(l->pHead == NULL)
    {
        return;
    }
    else if(l->pHead->pNext == NULL)
    {
        free_head(&*l);
    }
    else
    {
        for(nodes *i = l->pHead; i != NULL; i = i->pNext)
        {
            if(i->pNext == l->pLast)
            {
                free(l->pLast);
                i->pNext = NULL;
                l->pLast = i;
            }
        }
    }
}

void free_any(lists *l, int position, int count)
{
    // if(l->pHead == NULL)
    // {
    //     return;
    // }
    if(l->pHead == NULL || position == 1){
        //printf("\n1");
        free_head(&*l);
        return;
    }
    if(position == count + 1) // phan tu dau tien bang vi tri can xoa
    {
        //printf("\n2");
        free_head(&*l);
        return;
    }
    else
    {
        int count1 = 0;
        nodes *a = calloc(sizeof(nodes), 1);// node trung gian
        for(nodes *i = l->pHead; i != NULL; i = i->pNext)
        {
            count1++;
            //printf("\ncount %d", count1);
            if(count1 == position)
            {
                //printf("\n3");
                a->pNext = i->pNext;
                free(i);
                return;  
            }
            a = i;
        }
    }
    

}
void menu(lists *l)
{
    fractions ps;
    int key;
    int position;
    int count = 0;
    int count1 = 0;
    do
    {
        printf("\n\t\tMENU");
        printf("\n1. Them vao dau danh sach");
        printf("\n2. Them vao cuoi danh sach");
        printf("\n3. Xuat danh sach");
        printf("\n4. Them vao vi tri bat ki");
        printf("\n5. Xoa phan so dau tien");
        printf("\n6. Xoa phan so cuoi cung");
        printf("\n7. Xoa phan so o vi tri bat ki");
        printf("\n0. Ket thuc chuong trinh\n");

        printf("\nNhap su lua chon = "); scanf("%d", &key);
        switch(key)
        {
            case 0:
                printf("\nChuong trinh ket thuc");
                return;
            case 1:
                printf("\nNhap phan so ");
                add_fraction(&ps);
                nodes *p = init_node(ps);
                add_head(&*l, p);
                break;
            case 2:
                printf("\nNhap phan so ");
                add_fraction(&ps);
                nodes *p1 = init_node(ps);
                add_last(&*l, p1);
                break;;
            case 3:
                printf("\nXuat danh sach ");
                print(&*l);
                break;
            case 4:
                for(nodes *i = l->pHead; i != NULL; i = i->pNext)
                {
                    count++;
	            }
                printf("\ncount = %d", count);

                printf("\nNhap phan so can them"); add_fraction(&ps);
                nodes *p2 = init_node(ps);
				do
                {
					printf("\nNhap vi tri can them = ");
					scanf("%d", &position);
					if(position < 1 || position > count + 1)
                    {
						printf("\nVi tri can them nam trong doan tu[1; %d]", count + 1);
					}
				}while(position < 1 || position > count + 1);

                add_any(&*l, p2, position, count);
                break;
            case 5:
                free_head(&*l);
                break;
            case 6:
                free_last(&*l);
                break;
            case 7:
                for(nodes *i = l->pHead; i != NULL; i = i->pNext)
                {
                    count1++;
                }
                //printf("\ncount1 = %d", count1);
                do
                {
                    printf("\nNhap vi tri can xoa"); scanf("%d", &position);
                    
                }while(position < 1 || position > count1 + 1);
                free_any(&*l, position, count1);
                break;
        }
    }while(key >= 0 || key < 8);
}

int main(){
    lists l;
    init_list(&l);
    menu(&l);
    free_list(&l);
    return 0;
}