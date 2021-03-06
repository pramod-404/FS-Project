	#include<iostream> 
	#include<fstream>
	#include<stdio.h>
	#include<string.h>
	#include<process.h>
	#include<stdlib.h>
	#define SIZE 55
	using namespace std;
	char buffer[SIZE+1];
	class student
	{
		 char usn[15];
		 char total[20];
		 char percentage[20];
		 char name[20];
		 char dept[5];
		 char sub1[10],sub2[10],sub3[10],sub4[10];
	 public:
		 void getdata();
		 void putdata();
		 void pack();
		 void unpack();
		 void insert();
		 void display();
		 void modify(char *key);
		 void search(char *key);
		 void search1(char *key1);
		 void search3(char *key3,char *dept3);
		 void Delete();
	};
	void sortAndAdd(string dep);
	void clearFile(string fileName);
	void copyFile(string fromFile, string toFile);

//Delete Function/////

	void student::Delete()
	{
			
 		int found;
	 	string line;
	 	string dep;
	 	string buffer;
		ifstream fin;
		fin.open("record.txt");
		ofstream temp;
		temp.open("temp.txt");
		cout<< "\t\tWhich USN do you want to remove?\n ";
		cout<<"\t\t";
		cin >>usn;
		cout << "\t\tWhich department this usn belongs to (ISE, CSE, CIVIL, MECH, EEE, ECE)" << endl;
		cout<<"\t\t";
		cin >> dep;
		dep.insert(0, "|");
		dep.insert(0, usn);
		cout<<"\n\t\tDeleted Successfully"<<endl;
		while(getline(fin,line)){
			found = line.find(dep);
		    if(found == string::npos)
		    {
		    temp<<line<< endl;
		    }
		}
		temp.close();
		fin.close();
		remove("record.txt");
		rename("temp.txt","record.txt");
		 }

/////getdata//////

	void student::getdata()
	{
		 cout<<"\t\tEnter the student Usn\n";
		 cout<<"\t\t";
		 cin>>usn;
		 cout<<"\t\tEnter the Department Name\n";
		 cout<<"\t\t";
		 cin>>dept;
		 cout<<"\t\tEnter the Student Name\n";
		 cout<<"\t\t";
		 cin>>name;
		 cout<<"\t\tEnter the marks of subject 1\n";
		 cout<<"\t\t";
		 cin>>sub1;
		 cout<<"\t\tEnter the marks of subject 2\n";
		 cout<<"\t\t";
		 cin>>sub2;
		 cout<<"\t\tEnter the marks of subject 3\n";
		 cout<<"\t\t";
		 cin>>sub3;
		 cout<<"\t\tEnter the marks of subject 4\n";
		 cout<<"\t\t";
		 cin>>sub4;
	}

