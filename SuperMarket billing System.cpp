#include<iostream>
#include<fstream>


using namespace std;

class shopping
{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
	public:
		void menu();
	    void admin();
		void seller();
		void add();
		void edit();
		void rem();
		void list();
		void receipt();	
		
	    
		
};

   int main()
 {
 	shopping supermarket;
 	supermarket.menu();
 }
       
void shopping::menu()
{
	int choice;
	string email;
	string password;
	cout<<"\n\t\t\t\t\t-----------------------------------------\n";
	cout<<"\n";
	cout<<"\n\t\t\t\t\t           Supermarket Main Menu         \n";
	cout<<"\n";
	cout<<"\n\t\t\t\t\t-----------------------------------------\n";
	cout<<"\n";
	cout<<"\t\t\t\t\t |            1) Administrator           | \n";
	cout<<"\n";
	cout<<"\t\t\t\t\t |            2) Seller                  | \n";
	cout<<"\n";
	cout<<"\t\t\t\t\t |            3) Exit                    | \n";
	cout<<"\n";
	cout<<"\n\t\t\t\t             Please Select!              ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
		{
				
		cout<<"\t\t\t Please Login  \n";
		cout<<"\t\t\t---------------------\n";
		cout<<"\t\t\t Enter Email    \n";
		cout<<"\t\t\t---------------------";
		cout<<"\n\t\t\t\t";
		
		cin>>email;
		cout<<"\t\t\t---------------------\n";
		cout<<"\t\t\t Enter Password  \n";
        cout<<"\t\t\t---------------------";
        cout<<"\n\t\t\t\t";
        cin>>password;
        cout<<"\t\t\t---------------------";
        
        if(email=="uiit@email.com"&&password=="uiit")
          {
		  
			admin();
		  }
		else
		{
	      cout<<"Invalid username/password";		
	    }  	
	   }
		break;
		
		case 2:
		{
		
			seller();
			break;
		}
		case 3:
			{
			
		       exit(0);
			    break;
			}
	    default:
		    {
		    	system("cls");
		       cout<<" \n\n\tPlease Select from given options";
			   menu();
			}		
		
	}
	
}

void shopping::admin()
{
	system("cls");
	int choice;
	cout<<"\n\t\t\t\t\t-----------------------------------------\n";
	cout<<"\n";
	cout<<"\n\t\t\t\t\t           Administrator Menu            \n";
	cout<<"\n";
	cout<<"\n\t\t\t\t\t-----------------------------------------\n";
	cout<<"\n";
	cout<<"\n\t\t\t\t |____________1) Add product______________|\n";
	cout<<"\n";
	cout<<"\n\t\t\t\t |____________2) Edit product_____________|\n";
	cout<<"\n";
	cout<<"\n\t\t\t\t |____________3) Delete product___________|\n";
	cout<<"\n";
	cout<<"\n\t\t\t\t |____________4) Back to main menu________|\n";
	
	cout<<"\n\t\t\t  Please Enter your choice ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			add();
			break;
		case 2:
		     edit();
			 break;
		case 3:
		     rem();
		     break;
		case 4:
			system("cls");
		     menu();
			 break;
		default:
		     system("cls");
			 cout<<"\n\tInvalid Choice";
			 admin();	 	 	 	
	}
	
	
}

void shopping::seller()
{
	system("cls");
	int choice;
	cout<<"\n\t\t\t\t\t-----------------------------------------\n";
	cout<<"\n";
	cout<<"\n\t\t\t\t\t             Seller Menu                 \n";
	cout<<"\n";
	cout<<"\n\t\t\t\t\t-----------------------------------------\n";
	cout<<"\n";
	cout<<"\n\t\t\t________1) Sale Product________\n";
	cout<<"\n";
	cout<<"\n\t\t\t________2) Go Back_____________\n";
    cout<<"\n\t\t\t  Enter Your Choice:  ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
		case 2:
			system("cls");
		    menu();
		default:
		    system("cls");
			cout<<"\n\t Invalid Option ";
			seller();		
	}
}

