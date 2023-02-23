#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;

#pragma pack(1)
template <class T>
struct node
{
	T data;
	struct node *next;
    struct node *prev;
};

template <class T>
class SinglyLL
{
	public:
		struct node<T> * First;
		int iCount;
		
		SinglyLL();
		
		void InsertFirst(T no);
		void InsertLast(T no);
		void InsertAtPosition(T no,int ipos);
		
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPosition(int ipos);
		
		void Display();
			
};

template <class T>
class DoublyLL
{
	public:
		struct node<T> *First;
		int iCount;
	
		DoublyLL();	
		void InsertFirst(T no);
		void InsertLast(T no);
		void InsertAtPosition(T no,int ipos);
	
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPosition(int ipos);
	
		void Display();
};

template <class T>
class SinglyCL
{
	public:
		struct node<T> * First;
		struct node<T> * Last;

		int iCount;
		
		SinglyCL();
		
		void InsertFirst(T no);
		void InsertLast(T no);
		void InsertAtPosition(T no,int ipos);
		
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPosition(int ipos);
		
		void Display();
};

template <class T>
class DoublyCL
{
	public:
		
		struct node<T> *First;
		struct node<T> *Last;
		int iCount;
		
		DoublyCL();
		
		void InsertFirst(T no);
		void InsertLast(T no);
		void InsertAtPosition(T no,int ipos);
		
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPosition(int ipos);
		
		void Display();
};

template <class T>
class Stack
{
	public:
		struct node<T> *First;

		int iCount;

		Stack();

		void Push(T no);

		void Pop();

		void Display();
};

template <class T>
class Queue
{
	public:
		struct node<T> *First;

		int iCount;

		Queue();

		void Enqueue(T no);

		void Dequeue();

		void Display();
};

template <class T>
SinglyLL <T> :: SinglyLL()
{
	First = NULL;
	iCount =  0;
}

//struct is the optional keyword we can directly write node 

template <class T>
void SinglyLL <T> :: InsertFirst(T no)
{
	struct node<T> * newn = new struct node<T>;
	
	newn->data = no;
	newn->next = NULL;
	
	if(First == NULL)
	{
		First = newn;
		iCount++;
	}
	else
	{
		newn->next = First;
		First = newn;
		iCount++;
	}
}

template <class T>
void SinglyLL <T> :: InsertLast(T no)
{
	struct node<T> * newn = new struct node<T>;
	struct node<T> * temp = First;
	
	newn->data = no;
	newn->next = NULL;
	
	if(First == NULL)
	{
		First = newn;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
		iCount++;
	}
}

template <class T>
void SinglyLL<T> :: InsertAtPosition(T no,int ipos)
{	
	if((ipos < 1) || (ipos > (iCount + 1)))
	{
		cout<<"Invalid position\n";
		return;
	}
	
	if(ipos == 1)
	{
		InsertFirst(no);
	}
	else if(ipos == iCount+1)
	{
		InsertLast(no);
	}
	else
	{	
		struct node<T> * newn = new struct node<T>;
		struct node<T> * temp = First;
	
		newn->data = no;
		newn->next = NULL;
		
		for(int iCnt = 1;iCnt < ipos-1;iCnt++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
	}
}

template <class T>
void SinglyLL<T> :: DeleteFirst()
{	
	if(First == NULL)
	{
		return;
	}
	else
	{
		struct node<T> * temp = First;
		First = First->next;
		delete temp;
		iCount--;
	}
}

template <class T>
void SinglyLL<T> :: DeleteLast()
{
	if(First == NULL)
	{
		return;	
	}
	else
	{
		struct node<T> * temp = First;
		
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		delete temp->next;
		temp->next = NULL;
		iCount--;	
	}	
}

template <class T>
void SinglyLL<T> :: DeleteAtPosition(int ipos)
{
	if((ipos < 1) || (ipos > (iCount + 1)))
	{
		cout<<"Invalid Position\n";
		return;
	}
	
	if(ipos == 1)
	{
		DeleteFirst();
	}
	else if(ipos == iCount)
	{
		DeleteLast();
	}
	else
	{
		struct node<T> * temp1 = First;
		struct node<T> * temp2 = NULL;
		
		for(int iCnt = 1;iCnt < ipos-1;iCnt++)
		{
			temp1 = temp1->next;
		}
		temp2 = temp1->next;
		temp1->next = temp2->next;
		delete temp2;
		iCount--;
	}
}

template <class T>
void SinglyLL <T> :: Display()
{
	struct node<T> * temp = First;
	
	while(temp != NULL)
	{
		cout<<"| "<<temp->data<<" |->";
		temp = temp->next;
	}
	cout<<"NULL\n\n";
}

template <class T>
DoublyLL<T> :: DoublyLL()
{
	First = NULL;
	iCount = 0;
}

template <class T>
void DoublyLL<T> :: InsertFirst(T no)
{
	struct node<T>* newn = new struct node<T>;
	
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if(First == NULL)
	{
		First = newn;
		iCount++;
	}
	else
	{
		newn->next = First;
		First = newn;
		First->next->prev = First;
		iCount++;
	}
}

template <class T>
void DoublyLL<T> :: InsertLast(T no)
{
	struct node<T> * newn = new struct node<T>;
	
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if(First == NULL)
	{
		First = newn;
		iCount++;
	}
	else
	{
		struct node<T> *temp = First;
		
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		
		temp->next = newn;
		newn->prev = temp;
		iCount++;
	}
}

template <class T>
void DoublyLL<T> :: InsertAtPosition(T no,int ipos)
{
	
	if((ipos < 1) || (ipos > (iCount+1)))
	{
		cout<<"Invalid position\n";
		return;
	}
	
	if(ipos == 1)
	{
		InsertFirst(no);
	}
	else if(ipos == iCount+1)
	{
		InsertLast(no);
	}
	else
	{
		struct node<T> *newn = new struct node<T>;
		struct node<T> *temp = First;
	
		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;
		
		for(int iCnt = 1;iCnt < ipos -1; iCnt++)
		{
			temp = temp->next;
		}
		
		newn->next = temp->next;
		temp->next->prev = newn;
		newn->prev = temp;
		temp->next = newn;
		iCount++;
	}
}

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
	if(First == NULL)
	{
		return;
	}
	else
	{
		First = First->next;
		delete First->prev;
		First->prev = NULL;
		iCount--;
	}
}

