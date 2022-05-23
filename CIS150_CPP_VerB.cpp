#include <iostream>
#include <string>
using namespace std; 
struct DOA
{
	int day;
	int month;
	
};
struct item
{

	int number;
	string category;
	int startingBidPrice;
	DOA startingDate;
	DOA endDate;
	string status;
};
struct members
{
	int ID;
    string email;
    string name;
    string password;
    string address;
    int phoneNumber;
    int points;
    int numOfItems;
    item listOfItems[20];
	
}member[20];
struct SOLD
{
	int numOfItem;
	int buyer;
    int seller; 
    string category; 
    DOA time;
	int price;
	string approvment;
}arr_SOLD[30];

struct feedback 
{
	int ID;
    string comment;
    int rating;
}feedback_Var;


int    COUNTER = 0;
int    previous_Num0fItems = 0;
int    previous_Num0fMembers = 0;


void Buying_Requests (members *member, int nMembers )  
{
	int       id;
	string    PASSWORD;
	bool      is_Valid;
	cout<<"Please enter your PASSWORD :- " <<endl;  //password validation
		
	while (true) {	 	
		
		getline(cin, PASSWORD);	
		for( int i = 0; i < nMembers; i++ ){			
			if (member[i].password == PASSWORD){
				is_Valid = true;
				id = member[i].ID;
			}
		}
		
		if (is_Valid == true )
			break;
		else if(is_Valid == false)
			cout<<"invalid PASSWORD number..please retype your PASSWORD.. "<<endl;
	}
		
	cout<<endl;	
	int      num_OfRequests[20] = {0};
	int      num_OfRequestsIndex = 0;
	for( int k = 0; k < 30; k++ ){						
		if(arr_SOLD[k].seller == id &&  arr_SOLD[k].approvment == " waiting for the seller's approvment "){		
			cout<<"ITEM :- ";
			cout<<arr_SOLD[k].category<<endl;
			cout<<"THE BUYER'S ID :- ";
			cout<<arr_SOLD[k].buyer<<endl;
			cout<<"RQUESTED PRICE :- ";
			cout<<arr_SOLD[k].price<<endl;
			cout<<"==========================================="<<endl<<endl;
			num_OfRequests[num_OfRequestsIndex] = k;
			num_OfRequestsIndex++;		
		}
	}

		
	if (num_OfRequestsIndex > 0){
	
		cout<<"SEND YOUR REPLAY (by typing 'approved' or ' not approved' ) TO :- "<<endl;
		cout<<"**********************************************************************"<<endl;

		for( int i = 0; i < num_OfRequestsIndex; i++ ){

			cout<<"-Request number #"<<i+1<<" : ";
			getline(cin,arr_SOLD[num_OfRequests[i]].approvment);
			cout<<endl<<"____________________________________________________"<<endl;
			if(arr_SOLD[num_OfRequests[i]].approvment == "approved") //removing the item from the marketplace 
			
			{
				for(int i = 0; i < nMembers; i++ )
				{
					for (int j = 0; j < member[i].numOfItems; j++)
					{
											
						if(member[i].listOfItems[j].number == arr_SOLD[num_OfRequests[i]].numOfItem)						
							member[i].listOfItems[j].status = "sold";
					}
				}
			}	
		
		}
	
	}
		
	else if (num_OfRequestsIndex == 0)		
		cout<<"YOU DIDN'T RECEIVE ANY REQUESTS..."<<endl;

}



void Feedbacks (members * member, int nMembers)
{
	bool buyer_found = false;
	cout<<" Give your feedback on the other member(buyer/seller) :- "<<endl;
	cout<<"********************************************************"<<endl<<endl;
	cout<<"1. His ID :- ";
	cin>>feedback_Var.ID;
	cin.ignore();
					
	 
	while (true) {						
		for(int i = 0; i < nMembers; i++){							 
			if(member[i].ID == feedback_Var.ID){ 								 
				buyer_found = true;						
			}					
		}					
		
		if (buyer_found == true )		
			break;
		else if (buyer_found == false ){   
			cout<<"Invalid ID number ,,please re-type the buyer's ID"<<endl;
			cin>>feedback_Var.ID;
		    cin.ignore(); 
						
		}
				
	}
	
	cout<<"2. Comment :- " ;
	getline(cin,feedback_Var.comment);
	cout<<"3. Rating(from 1 to 5,, 5 is the highest) :- ";

	while (true) {	
		cin>>feedback_Var.rating;
		if(feedback_Var.rating == 1 || feedback_Var.rating == 2 || feedback_Var.rating == 3 || feedback_Var.rating == 4 || feedback_Var.rating == 5 )		
			break;		
		else 	
			cout<<"invalid entry ,,please enter a digit from 1 to 5 "<<endl;	
	}
		
	for( int i = 0 ; i < nMembers ; i++){			
		if(member[i].ID == feedback_Var.ID && feedback_Var.rating >= 3)		
			member[i].points+=1;
	
	}
		

}



