//PLEASE READ THE README FILE IF YOUR ANIMATIONS ARE NOT WORKING
//strings with spaces cannot be added
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>

using namespace std;
//BOOK NODE
struct b_node
{
    char b_name[70];
    char b_id[5];
    char b_genre[30];
    char b_author[60];
    double price;
    int edition;
    int total_qty;
    int qty_left;
    int times;

    b_node * next;
}p;

//BOOK CLASS
class book
{
    b_node * head;
    b_node * tail;
    public:
        book()
        {
            head=NULL;
            tail=NULL;
        }

        void add_book();
        void update_b_details();
        void remove_book();
        void display();
        void times_initialize();
        void edit_detail();
        //void reissue();
        void b_return();
        void issue();
     void count_books();
        b_node * srch(char arr[5]);
        b_node * reverse_ll(/*b_node * head--- if this is made as a non-class function*/);

        //void  recommend_book(head);
}b;

//COUNT NO. OF BOOKS
void book::count_books(){
        struct b_node *newnode = head;
            struct b_node *temp = head;
int cn=0;
        while(temp!=NULL){
            temp=temp->next;
            cn++;
        }
        cout<<"                            the number of books in the library are :"<<cn;

}
//DISPLAY ALL BOOKS
void book::display()
{
    struct b_node *newnode = head;
    if(head==NULL){
        cout<<"------------------------------------------------------------------------------------------"<<endl;
        cout<<"                                              NO BOOKS!!"<<endl;
        cout<<"------------------------------------------------------------------------------------------"<<endl;
    }
    else
    {
        while(newnode!=NULL)
        {
            cout<<"                                       BOOK NAME  :"<<newnode->b_name<<endl;
            cout<<"                                       BOOK ID :"<<newnode->b_id<<endl;
            cout<<"                                       BOOK GENRE :"<<newnode->b_genre<<endl;
            cout<<"                                       BOOK AUTHOR  :"<<newnode->b_author<<endl;
            cout<<"                                       PRICE OF THE BOOK  :"<<newnode->price<<endl;
            cout<<"                                       BOOK EDITION :"<<newnode->edition<<endl;
            cout<<"                                       QUANTITY OF THE BOOK :"<<newnode-> total_qty<<endl;
            cout<<"                                       QUANTITY LEFT IS : "<<newnode->qty_left<<endl;
            newnode=newnode->next;
        }
    }
}
//ADD BOOK
void book::add_book()
{
    int i =1;
    struct b_node *newnode;
    newnode= new b_node ;
    cout<<"                                       Enter book name ";
    cin>>newnode->b_name;
    cout<<"                                       Enter book ID ";
    cin>>newnode->b_id;
    cout<<"                                       Enter book genre ";
    cin>>newnode->b_genre;
    cout<<"                                       Enter book author";
    cin>>newnode->b_author;
    cout<<"                                       Enter price of the book ";
    cin>> newnode->price;
    cout<<"                                       Enter book edition ";
    cin>>newnode->edition;
    cout<<"                                       Enter quantity of the book ";
    cin>>newnode-> total_qty;

    //printf(“Number of books left”);
    // to be or not to be taken by the user!
    //newnode->times = 0;
    newnode->qty_left=newnode->total_qty;
    newnode->next=NULL;
    newnode->times=0;
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
    }
    cout<<"                                       NODE ADDED!!";
    cout<<"                                   \nLet us visualize insertion between a linked list\nPress enter...\n";
    getche();

    //Open new window
    initwindow(2000,2000,"Insertion");
    //Animation code
    while(i < 3)
    {
        readimagefile("frame_0_delay-1.5s.gif",10,10,1024,768);
        delay(1500);
        readimagefile("frame_1_delay-1.5s.gif",10,10,1024,768);
        delay(1500);
        readimagefile("frame_2_delay-1.5s.gif",10,10,1024,768);
        delay(1500);
        readimagefile("frame_3_delay-1.5s.gif",10,10,1024,768);
        delay(1500);
        readimagefile("frame_4_delay-1.5s.gif",10,10,1024,768);
        delay(1500);
        readimagefile("frame_5_delay-1.5s.gif",10,10,1024,768);
        delay(1500);
        i++;
    }
    closegraph();

}
//REMOVE BOOK---TO BE REVIEWED
void book::remove_book()
{
    int i = 1;
    char book_id[5];

    cout<<"Enter book_id:";
    cin>>book_id;

    b_node * ptr;
    ptr = new b_node;
    ptr= srch(book_id);
    struct b_node *temp;
    struct b_node *save ;
    temp=head;

    if(ptr==NULL)
        cout<<"cannot delete \n";

    else if(ptr==head)
        {
            head=head->next;
            if(ptr==tail)
                tail=head;
            delete ptr;
            cout<<"                                                 Book deleted ";
        }
     else
        {
            while(temp!=ptr)
                {
                    save =temp;
                    temp=temp->next;
                }
            save->next = ptr->next ;
            if(ptr->next==NULL)
                tail =save;
            delete ptr;
        }

     cout<<"\n                                                         Let us visualize deletion of a given node\nPress enter...\n";
     getche();
     //Open new window
     initwindow(2000,2000,"Insertion");
     //Animation code
     while(i < 3)
     {
        readimagefile("frame_1_delay-1.5s (2).gif",10,10,1024,768);
        delay(1500);
        readimagefile("frame_2_delay-1.5s (2).gif",10,10,1024,768);
        delay(1500);
        readimagefile("frame_3_delay-1.5s (2).gif",10,10,1024,768);
        delay(1500);
        readimagefile("frame_4_delay-1.5s (2).gif",10,10,1024,768);
        delay(1500);
        readimagefile("frame_5_delay-1.5s (2).gif",10,10,1024,768);
        delay(1500);
        readimagefile("frame_6_delay-1.5s.gif",10,10,1024,768);
        delay(1500);
        readimagefile("frame_7_delay-1.5s.gif",10,10,1024,768);
        delay(1500);
        readimagefile("frame_8_delay-1.5s.gif",10,10,1024,768);
        delay(1500);

        i++;
     }
     closegraph();


}//review this

