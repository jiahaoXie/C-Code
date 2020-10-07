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
    (*head)=(BiTreeNode *)malloc(sizeof(BiTreeNode)); //动态申请存储空间 
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
  
typedef struct lNode  //队列中的每一个节点
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
  
void AppendQueue(LQueue *Q,BiTreeNode *head)  //入队
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
        Q->rear->next=p1; //指向空节点 
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
        Q->front=Q->front->next;//指向队列中下一个即将出队的节点  
        return p;  
    }  
}  
  
int QueueNotEmpty(LQueue *Q)  
{  
    if(Q->front==NULL) return 0;  
    else return 1;  
}  
  
//层序遍历  
void LayerOrder(BiTreeNode *head)  
{  
    LQueue Q;  
    Initiate_Queue(&Q);  
    BiTreeNode *p;  
    if(head!=NULL) AppendQueue(&Q,head);//入队  
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
    cout<<"前序遍历为："<<endl;  
    DLR(head);  
    cout<<endl;  
    cout<<"层序遍历为："<<endl;  
    LayerOrder(head);  
    system("pause");  
}  