/*
Name:				Irtaza Haider						Zartaj Asim								Mohsin Zia
Reg#:				   2020474							  2020526                                 2020244
*/

#include <iostream>
#include <windows.h>
using namespace std;

	class CBook{
		
		private:	
				int ID;
				int pages;
				int price;
				string issuedBy;
				string issuedOn;					//Required Variables
				string bookName;
				string author;
				string ISBN;
				string returnDate;
	
		public:
				//Default + Parameterized Constructor.					
				CBook(int ID=0, int pages=0, int price=0, 
				string issuedBy="\0", string bookName="\0", string author="\0", string ISBN="\0",string issuedOn="\0", string returnDate="\0"){
					
					this->ID=ID;
					this->pages=pages;
					this->price=price;
					this->issuedBy=issuedBy;
					this->bookName=bookName;
					this->author=author;
					this->ISBN=ISBN;
					this->issuedOn=issuedOn;
					this->returnDate=returnDate;
					
				}		

				//Getters.
				int getID(){
					return ID;
				}
			
				int getPages(){
					return pages;
				}
				
				int getPrice(){
					return price;
				}
				
				string getIssuedBy(){
					return issuedBy;	
				}
				
				string getBookName(){
					return bookName;
				}
				
				string getAuthor(){
					return author;
				}

				string getISBN(){
					return ISBN;
				}
				
				string getIssuedOn(){
					return issuedOn;	
				}
				
				string getReturnDate(){
					return returnDate;
				}
	
				//Setters
				void setID(int id){
					this->ID=id;
				}			
				
				void setPages(int pages){
					this->pages=pages;
				}
				
				void setPrice(int price){
					this->price=price;
				}
				
				void setIssuedBy(string issued_by){
					this->issuedBy=issued_by;			
				}
				

				void setBookName(string book_name){
					this->bookName=book_name;
				}
				
				void setAuthor(string authour){
					this->author=authour;
				}


				void setISBN(string isbn){
					this->ISBN=isbn;
				}

				void setIssuedOn(string issue_on){
					this->issuedOn=issue_on;	
					
				}
				
				void setReturnDate(string return_date){
					this->returnDate=return_date;					
				}

			
				void printDetails(){												//To Print Details
					
							cout<<endl;
							cout<<"  Details of the book : "<<endl;
							cout<<"	The ID of book is : "<<ID<<endl;
							cout<<"	The name of book is : "<<bookName<<endl;
							cout<<"	The name of author of book is : "<<author<<endl;
							cout<<"	The ISBN code of book is : "<<ISBN<<endl;
							cout<<"	The price of book is : "<<price<<endl;
							cout<<"	The number of pages of book is : "<<pages<<endl;
							cout<<"	The book was issued by : "<<issuedBy<<endl;
							cout<<"	The book was issued on the date : "<<issuedOn<<endl;
							cout<<"	The book was returned on date : "<<returnDate<<endl;				
							cout<<endl<<endl;
							cout<<"---------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
					
				}
		
//				CBook copyConstructor(const CBook &cB){								//Instead Of Copy Constructor We Created 
//																					//getBook Function To Return books.
//							this->ID=cB.ID;
//							this->pages=cB.pages;
//							this->price=cB.price;
//							this->issuedBy=cB.issuedBy;
//							this->bookName=cB.bookName;
//							this->author=cB.author;
//							this->ISBN=cB.ISBN;
//							this->issuedOn=cB.issuedOn;
//							this->returnDate=cB.returnDate;
//					
//				}

				//Destructor.
				//~CBook(){}
	

				CBook getBook(){												//Dereferencing this pointer to return whole book.
			
					return *this;					
					
				}

		
	};

	struct bookNode{																//To Create Book List.
			
				CBook object;
				bookNode *next;
			
		};

	class CBookList{
		
		private:
		 
			CBook books;
			bookNode *headPtr;														//Required Variables.
				
		public:
				
			//Parameterized + Default Constructor.		
			CBookList(int ID=0, int pages=0, int price=0, 
			string issuedBy="\0", string bookName="\0", string author="\0", string ISBN="\0", string issuedOn="\0", string returnDate="\0"){
	
					books.setID(ID),
					books.setBookName(bookName),
					books.setAuthor(author),
					books.setISBN(ISBN),
					books.setPrice(price),
					books.setPages(pages),
					books.setIssuedBy(issuedBy),
					books.setIssuedOn(issuedOn),
					books.setReturnDate(returnDate);
					headPtr=NULL;

			}
					
			void addBookNode(){														//To Add Node At Tail As required.

					int ID;
					int pages;
					int price;
					string issuedBy;
					string issuedOn;
					string bookName;
					string author;
					string ISBN;
					string returnDate;
	
					bookNode *addBook=new bookNode;
					bookNode *ptrTemp=headPtr;
					
					cout<<"	Enter the ID for new book you wish to add to list : " ;
					cin>>ID;
					cout<<"	Enter number of pages of book : ";
					cin>>pages;
					cout<<"	Enter total price : ";
					cin>>price;
					fflush(stdin);
					cout<<"	Enter the full name of person who has issued this book : ";			//Taking Input from user/book Details.
					getline(cin,issuedBy);
					cout<<"	Enter the date of issue of this book : ";
					cin>>issuedOn;
					fflush(stdin);
					cout<<"	Enter the full name of the book : ";
					getline(cin,bookName);
					fflush(stdin);
					cout<<"	Enter the full name of author of book : ";
					getline(cin,author);
					cout<<"	Enter ISBN code of book : ";
					cin>>ISBN;
					cout<<"	Enter date when book was returned : ";
					cin>>returnDate;
					cout<<endl<<endl;
					cout<<"	Book Successfully Added To List "<<endl;
		
					addBook->object.setID(ID);
					addBook->object.setBookName(bookName),
					addBook->object.setAuthor(author),
					addBook->object.setISBN(ISBN),													//Setting the entered details to new book.
					addBook->object.setPrice(price),
					addBook->object.setPages(pages),
					addBook->object.setIssuedBy(issuedBy),
					addBook->object.setIssuedOn(issuedOn),
					addBook->object.setReturnDate(returnDate);
				
				
					addBook->next=NULL;
						
						if(headPtr==NULL){
							headPtr=addBook;
							return;
						}
																								//adding new book at tail.
						while(ptrTemp->next != NULL){
							ptrTemp=ptrTemp->next;
						}
						
						ptrTemp->next=addBook;
				
			}
		
			void returnIssuedBookToList(CBook return_book){				
	
					bookNode *addBook=new bookNode;												//Adding issued book again to the booklist
					bookNode *ptrTemp=headPtr;													//when it is returned.
					
					cout<<endl;
		
					addBook->object.setID(return_book.getID());
					addBook->object.setBookName(return_book.getBookName()),
					addBook->object.setAuthor(return_book.getAuthor()),
					addBook->object.setISBN(return_book.getISBN()),
					addBook->object.setPrice(return_book.getPrice()),							//Setting details of returned book.
					addBook->object.setPages(return_book.getPages()),
					addBook->object.setIssuedBy(return_book.getIssuedBy()),
					addBook->object.setIssuedOn(return_book.getIssuedOn()),
					addBook->object.setReturnDate(return_book.getReturnDate());
				
				
					addBook->next=NULL;
						
						if(headPtr==NULL){
							headPtr=addBook;
							return;
						}																		//Adding at tail.
			
						while(ptrTemp->next != NULL){
							ptrTemp=ptrTemp->next;
						}
						
						ptrTemp->next=addBook;
				
			}
	
			
		
			void printParticularBook(){
		
					bookNode *search=headPtr;
					int searchID;
					cout<<"	Enter the ID of the book you want to search : ";					//To Print Desired Book.
					cin>>searchID;
					cout<<endl<<endl;
					
					while(1){
					
						if(searchID == search->object.getID())	{
					
							search->object.printDetails();										//To print details of Book
							break;																//If book is present in book list.
						
						}
				
						else{
							search=search->next;												//Moving headPointer to tail of linked list.
						}
				
						if(search == NULL){
							cout<<"	There is no book in the list with ID you specified ! "<<endl<<endl;		//incase book not found.
							break;
						}
					}

			}
			
			
			void printAll(){
		
					bookNode *print=headPtr;
						
					while(print != NULL){													//To print details of all books in the book list.
						
						print->object.printDetails();
						print=print->next;
									
					}
			
			}
	
			void deleteList(){
			 			 
			   	bookNode* currentPtr = headPtr;
			 	bookNode* tempPtr = NULL ;
			 
			    while (currentPtr != NULL){													//To delete whole linked list.
			
					tempPtr = currentPtr->next ;
					delete currentPtr;		
					currentPtr = tempPtr;
				}
				
				headPtr=NULL;
				cout<<"				Linked List Successlly Deleted ! "<<endl;
			
			}


			void sortAscendingOrder(){
	
					int ID,temporaryID;

					int price,temporaryPrice;
			
					int pages,temporaryPages;
			
					string IssuedBy,temporaryIssuedBy;
			
					string IssuedOn,temporaryIssuedOn;
			
					string BookName,temporaryBookName;						//To sort in ascending order w.r.to ID.
			
					string author,temporaryAuthor;
			
					string ISBN,temporaryISBN;
			
					string returnDate,temporaryReturnDate;
			
					bookNode* ptrCurrent = headPtr;
			
					int numberOfBooks = 0;


					while (ptrCurrent != NULL){
						
						ptrCurrent = ptrCurrent->next;							//Getting total number of books in list.
						numberOfBooks++;
					
					}

					ptrCurrent = headPtr;

					for (int i=0;i<numberOfBooks;i++){
						
						while (ptrCurrent->next != NULL){
							
							if (ptrCurrent->object.getID() > ptrCurrent->next->object.getID()){
								
								temporaryID = ptrCurrent->object.getID();
								ID = ptrCurrent->next->object.getID();
								
								ptrCurrent->object.setID(ID);
								ptrCurrent->next->object.setID(temporaryID);					//In case next book ID is greater than current,
																								//We swap them and set them.
						
								temporaryPrice = ptrCurrent->object.getPrice();
								price = ptrCurrent->next->object.getPrice();
			
								ptrCurrent->object.setPrice(price);
								ptrCurrent->next->object.setPrice(temporaryPrice);
			
							
								temporaryPages = ptrCurrent->object.getPages();
								pages = ptrCurrent->next->object.getPages();
								
								ptrCurrent->object.setPages(pages);
								ptrCurrent->next->object.setPages(temporaryPages);
			
			
								temporaryIssuedBy = ptrCurrent->object.getIssuedBy();
								IssuedBy = ptrCurrent->next->object.getIssuedBy();
								
								ptrCurrent->object.setIssuedBy(IssuedBy);
								ptrCurrent->next->object.setIssuedBy(temporaryIssuedBy);
			
			
								temporaryIssuedOn = ptrCurrent->object.getIssuedOn();
								IssuedOn = ptrCurrent->next->object.getIssuedOn();
			
								ptrCurrent->object.setIssuedOn(IssuedOn);
								ptrCurrent->next->object.setIssuedOn(temporaryIssuedOn);
			
			
								temporaryBookName = ptrCurrent->object.getBookName();
								BookName = ptrCurrent->next->object.getBookName();
								
								ptrCurrent->object.setBookName(BookName);
								ptrCurrent->next->object.setBookName(temporaryBookName);
			
			
								temporaryAuthor = ptrCurrent->object.getAuthor();
								author = ptrCurrent->next->object.getAuthor();
								
								ptrCurrent->object.setAuthor(author);
								ptrCurrent->next->object.setAuthor(temporaryAuthor);
			
			
								temporaryISBN = ptrCurrent->object.getISBN();
								ISBN = ptrCurrent->next->object.getISBN();
							
								ptrCurrent->object.setISBN(ISBN);
								ptrCurrent->next->object.setISBN(temporaryISBN);
			
			
								temporaryReturnDate = ptrCurrent->object.getReturnDate();
								returnDate = ptrCurrent->next->object.getReturnDate();
										
								ptrCurrent->object.setReturnDate(returnDate);
								ptrCurrent->next->object.setReturnDate(temporaryReturnDate);

								}
								else{
									ptrCurrent = ptrCurrent->next;									//Moving to next book.
								}
							
							}
				
							ptrCurrent = headPtr;					//Setting to headPtr.
					}
				
			}
			

			void sortDescendingOrder(){
	
	
					int ID,temporaryID;

					int price,temporaryPrice;
			
					int pages,temporaryPages;
			
					string IssuedBy,temporaryIssuedBy;
			
					string IssuedOn,temporaryIssuedOn;
																						//To sort in descending order w.r.to ID.
					string BookName,temporaryBookName;	
			
					string author,temporaryAuthor;
			
					string ISBN,temporaryISBN;
			
					string returnDate,temporaryReturnDate;
			
					bookNode* ptrCurrent = headPtr;
			
					int numberOfBooks = 0;


					while (ptrCurrent != NULL){
						
						ptrCurrent = ptrCurrent->next;
						numberOfBooks++;
					
					}

					ptrCurrent = headPtr;

					for (int i=0;i<numberOfBooks;i++){									
						
						while (ptrCurrent->next != NULL){								//If we havenot reached till end of list.
							
							if (ptrCurrent->object.getID() < ptrCurrent->next->object.getID()){
								
								temporaryID = ptrCurrent->object.getID();
								ID = ptrCurrent->next->object.getID();
								
								ptrCurrent->object.setID(ID);
								ptrCurrent->next->object.setID(temporaryID);
			
						
								temporaryPrice = ptrCurrent->object.getPrice();
								price = ptrCurrent->next->object.getPrice();
																								//In case next book ID is less current,
								ptrCurrent->object.setPrice(price);								//We swap and set them.
								ptrCurrent->next->object.setPrice(temporaryPrice);
			
							
								temporaryPages = ptrCurrent->object.getPages();
								pages = ptrCurrent->next->object.getPages();
								
								ptrCurrent->object.setPages(pages);
								ptrCurrent->next->object.setPages(temporaryPages);
			
			
								temporaryIssuedBy = ptrCurrent->object.getIssuedBy();
								IssuedBy = ptrCurrent->next->object.getIssuedBy();
								
								ptrCurrent->object.setIssuedBy(IssuedBy);
								ptrCurrent->next->object.setIssuedBy(temporaryIssuedBy);
			
			
								temporaryIssuedOn = ptrCurrent->object.getIssuedOn();
								IssuedOn = ptrCurrent->next->object.getIssuedOn();
			
								ptrCurrent->object.setIssuedOn(IssuedOn);
								ptrCurrent->next->object.setIssuedOn(temporaryIssuedOn);
			
			
								temporaryBookName = ptrCurrent->object.getBookName();
								BookName = ptrCurrent->next->object.getBookName();
								
								ptrCurrent->object.setBookName(BookName);
								ptrCurrent->next->object.setBookName(temporaryBookName);
			
			
								temporaryAuthor = ptrCurrent->object.getAuthor();
								author = ptrCurrent->next->object.getAuthor();
								
								ptrCurrent->object.setAuthor(author);
								ptrCurrent->next->object.setAuthor(temporaryAuthor);
			
			
								temporaryISBN = ptrCurrent->object.getISBN();
								ISBN = ptrCurrent->next->object.getISBN();
							
								ptrCurrent->object.setISBN(ISBN);
								ptrCurrent->next->object.setISBN(temporaryISBN);
			
			
								temporaryReturnDate = ptrCurrent->object.getReturnDate();
								returnDate = ptrCurrent->next->object.getReturnDate();
										
								ptrCurrent->object.setReturnDate(returnDate);
								ptrCurrent->next->object.setReturnDate(temporaryReturnDate);

								}
								else{
									ptrCurrent = ptrCurrent->next;										//Moving to next book.
								}
							
							}
				
							ptrCurrent = headPtr;
					}
				
			}
			
			void deleteBook(int delID){			
			
				bookNode* ptrCurrent=headPtr;
				bookNode* ptrPrevious;
				
				while(ptrCurrent != NULL && ptrCurrent->object.getID() != delID){				//To delete book with their ID from list.
																								//Checking if book ID exists in book list.
					ptrPrevious=ptrCurrent;
					ptrCurrent=ptrCurrent->next;
					
				}
				
				if(ptrCurrent == NULL){
					
					cout<<"The book ID you entered doesn't exist in list "<<endl<<endl;			//In case book no found in list.
					return;
					
				}		
				
				if(ptrCurrent == headPtr){
					headPtr=headPtr->next;												//Moving head Ptr to next.					
				}	
			
				else{
					ptrPrevious->next=ptrCurrent->next;
				}
				
				delete ptrCurrent;													//Deleting desired book.
				
			}

		//Destructor.
		
		//~CBookList(){}

		bookNode* getBookHead(){
			
			return headPtr;													//To get book linked list head pointer / starting node.
		
		}
		

				
	};
	
	class CStudent{
		
		private:
			
			int stdID;
			int rollNumber;													//Required Variables.
			CBook issuedBooks[5]; 
			int counter;			
			string stdName;
			
		public:
		
			//Default+Parameterized Constructor.
			CStudent(int stdID=0,int rollNumber=0,int* booksIssued=0,string stdName="\0"){
				counter = 0 ;
				this->stdID=stdID;
				this->rollNumber=rollNumber;
				this->stdName=stdName;
				
			}
			//getters.
			int getStdID(){
				return stdID;
			}	

			int getRollNumber(){
				return rollNumber;				
			}	
						
			string getStdName(){
				return stdName;				
			}	
			
			//setters.
			void setStdID(int id){				
				this->stdID=id;
			}
		
			void setRollNumber(int rollNum){
				this->rollNumber=rollNum;
			}

			void setStdName(string stdName){
				this->stdName=stdName;
			}
			
			void studentDetails(){
				
				cout<<"  The details of the student are below : "<<endl<<endl;
				cout<<"	The name of the student is : "<<stdName<<endl;						//Printing student Details.
				cout<<"	The ID of the student is : "<<stdID<<endl;
				cout<<"	The roll number of the student is : "<<rollNumber<<endl<<endl;				
				
					
					cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
					cout<<"  					    "<<stdName<<" has issued the following book  "<<endl;				
					cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
					
				if(counter == 0){
					
					cout<<"  					    "<<stdName<<" has not issued any book  "<<endl<<endl<<endl;
					
				}

				
				for(int i=0;i<counter;i++){
										
					issuedBooks[i].printDetails();						//Printing issued books by student if any.
					
				}
			
			}
			
			void issuedBookDetails(){
							
				for(int i=0;i<counter;i++){
																		//Printing details of issued book.
					cout<<endl;
					issuedBooks[i].printDetails();
					
				}
				
			}	
			
			~CStudent(){}
				
			
			void setIssuedBook(bookNode *iB, int bookID){
					
				if(counter < 5){														//To make sure user issues not more than 5 books.
					
					this->issuedBooks[counter] = iB->object.getBook();			//To get issued book from the list we desire to issue.
					counter++;															//Counter of issued books.
					
				}
			}
		
			CBook getIssuedBookID(int bookID){											//To get issued books. Cbook type function.
						int i = 0;
						for(;i<counter;i++){
													
							if(bookID == issuedBooks[i].getID()){						//If passed book ID in prototype is found.
																						//We get issued book from here 
								break;	
								
							}
												
						}
						return issuedBooks[i];											//returning issued book.
	
				
			}
	
			
			void removeIssuedBook(int bookID){											//Removing issued book from the list.
				
						int index;
						
						for(int i=0;i<counter;i++){
													
							if(bookID == issuedBooks[i].getID()){						//Getting the book and its index to 
																						//remove it from issued book list.
								index=i;
							}
												
						}
						
						if(index == counter-1){
							
						}
						else{
							for(int i=index ; i<counter-1 ; i++){
								issuedBooks[i]=issuedBooks[i+1];
							}
						}
		
					counter--;
		
			}
			

	};
	
