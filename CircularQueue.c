//srishti1302

#include<stdio.h>
#define MAX 6

typedef struct{
    int key;
}element;
element cqueue[MAX];

void addcq(int front, int *rear, element item){

    if(front==((*rear+1)%MAX))
    {
        printf("Queue is full OVERFLOW \n ");
        return ;
    }
    *rear=(*rear+1)%MAX;
    cqueue[*rear]=item;
}

void deletecq(int *front, int rear){
    if(*front==rear)
    {
        printf("QUEUE IS EMPTY . UNDERFLOW");
        return;
    }

    *front=(*front+1)%MAX;
     printf("Deleted element is %d",cqueue[*front].key);

}
void display(int front,int rear){
    int i;
    if(front==rear)
    {
        printf("Empty Queue\n");
        return;
    }
    for(i=(front+1)%MAX;i!=(rear+1)%MAX;i=(i+1)%MAX)
        printf("%d\t",cqueue[i].key);
}

int main(){
    int f=0,r=0,s;
    char c='y';
    int t;
    element item;
    while(c=='y'||c=='Y')
    {
        printf("Enter choice 1.Insert 2.Delete 3.Display ");
        scanf("%d",&s);
        switch(s)
        {
            case 1:
                    printf("\n Enter element to be inserted ");
                    scanf("%d",&item.key);
                    addcq(f,&r,item);
                    break;
            case 2: deletecq(&f,r);

                    break;
            case 3: display(f,r);

        }
    printf("Want to continue y/n ");
    scanf(" %c",&c);
    }

}