void Adding_Items(members * member, int memberN ) 
{
	
	previous_Num0fItems=member[memberN].numOfItems;	
	cout<<endl<<"ENTER THE NUMBER OF ITEMS YOU WANT TO ADD :- ";	
	int num;	
	while (true) {
		
		cin>>num;
	    cin.ignore();
	    if(num > 0)	
			break; 
		else
			cout<<"Invalid entry..please retype a valid value"<<endl;
	}
	
	member[memberN].numOfItems+=num;

	for( int i = previous_Num0fItems; i < member[memberN].numOfItems; i++ ){

		cout<<endl;
		cout<<"the information of item number "<<i+1<<"."<<endl;
		cout<<"*************************************"<<endl<<endl;
	
		cout<<"The Item Number :- " ;
		cin>>member[memberN].listOfItems[i].number; 
		cin.ignore();
		cout<<endl;
		cout<<"The Category ( coins/ cars/ paintings/ books/ jewelries/ clothing ):- "; 		
		while (true){	  
			getline(cin,member[memberN].listOfItems[i].category);
			if (member[memberN].listOfItems[i].category == "coins" || member[memberN].listOfItems[i].category == "cars" || member[memberN].listOfItems[i].category == "paintings" || member[memberN].listOfItems[i].category == "books" || member[memberN].listOfItems[i].category == "jewelries" || member[memberN].listOfItems[i].category == "clothing" )	
				break;
			else
				cout<<" Invalid category name ,,please retype the name of the category "<<endl;
			
		}
		
		cout<<endl; 
		cout<<"The starting Bid Price:- " ;
		
		while (true) {		
			cin>>member[memberN].listOfItems[i].startingBidPrice;	
			if(member[memberN].listOfItems[i].startingBidPrice > 0) 
				break;
		   else
			   cout<<"Invalid entry..Please retype the starting bid price"<<endl;
		}
		cout<<endl;
		cout<<"The Start Date of the Auction process(day&month) :- " ;
		cin>>member[memberN].listOfItems[i].startingDate.day>>member[memberN].listOfItems[i].startingDate.month;
		cout<<endl;
		cout<<"The End Date of the Auction process(day&month) :- " ;
		cin>>member[memberN].listOfItems[i].endDate.day>>member[memberN].listOfItems[i].endDate.month;
		cin.ignore();
		cout<<endl;
		cout<<"The Status (available/sold) :- ";
		while (true){	
			
			getline(cin,member[memberN].listOfItems[i].status);
			if( member[memberN].listOfItems[i].status == "available" || member[memberN].listOfItems[i].status == "sold" )	
				break; 
		
			else 	
				cout<<"Invalid entry ,,,please type available or sold "<<endl;	
		}
	
	}


}



void Members_Info(members * member, int nMembers )
{
	for( int i = previous_Num0fMembers; i < nMembers; i++){
	
		cout<<"ENTER THE INFORMATION OF MEMBER NUMBER "<<i+1<<" :- "<<endl<<endl;
	    cout<<"E-mail :- ";
	    getline(cin,member[i].email); 
	    cout<<endl;
	    cout<<"Password :- ";
	    getline(cin,member[i].password);
	    cout<<endl;
	    cout<<"============================================="<<endl; 
	
	
	    cout<<"Name :- " ;
	    getline(cin,member[i].name);
	    cout<<endl;
	    cout<< "ID :- " ; 
	    cin>>member[i].ID;
	    cin.ignore();
	    cout<<endl;
	    cout<<"Address :- ";
	    getline(cin,member[i].address);
	    cout<<endl; 
	    cout<<"Phone Number :- ";
	    cin>>member[i].phoneNumber;
	    cout<<endl<<endl<<endl; 
	    member[i].points=0;



	   cout<<"DO YOU WANT TO ADD ITEMS TO OUR AUCTION (y/n) ?"<<endl;
	   char answer;
	   while (true){ 	  
		
		   cin>>answer;
	       if(answer =='y'){	
			   Adding_Items( member , i);			  
			   break;	 
		   }   
		   else if (answer == 'n'){			
			   cin.ignore();    
			   break; 	
		   }  
		   else cout<<"INVALID ENTRY..please enter (y/n) "<<endl;
	
	   }

	   cout<<endl<<endl;	
	}

}