template <class T>
void DoublyLL<T> :: DeleteLast()
{
	if(First == NULL)
	{
		return;
	}
	else if(First->next == NULL)
	{
		delete First;
		First = NULL;
	}
	else
	{
		struct node<T> *temp = First;
		
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		
		delete temp->next;
		temp->next = NULL;
		iCount--;
	}
}

template <class T>
void DoublyLL<T> :: DeleteAtPosition(int ipos)
{
	if((ipos < 1) || (ipos > (iCount + 1)))
	{
		cout<<"Invalid Position\n";
		return;
	}
	
	if(ipos == 1)
	{
		DeleteFirst();
	}
	else if(ipos == iCount)
	{
		DeleteLast();
	}
	else
	{
		struct node<T> *temp1 = First;
		struct node<T> *temp2 = NULL;
		
		for(int iCnt = 1;iCnt < ipos - 1; iCnt++)
		{
			temp1 = temp1->next;
		}
		
		temp2 = temp1->next;
		temp2->next->prev = temp1;
		temp1->next = temp2->next;
		delete temp2;
		iCount--;
	}
}

template <class T>
void DoublyLL<T> :: Display()
{
	struct node<T> * temp = First;
	
	cout<<"NULL<=>";
	while(temp != NULL)
	{
		cout<<"| "<<temp->data<<" |<=>";
		temp = temp->next;
	}
	cout<<"NULL\n\n";
}

template <class T>
SinglyCL<T> :: SinglyCL()
{
	First = NULL;
	Last = NULL;
	iCount = 0;
}

template <class T>
void SinglyCL<T> :: InsertFirst(T no)
{
	struct node<T> * newn = new struct node<T>;
	
	newn->data = no;
	newn->next = NULL;
	
	if(First == NULL && Last == NULL)
	{
		First = Last = newn;
		Last->next = First;
		iCount++;
	}
	else
	{
		newn->next = First;
		First = newn;
		Last->next = First;
		iCount++;
	}
}

template <class T>
void SinglyCL<T> :: InsertLast(T no)
{
	struct node<T> * newn = new struct node<T>;	
	
	newn->data = no;
	newn->next = NULL;
	
	if(First == NULL && Last == NULL)
	{
		First = Last = newn;
		Last->next = First;
		iCount++;	
	}
	else
	{	
		Last->next = newn;
		Last = newn;
		Last->next = First;
		iCount++;
	}
}

template <class T>
void SinglyCL<T> :: InsertAtPosition(T no,int ipos)
{
	if((ipos < 1) && (ipos > (iCount + 1)))
	{
		cout<<"Invalid Position/n";
		return;
	}
	
	if(ipos == 1)
	{
		InsertFirst(no);
	}
	else if(ipos == iCount + 1)
	{
		InsertLast(no);
	}
	else
	{
		struct node<T> * newn = new struct node<T>;
		struct node<T> * temp = First;
		
		newn->data = no;
		newn->next = NULL;
		
		for(int iCnt = 1;iCnt < ipos-1;iCnt++)
		{
			temp = temp->next;
		}
		
		newn->next = temp->next;
		temp->next = newn;
		iCount++;
	}
}

template <class T>
void SinglyCL<T> :: DeleteFirst()
{
	if(First == NULL && Last == NULL)
	{
		return;
	}
	else
	{
		First = First->next;
		delete Last->next;
		Last->next = First;
		iCount--;
	}
}

template <class T>
void SinglyCL<T> :: DeleteLast()
{
	if(First == NULL && Last == NULL)
	{
		return;
	}
	else if(First == Last)
	{
		delete First;
		First = NULL;
		Last = NULL;
	}
	else
	{
		struct node<T> * temp = First;
		
		while(temp->next != Last)
		{
			temp =temp->next;
		}
		Last = temp;
		delete Last->next;
		Last->next = First;
		iCount--;
	}
}

