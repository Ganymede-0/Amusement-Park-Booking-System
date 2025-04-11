#include <iostream> 
#include <fstream>

using namespace std;

string cho,ID,AGE,DAY,MONTH,NAME,ans;
const int LIMIT = 100;
int size=0;
    
//STRCTURE FOR INFO// 
struct booking { 
    string Name; 
    string ID;
    string age;
    string event;
    string day;
    string month;
    string price;

};

string fName="ticket.txt";
string bName="ticket_backup.txt";
booking ticket[LIMIT];
booking database[LIMIT];


//LOADDATA FUNCTION//
void loadData(string fName, booking ticket[]) {
ifstream inFile(fName.c_str()); 

if(inFile.is_open()) {
 
int counter=0; 
        while(!inFile.eof()) { 
getline(inFile, ticket[counter].Name); 
getline(inFile, ticket[counter].ID); 
getline(inFile, ticket[counter].age); 
getline(inFile, ticket[counter].event);
getline(inFile, ticket[counter].day);
getline(inFile, ticket[counter].month);
getline(inFile, ticket[counter].price);
counter++;}
size=counter-1;
inFile.close();}
else 
cout<<"Fail\n";
}

//SAVEDATA FUNCTION//
void saveData(string fname, booking ticket[]){
	ofstream ofile(fname.c_str());
	if(ofile.is_open()){
		for(int i=0;i<size;i++){
			ofile<<ticket[i].Name<<endl;
			ofile<<ticket[i].ID<<endl;
			ofile<<ticket[i].age<<endl;
			ofile<<ticket[i].event<<endl;
			ofile<<ticket[i].day<<endl;
			ofile<<ticket[i].month<<endl;
			ofile<<ticket[i].price<<endl;
		}
		ofile.close();
		cout<<"\nData Saved Successfully\n";
	}
	else
	    cout<<"Fail\n";
}

//BACKUP FUNCTION//
void backupData(string fName,string bName ) 
{
        ofstream outFile(bName.c_str() ); 
        ifstream inFile(fName.c_str() ); 
        string line;
        if(outFile.is_open() && inFile.is_open() ) 
		{
                do{
                    getline(inFile,line); 
                    outFile<< line << endl; 
                    }while(!inFile.eof());
                    outFile.close(); 
                    inFile.close(); 
                    cout<<"The file is backed up successfully.\n";
        }else 
                    cout << "Error: Unable to open the file!\n";
}


/// NAME LETTER CHECKING FUNC ///
string checkname(string NAME)
{
    for(int i=0 ; i<NAME.length();i++)
    if ( !isalpha(NAME[i]))
    	return "False"; 
    	
    	
    return "True";
}

///SECOND ID CHECKING FUNCTION ///
string checkID( booking ticket[], string ID, int size ){
	int i=0;
	while (i<size){
		if (ticket[i].ID == ID)
		return "False";
		i++;}
		
		return "True";
	
}
/// NUEMIRICAL CHECKING FUNC ///
string checkID( string ID ) {
   for( int i = 0; i < ID.length(); i++ ) {
      if( !isdigit( ID[i] )) {
         return "False";
      }
   }
   return "True";
}

/// PRICE FUNCTION ///
string price(string cho){
	if(cho =="1"){
	return "100";}
	
	else if(cho=="2"){
	return "150";}
	
	else
	return "50";
}




/// DISPLAY FUNCTION ///
void displayData(booking ticket[])
{
for (int i=0;i<size;i++){
cout << "\nName: "<< ticket[i].Name << "\n";
cout << "ID: "<< ticket[i].ID << "\n";
cout << "Age: "<< ticket[i].age<< "\n";
cout << "Event: "<< ticket[i].event << "\n";
cout << "Date: "<< ticket[i].day <<"/"<<ticket[i].month<<"\n";
cout << "TOTAL COST: "<< ticket[i].price << " SAR \n";

 }
}