void Transaction ( members * member, int memberN, int buyer_ID, int wanted_ItemN)
{
	int    bidPrice;
	char   answer; 
	bool   buyer_found=false;		

	while (true) {					
		
		for( int i = 0; i < memberN; i++ ){							
			if(member[i].ID == buyer_ID) 													
				buyer_found = true;							
		}	
		if (buyer_found == true) 
			break;				

		else if (buyer_found == false){		
			cout<<"Invalid ID number ,,please re-type the buyer's ID"<<endl;
			cin>>buyer_ID;	
		}	
	}

	bool item_found = false;
					

	while (true) {					  

		for( int i = 0; i < memberN; i++){ 					  
			for( int k = 0; k < member[i].numOfItems; k++ ){							 
				if(member[i].listOfItems[k].number == wanted_ItemN) 							  
					item_found = true ;				         
		
			}				 	
		}
					 
	
		if (item_found == true )
			break;				 
		else if( item_found == false ){
		
			cout<<"invalid number,,please eter the number of the item you want"<<endl;	
			cin>>wanted_ItemN;
	
		}				

	}	

		


	for(int i = 0; i< memberN; i++){	//iterating on the whole array to get the seller who put that item
	
		for(int j = 0; j < member[i].numOfItems; j++ ){

			if(member[i].listOfItems[j].number == wanted_ItemN){                           						
				cout<<"Are you willing to raise the Bid(y/n) ??"<<endl; 				
				while(true){			   
				
					cin>>answer; 					
					if(answer == 'y' || answer == 'n')						
						break;				
				
					else 
						cout<<"invalid answer,,please enter 'y' or 'n' "<<endl;				
				}			
			
				if(answer == 'y'){					
					cout<<" Enter the new Bid Price..."<<endl;				
				
					while (true) {						    					
					
						cin>>bidPrice;														
						if(bidPrice > member[i].listOfItems[j].startingBidPrice)						
							break;						
						else
							cout<<"invalid entry,,you should RAISE the bid ."<<endl ; ;			
				
					}			
				}				
		
				else if (answer == 'n')
					bidPrice = member[i].listOfItems[j].startingBidPrice;								
			

				while (true) {			//the other members are raiseing the bid on each other  
				
					cout<<" That item is now To member [ "<<buyer_ID<<" ] For [ "<<bidPrice<<" ]"<<endl;				
					cout<<"Does anyone want to RAISE THE BID to get that item(y/n)??"<<endl; 			
				
					while(true){
					
						cin>>answer; 					
						if(answer == 'y' || answer == 'n')		
							break;	        
					
						else
							cout<<"invalid answer,,please enter 'y' or 'n' "<<endl;	    	
					}									
				
					if(answer == 'y'){	
					
						cout<<" Enter your ID and the NEW BID PRICE.."<<endl ;
					    cin>>buyer_ID>>bidPrice ;	
					    buyer_found = false;	
						while (true) {		
						
							for(int i = 0; i < memberN; i++ ){
							
								if(member[i].ID == buyer_ID) 					
									buyer_found = true;
							}
						
							if(buyer_found == true) 
								break;
							
							else if (buyer_found == false){
								cout<<"Invalid ID number ,,please re-type the buyer's ID"<<endl;
							    cin>>buyer_ID;
						
							}
					
						}
				
					}
				
					else if (answer == 'n') 			
						break;
				
				}
				
			
				cout<<" THE ITEM NOW GOES TO MEMBER "<<buyer_ID<<" WITH PRICE "<<bidPrice<<endl<<endl; 			
				cout<<" the BUYING REQUEST has been sent to the seller...."<<endl;	
			
//Copying the information of the item that have been sold in arr_SOLD						
				for(int k = 0; k < memberN; k++ ){				
					if(member[k].ID == buyer_ID){	
					   
						arr_SOLD[COUNTER].numOfItem = member[i].listOfItems[j].number;
				     	arr_SOLD[COUNTER].buyer = member[k].ID;
						arr_SOLD[COUNTER].seller = member[i].ID;
						arr_SOLD[COUNTER].category = member[i].listOfItems[j].category;
						arr_SOLD[COUNTER].time.day = member[i].listOfItems[j].startingDate.day;
						arr_SOLD[COUNTER].time.month = member[i].listOfItems[j].startingDate.month;
						arr_SOLD[COUNTER].price = bidPrice;
						arr_SOLD[COUNTER].approvment = " waiting for the seller's approvment ";
						COUNTER++;
					
					}			
				}		
				
				cout<<"____________________thank you___________________"<<endl ;
									
		
			}		
		}
	}
}





