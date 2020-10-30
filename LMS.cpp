	#include <iostream>
#include <stdio.h>
#include <cctype>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <sstream>

using namespace std;
int COUNTERLOOPTIME=0;
ofstream OUTFILE;
ifstream INFILE;
string users,passwords;
string User_List, password_List,Name_List;
string codi;
bool check= false ;
int f=-1;
int BB=0;
string BIYA[10][50];
int index1,index,result;
////////////////////STRUCT///////////////////////
struct CourseType{
	string code[50];
	int Sem[50];
	int CrdHrs[50];
	string name[50];
};


//////*************************///////////////////////
  

// first function//
bool isValidCourseCode(string code)
{
	bool flag=false;
	int size=code.size();
	if(size==5)
	{
		if(code[0] >=65 && code[0]<=90)
		{
			if(code[1]>=65 && code[1]<=90)
			{
				if(code[2]>=48 && code[2]<=57)
				{
					if(code[3]>=48 && code[3]<=57)
					{
						if(code[4]>=48 && code[4]<=57)
						{
							flag=true;
						}
					}
				}
			}
		}
	}
	return flag;

	
}

//2nd function

bool isValidCourseName(string name)
{
	bool courseIsValid;
	for (int i = 0; i < name.size(); i++)
	{
		if ((name[i]>='a'&&name[i]<='z')||(name[i]>='A'&&name[i]<='Z') ||name[i]==' ')
		{
			courseIsValid=true;	
		}
		else
		{
		courseIsValid = false;	
		}
	}
	return courseIsValid;
}

//3rd function

bool ValidCreditHours(int hour)
{
	bool valid=true;
	if(hour==1|| hour==2 || hour==3 )
	{
	}
	else {
			bool valid=false;
	}
return ValidCreditHours;

}

//search array index//
// This function searchs n in the array and returns 1 if element exists within array and -1 if it doesn't.

int searchInArray(string code , string codelist[])
{
	int index= -1;
	for (int i = 0; i <COUNTERLOOPTIME; i++)
	{
		if (codelist[i] == code)
		{
			index=i;
		}
	}

return index;

}


 //search array index//
// This function searchs n in the array and returns 1 if element exists within array and -1 if it doesn't.

int searchArray(string regNo , string	stdRegNoList[])
{
	int index= -1;
	for (int i = 0; i <1000; i++)
	{
		if (stdRegNoList[i] == regNo)
		{
			index=i;
		}
	}

return index;

}
///////// search in arrrays for students log-in//////////

int searchInnArray(string passwords , string	stdNameList[],string regNo, string	stdRegNoList[])
{
	int index= -1;
	for (int i = 0; i <1000; i++)
	{
		if (stdNameList[i] == passwords&&stdRegNoList[i] == regNo)
		{
			index=i;
		}
	}

return index;

}

////////////search in struct array//

int searchInnnArray(string regNo, string	stdRegNoList[])
{
	int index= -1;
	for (int i = 0; i <1000; i++)
	{
		if (stdRegNoList[i] == regNo)
		{
			index=i;
			
		}
	}

return index;

}
//4th function
bool isValidSemester(int Sem)
{
 bool valid;
	if(Sem==1|| Sem==2 || Sem==3 || Sem==4 ||Sem==4 ||Sem==5 || Sem==6 ||Sem==7 ||Sem==8)
	{
		valid=true;
	}
	else
	{
		 valid=false;
	}
	return valid;
}


// valid reg no //
bool isValidRegistrationNumber(string regNo)
{
	bool flag=false;
	int size=regNo.size();
	if(size==11)
	{
		if(regNo[0] >=48 && regNo[0]<=57)
		{
			if(regNo[1]>=48 && regNo[1]<=57)
			{
				if(regNo[2]>=48 && regNo[2]<=57)
				{
					if(regNo[3]>=48 && regNo[3]<=57)
					{
						if(regNo[4]='-')
						{
						 if(regNo[5]>=65 && regNo[5]<=90)
						 {
						 	if(regNo[6]>=65 && regNo[6]<=90)
						 	{
						 		if(regNo[7]='-')
						 		{
						 			if(regNo[8] >=48 && regNo[8]<=57)
						 			{
						 				if(regNo[9] >=48 && regNo[9]<=57)
						 				{
						 					if(regNo[10] >=48 && regNo[10]<=57)
						 					{
						 						flag=true;
											 }
										 }
									 }
								 }
							 }
						 }
						}
					}
				}
			}
		}
	}
	return flag;

	
}

/// valid name //