struct studentNode{
		
		CStudent obj;												//To create student list.
		studentNode* next;
		
	};
	
	class CStudentList{
		
		private:

			CStudent std;
			studentNode* HeadPtr;
		
		public:
		
			CStudentList(){
				HeadPtr=NULL;									//Initializing head pointer.
			}
			
			//Parameterized constructor.
			CStudentList(int stdID,int rollNumber,int* booksIssued,string stdName,int size){

				std.setStdID(stdID);
				std.setRollNumber(rollNumber);
				size=5;
				booksIssued=new int[size];
				std.setStdName(stdName);

			}
			
			//To print particular student from the list.
			void printParticularStudent(){
		
					studentNode *search=HeadPtr;
					int searchID;
					
					if(HeadPtr == NULL){								//Checking if their exists any student in list./Or list is created..
						
						cout<<endl;
						cout<<"						Student List Is Empty ! "<<endl;
						return;
						
					}
					
					cout<<"	Enter the ID of the student of which you want to print details of : ";
					cin>>searchID;
					cout<<endl<<endl;
					
					while(1){
					
						if(searchID == search->obj.getStdID())	{				//Searching for desired ID.
					
							search->obj.studentDetails();
							break;	
						
						}
				
						else{
							search=search->next;								//Moving forward in list.
						}
				
						if(search == NULL){
							cout<<"	There is no book in the list with ID you specified ! "<<endl<<endl;	//incase book not found.
							break;
						}
					}

			}

			void printAllStudents(){
				
				studentNode* print=HeadPtr;
				 
				while(print != NULL){								//To Print all students present in the list.
					
					print->obj.studentDetails();
					print=print->next;
									
				}			
				
			}
				
				
			void printIssuedBooks(){
				
				studentNode* print=HeadPtr;
				 
				while(print != NULL){									//Print all issued Books.
					
					print->obj.issuedBookDetails();
					print=print->next;
									
				}			
				
			}
						
			void addNodeOfStudent(){
				
				studentNode* addStudent=new studentNode;				//Adding students in list.
				studentNode* tempPtr=HeadPtr; 
				
				int stdID;
				int rollNumber;
				string stdName;
				int* booksIssued;
				int size=5;
				
				cout<<"	Enter your student ID : ";
				cin>>stdID;
				
				cout<<"	Enter your roll number : ";
				cin>>rollNumber;
				
				booksIssued=new int[size];
				
				fflush(stdin);
				cout<<"	Enter your full name : ";							//To take full name as input with spaces.
				getline(cin,stdName);

	
				addStudent->obj.setStdID(stdID);
				addStudent->obj.setRollNumber(rollNumber);				//Setting the entered details.
				addStudent->obj.setStdName(stdName);
				

				addStudent->next=NULL;
				
				if(HeadPtr==NULL){
					HeadPtr=addStudent;
					return;
				}											//adding at tail.
				
				while(tempPtr->next != NULL){
					tempPtr=tempPtr->next;
				}
				
				tempPtr->next=addStudent;

			}
			
			void deleteStudent(){

				int deleteID;				
				cout<<"	Enter the ID of student which has to be deleted : ";					//To delete a student from list.
				cin>>deleteID;
			
			
				studentNode* ptrCurrent=HeadPtr;
				studentNode* ptrPrevious;
			
				while(ptrCurrent != NULL && ptrCurrent->obj.getStdID() != deleteID){			//Checking if entered ID exists in list.
					
					ptrPrevious=ptrCurrent;
					ptrCurrent=ptrCurrent->next;
					
				}
				
				if(ptrCurrent == NULL){
					
					cout<<"	The student ID you entered doesn't exist in list "<<endl<<endl;		//Incase student with ID not found.
					return;
					
				}		
				
				if(ptrCurrent == HeadPtr){											//Moving headPtr to next.
					HeadPtr=HeadPtr->next;													
				}	
			
				else{
					ptrPrevious->next=ptrCurrent->next;									//Moving forward.
				}
				
				delete ptrCurrent;														//Deleting the book we desire.
				
			}
			
			~CStudentList(){}															//destructor.
			
			studentNode* getStudentHead(){
				
				return HeadPtr;															//getting head of student list.
				
			}
			
	
	};
	
	class CLibrary{
		
		private:
			
			CBookList bL;
			CStudentList sL;
			int count;																	//Required Variables.
			int* issuedBooksID;
			int totalBooksIssued;
			bool issuedBookExist;


		public:
			//Default Constructor.
			CLibrary(){
				issuedBookExist=false;
				count=0;
			}
			//Destructor
			~CLibrary(){}
				
			void run(){																//We are operating whole program through this function.
			
					int mainChoice;
					int subChoice;				
					
					cout<<endl<<endl;
					
				
					while(true){
					
						system("Color 0A");

						cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
						cout<<"					WELCOME TO LIBRARY MANAGEMENT SYSTEM "<<endl;
						cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
						cout<<endl<<endl;
						cout<<"   Main Menu : "<<endl;
						cout<<"	1- Student "<<endl;
						cout<<"	2- Book "<<endl;	
						cout<<"	3- Library "<<endl;
						cout<<"	4- Exit "<<endl;
						cout<<"	Select your choice (1-4) : ";
						cin>>mainChoice;
						system("cls");
						cout<<endl;
						
						switch(mainChoice){
							
							case 1:
											
								cout<<endl<<endl;
								cout<<"   Sub Menu Of Student : "<<endl;	
								cout<<"	1- Add New Student "<<endl;
								cout<<"	2- Delete Existing Student "<<endl;
								cout<<"	3- Show Particular Student "<<endl;
								cout<<"	4- Show All Students "<<endl;
								cout<<"	Select your choice (1-4) : ";
								cin>>subChoice;
								system("cls");
							
								cout<<endl<<endl;
								
								//Calling the desired function .
								switch(subChoice){
									
									case 1:

										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
										cout<<"  					    "<<"Enter Details For Student You Want To Add  "<<endl;				
										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;

										sL.addNodeOfStudent();
										break;
											
									case 2:

										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
										cout<<"  					    "<<"Enter Student ID To Delete Student  "<<endl;				
										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
									
										sL.deleteStudent();
										break;
										
									case 3:
										
										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
										cout<<"  					"<<"Enter Following Details To Print Details Of Desired Student  "<<endl;				
										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;

										sL.printParticularStudent();
										break;
									
									case 4:
										
										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
										cout<<"  					    "<<"Details Of All Students  "<<endl;				
										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;										
										
										sL.printAllStudents();
										break;
									
									default:
										
										cout<<"	Invalid Choice"<<endl;
										break;	
													
								}
								
								break;
							
							
							case 2:
								
								cout<<endl<<endl;
								cout<<"   Sub Menu Of Book : "<<endl;
								cout<<"	1- Add New Book "<<endl;
								cout<<"	2- Delete Existing Book List"<<endl;
								cout<<"	3- Show particular Book "<<endl;
								cout<<"	4- Show all Books "<<endl;
								cout<<"	5- Sort Books in Ascending order "<<endl;
								cout<<"	6- Sort Books in Descending order "<<endl;
								cout<<"	Select your choice (1-6) : ";
								cin>>subChoice;
								system("cls");
							
								cout<<endl<<endl;
								
								//Calling the desired Function.							
								switch(subChoice){
									case 1:

										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
										cout<<"  					    "<<"Enter Details For Book You Want To Add  "<<endl;				
										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
										
										bL.addBookNode();
										break;
											
									case 2:
									
										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
										cout<<"  					    "<<"Entire Book List Has Been Deleted  "<<endl;				
										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
									
										bL.deleteList();					
										break;
										
									case 3:

										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
										cout<<"  					 "<<"Enter Details To Print Details Of Desired Book  "<<endl;				
										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
										
										bL.printParticularBook();
										break;
									
									case 4:

										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
										cout<<"  					    "<<"Details Of All Books  "<<endl;				
										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;

										
										bL.printAll();
										break;
									
									case 5:
										
										bL.sortAscendingOrder();
					
										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
										cout<<"  				"<<"Details Of Books After Sorting In Ascending Order  "<<endl;				
										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;

										bL.printAll();
										break;
					
									case 6:
										
										bL.sortDescendingOrder();

										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
										cout<<"  				"<<"Details Of Books After Sorting In Descending Order  "<<endl;				
										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;

					
										cout<<"	Book List after sorting in descending order is : "<<endl<<endl;
										bL.printAll();
										break;
					
									default:
										
										cout<<"	Invalid Choice"<<endl;
										break;	
					
								}
															
								break;
								
								
							case 3:
								
								cout<<endl<<endl;
								cout<<"   Sub Menu Of Library : "<<endl;
								cout<<"	1- Issue a book "<<endl;
								cout<<"	2- Return a book "<<endl;
								cout<<"	3- Print which books have been issued with their details "<<endl;
								cout<<"	Enter your choice (1-3) : ";
								cin>>subChoice;
								system("cls");
								
								cout<<endl;
								
								
								//Calling the desired Function.
								switch(subChoice){
									
									case 1:

										cout<<endl;
										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
										cout<<"  						   "<<"Enter Details To Issue Book  "<<endl;				
										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
									
										issueBook();
										break;
								
									case 2:
										
										cout<<endl;
										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
										cout<<"  					 	  "<<"Enter Details To Return Issued Book  "<<endl;				
										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
										
										returnABook();
										break;
										
									case 3:
										
										cout<<endl;
										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
										cout<<"  					  	  "<<"Details Of Issued Books  "<<endl;				
										cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
									
										sL.printIssuedBooks();
										
										break;
										
									default:
										cout<<"	Invalid Choice ! "<<endl;
										break;	
								}
										
								break;
								
								
							case 4:
								
								exit(0);			
								break;
									
											
							default:
							
								cout<<"	Invalid choice ! "<<endl<<endl;
									
						
						}
				
						cout<<endl<<endl<<endl;
						system("pause");
						system("cls");
				
					}
						
			
			
			}	
			void issueBook(){												//To issue the book.
				
				int issueID;
				int issuedTo;			
				
				bookNode* issuedBook=bL.getBookHead();						//Getting Head Pointers.
				studentNode* issueBy=sL.getStudentHead();
				
				cout<<endl<<endl;
				cout<<"	Enter the ID of book you want to issue : ";
				cin>>issueID;
				cout<<endl;
				
					if(bL.getBookHead() == NULL){							//Checking if book list in empty.
						
						cout<<"	Book List is Empty "<<endl;
						return;
						
					}
					
					while(issueID != issuedBook->object.getID()){			//To check if book is found.
						
						if(issuedBook->next == NULL){
							
								cout<<endl<<"	Book with "<<issueID<<" not found in the list "<<endl;			//Incase book not found in list.
								return;
						
						}
						else{						
						issuedBook = issuedBook->next;									//Moving Forward in list.					
						}
								
					} 
								
					cout<<"	Enter The ID of the student to whom you want to issue this book : ";
					cin>>issuedTo;
					cout<<endl;
					
					if(sL.getStudentHead() == NULL){									//Checking if student list is empty.
					
						cout<<"	Student List Is Empty "<<endl;
						return;
					
					}

										
					while(issuedTo != issueBy->obj.getStdID()){							//Incase book not found in list.
					
						if(issueBy->next == NULL){
					
							cout<<"	Student with ID "<<issuedTo<<" not found in the student list "<<endl;
							return;
						
						}
						else{
							issueBy = issueBy->next;									//Moving Forward
						}
					}
					string nameOfIssuer = issueBy->obj.getStdName(); 			
					issuedBook->object.setIssuedBy(nameOfIssuer) ;						//Updating name of issuer of book from none to student name.
					
					issuedBookExist = true;									
					count++;						
			
					issuedBooksID= new int [count];
					issuedBooksID[count]=issueID;
							
				if(count>5){
					
					cout<<"	Sorry you can only issue 5 books from library !"<<endl;			//To tell user that he have already issued maximum books he can.
					exit(0);
					
				}

				cout<<"	Book with ID "<<issueID<<" issued to the student with ID "<<issuedTo<<endl;	
				
				issueBy->obj.setIssuedBook(issuedBook, issueID);							//Setting issued book to books issued by student.
								
				bL.deleteBook(issueID);														//And finally removing it from list of books.
				
		}
			
			void returnABook(){																//To return the issued books.	
				
				CBook returned_book;
				int returnID;
				int issuedTo;			
				
				
				bookNode* returnedBook=bL.getBookHead();									//Getting headPtr of Student and booklist.
				studentNode* returnedBy=sL.getStudentHead();
									
				if(issuedBookExist == false){
					
					cout<<endl;
					cout<<"	Add book in the issued list first ! "<<endl;						//Incase issued booklist is empty
					return;
					
				}

				cout<<endl;
				cout<<"	Enter the ID of book you want to return : ";
				cin>>returnID;			

								
				while(true){
				
					returned_book = returnedBy->obj.getIssuedBookID(returnID);					//Getting complete issued book from issued book list.

					if(returnID == returned_book.getID()){										//If entered ID is in issued Book list ID's.
							
						bL.returnIssuedBookToList(returned_book);								//Calling Function To return the book.
						returnedBy->obj.removeIssuedBook(returnID);								//Removing it from issued book list and adding it to bookLists.
						
						count--;	
						cout<<"	Book was added to book list and remove from issued books  "<<endl;
						break;
						
					}
					else if(returnedBy->next == NULL){											//Incase book doesn't exists in list.
					
					cout<<"	The Book ID you entered doesn't exists in issued book list "<<endl;
					return;
					
					}
					else{								
					returnedBy=returnedBy->next;													//Moving forward.
					}
				}
				

			}
			
				
	};
	

int main(){
	
	CLibrary L;
	L.run();														//Calling run function from library.
	
	return 0;
}