void MARKETPLACE (members * member, int memberN )
{
	string    wanted_category;
	char      want_Item;
	int       buyer_ID,wantedItem, search_Choice1, search_Choice2, wanted_Price;
	int       available_ItemN=1;
	
	
	cout<<"____________________MARKETPLACE_____________________"<<endl<<endl<<endl;
	cout<<"DO YOU WANT TO SEARCH FOR A SPECIFIC ITEMS (click 1)??"<<endl;
	cout<<"********************************************************"<<endl;
	cout<<"OR DO YOU WANT TO DISPLAY ALL THA AVAILABLE ITEMS(click2)??"<<endl;
	cout<<"***********************************************************"<<endl;
	
	while(true){
	
		cin>>search_Choice1;
		if(search_Choice1 == 1 || search_Choice1 == 2) 	
			break; 
	    else
			cout<<" invalid entry,,please choose 1 or 2 " <<endl;	
	}
	
	if (search_Choice1 == 1){
	   
		cout<<endl<<endl;   
		cout<<"1.search by category."<<endl;
		cout<<"2.search by both category and price."<<endl;	
		while (true) {	
			cin>>search_Choice2;
			cout<<endl;
	        if(search_Choice2 == 1 || search_Choice2 == 2) 
				break; 
	        else 
				cout<<" invalid entry,,please choose 1 or 2 " <<endl;  
		}
	
	          	
		if(search_Choice2 == 1){
				   
			cout<<"-Enter the name of the category"<<endl;
			cout<<"(coins/cars/paintings/books/jewelries/clothing)"<<endl;
			
			while (true) {
	   			
				cin>>wanted_category; 
				if (wanted_category == "coins" || wanted_category == "cars" || wanted_category == "paintings" || wanted_category == "books" || wanted_category == "jewelries" || wanted_category == "clothing" )			
					break;
			    else 
				    cout<<endl<<endl<<" Invalid category name ,,please retype the name of the category "<<endl;		
			}
				
			for(int i = 0; i< memberN; i++){  //Displaying the item according to the wanted category 

				for(int j = 0; j < member[i].numOfItems; j++ ){
	
					if(member[i].listOfItems[j].category == wanted_category && member[i].listOfItems[j].status == "available"){
		
						cout<<" Item Number "<<available_ItemN<<" :- " <<endl;
					    cout<<"********************"<<endl<<endl;
						
						cout<<"The Seller Name :- "<<member[i].name<<endl;
						cout<<"The Seller ID : - "<<member[i].ID<<endl;
					    cout<<"Category :- "<<member[i].listOfItems[j].category<<endl;
						cout<<"Number :- "<<member[i].listOfItems[j].number<<endl;
						cout<<"Starting Bid Price :- " <<member[i].listOfItems[j].startingBidPrice<<endl;
			            cout<<"Starting Date of the Auction :- " <<member[i].listOfItems[j].startingDate.day<<" / "<<member[i].listOfItems[j].startingDate.month<<endl;
			            cout<<"End Date of the Auction :- "<<member[i].listOfItems[j].endDate.day<<" / "<<member[i].listOfItems[j].endDate.month<<endl;
						cout<<"STATUS :- "<<member[i].listOfItems[j].status<<endl;
						cout<<"Seller's Points :- "<<member[i].points<<endl<<endl;
				  	    cout<<"============================================================================="<<endl<<endl;	
						available_ItemN++;
					
					}
						
				}
			
			}

			
			
			if( available_ItemN == 1){	
				cout<<endl<<endl;
				cout<<" THERE'S NO ITEMS "<<endl;
		        cout<<"===================="<<endl;
            }
			
			else if (available_ItemN > 1){
				cout<<"DO YOU WANT TO CHOOSE AN ITEM?(y/n)"<<endl;			
				do{					
					while (true) {
						cin>>want_Item;				
						if(want_Item == 'y' || want_Item == 'n')					
							break; 				
						else 
							cout<<"invalid entry ,,please enter 'y' or 'n'"<<endl;	
					}						
					if (want_Item == 'y'){					
						cout<<" Enter your ID and Enter the NUMBER of the item you want.."<<endl;										
						cin>>buyer_ID>>wantedItem;				
					}	   
					else if( want_Item == 'n')
						 break;
					
					Transaction ( member,  memberN, buyer_ID,  wantedItem);
					cout<<endl<<"DO YOU WANT TO CHOOSE ANOTHER ITEM?(y/n)"<<endl;
				}while (want_Item == 'y');	    	
			}
		}
		

		
		else if (search_Choice2 == 2) {	  
			 
			cout<<"1.Enter the Name of the category(coins/cars/paintings/books/jewelries/clothing)"<<endl;
		    while (true) {	
				cin>>wanted_category; 
			    if (wanted_category == "coins" || wanted_category == "cars" || wanted_category == "paintings" || wanted_category == "books" || wanted_category == "jewelries" || wanted_category == "clothing" )	
					break; 
				else 
					cout<<endl<<endl<<" Invalid category name ,,please retype the name of the category "<<endl;
			 }

		     
			cout<<"2.Enter the Price you want"<<endl;
			while (true) {

				cin>>wanted_Price;
				if(wanted_Price > 0)			 
					break; 
				else				 
					cout<<endl<<endl<<"Invalid entry,,please enter a valid price. "<<endl;
			}
			 
			for(int i = 0; i < memberN; i++ ){

				for(int j = 0; j < member[i].numOfItems; j++){        //DISPLAYING THE ITEM ACCORDING TO THE WANTED PRICE AND CATEGORY

					if(member[i].listOfItems[j].category == wanted_category && member[i].listOfItems[j].startingBidPrice == wanted_Price && member[i].listOfItems[j].status == "available"){

						cout<<" Item Number "<<available_ItemN<<" :- " <<endl ;
					    cout<<"********************"<<endl<<endl ;
						
						cout<<"The Seller Name :- "<<member[i].name<<endl ;
						cout<<"The Seller ID : - "<<member[i].ID<<endl;
					    cout<<"Category :- "<<member[i].listOfItems[j].category<<endl ;
						cout<<"Number :- "<<member[i].listOfItems[j].number<<endl;
						cout<<"Starting Bid Price :- " <<member[i].listOfItems[j].startingBidPrice<<endl;
			            cout<<"Starting Date of the Auction :- " <<member[i].listOfItems[j].startingDate.day<<" / "<<member[i].listOfItems[j].startingDate.month<<endl;
			            cout<<"End Date of the Auction :- "<<member[i].listOfItems[j].endDate.day<<" / "<<member[i].listOfItems[j].endDate.month<<endl;
			            cout<<"STATUS :- "<<member[i].listOfItems[j].status<<endl;
						cout<<"Seller's Points :- "<<member[i].points<<endl<<endl;
				  	    cout<<"============================================================================="<<endl<<endl;
						available_ItemN++;
					}
				
				
				}
			
			 }
			 if( available_ItemN == 1){
				cout<<endl<<endl;
				cout<<" THERE'S NO ITEMS "<<endl;
		        cout<<"===================="<<endl;
            }	
			else if (available_ItemN > 1) {				
				 cout<<"DO YOU WANT TO CHOOSE AN ITEM?(y/n)"<<endl;							
				 do{

					 while (true) {
						 cin>>want_Item;										
						 if(want_Item == 'y' || want_Item == 'n')												
							 break; 										
						 else 
							 cout<<"invalid entry ,,please enter 'y' or 'n'"<<endl;					
					 }									 
					 if (want_Item == 'y'){
						 cout<<" Enter your ID and Enter the NUMBER of the item you want.."<<endl;																
						 cin>>buyer_ID>>wantedItem;								
					 }				 
					 else if( want_Item == 'n')		 
						 break;
					 
					 Transaction ( member,  memberN, buyer_ID,  wantedItem );					 
					 cout<<"DO YOU WANT TO CHOOSE ANOTHER ITEM?(y/n)"<<endl;				
				 }while (want_Item == 'y');	    			
			 
			
			}

		}	

}	

else if (search_Choice1 == 2){
		
	cout<<"THOSE ARE ALL THE AVAILABLE ITEMS :- "<<endl;	
	cout<<"==================================="<<endl<<endl<<endl;	
	for(int i = 0; i < memberN; i++ ){
   
		for(int j = 0; j < member[i].numOfItems; j++ ){
			
			if(member[i].listOfItems[j].status == "available" ){             //DISPLAYING ALL THE AVAILABLE ITEMS OR THE ITEMS THAT THE SELLER DID NOT APPROVE ON IT'S REQUEST YET
	
				cout<<" Item Number "<<available_ItemN<<" :- " <<endl;
				cout<<"********************"<<endl<<endl;
					
				cout<<"The Seller Name :- "<<member[i].name<<endl;
				cout<<"The Seller ID : - "<<member[i].ID<<endl;
				cout<<"Category :- "<<member[i].listOfItems[j].category<<endl;
			    cout<<"Number :- "<<member[i].listOfItems[j].number<<endl;
			    cout<<"Starting Bid Price :- " <<member[i].listOfItems[j].startingBidPrice<<endl;
			    cout<<"Starting Date of the Auction :- " <<member[i].listOfItems[j].startingDate.day<<" / "<<member[i].listOfItems[j].startingDate.month<<endl;
			    cout<<"End Date of the Auction :- "<<member[i].listOfItems[j].endDate.day<<" / "<<member[i].listOfItems[j].endDate.month<<endl;
			    cout<<"STATUS :- "<<member[i].listOfItems[j].status<<endl;
			    cout<<"Seller's Points :- "<<member[i].points<<endl<<endl;
				cout<<"============================================================================="<<endl<<endl;
			    available_ItemN++;
				
			}
				
		}
			
	}
		
	if( available_ItemN == 1){
        
		cout<<endl<<endl;
		cout<<" THERE'S NO ITEMS "<<endl;
		cout<<"===================="<<endl;       
	}
		 
	else if (available_ItemN > 1){
				 
		cout<<"DO YOU WANT TO CHOOSE AN ITEM?(y/n)"<<endl;									 
		do{
			
			while (true) {		 
				cin>>want_Item;													
				if(want_Item == 'y' || want_Item == 'n')																	 
					break; 										
				else 
					cout<<"invalid entry ,,please enter 'y' or 'n'"<<endl;					
					
			}									
					 
			if (want_Item == 'y'){			 
				cout<<" Enter your ID and Enter the NUMBER of the item you want.."<<endl;																
			    cin>>buyer_ID>>wantedItem;												
			}	
					  
			else if( want_Item == 'n')					
				break;

			Transaction ( member,  memberN, buyer_ID,  wantedItem );								 
			cout<<"DO YOU WANT TO CHOOSE ANOTHER ITEM?(y/n)"<<endl;				
				 
				 
		}while (want_Item == 'y');	    				 
		
	}

}
}