/// TICKET BOOKING FUNCTION ///
void bookTic(booking ticket[] ){
	
	do{
cout<<"\n \t \t \t ~~~~~~~~~~~~ ";
cout<<"\n \t \t \t   WELCOME!   \n";
cout<<" \t \t \t ~~~~~~~~~~~~ \n";
cout<<"\t    Please Enter Your Booking Informations: ";
//#1
cout<<"\n \tName: "; cin>> NAME;
while(checkname(NAME)=="False")
    {
       cout<<" \tPlease enter a valid NAME!";
       cout<<"\n \tName: "; cin>> NAME;
       ticket[size].Name=NAME;
    }
    ticket[size].Name=NAME;


//#2
cout<<" \tID (4 integers): "; cin>> ID;
while(checkID(ticket, ID, size )=="False")
	{
	cout<<"\tthis ID is allready taken!";
    cout<<"\n \tID (4 integers): "; cin>> ID;
    ticket[size].ID=ID;	}
while(checkID(ID)=="False" || ID.length()!=4)
    {
       cout<<" \tPlease enter a valid ID!";
       cout<<"\n \tID (4 integers): "; cin>> ID;
       ticket[size].ID=ID;
    }
ticket[size].ID=ID;

//#3
cout<<" \tAge: "; cin>> AGE;
ticket[size].age=AGE;
while(checkID(AGE)=="False" || AGE.length()>2 )
    {
       cout<<" \tPlease enter a vaid age!";
       cout<<"\n \tAge: "; cin>> AGE;
       ticket[size].age=AGE;
    }
ticket[size].age=AGE;

//#4
cout<<"\n \tChoosen Event: (Enter one number Only) ";
cout<<"\n \t(1) Horse Riding.  ";
cout<<"\n \t(2) Games Area.  ";
cout<<"\n \t(3) Shopping Area.  ";
cout<<"\n \t Choosen Event:  ";
cin>>cho;
while(cho != "1" && cho != "2" && cho != "3")
    {
       cout<<" \tPlease enter a vaid choise!";
       cout<<"\n \t Choosen Event:  "; cin>> cho;
       ticket[size].event=cho;
       ticket[size].price=price(cho);
    }
ticket[size].event=cho;
ticket[size].price=price(cho);

//#5
cout<<"\n \tBooking Date: (DD-MM): ";
cout<<"\n \tDay: "; cin>> DAY;
while(checkID(DAY)=="False" || DAY.length()>2 )
    {
       cout<<" \tPlease enter a valid DAY!";
       cout<<"\n \tDay: "; cin>> DAY;
       ticket[size].day=DAY;
    }
ticket[size].day=DAY;

//#6
cout<<" \tMonth: "; cin>> MONTH ;
while(checkID(MONTH)=="False" || MONTH.length()>2  )
    {
       cout<<" \tPlease enter a valid MONTH!";
       cout<<"\n \tMonth: "; cin>> MONTH;
       ticket[size].month=MONTH;
    }
ticket[size].month=MONTH;


cout<<"\n\t    Your Booking have been added successfully!\n";
cout<<"\nYOUR BILL is:\n";
cout << "\nName: "<< ticket[size].Name << "\n";
cout << "ID: "<< ticket[size].ID << "\n";
cout << "Age: "<< ticket[size].age<< "\n";
cout << "Event: "<< ticket[size].event << "\n";
cout << "Date: "<< ticket[size].day <<"/"<<ticket[size].month<<"\n";
cout<<"TOTAL COST: "<< ticket[size].price<< " SAR. \n";
size++;
cout<<"\n\n \tEnter -1 to return to the menue. \n \tIf you want another reservation, Enter any other (integer).\n";
cin>>ans;}
while(ans!= "-1");

}


//SEARCH function:
int searchID( booking ticket[],int size){

	string Id;
	cout<<"\nPlease enter your id: ";
	cin>>Id;
	for(int i=0 ; i<size ; i++){
	
	    if(ticket[i].ID == Id)
	       return i;}
		
		return -1;
	}

//Delete function:
int deleteID( booking ticket[] , int &size , string id){
	int i , j , found = 0;
	for( i=0 ; i < size; i++){
		if( ticket[i].ID == id){
			for( j=i; j < ( size-1 ); j++)
                ticket[j] = ticket[j+1];
                
            found++;
            size--;
            break;
		}
	}
	return found;
}