template <class T>
void SinglyCL<T> :: DeleteAtPosition(int ipos)
{
	if((ipos < 1) || (ipos > (iCount + 1)))
	{
		cout<<"Invalid Position\n";
		return;
	}
	
	if(ipos == 1)
	{
		DeleteFirst();
	}
	else if(ipos == iCount)
	{
		DeleteLast();
	}
	else
	{
		struct node<T> * temp1 = First;
		struct node<T> * temp2 = NULL;
		
		for(int iCnt = 1;iCnt < ipos-1;iCnt++)
		{
			temp1 = temp1->next;
		}
		temp2 = temp1->next;
		temp1->next = temp2->next;
		delete temp2;
		iCount--;
	}
}

template <class T>
void SinglyCL<T> :: Display()
{
	struct node<T> * temp = First;
	
	cout<<"->";
	do
	{
		cout<<"| "<<temp->data<<" |->";
		temp = temp->next;
	}while(temp != Last->next);
	cout<<"\n\n";
}




template <class T>
DoublyCL<T> :: DoublyCL()
{
	First = NULL;
	Last = NULL;
	iCount = 0;
}

template <class T>
void DoublyCL<T> :: InsertFirst(T no)
{
	struct node<T> *newn = new struct node<T>;
	
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if((First == NULL) && (Last == NULL))
	{
		First = Last = newn;
		iCount++;
	}
	else
	{
		newn->next = First;
		First = newn;
		Last->next = First;
		First->prev = Last;
		Last->prev = First;
		iCount++;
	}
}

template <class T>
void DoublyCL<T> :: InsertLast(T no)
{
	struct node<T> *newn = new struct node<T>;
	
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if((First == NULL) && (Last == NULL))
	{
		First = Last = newn;
		iCount++;
	}
	else
	{
		Last->next = newn;
		newn->prev = Last;
		newn->next = First;
		Last = newn;
		First->prev = Last;
		iCount++;
	}
}

template <class T>
void DoublyCL<T> :: InsertAtPosition(T no,int ipos)
{
	if((ipos < 1) || (ipos > (iCount + 1)))
	{
		cout<<"Invalid Position\n";
		return;
	}
	
	if(ipos == 1)
	{
		InsertFirst(no);
	}
	else if(ipos == iCount + 1)
	{
		InsertLast(no);
	}
	else
	{
		struct node<T> *newn = new struct node<T>;
		struct node<T> *temp = First;
		
		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;
		
		for(int iCnt = 1;iCnt < ipos - 1; iCnt++)
		{
			temp = temp->next;
		}
		
		newn->next = temp->next;
		temp->next = newn;
		newn->prev = temp;
		newn->next->prev = newn;
		iCount++;
	}
}

template <class T>
void DoublyCL<T> :: DeleteFirst()
{
	if((First == NULL) && (Last == NULL))
	{
		return;	
	}
	else
	{
		First = First->next;
		delete Last->next;
		First->prev = Last;
		Last->next = First;
		iCount--;	
	}	
}

template <class T>
void DoublyCL<T> :: DeleteLast()
{
	if((First == NULL) && (Last == NULL))
	{
		return;
	}
	else if((First->next == Last) && (Last->next == First))
	{
		delete First;
		First = NULL;
		Last = NULL;
		iCount--;
	}
	else
	{
		Last = Last->prev;
		delete First->prev;
		Last->next = First;
		First->prev = Last;
		iCount--;
	}
}

template <class T>
void DoublyCL<T> :: DeleteAtPosition(int ipos)
{
	if((ipos < 1) && (ipos > (iCount + 1)))
	{
		cout<<"Invalid Position\n";
		return;
	}
	
	if(ipos == 1)
	{
		DeleteFirst();
	}
	else if(ipos == iCount)
	{
		DeleteLast();
	}
	else
	{
		struct node<T> *temp1 = First;
		struct node<T> *temp2 = NULL;
		
		for(int iCnt = 1;iCnt < ipos-1; iCnt++)
		{
			temp1 = temp1->next;
		}
		
		temp2 = temp1->next;
		temp1->next = temp2->next;
		temp2->next->prev = temp1;
		delete temp2;
		iCount--;
	}
}

template <class T>
void DoublyCL<T> :: Display()
{
	struct node<T> *temp = First;
	
	cout<<"<=>";
	do
	{
		cout<<"| "<<temp->data<<" |<=>";
		temp = temp->next;
	}while(temp != Last->next);
	cout<<"\n\n";
}

template <class T>
Stack <T> :: Stack()
{
	First = NULL;
	iCount =  0;
}

template <class T>
void Stack <T> :: Push(T no)
{
	struct node<T> * newn = new struct node<T>;
	
	newn->data = no;
	newn->next = NULL;
	
	if(First == NULL)
	{
		First = newn;
		iCount++;
	}
	else
	{
		newn->next = First;
		First = newn;
		iCount++;
	}
}

template <class T>
void Stack<T> :: Pop()
{	
	if(First == NULL)
	{
		return;
	}
	else
	{
		struct node<T> * temp = First;
		First = First->next;
		delete temp;
		iCount--;
	}
}

template <class T>
void Stack <T> :: Display()
{
	struct node<T> * temp = First;
	
	while(temp != NULL)
	{
		cout<<"| "<<temp->data<<" |->";
		temp = temp->next;
	}
	cout<<"NULL\n\n";
}