//putdata////
	void student::putdata()
	 {
	  	cout<<"\t\t"<<usn<<"\t"<<dept<<"\t\t"<<name<<"\t\t"<<sub1<<"\t"<<sub2<<"\t"<<sub3<<"\t"<<sub4<<"\t"<<total<<"\t"<<percentage<<endl;
	 }
 
 // pack///
 
 void student::pack(){
	 int m1, m2, m3, m4, total;
	 float percentage;
	 char totalBuffer[20];
	 strcpy(buffer,usn); strcat(buffer,"|");
	 strcat(buffer,dept); strcat(buffer,"|");
	 strcat(buffer,name); strcat(buffer,"|");
	 strcat(buffer,sub1); strcat(buffer,"|");
	 strcat(buffer,sub2); strcat(buffer,"|");
	 strcat(buffer,sub3); strcat(buffer,"|");
	 strcat(buffer,sub4); strcat(buffer,"|");
	 
	 //add the total marks
	 m1 = atoi(sub1);
	 m2 = atoi(sub2);
	 m3 = atoi(sub3);
	 m4 = atoi(sub4);
	 total = m1+m2+m3+m4;
	 sprintf(totalBuffer, "%d", total);
	 strcat(buffer, totalBuffer);
	 strcat(buffer,"|");
	 percentage = (float)total/4.0;
	 sprintf(totalBuffer, "%.2f", percentage);
	 strcat(buffer, totalBuffer);
	 strcat(buffer,"\n");
	 }
	 
	// Unpack.////////
	
	void student::unpack()
	{
		 char *p;
		 p=strtok(buffer,"|"); strcpy(usn,p);
		 p=strtok(NULL,"|"); strcpy(dept,p);
		 p=strtok(NULL,"|"); strcpy(name,p);
		 p=strtok(NULL,"|"); strcpy(sub1,p);
		 p=strtok(NULL,"|"); strcpy(sub2,p);
		 p=strtok(NULL,"|"); strcpy(sub3,p);
		 p=strtok(NULL,"|"); strcpy(sub4,p);
		 p=strtok(NULL,"|"); strcpy(total,p);
		 p=strtok(NULL,"\n"); strcpy(percentage,p);
	}
	
	//insert///
	
	void student::insert()
	{
		 getdata();
		 pack();
		 ofstream fout("record.txt",ios::app);
		 fout<<buffer;
		 fout.close();
	}
	
	//display//
	
	void student::display() 
			{ 
 				ifstream fin("record.txt"); 
 				while(!fin.eof()) 
				{ 
 				fin.getline(buffer,SIZE+1,'\n');  
				 if(fin.fail())
				 	break;
					unpack(); 
 					putdata(); 
					} 
					
 				fin.close();
			}
	
	

	//Search by Department//
	
	void student::search(char *key)
	{
		 ifstream fin("record.txt");
		 int count=0;
		while(!fin.eof())
		{
		 fin.getline(buffer,SIZE+1,'\n');
		 if(fin.fail()) break;
		 unpack();
		 if(strcmp(dept,key)==0)
		 {
		putdata();
		count++;
		 }
		}
		 cout<<"\t\ttotal records found:"<<count<<endl;
		 fin.close();
	}
	
	//search by USN///
	
	void student::search1(char *key1)
	{
		 ifstream fin("record.txt");
		 int count=0;
		while(!fin.eof())
		{
		 fin.getline(buffer,SIZE+1,'\n');
		 if(fin.fail()) break;
		 unpack();
		 if(strcmp(usn,key1)==0)
		 {
		putdata();
		count++;
		 }
		}
		 cout<<"\t\ttotal records found:"<<count<<endl;
		 fin.close();
	}
	
	//Report
	
	void student::search3(char *key3,char *dept3)
	{
		 ifstream fin("record.txt");
		 int count=0;
		while(!fin.eof())
		{
		 fin.getline(buffer,SIZE+1,'\n');
		 if(fin.fail()) break;
		 unpack();
		 if(strcmp(usn,key3)==0)
		 {
		 	if(strcmp(dept,dept3)==0)
		 		{
				putdata();
				count++;
		 		}
		}	
	}
	cout<<"\n\t\ttotal records found:"<<count<<endl<<endl;
		 fin.close();
	}
	//Modify//
	
	
	void student::modify(char *key)
	{
		 ifstream fin("record.txt");
		ofstream fout("temp.txt");
		 int count=0;
		 while(!fin.eof())
		 {
		 fin.getline(buffer,SIZE+1,'\n');
		 if(fin.fail()) break;
		 unpack();
		 if(strcmp(usn,key)==0)
		 {
		getdata();
		count++;
		 }
		 pack();
		 fout<<buffer;
		 }
		 if(count==0)
		 cout<<"\t\tUSN not found:"<<endl;
		 else
		 cout<<"\t\tModified."<<endl;
		 fin.close();
		 fout.close();
		 remove("record.txt");
		 rename("temp.txt","record.txt");
	}


