#include<iostream>  
using namespace std;  
  
typedef struct biTreeNode  
{  
    char data;  
    struct biTreeNode *LChild;  
    struct biTreeNode *RChild;  
}BiTreeNode;  
  
  
void Initiate_Tree(BiTreeNode **head)  
{  
    (*head)=(BiTreeNode *)malloc(sizeof(BiTreeNode)); //��̬����洢�ռ� 
    (*head)->LChild=NULL;  
    (*head)->RChild=NULL;  
}  
  
 BiTreeNode *InsertLChild(BiTreeNode *head,char x)  
{  
    if(head==NULL) return NULL;  
    else  
    {  
    BiTreeNode *p1,*p2;  
    p1=head->LChild;  //p1=NULL
    p2=(BiTreeNode*)malloc(sizeof(BiTreeNode));  
    p2->data=x;  
    p2->RChild=NULL;  
    head->LChild=p2;  
    p2->LChild=p1;  
    return p2;  
    }  
}  
  
  
BiTreeNode* InsertRChild(BiTreeNode *head,char x)  
{  
    if(head==NULL) return NULL;  
    {  
    BiTreeNode *p1,*p2;  
    p1=head->RChild;  
    p2=(BiTreeNode*)malloc(sizeof(BiTreeNode));  
    p2->data=x;  
    p2->LChild=NULL;  
    head->RChild=p2;  
    p2->RChild=p1;  
    return p2;  
    }  
}  
  
void DLR(BiTreeNode *head)  
{  
    if(head==NULL)  return;  
    else  
    {  
    cout<<head->data<<"  ";  
    DLR(head->LChild);  
    DLR(head->RChild);  
    }  
}  
  
//==================================================  
  
typedef struct lNode  //�����е�ÿһ���ڵ�
{  
    BiTreeNode *data;  
    struct lNode *next;  
}LNode;  
  
  
typedef struct lQueue  
{  
    LNode *front;  
    LNode *rear;  
}LQueue;  
  
  
void Initiate_Queue(LQueue *Q)  
{  
    Q->front=NULL;  
    Q->rear=NULL;  
}  
  
void AppendQueue(LQueue *Q,BiTreeNode *head)  //���
{  
    LNode *p1;  
    p1=(LNode *)malloc(sizeof(LNode));  
    p1->next=NULL;  
    p1->data=head;  
    if(Q->front==NULL) 
    {  
        Q->front=Q->rear=p1;  
    }  
    else  
    {  
        Q->rear->next=p1; //ָ��սڵ� 
        Q->rear=p1;  
    }  
}  
  
BiTreeNode * QueueDelete(LQueue *Q)  
{  
    if(Q->front==NULL) return NULL;  
    else  
    {  
        BiTreeNode *p;  
        p=Q->front->data;  
        Q->front=Q->front->next;//ָ���������һ���������ӵĽڵ�  
        return p;  
    }  
}  
  
int QueueNotEmpty(LQueue *Q)  
{  
    if(Q->front==NULL) return 0;  
    else return 1;  
}  
  
//�������  
void LayerOrder(BiTreeNode *head)  
{  
    LQueue Q;  
    Initiate_Queue(&Q);  
    BiTreeNode *p;  
    if(head!=NULL) AppendQueue(&Q,head);//���  
    while(QueueNotEmpty(&Q))  
    {  
        p=QueueDelete(&Q);  
        cout<<p->data<<"  ";  
        if(p->LChild!=NULL) AppendQueue(&Q,p->LChild);  
        if(p->RChild!=NULL) AppendQueue(&Q,p->RChild);      
    }  
}  
  
  
void main()  
{  
    BiTreeNode *head,*p,*p1;  
    Initiate_Tree(&head); 
    head->data='j';  
    p=InsertLChild(head,'k');  
    p=InsertLChild(p,'a');  
    InsertRChild(head,'b');  
    cout<<"ǰ�����Ϊ��"<<endl;  
    DLR(head);  
    cout<<endl;  
    cout<<"�������Ϊ��"<<endl;  
    LayerOrder(head);  
    system("pause");  
}  