bool isValidStudentName(string StudentName)
{
	bool courseIsValid;
	for (int i = 0; i < StudentName.size(); i++)
	{
		if ((StudentName[i]>='a'&&StudentName[i]<='z')||(StudentName[i]>='A'&&StudentName[i]<='Z') ||StudentName[i]==' ')
		{
			courseIsValid=true;	
		}
		else
		{
		courseIsValid = false;	
		}
	}
	return courseIsValid;
}


//ADD course?//

 void AddCourse(string codelist[],string namelist[],int crtHrsList[],int semiList[],string code,string name, int hour,int Sem)
{  
	int i=COUNTERLOOPTIME;
	if(isValidCourseCode(code)==true)
	{  	
		 codelist[i]=code;
		if(isValidCourseName(name)==true)
		{	
			 namelist[i]=name;
			if(ValidCreditHours(hour)==true)
			{	
				namelist[i]=hour;
				if(isValidSemester(Sem)==true)
				{
					codelist[i]=code;
					crtHrsList[i]=hour;
					semiList[i]=Sem;
					namelist[i]=name;
					COUNTERLOOPTIME++;	
				}
				else
				{
					cout<<"Semester not valid !";
				}
			}
			else
			{
				cout<<"Credit Hour not valid !";
			}
		}
		else
		{
			cout<<"Course Name not valid !";
		}
	}
	else
	{
		cout<<"Course Code not valid !";
	}
}

    // edit course //

void EditCourse(string codelist[],string namelist[],int crtHrsList[],int semiList[],string code,string name, int hour,int Sem, int index)
{
     int i;
	 if(isValidCourseCode(code)==1)
	
		{
			if(isValidCourseName(name)==1)
			
			{
				if(ValidCreditHours(hour)==1)
				
					{
						if(isValidSemester(Sem)==1)
						
						{
									codelist[index]=code;
									namelist[index]=name;
									namelist[index]=hour;
									semiList[index]=Sem;
							
						}
					}
			}
		}

}

 // delete course//

void DeleteCourse(string codelist[],string namelist[],int crtHrsList[],int semiList[],string code,string name, int hour,int Sem , int index)
{
	
    for(int i=index ; i<=COUNTERLOOPTIME; i++ )	
	    
	    {
		 	codelist[i]=codelist[i+1];
			namelist[i]=namelist[i+1];
			namelist[i]=namelist[i+1];
			semiList[i]=semiList[i+1];   	
		}	 
		COUNTERLOOPTIME=COUNTERLOOPTIME-1;
	
}
	
 // Veiw Course //

void VeiwAllCourse(string codelist[],string namelist[],int crtHrsList[],int semiList[])
{
	for( int i=0 ; i<COUNTERLOOPTIME ; i++)
		
		{
			cout<<codelist[i]<<setw(20)<<namelist[i]<<setw(17)<<crtHrsList[i]<<setw(15)<<semiList[i]<<endl;				
		}

}
					
 // veiw courses of semester//


void VeiwSemesterCourses(string codelist[],string namelist[],int crtHrsList[],int semiList[],int Sem)
{
	string len;
	int j=0;
	
	// array for storing the indeces of the matching semester.

	int ans_index[COUNTERLOOPTIME];
	for(int i=0;i<COUNTERLOOPTIME;i++)
	{
		if(semiList[i]==Sem)
		{
			ans_index[j]=i;
			j++;
		}
	}
	
	for( int i=0 ;i<j;i++)
	{
		int index=ans_index[i];
		cout<<codelist[index]<<setw(25)<<namelist[index]<<setw(15)<<crtHrsList[index]<<endl;

    }
		
}

// save courses//
bool saveCourses(string codelist[],int semiList[],int crtHrsList[],string namelist[])
{
	bool flag;
if( COUNTERLOOPTIME > 0 )
{


for ( int i = 0; i < COUNTERLOOPTIME ; i++)	
{
	
OUTFILE<<codelist[i]<<" "<<semiList[i]<<" "<<crtHrsList[i]<<" "<<namelist[i]<<endl;
flag = true;
}
}
else {
	flag= false;
}
return flag;
}

