#include<stdio.h>
#include<stdlib.h>
typedef struct Node{

int data;
struct Node *next;

}node;

    //////////////////////////////////////No.OF NODES
    int n_nodes(node * ptr){
    int c=0;
    while((*ptr).next!=NULL){
        c=c+1;
        ptr=(*ptr).next;
    }
    return c;
    }
//////////////////////////////////////INSERT AT SPECIFIC NODES
node * inser(node * ptr,int data,int index){
    int g=0;
     node * head=(node *)malloc(sizeof(node));
    head=ptr;
    if(index==0){
        node * pcc=(node *)malloc(sizeof(node));
        (*pcc).data=data;
        (*pcc).next=ptr;
        return pcc;
    }

    else if(index==(n_nodes(head)+1)){
                    
                        node * pcc=(node *)malloc(sizeof(node));
                        (*pcc).data=data;
                        (*pcc).next=NULL;
                        
                        while((*ptr).next!=NULL){
                            ptr=(*ptr).next;

                        }
                        (*ptr).next=pcc;
                        return head;
                    }

    else if(index<=n_nodes(head))
    {
        while(g!=index-1)
            {

            ptr=(*ptr).next;
            g++;
            }
            node * pcc=(node *)malloc(sizeof(node));
                                (*pcc).data=data;
                                (*pcc).next=(*ptr).next;
                                (*ptr).next=pcc;
                            
                                return head;
    }



     else printf("Enter a valid index.\n");
     return head;
   
    }
    ////////////////////////////////////////////////TRAVERSAL
void trav(node *ptr){

while(ptr!=NULL){

printf("\n%d\n",(*ptr).data);
ptr=(*ptr).next;
}
}
////////////////////////////////////////////////////INITIALISING
void init(node *ptr){
    int a,x;
    node * head=(node *)malloc(sizeof(node));
    head=ptr;

printf("Enter the size of linked list=");
scanf("%d",&a);
for(int i=0;i<a;i++){
printf("Enter val of index[%d]= ",i);
scanf("%d",&x);
printf("\n");
if(i==0){
(*ptr).data=x;
}
else{
    head=inser(head,x,i);

}
}
}
//////////////////////////////////////////DELETING AT DESIRED INDEX
node * del(node * ptr){
int index,g=0;
printf("Enter INDEX to delete the Node=");
scanf("%d",&index);
 node * head=(node *)malloc(sizeof(node));
    head=ptr;

if(index==0){
  ptr=(*ptr).next;
  return ptr;
}
else if(index==(n_nodes(head))){
     node * P=(node *)malloc(sizeof(node));
    P=ptr;
     node * P1=(node *)malloc(sizeof(node));
    P1=(*ptr).next;
    while((*P1).next!=NULL){
        P=(*P).next;


     

    }
    (*P).next=NULL;

return head;



    
}
else if(0<index && index<n_nodes(head)){
    node * P=(node *)malloc(sizeof(node));
    P=ptr;
     node * P1=(node *)malloc(sizeof(node));
    P1=(*ptr).next;
while(g<(index-1)){
      P=(*P).next;
      P1=(*P1).next;



}
(*P).next=(*P1).next;
return head;
}
else {printf("Enter a valid index.\n");
return head;}
}
////////////////////////////////////////////////////////SEARCHING