//void book :: times_initialize()
//{
//    times = 0;
//}

/*void book :: reissue()
{
    char book_id[5];
    cout<<"                                      Enter book ID";
    cin>>book_id;
   struct b_node *ptr = srch(book_id);
    if(ptr->times < 3)
         ptr->times++;
    else
         cout<<"                                 Book cannot be reissued!";
}*/

//EDIT DETAILS
void book :: edit_detail()
{
      char book_id[5];
      cout<<"                                         Enter book_id to edit details";
      cin>>book_id;
      int choice;

      b_node * ptr;
      ptr= srch(book_id);

      if(ptr == NULL)
        cout<<"\nERROR: No Book in the database\n";

      else
      {   cout<<"              ENTER CHOICE\n";
          cout<<"            1.Book name \n";
          cout<<"            2.Book Id\n";
          cout<<"            3.Book Genre \n";
          cout<<"            4.Book Author\n";
          cout<<"            5.Price\n";
          cout<<"            6.Book Edition\n";
          cout<<"            7.Total Quantity";


          cin>>choice;

          switch(choice)
          {
              case 1:
                    cout<<"                                  Enter the book_name";
                    cin>>ptr->b_name;
                    break;

              case 2:
                    cout<<"                                  Enter the book_id";
                    cin>>ptr->b_id;
                    break;

              case 3:
                    cout<<"                                  Enter the book_genre";
                    cin>>ptr->b_genre;
                    break;

              case 4:
                    cout<<"                                  Enter the book_author";
                    cin>>ptr->b_author;
                    break;

              case 5:
                    cout<<"                                  Enter the price of book";
                    cin>>ptr->price;
                    break;

              case 6:
                    cout<<"                                  Enter the book_edition";
                    cin>>ptr->edition;
                    break;

              case 7:
                    cout<<"                                  Enter the total quantity";
                    cin>>ptr->total_qty;
                    ptr->qty_left  = ptr->total_qty;
                    break;

              default:
                    cout<<"invalid choice!!";
                    break;

            }
    }
}

//SEARCHING
b_node *book:: srch(char arr[5])
{
    b_node * temp = head;
    while (temp != NULL)
    {
        if (!strcmp(temp->b_id,arr))
        {
            return temp;
        }
        temp = temp->next;
    }
   return NULL;
}