//////////////////////////////////////////////////////////////////////////////////
void sortAndAdd(string dep){

	string buffer, USN;
	int department[40];
	int checkDep;
	int totalStud = 0;
	int iterate, i=0, j=0, temp;

	ifstream readFile("record.txt", ios::in | ios::app);
	ofstream writeFile("dummy.txt", ios::out | ios::app);

	if(readFile.bad()){
		cout << "sorry cannot open hello.txt" << endl;
	}

	if(writeFile.bad()){
		cout << "sorry cannot open dummy.txt" << endl;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	

	while (!readFile.eof())
	{
		getline(readFile, buffer);
       // cout << buffer << endl;
        
		checkDep = buffer.find(dep);                     //find if there is "EEE" 

		if(checkDep != string::npos){                      //get the position of the usn
			USN = buffer.substr(0,3);	
			department[totalStud] = atoi(USN.c_str());	
			totalStud++;
		}
	}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	

	//sort the array
    i = 0;
	while(i < totalStud){
	    j = 0;	
		while(j < totalStud-1){

			if(department[j] > department[j+1]){
				temp = department[j];
				department[j] = department[j+1];
				department[j+1] = temp;
			}	
			j++;
		}
		i++;
	}		
	
    i = 0;
    
//cout << department[0] << " " << department[1] << endl; ////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	iterate = 0;
	while(iterate < totalStud){                   

        readFile.clear();
		readFile.seekg(0); //reset pointer to start
		while(!readFile.eof()){
			
			getline(readFile, buffer);
        //    cout << "buffer " << buffer << endl;
			checkDep = buffer.find(dep);

			if(checkDep != string::npos){
				if(department[iterate]  == atoi( buffer.substr(0, 3).c_str())){
				//	cout << " finally " << buffer.substr(0, 3) << endl;
					writeFile << buffer << endl;
				}	
			}


		}
		iterate++;
	}


	writeFile.close();
	readFile.close();

}


void clearFile(string fileName){

	ofstream clearFile("dummy.txt");
	clearFile.close();

}

void copyFile(string fromFile, string toFile){
	
	remove("record.txt");
    if(rename("dummy.txt", "record.txt") == 0){
    	cout << "success" << endl;
	}
	
	else
		cout << "error" << endl;
}
////////////////////////////////////////////////////////////////////////////////
void sorted()
{
					clearFile("dummy.txt");
	
						sortAndAdd("CSE");
						sortAndAdd("EEE");
						sortAndAdd("ISE");
						sortAndAdd("MECH");

    				copyFile("dummy.txt", "record.txt");
}
/////////////////////////////////////////////////////////////////////////////////
//Main Function////

	int main()
	{
	 int choice,choice1;
	 student s;
	 char key[15],key1[15],key2[15];
	 char user[20],pass[20];
	 while(1)
	 {
	 	cout<<"\t\t-----------------"<<endl;
	 	cout<<"\t\t|WELCOME TO SRMS |\n";
	 	cout<<"\t\t-----------------"<<endl;
	 cout<<"\t\t1.Department Login\n\t\t2.Student Login\n\t\tEnter your Choice\n";
	 cout<<"\t\t";
	 cin>>choice1;
	 switch(choice1)
	 {
	 	case 1: 
		 {
		cout<<"\t\tPlease Enter Your Username :"<<endl;
		cout<<"\t\t";
	 	cin>>user;
	 	cout<<"\t\tPlease enter your password :"<<endl;
	 	cout<<"\t\t";
	 	cin>>pass;
	 	if (strcmp(user, "1")==0 && strcmp(pass, "2")==0)
		 while(1)
	 	{
			cout<<"\n\t\t1.Create a new Student record\n"<<"\t\t2.Display All Records\n"<<"\t\t3.Search a Record\n"<<"\t\t4.Modify Records\n"<<"\t\t5.Delete Records\n"<<"\t\t6.Exit \n\t\tEnter Your choice :\n";
		 	cout<<"\t\t";
			cin>>choice;
		 	switch(choice)
		 	{
				case 1: s.insert();
					cout<<"\t\tDone!\n";
					break;
					
				case 2: 
					int choice4;
					cout<<"\t\t1.Sort\n\t\t2.Display\n\t\tEnter your choice\n";
					cout<<"\t\t";
					cin>>choice4;
					switch(choice4)
					{
						case 1:sorted();
							cout<<"\n\t\tSorting is Done"<<endl;
							break;
						case 2:cout<<"\n\t\tThe Contents are:\n"<<endl;
							cout<<"\t\t"<<"usn"<<"\t"<<"Department"<<"\t"<<"Name"<<"\t\t"<<"sub1"<<"\t"<<"sub2"<<"\t"<<"sub3"<<"\t"<<"sub4"<<"\t"<<"total"<<"\t"<<"Percentage"<<endl;
							s.display();
							cout<<"\n\t\tDone!\n";
							break;
						default:break;;
						
					}
					break;
				
				case 3: int choice2;
					cout<<"\t\t1.Search By Department\n\t\t2.Search By USN\n\t\tEnter your choice\n";
					cout<<"\t\t";
					cin>>choice2;
					switch(choice2)
					{
						case 1:cout<<"\t\tEnter the Department ID:\n";
							cout<<"\t\t";
							cin>>key;
							cout<<"\t\t"<<"usn"<<"\t"<<"Department"<<"\t"<<"Name"<<"\t\t"<<"sub1"<<"\t"<<"sub2"<<"\t"<<"sub3"<<"\t"<<"sub4"<<"\t"<<"total"<<"\t"<<"Percentage"<<endl;				s.search(key);
							cout<<"\t\tDone!\n";
							break;
						case 2:cout<<"\t\tEnter the USN:"<<endl;
							cout<<"\t\t";
							cin>>key1;
							cout<<"\t\t"<<"usn"<<"\t"<<"Department"<<"\t"<<"Name"<<"\t\t"<<"sub1"<<"\t"<<"sub2"<<"\t"<<"sub3"<<"\t"<<"sub4"<<"\t"<<"total"<<"\t"<<"Percentage"<<endl;				s.search1(key1);
							cout<<"\t\tDone!\n";
							break;
						default:"\n";
						exit(0);
					}
					break;
					
				case 4: cout<<"\t\tEnter the usn to modify:"<<endl;
					cout<<"\t\t";
				 	cin>>key;
				 	s.modify(key);
				 	cout<<"\t\tDone!\n";
				 	break;
				case 5:s.Delete();
				 	break;
			 	case 6:cout<<"\t\tThank You"<<endl;
					default: exit(0);
		 	}
	 	}
	 	else
	 	cout<<"\t\tplease try again:"<<endl;
	 }
	 	break;
	 	case 2:
	 	char key3[15],dept3[5];
	 	int choice2;
	 	cout<<"\t\t1.Result\n\t\t2.exit"<<endl;
	 	cout<<"\t\t";
	 	cin>>choice2;
	 	switch(choice2)
	 	{
	 		case 1:cout<<"\t\tEnter the USN:"<<endl;
	 			cout<<"\t\t";
				cin>>key3;
				cout << "\t\tWhich department this usn belongs to (ISE, CSE, CIVIL, MECH, EEE, ECE)" << endl;
				cout<<"\t\t";
				cin>>dept3;
				cout<<"\n\t\tYour Result:\n"<<endl;
				cout<<"\t\t"<<"usn"<<"\t"<<"Department"<<"\t"<<"Name"<<"\t\t"<<"sub1"<<"\t"<<"sub2"<<"\t"<<"sub3"<<"\t"<<"sub4"<<"\t"<<"total"<<"\t"<<"Percentage"<<endl;
				s.search3(key3,dept3);
	 		break;
	 	default:cout<<"\t\tInvalid";
	 }
	 break;
	 default:cout<<"\t\tInvalid...Please Try Again"<<endl;
	}
	}
}

 
