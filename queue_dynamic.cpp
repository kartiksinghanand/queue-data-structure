#include<iostream>
#include<stdlib.h>

using namespace std;

struct node{
int info;
struct node* link;
};

struct node* frnt=NULL,*last=NULL;

void dequeue();
void enqueue(int data);
void display();
int main()
{
    int ch,x;
    while(1)
    {cout<<"\nselect an option"
        <<"\n1.enqueue \n2.dequeue \n3.display the queue \n4.exit                  your choice: ";

        cin>>ch;
        switch(ch)
        {
            case 1:{cout<<"                        enter the data: "; cin>>x;enqueue(x); break;}
            case 2: dequeue(); break;
            case 3: {display();break;}
            case 4: exit(1); break;
            default:cout<<"                                                 invalid choice\n";
        }
     }
}

void enqueue(int data)
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    if(frnt==NULL&&last==NULL)
    {
        temp->link=NULL;
        frnt=temp;
        last=temp;
        return;
    }
    else{
        last->link=temp;
        temp->link=NULL;
        last=temp;
        return;
    }
}

void dequeue(){

struct node* ptr=frnt;
      if(frnt==NULL&&last==NULL)
      {
        cout<<"                                                           queue is empty\n";
        return;
      }
      ptr=ptr->link;
      frnt->link=NULL;
      free(frnt);
      frnt=ptr;
      return;
}


void display()
{
  struct node* ptr=frnt;
  if(frnt==NULL)
  {
cout<<"                                                          queue is empty";
 return;
  }
  else {
        cout<<"                                                              queue is:";

   while(ptr->link!=NULL)
   {
    cout<<ptr->info<<", ";
    ptr=ptr->link;
   }
   cout<<ptr->info;
      }
}