void MONTHLY_REPORT()
{
	
	int     category_Counter[6] = {0};
	int     top_category_NumOfElements , top_categoryINDEX = -1;
	string  top_category_name;
	int     rq_month;


	for(int i = 0; i < 30; i++){
	
		if(arr_SOLD[i].category == "coins" && arr_SOLD[i].approvment == "approved")
			category_Counter[0]++;
	    else if (arr_SOLD[i].category == "cars" && arr_SOLD[i].approvment == "approved")
		    category_Counter[1]++;
	    else if (arr_SOLD[i].category == "paintings" && arr_SOLD[i].approvment == "approved")
		    category_Counter[2]++;
	    else if (arr_SOLD[i].category == "books" && arr_SOLD[i].approvment == "approved")
		    category_Counter[3]++;
	    else if (arr_SOLD[i].category == "jewelries" && arr_SOLD[i].approvment == "approved")
		    category_Counter[4]++;
	    else if (arr_SOLD[i].category == "clothing" && arr_SOLD[i].approvment == "approved")
		    category_Counter[5]++;
    }

	top_category_NumOfElements = category_Counter[0];

	for( int i = 1; i < 6 ; i++ ){	
		if(category_Counter[i] > top_category_NumOfElements){
		
			top_category_NumOfElements = category_Counter[i];
		    top_categoryINDEX=i;	
		}

	}
	
	if( top_categoryINDEX == -1){

		if(category_Counter[0] > 0)
			top_categoryINDEX = 0;
	}

	switch (top_categoryINDEX){
	case 0 :
		top_category_name = "coins";
		break;
    case 1 :
	    top_category_name = "cars";
	    break;
    case 2 :
	    top_category_name = "paintings";
	    break;
    case 3 :
	    top_category_name = "books";
	    break;
    case 4 : 
	    top_category_name = "jewelries";
	    break;
    case 5 :
	    top_category_name = "clothing";
	    break;
	case -1 :
		top_category_name = "nothing";
	default:
		break;

	}

	
	cout<<"               TOP CATEGORY OVERALL IS "<<top_category_name<<endl;         //DISPLAYING THE REPORT UPON ALL THE MONTHS 
    cout<<"               ================================= "<<endl<<endl;
    cout<<"\t\tCATEGORIES\t\t\tNUMBER OF SOLD ITEMS"<<endl;
    cout<<"\t\t**********\t\t\t*****************"<<endl<<endl;
    cout<<"\t\t1.coins \t\t\t "<<category_Counter[0]<<endl;
    cout<<"\t\t2.cars \t\t\t\t "<<category_Counter[1]<<endl;
    cout<<"\t\t3.paintings \t\t\t "<<category_Counter[2]<<endl;
    cout<<"\t\t4.books \t\t\t "<<category_Counter[3]<<endl;
    cout<<"\t\t5.jewelries \t\t\t "<<category_Counter[4]<<endl;
    cout<<"\t\t6.clothing \t\t\t "<<category_Counter[5]<<endl;


    cout<<"Enter the month you want to see it's monthly report(1,2,3...) :- ";
	while (true) {

   
		cin>>rq_month;
		if(rq_month == 1 || rq_month == 2 || rq_month == 3 || rq_month == 4 || rq_month == 5 || rq_month == 6 || rq_month == 7 || rq_month == 8 || rq_month == 9 || rq_month == 10 || rq_month == 11 || rq_month == 12)		
			break;
		else 	
			cout<<"invalid entery please enter a valid month number "<<endl;
	}
	
	cout<<endl<<endl;
	
	for(int i = 0; i < 6; i++)	
		category_Counter[i] = 0;

	
	for(int i = 0; i < 30; i++ ){

		if(arr_SOLD[i].category == "coins" && arr_SOLD[i].time.month == rq_month && arr_SOLD[i].approvment == "approved")
			category_Counter[0]++;
	    else if (arr_SOLD[i].category == "cars" && arr_SOLD[i].time.month == rq_month && arr_SOLD[i].approvment == "approved")
		    category_Counter[1]++;
	    else if (arr_SOLD[i].category == "paintings" && arr_SOLD[i].time.month == rq_month && arr_SOLD[i].approvment == "approved")
		    category_Counter[2]++;
	    else if (arr_SOLD[i].category == "books" && arr_SOLD[i].time.month == rq_month && arr_SOLD[i].approvment == "approved")
		    category_Counter[3]++;
	    else if (arr_SOLD[i].category == "jewelries" && arr_SOLD[i].time.month == rq_month && arr_SOLD[i].approvment == "approved")
		    category_Counter[4]++;
	    else if (arr_SOLD[i].category == "clothing" && arr_SOLD[i].time.month == rq_month && arr_SOLD[i].approvment == "approved")
		    category_Counter[5]++;

	}
	
	top_categoryINDEX = -1;
	top_category_NumOfElements = category_Counter[0];
	for( int i = 1; i < 6 ; i++ ){	
		if(category_Counter[i] > top_category_NumOfElements){	

			top_category_NumOfElements = category_Counter[i];
 		    top_categoryINDEX = i;		
		}
	
	}
	if( top_categoryINDEX == -1){

		if(category_Counter[0] > 0)
			top_categoryINDEX = 0;
	}

	switch (top_categoryINDEX){
	
	case 0 :
		top_category_name = "coins";
	    break;
	case 1 :
	    top_category_name = "cars";
		break;
    case 2 :
		top_category_name = "paintings";
	    break;
    case 3 :
	    top_category_name = "books";
	    break;
    case 4 : 
	    top_category_name = "jewelries";
	    break;
    case 5 :
	    top_category_name = "clothing";
	    break;
	case -1 :
		top_category_name = "nothing";
    default:
	    break;
}

	cout<<"               TOP CATEGORY of that month IS ["<<top_category_name<<"]"<<endl;  //DISPLAYING THE REPORT UPON THE REQUIRED MONTH ONLY
    cout<<"               ================================================ "<<endl<<endl;
    cout<<"\t\tCATEGORIES\t\t\tNUMBER OF SOLD ITEMS"<<endl;
    cout<<"\t\t**********\t\t\t*****************"<<endl<<endl;
    cout<<"\t\t1.coins \t\t\t "<<category_Counter[0]<<endl;
    cout<<"\t\t2.cars \t\t\t\t "<<category_Counter[1]<<endl;
    cout<<"\t\t3.paintings \t\t\t "<<category_Counter[2]<<endl;
    cout<<"\t\t4.books \t\t\t "<<category_Counter[3]<<endl;
    cout<<"\t\t5.jewelries \t\t\t "<<category_Counter[4]<<endl;
    cout<<"\t\t6.clothing \t\t\t "<<category_Counter[5]<<endl;

}



