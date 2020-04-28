#include <iostream>
using namespace std;
class node
{
public:
  int data;
  node *next;
  node *prev;

};

node *start = NULL;



void insert_beg (int x = 0)
{
  node *newnode = new node;	// create a node and allocate memory
  newnode->data = x;
  if (start == NULL)		//check if list empty
    {
      start = newnode;		// assign new node as start.
    }
  else				//if list not empty
    {
      newnode->next = start;	// change next of newnode to point to start
      start->prev = newnode;
      start = newnode;		// Change start to point to newly created node
    }
}


void insert_end (int x = 0)
{
  node *newnode = new node;	//Create a node and allocate memory.    
  newnode->data = x;
  node *temp;			//Create a temporary node pointer for traversing
  if (start == NULL)		//Check if list empty
    {
      start = newnode;
    }
  else
    {
      temp = start;		//assign temporary with starting address of the list
      while (temp->next != NULL)	//traverse till the last node
	temp = temp->next;
      temp->next = newnode;	// change next of last node to recently created node
      newnode->prev = temp;
    }
}

int total ()
{
  node *temp;
  temp=start;
  int totalnodes = 1;		//check for valid position, find totalnodes by traversing the list
  while (temp->next != NULL)	//traverse till the last node
    {
      temp = temp->next;
      totalnodes += 1;
    }
    if (start==NULL)
    {totalnodes=0;
    }
  return totalnodes;
}


void insert_mid (int x,int pos)
{
  node *newnode = new node;
  newnode->data = x;
  node *temp, *prev1;
  temp = start;
  int  totalnodes, ctr = 1;
  totalnodes=total();
 
  
  if ((pos > 1) && (pos < totalnodes))
    {
      prev1 = start;
      temp = prev1;
      while (ctr < pos)
	{
	  prev1 = temp;
	  temp = temp->next;
	  ctr++;
	}
      prev1->next = newnode;	//change next and prev pointers to include new node in between
      newnode->prev = prev1;    //prev1 is not a memeber of node class
      newnode->next = temp;     //prev1 is a pointers
      temp->prev = newnode;
    }
  else
    {
      std::cout << "position is not a middle position" << std::endl;
    }
}


void traverse ()
{
  node *temp;
  temp = start;
  if (start == NULL)
    std::cout << " Empty List" << std::endl;
  else
    {
      while (temp != NULL)
	{
	  std::cout << temp->data << std::endl;
	  temp = temp->next;
	}
    }
  std::cout << "NULL" << std::endl;
}

void delete_beg ()
{
    node *temp;
  if (start == NULL)
    {
      cout<<"\nEmpty list ";
}
else
{
temp=start; 
start = start->next;
start->prev=NULL;
delete temp;
}
}


void delete_end()
{node *temp,*del;
if(start == NULL)
{
cout<<" Empty list ";
      return;
    }
  else
    {
      temp = start;
      while (temp->next!= NULL)
	{
	  temp = temp->next;
	}
	del=temp;
	temp=temp->prev;
      temp->next = NULL;
    delete del;}
}

void delete_mid (int pos)
{
  node *temp, *prev1,* del;
  temp = start;
  int  totalnodes, ctr = 1;
  totalnodes=total();
 
  
  if ((pos > 1) && (pos < totalnodes))
    {
      prev1 = start;
      temp = prev1;
      while (ctr < pos)
	{
	  prev1 = temp;
	  temp = temp->next;
	  ctr++;
	}
	del=temp;
    prev1->next = temp->next->next;
    prev1->next->prev=prev1;
    delete del;
    }
    else
    {
    cout<<" Invalid position..";
    }
    
}
void monstereat()
{
    int totalnodes;
    node *prev1, *temp, *del;
    temp = start;
    totalnodes=total();
    if (totalnodes>1)
    {
        
    for(int i =1;i<(totalnodes+1);i=i+2)
    {
        if (i==1)
        {
            temp=temp->next->next;
            delete_beg();
        }
        else if (i==totalnodes)
        {
            delete_end();
        }
        else
        {del=temp;
        prev1=temp->prev;
         prev1->next = temp->next;
         prev1->next->prev=prev1;
         delete del;
         if(prev1->next->next!=NULL)
         {temp=prev1->next->next;
         }
        }
    } 
    }
    
}


int main ()
{
  node n1;


  insert_beg (3);
  insert_beg (1);
  insert_end (4);
  insert_mid (2,2);
  for (int i=5;i<1001;i++)
  {
      insert_end(i);
  }
  int t=total();
  while(t>1)
  {
      monstereat();
      //cout<<"\t"<<total()<<"\n";      
      traverse();
      t=total();
  }
  
}