void shopping::add()
{
	system("cls");
	fstream data;
	
	int code;
	int token=0;
	float pprice;
	float discount;
	string name;
	
	cout<<"\n\t\t\t\t\t-----------------------------------------\n";
	cout<<"\n";
	cout<<"\n\t\t\t\t\t            Add Menu                     \n";
	cout<<"\n";
	cout<<"\n\t\t\t\t\t-----------------------------------------\n";
	cout<<"\n";
	
	cout<<"\n\t\t\t Add new Product \n";
	cout<<"\t\t\t___________________";
	cout<<"\n\t\t\t Enter Product code: ";
	cin>>pcode;
	cout<<"\n\t\t\t Enter Product name: ";
	cin>>pname;
	cout<<"\n\t\t\t Price of Product: ";
	cin>>price;
	cout<<"\n\t\t\t Discount on Product: ";
	cin>>dis;
	
	data.open("productdata.txt", ios::app|ios::in);
	if(!data)
	{
		data.open("productdata.txt", ios::app|ios::out);
		data<<"  "<<pcode<<"   "<<pname<<"  "<<price<<"   "<<dis<<"\n";
		data.close();
	}
	else
	{
	
		while(data>>code>>name>>pprice>>discount)
		{
			if(code==pcode)
			   token++;
			
			data>>code>>name>>pprice>>discount;
			
		}
		data.close();
		
		if(token==1)
		{
			system("cls");
			cout<<"\n\t This Product is already added \n\t  Add another product";
			admin();
		}
		else
		{
			data.open("productdata.txt", ios::app|ios::out);
			data<<"  "<<pcode<<"   "<<pname<<"  "<<price<<"   "<<dis<<"\n";
			data.close();
			
		}
	}
	admin();
 	cout<<"\n\t\t\t Record Added";
}