void display_MyItems( members * member, int nMembers)
{
	bool      i_Sold=false , i_Bought=false;
	bool      is_Valid=false;
	string    PASSWORD;
	int       id;
	cout<<"Please enter your PASSWORD..........."<<endl;

	while (true) {			
		getline(cin,PASSWORD);				
		for( int i = 0; i < nMembers; i++){		
			if(member[i].password == PASSWORD){
				is_Valid = true;
				id = member[i].ID;
			}	
		}
		
		if (is_Valid == true)
			break;		
		else if(is_Valid == false)
			cout<<"invalid PASSWORD number..please enter a valid value "<<endl;
	}

		
	cout<<endl<<endl;


	cout<<"THE ITEMS YOU WANT :- "<<endl<<endl;
	for( int i = 0; i < 30; i++){
		if( arr_SOLD[i].buyer == id){

			i_Bought = true;
		    cout<<"-"<<arr_SOLD[i].category<<",\t Price :-"<<arr_SOLD[i].price<<",\t Seller :-"<<arr_SOLD[i].seller<<",\t Seller's response :-"<<arr_SOLD[i].approvment<<endl<<endl;
		
		}
	
	}
	
	if (i_Bought == false)	
		cout<<"YOU DIDN'T BUY ANY ITEMS YET..."<<endl<<endl;

	cout<<"THE ITEMS YOU SOLD :- "<<endl<<endl;
	for( int i = 0; i < 30; i++ ){	
		if( arr_SOLD[i].seller == id && arr_SOLD[i].approvment=="approved" ){

			i_Sold = true;
		    cout<<"-"<<arr_SOLD[i].category<<",\t Price :-"<<arr_SOLD[i].price <<",\t Buyer :- "<<arr_SOLD[i].buyer<<endl;
		
		}
	}
	cout<<endl<<endl;
	
	if (i_Sold == false)
		cout<<"YOU DIDN'T SELL ANYTHING YET...."<<endl;

	else{
		char ans;
		cout<<"can you give us your Feedback about the buyer(y/n)??"<<endl;
		cout<<"------------------------------------------------------"<<endl;
		while (true) {
			cin>>ans;		
			if (ans == 'y' || ans == 'n')
				break;
			else 
				cout<<"invalid entery... please enter 'y' or 'n' "<<endl;
		}
		if(ans == 'y')
			Feedbacks ( member, nMembers);
	}
}