//load courses//
bool loadCourses(string codelist[],string namelist[],int crtHrsList[],int semiList[])
{   bool flag;
INFILE.open("Courses.txt");
	if(INFILE.is_open() )
	{
		cout<<"Courses file exist  "<<endl;
		flag=true;
	}
	else
	{
		cout<<"file doesnot exist "<<endl;
		flag=false;
		
	}
	
	if(flag==1)
	
{
	
for ( int i = 0; i < COUNTERLOOPTIME ; i++)
{
		string someString;
		while(getline(INFILE, someString)){ 
			int i = 0;
			string courseName, courseCode;
			int semesterNum, creditHours;
			
			
			while(someString[i] != ','){ 
				courseCode += someString[i];
				i++;
			}
			i++; 
			while(someString[i] != ','){
				courseName += someString[i];
				i++;
			} 
			i++;
			creditHours = someString[i];
			i++;
			semesterNum = someString[i];
			
			codelist[COUNTERLOOPTIME] = courseCode;
			namelist[COUNTERLOOPTIME] = courseName;
			semiList[COUNTERLOOPTIME] = semesterNum;
			crtHrsList[COUNTERLOOPTIME] = creditHours;
}			COUNTERLOOPTIME++;
}
}

	
	
	return flag;
}

//user's load //
bool loadUsers(string usersList[] , string passwordsList[])
{   
    int i=0;
    bool flag=false;
	INFILE.open("Users.txt");
    if(INFILE.is_open())
     {
	   string LINE[1000];
     while(getline(INFILE,LINE[i]))
	 {
	 
	  stringstream ss (LINE[i]);
	  getline( ss , User_List , ',');
	   getline( ss , password_List , ',');
	   usersList[i] =User_List;
	   passwordsList[i] =password_List;
	   i++;
	}
	flag= true;
	}
	else {
		
		flag =false;
	}
	return flag;
}


///bool login//
bool login(string usersList[],string passwordsList[] )
{
	for (int i=0 ; i<3 ; i++)
	{
		if( usersList[i]==users   &&   passwordsList[i]==passwords)
		{
			check=true;
		}
		
	}
	
		
	return check;
}




///bool login//
bool loginG(string stdRegNoList[],string stdNamesList[] )
{
	for (int i=0 ; i<1000; i++)
	{
		if( stdRegNoList[i]==users   &&   stdNamesList[i]==passwords)
		{
			check=true;
		}
		
	}
	
		
	return check;
}

//******************************************//   part 3    //****************************************//


//ADD STUDENT //
void AddStudent (string stdNamesList[] , string stdRegNoList[], string StudentName, string regNo)
{    
    f++;;
     for(  f ;f<COUNTERLOOPTIME ; ){
	 
	 
	stdNamesList[f]=StudentName;
	
	stdRegNoList[f]=regNo;
	cout<<f;
cout<<" Student is Added Sucesssfully "<<endl;
break;
}
}


// UPDATE STUDENT //
void updateStudent(string stdNamesList[] , string stdRegNoList[], string StudentName, string regNo ,int index)
{
    stdNamesList[index]=StudentName;
	
	stdRegNoList[index]=regNo;	
	cout<<" Student is Added Sucesssfully "<<endl;
	
}
// delete Student //
void DeleteStudent(string stdNamesList[] , string  stdRegNoList[],CourseType stdCourseList[],string regNo,int index)
{
	
            char f='\0';
		 	stdNamesList[index]=f;
		    stdRegNoList[index]=f;
	
			 		 
		COUNTERLOOPTIME=COUNTERLOOPTIME-1;
	
}
  // VEIW ALL STUDENTS //
  void VeiwAllStudents(string stdRegNoList[],string stdNamesList[])
{
		for( int i=0 ; i<10  ; i++)
		
		{
			cout<<stdRegNoList[i]<<setw(20)<<stdNamesList[i]<<endl;				
		}

}

// register course//
void registerCourse(string stdRegNoList[], CourseType stdCourseList[], string codelist[], string regNo ,string code,int index,int index1)	
 {
 

	stdRegNoList[index]=regNo;
		codelist[index1]=code;
		
			for( int L ;L<50 ;)
			{
			stdCourseList[index].code[L]=code;
			L++;
			
			break;
			
		}
		
	}
	
	///// course list
	
	int searchInArray(string code , CourseType stdCourseList[])
{
	int index1= -1;
	for (int i = 0; i <COUNTERLOOPTIME; i++)
	{
		if ( stdCourseList[i].code[i] == code)
		{
			index1=i;
		}
	}

return index;

}

// unregistre course //

	void unRegisterCourse(string stdRegNoList[], CourseType stdCourseList[], string regNo ,string code,int index,int index1)	
 {
 

	stdRegNoList[index]=regNo;
	
		stdCourseList[index].code[index1]='\0';
		
	}	
 
 
 	/////Save Student //