void shopping::edit()
{
	system("cls");
	fstream data, data1;
	
	int pkey;
	int token=0;
	int code;
	float pprice;
	float discount;
	string name;
	
	cout<<"\n\t\t\t\t\t-----------------------------------------\n";
	cout<<"\n";
	cout<<"\n\t\t\t\t\t            Edit Menu                    \n";
	cout<<"\n";
	cout<<"\n\t\t\t\t\t-----------------------------------------\n";
	cout<<"\n";
	cout<<"\n\t\t\t\t Modify The Record ";
	cout<<"\n\t\t\t\t____________________";
	cout<<"\n\t\t\t Product code:  ";
	cin>>pkey;
	
	data.open("productdata.txt", ios::in);
	if(!data)
	{
		cout<<"\n\n Product does not exit! ";
	}
	else
	{
		data1.open("productdata1.txt", ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
	  while(!data.eof())
	  {
	  	if(pkey==pcode)
	  	{
	  		cout<<"\n\t\t\t Product new code: ";
	  		cin>>code;
	  		cout<<"\n\t\t\t Name of Product:  ";
	  		cin>>name;
	  		cout<<"\n\t\t\t Price of Product:  ";
	  		cin>>pprice;
	  		cout<<"\n\t\t\t Discount on Product:  ";
	  		cin>>discount;
	  		data1<<"  "<<code<<"  "<<name<<"  "<<pprice<<"  "<<discount<<" \n";
	  		cout<<"\n\n\t\t\t\t Recored Edited ";
	  		token++;
	  		
		}
		else
		{
			data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis;
		}
		data>>pcode>>pname>>price>>dis;
	  }
	  data.close();
	  data1.close();
	  
	  remove("productdata.txt");
	  rename("productdata1.txt","productdata.txt");
	  
	  if(token==0)
	  {
	  	cout<<"\n\n\t\t Record not found ";
	  }
		
	}
}

 void shopping::rem()
 {
 	system("cls");
 	fstream data, data1;
 	char choice;
 	int pkey;
 	int token=0;
 	cout<<"\n\t\t\t\t\t-----------------------------------------\n";
	cout<<"\n";
	cout<<"\n\t\t\t\t\t            Delete Menu                  \n";
	cout<<"\n";
	cout<<"\n\t\t\t\t\t-----------------------------------------\n";
	cout<<"\n";
 	cout<<"\n\t\t Delete Product ";
 	cout<<"\n\t\t________________";
 	cout<<"\n\n\t Enter Product Key ";
 	cin>>pkey;
 	data.open("productdata.txt", ios::in);
 	if(!data)
 	{
 		cout<<"File does not exist ";
 		
	}
	else
	{
		data1.open("productdata1.txt", ios::app|ios::out);
		while(data>>pcode>>pname>>price>>dis)
		{
			if(pcode==pkey)
			{
				cout<<"\n\t\t\t Product deleted successfully ";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("productdata.txt");
		rename("productdata1.txt", "productdata.txt");
		
		if(token==0)
		{
			cout<<"Record not found ";
			cout<<"\nDo you want to delete another another product?";
			cin>>choice;
			if(choice=='y'||choice=='Y')
			 rem();
		
		}
		
	}
		
			
 }

 void shopping::list()
 {
 	system("cls");
 	fstream data;
 	data.open("productdata.txt", ios::in);
 	cout<<"\n\t\t\t\t\t Product list";
 	cout<<"\n\n\t\t\t___________________________________________________\n";
 	cout<"\t\t\t\tProduct No \t\t Name \t\t Price \n";
  	cout<<"\n\n\t\t\t___________________________________________________\n";
	
	while(data>>pcode>>pname>>price>>dis)
	{
		cout<<"\t\t\t"<<pcode<<" \t\t "<<pname<<" \t\t "<<price<<" \n";
		cout<<"\n\n\t\t\t___________________________________________________\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();  	
 	
 }
 
 void shopping::receipt()
 {
 	
 	system("cls");
 	fstream data;
 	
 	int codearray[200];
 	int qarray[200];
 	char choice;
 	int count=0;
 	float amount=0;
 	float discount=0;
 	float total=0;
 	
 
	data.open("productdata.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n Empty database";
	}  
	else
	{     
		data.close();
		cout<<"\t\t\t";
		    list();
			cout<<"\n\t\t\t\t\t|________________________________________|\n";
	        cout<<"\t\t\t\t\t|                                        | \n ";
	        cout<<"\n\t\t\t\t\t|               Receipt                  | \n";
	        cout<<"\t\t\t\t\t|                                        | \n";
	        cout<<"\n\t\t\t\t\t|________________________________________|\n";
	        cout<<"\n";
	        do
	        {     
	        	cout<<"\n\nEnter Product code: ";   
	        	cin>>codearray[count];    
	        	cout<<"\n Enter Product Quantity";
	        	cin>>qarray[count];
	        	for(int i=0; i<count; i++)
	        	{   
	        		if(codearray[count]=codearray[i])
	        		{
					
	        		   cout<<"\n\n Duplicate Product code, please try again: ";
	        		   receipt();
	        		}
				}
				count++;
				cout<<"\n\n Do you want to buy another product? if yes then press y: ";
				cin>>choice; 
			}
			while(choice== 'y' || choice== 'Y');
			  
			cout<<"\n\n\t\t\t______________________Receipt___________________________\n";
			cout<<"\n\tProduct No    Product name   Quantity    price    Amount   Discount\n";
			
			for(int i=0; i<count; i++)
			{
				data.open("productdata.txt",ios::in);
				while(data>>pcode>>pname>>price>>dis)
				{
					if(pcode==codearray[i])
					{
						amount=price*qarray[i];
						dis=amount-(amount*dis/100);
						total=total+dis;
						cout<<"\n\t"<<pcode<<"\t      "<<pname<<"\t      "<<qarray[i]<<"\t      "<<price<<"\t      "<<amount<<"\t      "<<dis;
						
					}
					data>>pcode>>pname>>price>>dis;
					
					
				}
			}
			data.close();
			
	 
		
		
	}
	
	cout<<"\n\t\t_______________________________________________________________";
	cout<<"\n Total Amount: "<<total;
	
	cout<<"\n\n\tPress n to go back to seller menu";
	cin>>choice;
	if(choice=='n' || choice=='N')
	{
		seller();
	}
	
 }
 
 