int main()
{
	
	
	int   numOfMembers = 0;

	cout<<"________________________________________WELCOME TO TODAY'S AUCTION______________________________________"<<endl<<endl<<endl<<endl;
	cout<<"ENTER THE NUMBER OF MEMBERS PARTICIPATING IN TODAY'S AUCTION :-  ";

	while (true) {
	cin>>numOfMembers;
	cin.ignore();
	if(numOfMembers > 0)
		break; 
	else cout<<"Invalid entry..please retype a valid value"<<endl;
	}
	
	Members_Info(member, numOfMembers );


	while (true) {

		cout<<endl<<endl<<endl;
	    cout<<"==================================================================="<<endl;
	    cout<<endl<<"__________________________MAIN MENU___________________________"<<endl<<endl;

	    cout<<"1. GO TO THE MARKETPLACE TO CHOOSE ITEMS AND START BIDDING (click 1)"<<endl;
	    cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
	    cout<<"2. MONTHLY REPORT (click 2 ) " <<endl; 
	    cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
	    cout<<"3. DISPLAY MY ITEMS (click 3) " <<endl;
	    cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
	    cout<<"4. ADD ANOTHER ITEMS (click 4)" <<endl;
	    cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl; 
	    cout<<"5. SIGN UP FOR A NEW MEMBER (click 5 ) "<<endl;
	    cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
		cout<<"6. RECORD YOUR FEEDBACK ABOUT ANOTHER MEMBER (click 6) "<<endl; 
		cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
        cout<<"7. THE RECEIVED BUYING REQUESTS (click 7 ) " <<endl; 
		cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
		cout<<"8. EXIT (click 8 ) "<<endl;
	    cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
	    
		int choiceOfMainMenu ;
 
		while (true) {
		
			cin>>choiceOfMainMenu ; 
		    cin.ignore();
		    if(choiceOfMainMenu != 1 && choiceOfMainMenu != 2 && choiceOfMainMenu != 3 && choiceOfMainMenu != 4 && choiceOfMainMenu != 5 && choiceOfMainMenu != 6 && choiceOfMainMenu != 7 && choiceOfMainMenu != 8)		 
				cout<<"Invalid entry..please retype a valid value"<<endl;	
			else
				break;	
		}	
	
		if(choiceOfMainMenu == 1)
			MARKETPLACE(member,  numOfMembers);


		else if (choiceOfMainMenu == 2)
			MONTHLY_REPORT();


		else if(choiceOfMainMenu == 3)
			display_MyItems(member, numOfMembers );


		else if (choiceOfMainMenu == 4){
	
			bool validID = false;
			int id, i, index;
			cout<<"Enter your ID :- " ;


			while (true) {
				cin>>id;                              			
				for( i = 0; i < numOfMembers; i++ )
					if(member[i].ID == id) 
					{
						validID=true;
						index=i;
					}
					
				if (validID == true) 
					break;
				else if (validID == false)
					cout<<"invalid ID please retype your ID.."<<endl;
			}
				
			Adding_Items( member, index);
		}


		else if(choiceOfMainMenu == 5){
			
			previous_Num0fMembers = numOfMembers;
			numOfMembers++;
			Members_Info(member, numOfMembers );
		}


		else if(choiceOfMainMenu == 6)
			Feedbacks ( member, numOfMembers);
		

		else if (choiceOfMainMenu == 7)
			 Buying_Requests (member, numOfMembers );


		else if (choiceOfMainMenu == 8)
			break;
	
	}

		system ("pause");
		return 0 ; 
}
  