void sec(node *ptr,int ele){
    int g=-1,s=0;
    while((*ptr).next!=NULL){
    ptr=(*ptr).next;
    g++;
    if((*ptr).data==ele){
         s=1;
        printf("\n%d is present at index %d\n",ele,g+1);
        return;
    }
}
if(s!=0)
printf("ELEMENT NHI MILA,DOOSRA SEARCH KRO");
}
/////////////////////////////////////////////////////////SORTING IN ASCENDING ORDER
void sort1(node *ptr){

node * P=(node *)malloc(sizeof(node));
    P=ptr;
    node * P1=(node *)malloc(sizeof(node));
   
    
    
    
    while((*P).next!=NULL){
        P1=(*P).next;
              while(P1!=NULL){int g;
                    if((*P).data>(*P1).data){
                          g=(*P).data;
                          (*P).data=(*P1).data;
                          (*P1).data=g;
                    }




                P1=(*P1).next;
              }
      P=(*P).next;


    }




}
///////////////////////////////////////////////////REVERSE OF THE LINKED LIST
node * rev(node *ptr){
    
  node * P=(node *)malloc(sizeof(node));
    P=ptr;
    node * P1=(node *)malloc(sizeof(node));
    P1=NULL;
    
    node * P2=(node *)malloc(sizeof(node));
      
    
     
     
    while(P!=NULL){
        P2=(*P).next;
     (*P).next=P1;
     P1=P;
     P=P2;
}
    return P1;


}
///////////////////////////////////////////////////////////////INITIALISATION OF BOTH POLYNOMIALS
void init1(node *ptr){
    int a,x;
    node * head=(node *)malloc(sizeof(node));
    head=ptr;

printf("Enter the DEGREE of POLYNOMIAL=");
scanf("%d",&a);
for(int i=0;i<(a+1);i++){
printf("Enter val of DEGREE[%d]= ",(i));
scanf("%d",&x);
printf("\n");
if(i==0){
(*ptr).data=x;
}
else{
    head=inser(head,x,i);

}
}
}
///////////////////////////////////////////////////////////////////////ADDITION OF BOTH POLYNOMIALS
void poly(node* ptr,node * ptr1){
    int i=0;
printf("ADDITION OF ENTERED 2 POLYNOMIALS ARE=\n");
while(ptr!=NULL&&ptr1!=NULL){
printf("%dx^%d+",((*ptr).data+(*ptr1).data),i);
ptr=(*ptr).next;
ptr1=(*ptr1).next;
i++;

}
}
/////////////////////////////////////////////////////////MAIN
void main(){
    int size_of_nodes,n;
    char y='y';


while(y=='Y'||y=='y'){
    //////////////////////declearing NODES
node* head;
head=(node *)malloc(sizeof(node));
(* head).next=NULL;
init(head);
    printf("1.Insert any Value at desired index\n2.Delete desired Node\n3.No. of Nodes\n4.Traverse\n5.Search element\n6.Sort in ASCENDING ORDER\n7.Reverse the list\n8.TO add two polynomials\nSELECT OPTION=");
    scanf("%d",&n);
    printf("\n");
    switch(n){
case 1 :  int q,q1; 
          size_of_nodes=n_nodes(head);
        printf("No. of NODES=%d\n",size_of_nodes+1);
                printf("Enter INDEX=");
                scanf("%d",&q);
            
            printf("\n");
            printf("Enter DATA=");
           scanf("%d",&q1);
           printf("\n");
            head=inser(head,q1,q);
            trav(head);

            break;
case 2 :   printf("\nORIGINAL linked list:\n");
                trav(head);
           
          head=del(head);
          printf("\nNEW linked list:\n");
          trav(head);
            break;
case 3: size_of_nodes=n_nodes(head);
        printf("No. of NODES=%d\n",size_of_nodes+1);
                        break;   
case 4:  

              trav(head);
               break; 
case 5:  int t;
        printf("\nEnter the element=");
        scanf("%d",&t);  
        sec(head,t);    



                break;
case 6: 
            sort1(head);
            trav(head);

            break;
case 7: head=rev(head);
        trav(head);


                break;
case 8:         node* head1=(node *)malloc(sizeof(node));
                (* head1).next=NULL;
                node* head2=(node *)malloc(sizeof(node));
                (* head2).next=NULL;
                init1(head1);
                 init1(head2);
                 poly(head1,head2);
                
                break;

default :  printf("\nHEHEHEHE KRR DI NA GALTI! \n KRO FIR SE ");

}
printf("\nWant to continue again[Y/N]=");
scanf("%s",&y);
}}