void saveStudents(string stdRegNoList[], string stdNamesList[],CourseType stdCourseList[])
{ OUTFILE.open("Students.txt");
  if (OUTFILE.is_open())
		{
			
	for( int f=0  ; f < 1000 ; )
	{
        if (stdRegNoList[f]!="\0"){
		
    
			OUTFILE<<stdRegNoList[f]<<","<<stdNamesList[f]<<endl;
	
			for ( int L=0 ; L<50 ;L++)
			{
			if(stdCourseList[f].code[L]!="\0")
			{
	    	       OUTFILE<<stdCourseList[f].code[L]<<","; 
	             }
          }
          OUTFILE<<endl;
  }
        f++;	
      }
}
OUTFILE.close();
}
///////////load students//
bool LoadStudents(string stdRegNoList[], string stdNamesList[],CourseType stdCourseList[])
{   ifstream INFILE;
    string regNo,codes[50],Name;
	int i=0;
    bool flag=false;
	INFILE.open("Students.txt");
    if(INFILE.is_open())
     {
     	flag=true;
		 	   string LINE[1000];
     while(getline(INFILE,LINE[i]))
	 {  stringstream ss (LINE[i]);
	    getline( ss , regNo , ',');
	    getline( ss , Name , ',');
	   	stdRegNoList[i]= regNo;
	   	
	   stdNamesList[i]=Name;
	  
	   for(int j=0; j<50 ;j++)
	   {
	         getline( ss ,codi,',');
	         stdCourseList[i].code[j]=codi;

} 
	   i++;
}
	}
	return flag;
}


// veiw registered courses//
void VeiwregisterCourse(string regNo, string	stdRegNoList[], CourseType stdCourseList[],int result)	
 {
 	int index= -1;
	for (int i = 0; i <1000; i++)
	{
		if (stdRegNoList[i] == regNo)
		{
			index=i;
			if(index==result){
			for( int L=0 ;L<50 ;L++)
			{ 
			
			cout << stdCourseList[i].code[L];
					
		}
	}else{cout<<"try agian";
	}
		
			
		}
	}
 	
		
	}

