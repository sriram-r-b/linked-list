
#include <iostream>
using namespace std;
class node {
public:
int data;
node* next;
node* prev;

};

node *start = NULL;



void insert_beg(int x=0)
{
node *newnode=new node;   // create a node and allocate memory
newnode -> data=x;
if(start == NULL) //check if list empty
{
start = newnode;  // assign new node as start.
}
else            //if list not empty
{
newnode -> next = start;// change next of newnode to point to start
start -> prev = newnode;
start = newnode;    // Change start to point to newly created node
}
}


void insert_end(int x=0)
{
node *newnode = new node; //Create a node and allocate memory.    
newnode -> data=x;
node *temp;      //Create a temporary node pointer for traversing
if(start == NULL)   //Check if list empty
{
start = newnode;
}
else
{
 temp = start;  //assign temporary with starting address of the list
while(temp -> next != NULL) //traverse till the last node
temp = temp -> next;
temp->next = newnode;// change next of last node to recently created node
newnode -> prev = temp;
}
}


void insert_mid(int x)
{
node *newnode = new node;
newnode -> data=x;
node *temp, *prev1;
temp=start;
int pos,totalnodes=0,ctr = 1;
cin>>pos;
//check for valid position, find totalnodes by traversing the list
while(temp -> next != NULL) //traverse till the last node
{
    temp = temp -> next;
    totalnodes+=1;
}
if((pos > 1 )&& (pos < totalnodes))
{
prev1 = start;
temp= prev1;
while(ctr < pos)
{
prev1 = temp;
temp = temp -> next;
ctr++;
}
prev1 -> next = newnode; //change next pointers to include new node in bbetween
newnode ->prev = prev1;
newnode -> next = temp;
temp -> prev =newnode;
}
else
{
std::cout <<"position is not a middle position"<< std::endl;
}
}


void traverse()
{
node *temp;
temp = start;
if(start == NULL )
std::cout <<" Empty List"<< std::endl; 
else
{
while (temp != NULL)
{
std::cout << temp -> data << std::endl;
temp = temp -> next;
}
}
std::cout << "NULL" << std::endl;
}




int main()
{
    node n1;
    
    
    insert_beg(1);
    insert_end(4);
    insert_mid(3);
    traverse();
}


