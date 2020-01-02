
#include<iostream>
#include<string>
using namespace std;
class word
{
 public:
 		 string name;
		 string meaning;
		 word*next;
		 word(string a,string n,word*w=NULL)
		 {
		  name=a;
		  meaning=n;
		  next=w;
		 }
		 
};
class dictionary
{
 word* head,*tail;
 public:
        dictionary()
		{
		 head=tail=NULL;
		}
		bool isempty();
		void display();
		void deletion();
		void insert(string,string);
		void addtohead(string,string);
		void addtotail(string,string);
		void search();
};
void dictionary::search()
{ 
 string sname;
 word* temp;
 cout<<"\nEnter the name you wish to search"<<endl;
 cin>>sname;
 for(temp=head;temp!=NULL;temp=temp->next)
 {
  if(temp->name==sname)
  {
   cout<<"\nWORD: "<<temp->name<<"\nMEANING"<<temp->meaning<<endl;
  }
  if(temp==NULL)
   cout<<"\nThe name "<<sname<<" does not exist in the dictionary."<<endl;
 }
}
void dictionary::deletion()
{
 if(head==NULL)
  cout<<"\nThere is no contact in the directory";
 else
 {
  word*temp,*temp1;
  string del;
  cout<<"\nEnter the word you wish to delete"<<endl;
  cin>>del;
  if(head->name==del)
  {
   temp1=head;
   head=NULL;
   delete temp1;
  }
  else
  {
   for(temp=head;temp->next->next!=NULL && temp->next->name!=del;temp=temp->next);
   if(temp->next->name==del)
   {
    temp1=temp->next;
	temp->next=temp1->next;
	delete temp1;
   }
   else
    cout<<"\nThe word "<<del<<" not found in the dictionaryy"<<endl;
  }
 }
}
void dictionary::insert(string n, string x)
{
 word* c=new word(n,x,NULL);
 word*temp,*temp1;
 if(head==NULL)
   addtohead(n,x);
 else
  if((head->name>=c->name))
   addtohead(n,x);
  else if((tail->name<c->name))
   addtotail(n,x);
  else
  {
   for(temp=head;temp->next->next!=NULL && ((temp->next->name)<=(c->name));temp=temp->next);
   if((temp->next->name)>(c->name))
   {
    c->next=temp->next;
	temp->next=c;
   }
  }
}
void dictionary::display()
{
 word*temp;
 for(temp=head;temp!=NULL;temp=temp->next)
 {
  cout<<"\nWORD:"<<temp->name<<"\nMEANING: "<<temp->meaning<<endl;
 }
}
void dictionary::addtohead(string n,string x)
{
 word*c=new word(n,x,NULL);
 if(head==NULL)
  tail=head=c;
 else
 {
  c->next=head;
  head=c;
 }
}
void dictionary::addtotail(string n,string x)
{
 word*c=new word(n,x,NULL);
 if(tail==NULL)
  tail=head=c;
 else
 {
  tail->next=c;
  tail=c;
 }
}
int main()
{; 
 dictionary d;
 int choice;
 string n;
 char ch='y';
 string name;
 word* nptr;
 while(ch=='y' || ch=='Y')
 {
  cout<<"\nMAIN MENU"
      <<"\n1.Add new word"
	  <<"\n2.Delete existing word"
	  <<"\n3.Display all the words"
	  <<"\n4.Search for a word"
	  <<"\nEnter choice(1-4)"<<endl;
  cin>>choice;
  switch(choice)
  {
   case 1:cout<<"\nEnter the word"<<endl;
          cin>>name;
		  cout<<"\nEnter its meaning"<<endl;
		  cin>>n;
		  d.insert(name,n);
		  break;
   case 2:d.deletion();
		  break;
   case 3:d.display();
          break;
   case 4:d.search();
          break;
   default:cout<<"\nINVALID CHOICE"<<endl;
           break;
  }
  cout<<"\nDo you wish to continue?(y/n)"<<endl;
  cin>>ch;
 }
 return 0;
}
 
 

   