int main()
{
	

	string codelist[1000]="",namelist[1000]="";
	string code,name;
	int crtHrsList[1000],semiList[1000];
	int hour,Sem;
	string usersList[1000] , passwordsList[1000];
	int A;
	string	stdRegNoList[1000];
	string stdNamesList[1000];
	string StudentName;
	string regNo;
	CourseType stdCourseList[1000];
		

	LoadStudents(stdRegNoList, stdNamesList,stdCourseList);
	 cout<<"choose the option for log in"<<endl;
   cout<<"1"<<" for admin"<<endl;
   cout<<"2"<<" for student"<<endl;
   cout<<"Enter Option ";
   int opt;
   cin>>opt;
   
   if(opt==1)
{
    int result = loadUsers(usersList , passwordsList);
	if(result !=-1)
	{
	
	
	Label :
	cout<<"\n  **Welcome to University learning management system**"<<endl;
	cout<<"//****************uet*************//"<<endl<<endl<<endl;
	cout<<"Dear User, current software is intended for authorized users only"<<endl<<endl;
    cout<<"Login to the system to get access.";
    cout<<endl;
    
  do{
  
  	
	do{
	
    cout<<"Username: ";
    cin>>users; 
	cout<<endl;
	cout<<"Password: ";
	cin>>passwords;

	
	login(usersList , passwordsList);
	
}while(check!=true);

		
  if ( check ==true)
   {
   
	cout<<"1"<<"      "<<"ADD Course"<<endl;
	cout<<"2"<<"      "<<"Update Course"<<endl;
	cout<<"3"<<"      "<<"Delete Course"<<endl;
	cout<<"4"<<"      "<<"Veiw All Course"<<endl;
	cout<<"5"<<"      "<<"Veiw Courses Of Semester"<<endl;
	cout<<"6"<<"       "<<"Add Student"<<endl;
	cout<<"7"<<"       "<<"Undate Student"<<endl;
	cout<<"8"<<"       "<<"Delete Student"<<endl;
	cout<<"9"<<"       "<<"Veiw all students"<<endl;
	cout<<"10"<<"       "<<"Register Course for student "<<endl;
	cout<<"11"<<"       "<<"Unregister Course"<<endl;
	cout<<"12"<<"      "<<" logout "<<endl;
	cout<<"13"<<"      "<<"Exit Program"<<endl;
	cout<<endl;

	
	
	
	loadCourses(codelist, namelist, crtHrsList, semiList);
	
	
do
{
	cout<<"choose  ONE of the following option : ";
    cin>>A;
	if(A==1)
	{
		cout<<""""""""""""""""""""""""""""""""<<endl;
	   cout<<"\nEnter details to add course : ";
		cout<<""""""""""""""""""""""""""""""""<<endl;
	   cout<<endl;
	   
	   cout<<"enter Course Code, Semester, Credit Hour, Enter course name ";
	   cout<<endl;
	
	    cin>>code;
		cout<<endl;
		cin>>Sem;		
		cout<<endl;
		cin>>hour;
		cout<<endl;
	    getline(cin,name);
	    
	    AddCourse(codelist, namelist, crtHrsList, semiList, code, name, hour, Sem);
	    cout<<"Course is ADDED successfully ";
	    cout<<endl;
		cout<<endl;	
	
	}
	
	else if(A==2)
	{
	  
		 cout<<"Enter the Course Code you Want to Change"<<endl;
	     cin>>code;
	     int result = searchInArray(code,codelist);
		 cout<<endl; 
	        

		if (result != -1)
		{
			cout<<"Enter the details of new COURSE"<<endl;
			cin>>code;
			getline(cin,name);
			cin>>hour>>Sem;

			EditCourse(codelist, namelist, crtHrsList, semiList, code, name, hour, Sem , result);
			cout<<"Course has been changed sucessfully";
			cout<<endl;
			cout<<endl;
			
		}
		
		else
		{
		cout<<"Code Does not Exist in the codelist"<<endl<<endl;
		}
	        
	}
	else if(A==3)
	{
		cout<<"Enter Course Code you want to delete "<<endl;
		cin>>code;
	    int result = searchInArray(code,codelist); 
	        if (result!= -1)
	        {
				DeleteCourse(codelist, namelist, crtHrsList, semiList, code, name, hour, Sem, result);
				cout<<"Course has been deleted";
				cout<<endl;
			}
			else
			{
				cout<<"Course Code does not exist ";
			}
	
	}
	
	else if (A==4)
	{   
	    cout<<"All courses are as follow : "<<endl;
	    cout << "Course Code" <<setw(15)<<"Name"<<setw(20)<<"CrtHours"<<setw(15)<<"semester"<<endl;
		VeiwAllCourse(codelist, namelist, crtHrsList, semiList );
		cout<<endl;	
	}
	
	else if(A==5)
	{
		
		cout <<"Enter the semester number : "<<endl;
		cin>>Sem;
		if(isValidSemester(Sem)==1)
    		{
				cout << "Course Code" <<setw(18)<<"Name"<<setw(20)<<"CrtHours"<<endl;
				VeiwSemesterCourses(codelist, namelist, crtHrsList, semiList, Sem);
				cout<<endl;	
			}
		else
			{
				cout<<"Semester not Valid : "<<endl;
			}
	}
	
	else if(A==6)
		{
			COUNTERLOOPTIME++;

			cout<<"registration number  will be as follow e.g  2018-CS-211  or 2018-CS-001";
			cout<<endl;
			cout<<endl;
			cout<<"Enter the reggistration no "<<endl;
			cin >> regNo;
			int r=isValidRegistrationNumber(regNo);
			if (r==true){
			
			     cout << "Enter the Student Name "<<endl;
			     cin>>StudentName;
			
			     AddStudent (stdNamesList ,stdRegNoList,StudentName, regNo) ;
            }
            else{
            	cout<<"please enter valid registration no "<<endl;
			}
		}
	  
	else if (A==7)
	{
		cout<<"Enter the Student name you Want to Change"<<endl;
	     cin >> StudentName;
	     int result = searchArray(StudentName,stdNamesList);
	    
		 cout<<endl;
		 
	        

		if (result != -1)
		{
			cout<<"Enter the name and registration no of new student "<<endl;
			cout<<endl;
			cout<<endl;
			cout<<"Enter the reggistration no "<<endl;
			cin >> regNo;
			int r=isValidRegistrationNumber(regNo);
			if (r==true){
			      cout << "Enter the Student Name "<<endl;
			      cin >> StudentName;
			      updateStudent( stdNamesList , stdRegNoList,StudentName, regNo , result);
	}
			
			else{
            	cout<<"please enter valid registration no "<<endl;
			}
		
	}
	else {
		cout<<"student doesnot exist "<<endl;
	}
	}
		
		else if(A==8)
	{
		cout<<"Enter Student's Registration you want to delete "<<endl;
		cin>>regNo;
		int r=isValidRegistrationNumber(regNo);
			if (r==true){
	    int result = searchArray(regNo,stdRegNoList); 
	        if (result!= -1)
	        {
				DeleteStudent(stdNamesList,stdRegNoList, stdCourseList ,regNo,result);
				cout<<"student has been deleted";
				cout<<endl;
			}
			else
			{
				cout<<"student  does not exist ";
			}
		}
		else{
            	cout<<"please enter valid registration no "<<endl;
			}
	
	}
		
	else if(A==9)
	{
		
	cout<<"Following are the Students : "<<endl;
	    int f=0;
	    cout << "Reg. no " <<setw(20)<<"Name"<<endl;
		VeiwAllStudents(stdRegNoList, stdNamesList);
		cout<<endl;	
		f++;
	
	
	}
	else if (A==10)
	{
		cout<<endl;
	cout<<"Enter registration Number of the student for course registration:"<<endl;
	cout<<endl;
	cout<<"registration number  will be as follow e.g  2018-CS-211  or 2018-CS-001";
	cout<<endl;
	cin>>regNo;
	int resultTT=isValidRegistrationNumber(regNo);
	if  ( resultTT ==true)	
	{
	int result = searchArray(regNo,stdRegNoList); 
	        if (result!= -1)
	        { cout<<"Enter the Course Code you Want to register"<<endl;
	         cin>>code;
	           int result1 = searchInArray(code,codelist);
	           if (result1!= -1){
			   
	          registerCourse(stdRegNoList, stdCourseList, codelist, regNo, code,result,result1);
	          cout<<"course is registered";
	          cout<<endl;
	      }
            }
	 }	
	 else {
	 	cout<<"please enter valid registration no "<<endl;
	 } 
}
	  
	else if (A==11)
		{
		cout<<endl;
	cout<<"Enter registration Number of the student for course registration:"<<endl;
	cout<<endl;
	cout<<"registration number  will be as follow e.g  2018-CS-211  or 2018-CS-001";
	cout<<endl;
	cin>>regNo;
	int resultTT=isValidRegistrationNumber(regNo);
	if  ( resultTT ==true)	
	{
	int result = searchArray(regNo,stdRegNoList); 
	        if (result!= -1)
	        { cout<<"Enter the Course Code you Want to UnRegister"<<endl;
	         cin>>code;
	           int result1 = searchInArray(code,stdCourseList);
	           if (result1!= -1){
			   
	          unRegisterCourse(stdRegNoList, stdCourseList, regNo, code,result,result1);
	          cout<<"course is unregistered";
	          cout<<endl;
	      }
            }
	 }	
	 else {
	 	cout<<"please enter valid registration no "<<endl;
	 } 
}
    else if (A==12)
    {
    		
		}
	else if (A==13)
	{
	
			OUTFILE.open("Courses.txt");
			saveCourses(codelist,semiList, crtHrsList,namelist);
			OUTFILE.close();
		
			saveStudents(stdRegNoList, stdNamesList,stdCourseList);
			
			cout<<"The program is going to terminate !";
			return 0;
	}
		
/*	string aaa;
	cout<<"\n\nPress Enter to continue !";
	cin.ignore(50,'\n');
	cin.clear();
	getline(cin,aaa);
*/
	
}while (A != 13);

}


else 
{
	cout<<"Sorry, we are unable to run the program, as user data does not exist.";
}

}while(A==12);
 
 
}
}
LoadStudents(stdRegNoList, stdNamesList,stdCourseList);
if ( opt==2)
{
	int B;

		
do{
	
	
    cout<<"Username: ";
    cin>>users; 
	cout<<endl;
	cout<<"Password: ";
	cin>>passwords;
int result = searchInnArray(passwords,stdNamesList,users,stdRegNoList);
int L=0;
	cout<<stdCourseList[result].code[L];
if (result!=-1)
	        {
	cout<<"1"<<"      "<<"Veiw Registered Courses"<<endl;
	cout<<"2"<<"      "<<"Logout"<<endl;
	cout<<"3"<<"      "<<"exit"<<endl;  
	cout<<"choose ONE option ";
	cin>>B;
	if (B==1)
	{ 
	cout<<"please Enter your reGistratiom number to veiw registered Courses"<<endl;
	cin>>regNo;
VeiwregisterCourse(regNo,stdRegNoList, stdCourseList,result);


	}else if (B==2)
	{
		
	}
	else if (B==3)
	{
	return 0;	
	}

}
}while(B==2);
}
}

	
	