// UPDATE function
void update(booking ticket[])
{	int updatechoice, index;
	index=searchID(ticket,size);
	
	if (index<0)
	{
		cout<<"\nNot found!!\n";
		return; 
	}else{
	
	cout<<"\nWhat would you like to upadate: ";
	
	cout<<"\n1- Date";
	cout<<"\n2- Event\n";
	cin>>updatechoice;
}
	if(updatechoice == 1){
		cout<<"\nOld Date: "<<ticket[index].day <<"/"<<ticket[index].month<<"\n";
		cout<<"\nNew Date:- ";
		cout<<"\nEnter new day: ";
		cin>>ticket[index].day;
		cout<<"\nEnter new month: ";
		cin>>ticket[index].month;
		cout<<"\nDate updated successfully. \n";
	}

	if(updatechoice == 2){
		cout<<"\nOld Event: "<<ticket[index].event;
		cout<<"\nNew Event:- ";
		cout<<"\n \t(1) Horse Riding.  ";
		cout<<"\n \t(2) Games Area.  ";
		cout<<"\n \t(3) Shopping Area.  ";
		cin>>cho;
		ticket[index].event=cho;
        ticket[index].price=price(cho);
		
		cout<<"\nEvent updated successfully. \n";
	}
	
}
//SORT function:
void sort_ages(booking ticket[])
{
	do{
	bool ordered=false;
	booking temp;
	
	if (size < 2) 
		cout<<"\nNothing to sort!!";
		
    for(int i=0; i<size-1 && ordered==false; ++i) 
    {	 
		ordered=true;
		for(int j=0; j<size-1; ++j)
  	     	if(ticket[j].age < ticket[j+1].age)     
	     	{        
			ordered=false;
	            temp = ticket[j];
	            ticket[j] = ticket[j+1];
	            ticket[j+1] = temp;
	    	}
 	}
 	cout<<"\nAges from older to younger:";
 	displayData(ticket);	

cout<<"\n\n \tEnter -1 to return to the menue. \n \tIf you want another order, Enter any other (integer).\n";
cin>>ans;}
while(ans!= "-1" );}

//DISPLAY MENU funcation
void menu(int &choice){
	cout<<"\n\n**********MENU*************\n";
	cout<<"1-Book a Ticket.\n";
	cout<<"2-Search For a Ticket.\n";
	cout<<"3-Delete a Ticket\n";
	cout<<"4-Display All Ticket.\n";
	cout<<"5-Update a Ticket.\n";
	cout<<"6-Sort By Age.\n";
	cout<<"7-Exit\n";
	cout<<"Choose:";
	cin>>choice;
}
/// MAIN ///
int main(){
	booking database[LIMIT];
	int choice;
	string fName="ticket.txt";
    string bName="ticket_backup.txt";
    loadData( fName, database);

	
string idDel;
	int i;
	int f;
	do{
		menu(choice);
	switch(choice){
		case 1:
			bookTic(database);
			saveData( fName, database);
			backupData( fName, bName );
			break;
		case 2:
			i=searchID( database ,  size );
            
			if(i!=-1){
				cout<<"Your Ticket information:\n";
				cout<<"Name: "<<database[i].Name<<"\t";
				cout<<"ID: "<<database[i].ID<<endl;
				cout<<"Age: "<<database[i].age<<"\tEvent: "<<database[i].event<<endl;
				cout<<"Date: "<<endl;
				cout<<"Day: "<<database[i].day<<"\tMonth: "<<database[i].month;
				cout<<"\nTOTAL COST: "<<database[i].price<<endl;
				
			}else
			     cout<<"ticket is not found";
			
			
			break;
		case 3:
			cout<<"Enter ID: ";
			cin>>idDel;
		    f=deleteID( database , size ,  idDel);
		    if(f!=0){
			
		      cout<<"Ticket deleted successfully.";
		      saveData( fName, database);}
		    else
			    cout<<"ticket is not found.";
				
			break;
		case 4:
			displayData(database);
		    break;
	
		case 5:
		      	  
			update(database);
			saveData( fName, database);
			backupData( fName, bName ) ;
			break;
		
		case 6:
		     	sort_ages(database);
		     	saveData( fName, database);
		        backupData( fName, bName ) ;
		     	break;
			
}

}while(choice!=7);


	
	
return 0;
}
	