template <class T>
Queue <T> :: Queue()
{
	First = NULL;
	iCount =  0;
}

template <class T>
void Queue <T> :: Enqueue(T no)
{
	struct node<T> * newn = new struct node<T>;
	struct node<T> * temp = First;
	
	newn->data = no;
	newn->next = NULL;
	
	if(First == NULL)
	{
		First = newn;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
		iCount++;
	}
}

template <class T>
void Queue<T> :: Dequeue()
{	
	if(First == NULL)
	{
		return;
	}
	else
	{
		struct node<T> * temp = First;
		First = First->next;
		delete temp;
		iCount--;
	}
}

template <class T>
void Queue <T> :: Display()
{
	struct node<T> * temp = First;
	
	while(temp != NULL)
	{
		cout<<"| "<<temp->data<<" |->";
		temp = temp->next;
	}
	cout<<"NULL\n\n";
}

int main()
{
    string str =" ";
	char cTer = ' ';
    int no = 0,select = 0,iChoice = 0,iNo = 0,iPos = 0;
	float fNo = 0.0;
	double dNo = 0.000;
	char c = '\0';    
    cout<<"......Welcome to C++ Customized Standard Template Library.......\n\n";

    while(1)
    {
		printf("-------------------------------------------------------------------\n");
		
		printf("Which linked list you want to use : -\n\n");
		printf("1 : Singly Linear Linked List\n");
		printf("2 : Singly Circular Linked List\n");
		printf("3 : Doubly Linear Linked List\n");
		printf("4 : Doubly Circular Linked List\n");
		printf("5 : Stack\n");
		printf("6 : Queue\n");
		printf("7 : Exit\n"); 
		scanf("%d",&iChoice);

		if(iChoice == 7)
		{
			break;
		}

		printf("Select the datatype for the linked list: -\n\n");
		printf("1 : Integer\n");
		printf("2 : Float\n");
		printf("3 : Double\n");
		printf("4 : Character\n");
		printf("5 : Exit\n");
		cin>>select; 
		
/////////////////////////////////////////////////////////////////

		SinglyLL<int>*iobj = new SinglyLL<int>();

		SinglyLL<float> *fobj = new SinglyLL<float>();
			
		SinglyLL<double> *dobj = new SinglyLL<double>();
			
		SinglyLL<char> *cobj = new SinglyLL<char>();
///////////////////////////////////////////////////////////////////

		SinglyCL <int> *isobj = new SinglyCL<int>();

		SinglyCL <float> *fsobj = new SinglyCL<float>();

		SinglyCL <double> *dsobj = new SinglyCL<double>();

		SinglyCL <char> *csobj = new SinglyCL<char>();

///////////////////////////////////////////////////////////////////
		
		DoublyLL <int> *idobj = new DoublyLL<int>();

		DoublyLL <float> *fdobj = new DoublyLL<float>();

		DoublyLL <double> *ddobj = new DoublyLL<double>();

		DoublyLL <char> *cdobj = new DoublyLL<char>();

///////////////////////////////////////////////////////////////////

		DoublyCL <int> *dcobj = new DoublyCL<int>();

		DoublyCL <float> *fdcobj = new DoublyCL<float>();

		DoublyCL <double> *ddcobj = new DoublyCL<double>();

		DoublyCL <char> *cdcobj = new DoublyCL<char>();

///////////////////////////////////////////////////////////////////

		Stack <int> *siobj = new Stack<int>();

		Stack <float> *sfobj = new Stack<float>();

		Stack <double> *sdobj = new Stack<double>();

		Stack <char> *scobj = new Stack<char>();

///////////////////////////////////////////////////////////////////

		Queue <int> *qiobj = new Queue<int>();

		Queue <float> *qfobj = new Queue<float>();

		Queue <double> *qdobj = new Queue<double>();

		Queue <char> *qcobj = new Queue<char>();

//////////////////////////////////////////////////////////////////

		switch(iChoice)
		{
			case 1: 
			
				while(1)
				{
					printf("Please choose the operation to perform\n\n");
					printf("1 : Insert new node at first position\n");
					printf("2 : Insert new node at last position\n");
					printf("3 : Insert node at given position\n");
					printf("4 : Delete node from first position\n");
					printf("5 : Delete node from last position\n"); 
					printf("6 : Delete node from given position\n");
					printf("7 : Display and count node from given position\n");
					printf("8 : Go back to linked list menu\n");
					
					cin>>no;

					if(no == 1)
					{
						if(select == 1)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>iNo;
							iobj->InsertFirst(iNo);
						}
						else if(select == 2)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>fNo;
							fobj->InsertFirst(fNo);
						}
						else if(select == 3)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>dNo;
							dobj->InsertFirst(dNo);
						}
						else if(select == 4)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>c;
							cobj->InsertFirst(c);
						}
					}
					else if(no == 2)
					{	
						if(select == 1)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>iNo;
				
							iobj->InsertLast(iNo);
						}
						else if(select == 2)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>fNo;
				
							fobj->InsertLast(fNo);
						}
						else if(select == 3)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>dNo;
				
							dobj->InsertLast(dNo);
						}
						else if(select == 4)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>c;
				
							cobj->InsertLast(c);
						}
					}
					else if(no == 3)
					{
						if(select == 1)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>iNo;
							cout<<"Enter the position where you want to insert the data : \n";
							cin>>iPos;
				
							iobj->InsertAtPosition(iNo,iPos);
						}
						else if(select == 2)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>fNo;
							cout<<"Enter the position where you want to insert the data : \n";
							cin>>iPos;
				
							fobj->InsertAtPosition(fNo,iPos);
						}
						else if(select == 3)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>dNo;
							cout<<"Enter the position where you want to insert the data : \n";
							cin>>iPos;
				
							dobj->InsertAtPosition(dNo,iPos);
						}
						else if(select == 4)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>c;
							cout<<"Enter the position where you want to insert the data : \n";
							cin>>iPos;
				
							cobj->InsertAtPosition(c,iPos);
						}	
					}
					else if(no == 4)
					{
						if(select == 1)
						{
							iobj->DeleteFirst();
						}
						else if(select == 2)
						{
							fobj->DeleteFirst();
						}
						else if(select == 3)
						{
							dobj->DeleteFirst();
						}
						else if(select == 4)
						{
							cobj->DeleteFirst();
						}	
					}
					else if(no == 5)
					{
						if(select == 1)
						{
							iobj->DeleteLast();
						}
						else if(select == 2)
						{
							fobj->DeleteLast();
						}
						else if(select == 3)
						{
							dobj->DeleteLast();
						}
						else if(select == 4)
						{
							cobj->DeleteLast();
						}
					}
					else if(no == 6)
					{
						if(select == 1)
						{
							cout<<"Enter the poition of node to delete:- \n";
							cin>>iPos;

							iobj->DeleteAtPosition(iPos);
						}
						else if(select == 2)
						{
							cout<<"Enter the poition of node to delete:- \n";
							cin>>iPos;

							fobj->DeleteAtPosition(iPos);
						}
						else if(select == 3)
						{
							cout<<"Enter the poition of node to delete:- \n";
							cin>>iPos;

							dobj->DeleteAtPosition(iPos);
						}
						else if(select == 4)
						{
							cout<<"Enter the poition of node to delete:- \n";
							cin>>iPos;

							cobj->DeleteAtPosition(iPos);
						}
					}
					else if(no == 7)
					{
						if(select == 1)
						{
							iobj->Display();
							cout<<"Number of nodes in the linked list : "<<iobj->iCount<<"\n";

						}
						else if(select == 2)
						{
							fobj->Display();
							cout<<"Number of nodes in the linked list : "<<fobj->iCount<<"\n";

						}
						else if(select == 3)
						{
							dobj->Display();
							cout<<"Number of nodes in the linked list : "<<dobj->iCount<<"\n";

						}
						else if(select == 4)
						{
							cobj->Display();
							cout<<"Number of nodes in the linked list : "<<cobj->iCount<<"\n";

						}
					}
					else if(no == 8)
					{
						if(select == 1)
						{
							delete iobj;
						}
						else if(select == 2)
						{
							delete fobj;

						}
						else if(select == 3)
						{
							delete dobj;
						}
						else if(select == 4)
						{
							delete cobj;
						}
						
						break;
					}	
				}
				break;
			case 2: 
				
				while(1)
				{
					printf("Please choose the operation to perform\n\n");
					printf("1 : Insert new node at first position\n");
					printf("2 : Insert new node at last position\n");
					printf("3 : Insert node at given position\n");
					printf("4 : Delete node from first position\n");
					printf("5 : Delete node from last position\n"); 
					printf("6 : Delete node from given position\n");
					printf("7 : Display and count node from given position\n");
					printf("8 : Go back to linked list menu\n");
					
					cin>>no;

					if(no == 1)
					{
						if(select == 1)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>iNo;
							isobj->InsertFirst(iNo);
						}
						else if(select == 2)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>fNo;
							fsobj->InsertFirst(fNo);
						}
						else if(select == 3)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>dNo;
							dsobj->InsertFirst(dNo);
						}
						else if(select == 4)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>c;
							csobj->InsertFirst(c);
						}
					}
					else if(no == 2)
					{	
						if(select == 1)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>iNo;
				
							isobj->InsertLast(iNo);
						}
						else if(select == 2)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>fNo;
				
							fsobj->InsertLast(fNo);
						}
						else if(select == 3)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>dNo;
				
							dsobj->InsertLast(dNo);
						}
						else if(select == 4)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>c;
				
							csobj->InsertLast(c);
						}
					}
					else if(no == 3)
					{
						if(select == 1)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>iNo;
							cout<<"Enter the position where you want to insert the data : \n";
							cin>>iPos;
				
							isobj->InsertAtPosition(iNo,iPos);
						}
						else if(select == 2)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>fNo;
							cout<<"Enter the position where you want to insert the data : \n";
							cin>>iPos;
				
							fsobj->InsertAtPosition(fNo,iPos);
						}
						else if(select == 3)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>dNo;
							cout<<"Enter the position where you want to insert the data : \n";
							cin>>iPos;
				
							dsobj->InsertAtPosition(dNo,iPos);
						}
						else if(select == 4)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>c;
							cout<<"Enter the position where you want to insert the data : \n";
							cin>>iPos;
				
							csobj->InsertAtPosition(c,iPos);
						}	
					}
					else if(no == 4)
					{
						if(select == 1)
						{
							isobj->DeleteFirst();
						}
						else if(select == 2)
						{
							fsobj->DeleteFirst();
						}
						else if(select == 3)
						{
							dsobj->DeleteFirst();
						}
						else if(select == 4)
						{
							csobj->DeleteFirst();
						}	
					}
					else if(no == 5)
					{
						if(select == 1)
						{
							isobj->DeleteLast();
						}
						else if(select == 2)
						{
							fsobj->DeleteLast();
						}
						else if(select == 3)
						{
							dsobj->DeleteLast();
						}
						else if(select == 4)
						{
							csobj->DeleteLast();
						}	
					}
					else if(no == 6)
					{
						if(select == 1)
						{
							cout<<"Enter the poition of node to delete:- \n";
							cin>>iPos;

							isobj->DeleteAtPosition(iPos);
						}
						else if(select == 2)
						{
							cout<<"Enter the poition of node to delete:- \n";
							cin>>iPos;

							fsobj->DeleteAtPosition(iPos);
						}
						else if(select == 3)
						{
							cout<<"Enter the poition of node to delete:- \n";
							cin>>iPos;

							dsobj->DeleteAtPosition(iPos);
						}
						else if(select == 4)
						{
							cout<<"Enter the poition of node to delete:- \n";
							cin>>iPos;

							csobj->DeleteAtPosition(iPos);
						}
					}
					else if(no == 7)
					{
						if(select == 1)
						{
							isobj->Display();
							cout<<"Number of nodes in the linked list : "<<isobj->iCount<<"\n";
						}
						else if(select == 2)
						{
							fsobj->Display();
							cout<<"Number of nodes in the linked list : "<<fsobj->iCount<<"\n";
						}
						else if(select == 3)
						{
							dsobj->Display();
							cout<<"Number of nodes in the linked list : "<<dsobj->iCount<<"\n";
						}
						else if(select == 4)
						{
							csobj->Display();
							cout<<"Number of nodes in the linked list : "<<csobj->iCount<<"\n";

						}
					}
					else if(no == 8)
					{
						if(select == 1)
						{
							delete isobj;

						}
						else if(select == 2)
						{
							delete fsobj;

						}
						else if(select == 3)
						{
							delete dsobj;
						}
						else if(select == 4)
						{
							delete csobj;
						}
						break;
					}
					
				}
				break;

			case 3:

				while(1)
				{
					printf("Please choose the operation to perform\n\n");
					printf("1 : Insert new node at first position\n");
					printf("2 : Insert new node at last position\n");
					printf("3 : Insert node at given position\n");
					printf("4 : Delete node from first position\n");
					printf("5 : Delete node from last position\n"); 
					printf("6 : Delete node from given position\n");
					printf("7 : Display and count node from given position\n");
					printf("8 : Go back to linked list menu\n");
					
					cin>>no;

					if(no == 1)
					{
						if(select == 1)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>iNo;
							idobj->InsertFirst(iNo);
						}
						else if(select == 2)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>fNo;
							fdobj->InsertFirst(fNo);
						}
						else if(select == 3)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>dNo;
							ddobj->InsertFirst(dNo);
						}
						else if(select == 4)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>c;
							cdobj->InsertFirst(c);
						}
					}
					else if(no == 2)
					{	
						if(select == 1)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>iNo;
				
							idobj->InsertLast(iNo);
						}
						else if(select == 2)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>fNo;
				
							fdobj->InsertLast(fNo);
						}
						else if(select == 3)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>dNo;
				
							ddobj->InsertLast(dNo);
						}
						else if(select == 4)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>c;
				
							cdobj->InsertLast(c);
						}	
					}
					else if(no == 3)
					{
						if(select == 1)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>iNo;
							cout<<"Enter the position where you want to insert the data : \n";
							cin>>iPos;
				
							idobj->InsertAtPosition(iNo,iPos);
						}
						else if(select == 2)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>fNo;
							cout<<"Enter the position where you want to insert the data : \n";
							cin>>iPos;
				
							fdobj->InsertAtPosition(fNo,iPos);
						}
						else if(select == 3)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>dNo;
							cout<<"Enter the position where you want to insert the data : \n";
							cin>>iPos;
				
							ddobj->InsertAtPosition(dNo,iPos);
						}
						else if(select == 4)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>c;
							cout<<"Enter the position where you want to insert the data : \n";
							cin>>iPos;
				
							cdobj->InsertAtPosition(c,iPos);
						}
					}
					else if(no == 4)
					{
						if(select == 1)
						{
							idobj->DeleteFirst();
						}
						else if(select == 2)
						{
							fdobj->DeleteFirst();
						}
						else if(select == 3)
						{
							ddobj->DeleteFirst();
						}
						else if(select == 4)
						{
							cdobj->DeleteFirst();
						}	
					}
					else if(no == 5)
					{
						if(select == 1)
						{
							idobj->DeleteLast();
						}
						else if(select == 2)
						{
							fdobj->DeleteLast();
						}
						else if(select == 3)
						{
							ddobj->DeleteLast();
						}
						else if(select == 4)
						{
							cdobj->DeleteLast();
						}	
					}
					else if(no == 6)
					{
						if(select == 1)
						{
							cout<<"Enter the poition of node to delete:- \n";
							cin>>iPos;

							idobj->DeleteAtPosition(iPos);
						}
						else if(select == 2)
						{
							cout<<"Enter the poition of node to delete:- \n";
							cin>>iPos;

							fdobj->DeleteAtPosition(iPos);
						}
						else if(select == 3)
						{
							cout<<"Enter the poition of node to delete:- \n";
							cin>>iPos;

							ddobj->DeleteAtPosition(iPos);
						}
						else if(select == 4)
						{
							cout<<"Enter the poition of node to delete:- \n";
							cin>>iPos;

							cdobj->DeleteAtPosition(iPos);
						}
					}
					else if(no == 7)
					{
						if(select == 1)
						{
							idobj->Display();
							cout<<"Number of nodes in the linked list : "<<idobj->iCount<<"\n";
						}
						else if(select == 2)
						{
							fdobj->Display();
							cout<<"Number of nodes in the linked list : "<<fdobj->iCount<<"\n";
						}
						else if(select == 3)
						{
							ddobj->Display();
							cout<<"Number of nodes in the linked list : "<<ddobj->iCount<<"\n";
						}
						else if(select == 4)
						{
							cdobj->Display();
							cout<<"Number of nodes in the linked list : "<<cdobj->iCount<<"\n";
						}
					}
					else if(no == 8)
					{
						if(select == 1)
						{
							delete idobj;
						}
						else if(select == 2)
						{
							delete fdobj;
						}
						else if(select == 3)
						{
							delete ddobj;
						}
						else if(select == 4)
						{
							delete cdobj;
						}
						break;
					}
					
				}
				break;

			case 4:

				while(1)
				{
					printf("Please choose the operation to perform\n\n");
					printf("1 : Insert new node at first position\n");
					printf("2 : Insert new node at last position\n");
					printf("3 : Insert node at given position\n");
					printf("4 : Delete node from first position\n");
					printf("5 : Delete node from last position\n"); 
					printf("6 : Delete node from given position\n");
					printf("7 : Display and count node from given position\n");
					printf("8 : Go back to linked list menu\n");
					
					cin>>no;

					if(no == 1)
					{
						if(select == 1)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>iNo;
							dcobj->InsertFirst(iNo);
						}
						else if(select == 2)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>fNo;
							fdcobj->InsertFirst(fNo);
						}
						else if(select == 3)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>dNo;
							ddcobj->InsertFirst(dNo);
						}
						else if(select == 4)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>c;
							cdcobj->InsertFirst(c);
						}
					}
					else if(no == 2)
					{	
						if(select == 1)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>iNo;
				
							dcobj->InsertLast(iNo);
						}
						else if(select == 2)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>fNo;
				
							fdcobj->InsertLast(fNo);
						}
						else if(select == 3)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>dNo;
				
							ddcobj->InsertLast(dNo);
						}
						else if(select == 4)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>c;
				
							cdcobj->InsertLast(c);
						}
					}
					else if(no == 3)
					{
						if(select == 1)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>iNo;
							cout<<"Enter the position where you want to insert the data : \n";
							cin>>iPos;
				
							dcobj->InsertAtPosition(iNo,iPos);
						}
						else if(select == 2)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>fNo;
							cout<<"Enter the position where you want to insert the data : \n";
							cin>>iPos;
				
							fdcobj->InsertAtPosition(fNo,iPos);
						}
						else if(select == 3)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>dNo;
							cout<<"Enter the position where you want to insert the data : \n";
							cin>>iPos;
				
							ddcobj->InsertAtPosition(dNo,iPos);
						}
						else if(select == 4)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>c;
							cout<<"Enter the position where you want to insert the data : \n";
							cin>>iPos;
				
							cdcobj->InsertAtPosition(c,iPos);
						}
					}
					else if(no == 4)
					{
				
						if(select == 1)
						{
							dcobj->DeleteFirst();
						}
						else if(select == 2)
						{
							fdcobj->DeleteFirst();
						}
						else if(select == 3)
						{
							ddcobj->DeleteFirst();
						}
						else if(select == 4)
						{
							cdcobj->DeleteFirst();
						}	
					}
					else if(no == 5)
					{
						if(select == 1)
						{
							dcobj->DeleteLast();
						}
						else if(select == 2)
						{
							fdcobj->DeleteLast();
						}
						else if(select == 3)
						{
							ddcobj->DeleteLast();
						}
						else if(select == 4)
						{
							cdcobj->DeleteLast();
						}
					}
					else if(no == 6)
					{
						if(select == 1)
						{
							cout<<"Enter the poition of node to delete:- \n";
							cin>>iPos;

							dcobj->DeleteAtPosition(iPos);
						}
						else if(select == 2)
						{
							cout<<"Enter the poition of node to delete:- \n";
							cin>>iPos;

							fdcobj->DeleteAtPosition(iPos);
						}
						else if(select == 3)
						{
							cout<<"Enter the poition of node to delete:- \n";
							cin>>iPos;

							ddcobj->DeleteAtPosition(iPos);
						}
						else if(select == 4)
						{
							cout<<"Enter the poition of node to delete:- \n";
							cin>>iPos;

							cdcobj->DeleteAtPosition(iPos);
						}
					}
					else if(no == 7)
					{
						if(select == 1)
						{
							dcobj->Display();
							cout<<"Number of nodes in the linked list : "<<dcobj->iCount<<"\n";
						}
						else if(select == 2)
						{
							fdcobj->Display();
							cout<<"Number of nodes in the linked list : "<<fdcobj->iCount<<"\n";
						}
						else if(select == 3)
						{
							ddcobj->Display();
							cout<<"Number of nodes in the linked list : "<<ddcobj->iCount<<"\n";
						}
						else if(select == 4)
						{
							cdcobj->Display();
							cout<<"Number of nodes in the linked list : "<<cdcobj->iCount<<"\n";
						}
					}
					else if(no == 8)
					{
						if(select == 1)
						{
							delete dcobj;
						}
						else if(select == 2)
						{
							delete fdcobj;
						}
						else if(select == 3)
						{
							delete ddcobj;
						}
						else if(select == 4)
						{
							delete cdcobj;
						}
						break;
					}
					
				}
				break;
			
			case 5:

				while(1)
				{
					printf("Please choose the operation to perform\n\n");
					printf("1 : Insert new node at first position\n");
					printf("2 : Delete node from first position\n");
					printf("3 : Display and count node from given position\n");
					printf("4 : Go back to linked list menu\n");
					
					cin>>no;

					if(no == 1)
					{
						if(select == 1)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>iNo;
							siobj->Push(iNo);
						}
						else if(select == 2)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>fNo;
							sfobj->Push(fNo);
						}
						else if(select == 3)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>dNo;
							sdobj->Push(dNo);
						}
						else if(select == 4)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>c;
							scobj->Push(c);
						}
					}
					
					
					else if(no == 2)
					{
				
						if(select == 1)
						{
							siobj->Pop();
						}
						else if(select == 2)
						{
							sfobj->Pop();
						}
						else if(select == 3)
						{
							sdobj->Pop();
						}
						else if(select == 4)
						{
							scobj->Pop();
						}	
					}
					
					else if(no == 3)
					{
						if(select == 1)
						{
							siobj->Display();
							cout<<"Number of nodes in the linked list : "<<siobj->iCount<<"\n";
						}
						else if(select == 2)
						{
							sfobj->Display();
							cout<<"Number of nodes in the linked list : "<<sfobj->iCount<<"\n";
						}
						else if(select == 3)
						{
							sdobj->Display();
							cout<<"Number of nodes in the linked list : "<<sdobj->iCount<<"\n";
						}
						else if(select == 4)
						{
							scobj->Display();
							cout<<"Number of nodes in the linked list : "<<scobj->iCount<<"\n";
						}
					}
					else if(no == 4)
					{
						if(select == 1)
						{
							delete siobj;

						}
						else if(select == 2)
						{
							delete sfobj;

						}
						else if(select == 3)
						{
							delete sdobj;
						}
						else if(select == 4)
						{
							delete scobj;
						}
						break;
					}
					
				}
				break;
		
			case 6:

				while(1)
				{
					printf("Please choose the operation to perform\n\n");
					printf("1 : Insert new node at last position\n");
					printf("2 : Delete node from first position\n");
					printf("3 : Display and count node from given position\n");
					printf("4 : Go back to linked list menu\n");
					
					cin>>no;

					if(no == 1)
					{	
						if(select == 1)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>iNo;
				
							qiobj->Enqueue(iNo);
						}
						else if(select == 2)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>fNo;
				
							qfobj->Enqueue(fNo);
						}
						else if(select == 3)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>dNo;
				
							qdobj->Enqueue(dNo);
						}
						else if(select == 4)
						{
							cout<<"Enter the data that you want to insert : \n";
							cin>>c;
				
							qcobj->Enqueue(c);
						}
					}
					else if(no == 2)
					{
				
						if(select == 1)
						{
							qiobj->Dequeue();
						}
						else if(select == 2)
						{
							qfobj->Dequeue();
						}
						else if(select == 3)
						{
							qdobj->Dequeue();
						}
						else if(select == 4)
						{
							qcobj->Dequeue();
						}	
					}
					else if(no == 3)
					{
						if(select == 1)
						{
							qiobj->Display();
							cout<<"Number of nodes in the linked list : "<<qiobj->iCount<<"\n";
						}
						else if(select == 2)
						{
							qfobj->Display();
							cout<<"Number of nodes in the linked list : "<<qfobj->iCount<<"\n";
						}
						else if(select == 3)
						{
							qdobj->Display();
							cout<<"Number of nodes in the linked list : "<<qdobj->iCount<<"\n";
						}
						else if(select == 4)
						{
							qcobj->Display();
							cout<<"Number of nodes in the linked list : "<<qcobj->iCount<<"\n";
						}
					}
					else if(no == 4)
					{
						if(select == 1)
						{
							delete qiobj;
						}
						else if(select == 2)
						{
							delete qfobj;
						}
						else if(select == 3)
						{
							delete qdobj;
						}
						else if(select == 4)
						{
							delete qcobj;
						}
						break;
					}
					
				}
				break;
		}
		printf("-------------------------------------------------------------------\n");
	}	
	return 0;
}
