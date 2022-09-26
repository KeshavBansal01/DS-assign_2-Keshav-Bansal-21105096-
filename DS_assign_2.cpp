//Question no.1///

#include<iostream>
using namespace std;
 
 struct node
 {
    int data;
    node * next;
 };


class circular_linked_list
{
    node* head=NULL;//  First element wil be pointed
    node* last = NULL; // Last element will be pointed
   public:
    void insert( int data)
    {  node * temp = new node();
     temp->data= data;
        if(head==NULL)
        {
            head= temp;
            last= temp;
            last->next= head;
        }
        else{
        last->next= temp;
         last= temp;
         temp->next= head;
        }
    }
    void display()
    {   
    
         node * temp= head;
        cout<<"Head-->";
         while(temp->next!= head)
         // Answer for Question1( condition that transversing a linked list a element came at the first position) : If I say the first element as head 
         // then when my transversing element next which is the pointer vector points to the head then that will be at the last elment so next 
         // element will be the first element when my transversing element becomes head the first element.
         {   
           
             cout<<temp->data<<"-->";
              temp= temp->next;
         }
          
             cout<<temp->data<<"-->Head";

    }

};
 
int main()
{ circular_linked_list a;
 a.insert(5);
 a.insert(10);
 a.insert(15);
 a.display();

    return 0;
}
/*

//Question no. 2
// 1.)Circular Linked Lists can be used to manage the computing resources of the computer.
// 2.)The real life application where the circular linked list is used is our Personal Computers, where multiple applications are running. 
// 3.)All the running applications are kept in a circular linked list and the OS gives a fixed time slot to all for running.
// ////The Operating System keeps on iterating over the linked list until all the applications are completed.
// 4.)Another example can be Multiplayer games. All the Players are kept in a Circular Linked List
///////and the pointer keeps on moving forward as a player's chance ends.
//5.) Circular Linked List can also be used to create Circular Queue. 
/////In a Queue we have to keep two pointers, FRONT and REAR in memory all the time, 
//////where as in Circular Linked List, only one pointer is required.