void book :: issue()
{   char book_id[5];
    cout<<"                                        Enter book_id to issue book";
    cin>>book_id;

    b_node * ptr;

    ptr= srch(book_id);
    if(ptr->qty_left>0)
        {
            ptr->qty_left-=1;
        }
    else
        {
            cout <<"                                       CANNOT ISSUE!!";
            cout<<"                                         quantity left " << ptr->qty_left ;
        }
}
void book:: b_return()
{    char book_id[5];
     cout<<"                                        Enter book_id to return book";
     cin>>book_id;
     b_node * ptr;
     ptr= srch(book_id);

     if(ptr->qty_left<ptr->total_qty)
        ptr->qty_left+=1;

     else
        cout<<"INVALID RETURN !!";
}

b_node * book:: reverse_ll()
{
    b_node * prev = NULL;
    b_node * curr = head;
    b_node * nextnode = NULL;

    while(curr)
    {
        nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }

    return prev;
}

/*
//VISITOR STRUCTURE
struct v_node
{
    char v_name[70];
    char mem_no[5];
    char email[30];
    char mem_type[40];
    char exp_date[12];//Input date as : "Enter date (DD/MM/YY):";
    int no_of_books;
    int reissue_times;//DO NOT take this as input from user
    double money_due;
    char m_b_id[5];//id of book issued to member, only one book can be issued at a time
    v_node * next;
};
//VISITOR CLASS
class visitor
{
    v_node * head;
    public:
        visitor()
        {
            head=NULL;
        }
        void add_member();
        void remove_member();
        void add_details();
        void remove_details();
        void update_details();
        //Issue
        //Re-issue
        //Return
}v;
//ADDING MEMBER
void visitor::add_member()
{
    struct v_node *newnode;
    newnode= new v_node;
    cout<<"Enter member name\n";
    cin>>newnode->v_name;
    cout<<"Enter membership number";
    cin>>newnode->mem_no;
    cout<<"Enter email\n";
    cin>>newnode->email;
    cout<<"Enter membership type\n";
    cin>>newnode->mem_type;
    cout<<"Enter expiry date\n";
    cin>>newnode->exp_date;
    cout<<"Enter no. of books\n";
    cin>> newnode->no_of_books;
    cout<<"Enter money due\n";
    cin>> newnode-> money_due;
    cout<<"Enter book id issued\n";
    cin>> newnode->m_b_id;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
    }
}
*/


int main()
{

    system("COLOR B0");
    cout<<"\n\n";
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                             LIBRARY MANAGEMENT SYSTEM                              "<<endl;
    cout<<"                                    DATA STRUCTURES PROJECT USING LINKED LISTS                      "<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
     int flag=0;

do{

    int ch ;
    cout<<"\n\n";
    cout<<"                   ***********************************************************************"<<endl;
    cout<<"                   ***********************************************************************"<<endl;
    cout<<"                   **---------------------------MENU------------------------------------**\n"<<endl;
    cout<<"                   **-------------------------1.ENTER BOOK DETAILS----------------------**\n"<<endl;
    cout<<"                   **-------------------------2.REMOVE BOOK ----------------------------**\n"<<endl;
    cout<<"                   **-------------------------3.EDIT BOOK DETAILS ----------------------**\n"<<endl;
    cout<<"                   **-------------------------4.ISSUE BOOK -----------------------------**\n"<<endl;
//    cout<<"                   **-------------------------5.REISSUE BOOK----------------------------**\n"<<endl;
    cout<<"                   **-------------------------5.RETURN A BOOK --------------------------**\n"<<endl;
    cout<<"                   **-------------------------6.DISPLAY---------------------------------**\n"<<endl;
    cout<<"                   **-------------------------7.COUNT NUMBER OF BOOKS STORED-------------**\n"<<endl;
    cout<<"                   **-------------------------8.EXIT---------------------------------**\n"<<endl;
    cout<<"                   **-------------------------Enter your choice?------------------------**\n"<<endl;
    cout<<"                   ***********************************************************************"<<endl;
    cout<<"                   ***********************************************************************"<<endl;
    cin>>ch;
    switch(ch)
    {
            case 1: b.add_book();
                    break;
            case 2: b.remove_book();
                    break;
            case 3: b.edit_detail();
                    break;
            case 4: b.issue();
                    break;
                  /*case 5:
                    b.reissue();
                    break;*/
            case 5: b.b_return();
                    break;
            case 6: b.display();
                    break;
            case 7: b.count_books();
                    break;
            case 8: cout<<"Exiting...";
                    flag = 1;
                    break;

            default:cout<<"invalid ";
                    break;
    }
  }while(flag!=1);
         return 0;
}
