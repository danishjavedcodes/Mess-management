
//all arays used as array[t_data][5] should be replaced by array[100][5] when code is open in visual studio community version

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
string check(string reg, bool &c);
void registration();
void Search();
void messstatus();
void delete_student();
void in_out();
void calculate_bill();
int stringTointeger(string str);
void sort_file();
int main()
{
    cout << "***********************************\n" ;
    cout << "Welcome To Mess Student Record" << endl ;
    bool endcon=1;
    int select;
    cout << "***********************************\n" ;
    cout << "Select option \n 1) Register new student. \n 2) Search Student record. \n 3) Change Student mess status.\n 4) Delete student record. \n 5) Show total number of in/out students. \n 6) Calculate total bill. \n 7) Sort table.\n 8) Exit. \n";
    cout << " ";
    cin >> select;
    cout << "\n ***********************************\n";
            switch (select)
            {
                case 1:
                {
                registration();
                break;
                }
                case 2:
                {
                    Search();
                    break;
                }
                case 3:
                {
                    messstatus();
                    break;
                }
                case 4:
                {
                    delete_student();
                    break;
                }
                case 5:
                {
                    in_out();
                    break;
                }
                case 6:
                {
                calculate_bill();
                    break;
                }
                case 7:
                {
                    sort_file();
                    break;
                }
                case 8:
                endcon=0;
                break;
                default:
                {
                    cout << "\nChoose correct option: \n";
                     cout << "Select option \n 1) Register new student. \n 2) Search Student record. \n 3) Change Student mess status.\n 4) Delete student record. \n 5)Show total number of in/out students. \n 6) Calculate total bill. \n 7) Sort table.\n 8) Exit. \n";
                            cin >> select;
                            cout << "\n ***********************************\n";
                                    switch (select)
                                    {
                                        case 1:
                                        {
                                        registration();
                                        break;
                                        }
                                        case 2:
                                        {
                                            Search();
                                            break;
                                        }
                                        case 3:
                                        {
                                            messstatus();
                                            break;
                                        }
                                        case 4:
                                        {
                                            delete_student();
                                            break;
                                        }
                                        case 5:
                                        {
                                            in_out();
                                            break;
                                        }
                                        case 6:
                                        {
                                        calculate_bill();
                                            break;
                                        }
                                        case 7:
                                        {
                                            sort_file();
                                            break;
                                        }
                                        case 8:
                                        endcon=0;
                                        break;
                                        default:
                                        {
                                            cout << "\nChoose correct option: \n";
                                            
                                        }
                                }
                                        }
                                }

    cout << "\n***********************************";

    
}
string check(string reg, bool &c)
{
    ifstream search;
    search.open("data.csv");
    string line;
    while (getline (search, line))
    {
        int flag=0;
        string  Reg;
        stringstream s;
        s<<line;
        for (int i=0; i<line.size(); i++)
        {
            if (line[i]==',')
            {
                flag++;
            }else{
                if (flag==0)
                {
                    Reg+=line[i];
                }
            }

        }
        if (reg==Reg)
        {
            c=1;
            cout << line;
        }
        
    }
    return line;
}
void registration()
{
    bool c;
    ofstream data_entry;
    data_entry.open("data.csv", ios::app);
    int bill=0,days=0;
    string name, reg;
    string status="out";
    cout << "Enter registration number: ";
    cin >> reg;
    cout << "Enter name: ";
    cin.ignore();
    getline (cin, name);
    check (reg,c);
    if (c==0)
    data_entry << "\n" << reg << "," <<name << "," << bill << "," << status << "," <<days;
    else
    cout<<"\nRecord with registration number " << reg << " is already exist";
    data_entry.close();
    sort_file();
}
void Search()
{
    string line;
    bool c=0;
    string reg;
    cout<<"Enter registration number: ";
    cin.ignore();
    getline (cin, reg);
    line = check(reg, c);
    cout<<endl;
    if (c==1)
    {
        cout << "Record found\n";
        cout << line;
    }
    else
    {
        cout << "record not found\n";
    }
}
void messstatus()
{
    string name,days;
    string status;
    char con;
    string reg, fname, word, line;
    fname="data.csv";
    vector<vector<string>> all_data;
	vector<string> row_data;
    cout<< "Enter Reg number: ";
    cin >> reg;
    int t_rows, t_cols; 
    
	fstream file(fname, ios::in);
	while(getline(file, line)) 
    {
        row_data.clear(); 
        stringstream str(line); 
        while(getline(str, word, ',')) 
        {
            row_data.push_back(word); 
        } 
        all_data.push_back(row_data); 
    }
    t_rows = all_data.size();
    for(int row = 0; row < t_rows; row++)
	{
            if (reg==all_data[row][0])
             {
                 cout << "The current status is: " << all_data [row][3];
                 cout<< "\nDo you want to change status: (y/n)";
                 cin >> con;
                 if (con=='y'||con=='Y')
                 {
                     cout<< "Please enter status" << endl;
                     cin >> status;
                     all_data [row][3] = status;
                     days = to_string (stoi(all_data [row][4])+1);
                     all_data [row][4] = days;

                 }
             }
        
    }

    name = "tempfile.csv";
    fstream newfile ;
    newfile.open(name, ios:: out| ios :: app);
    for(int row = 0; row < t_rows; row++) 
	{
        t_cols = all_data[row].size(); 
		for(int col = 0; col < t_cols; col++) 
		{
			if (col < (t_cols - 1)) 
            {
                newfile << all_data[row][col] << ","; 
            }
            else if (col == (t_cols - 1)) 
            {
                newfile << all_data[row][col] << "\n"; 
            }
		} 
	}
    file.close();
    newfile.close();
    
    remove("data.csv");
    rename("tempfile.csv","data.csv");
    
    
}
int convert(string str)
{
    int temp = 0;
    for (int i = 0; i < str.length(); i++) {

        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}
void calculate_bill()
{
    string name,days,bill;
    string status;
    char con;
    string reg, fname, word, line;
    fname="data.csv";
    vector<vector<string>> all_data;
	vector<string> row_data;
    cout<< "Enter Reg number: ";
    cin >> reg;
    int t_rows, t_cols; 
    
	fstream file(fname, ios::in);
	while(getline(file, line)) 
    {
        row_data.clear(); 
        stringstream str(line); 
        while(getline(str, word, ',')) 
        {
            row_data.push_back(word); 
        } 
        all_data.push_back(row_data); 
    }
    t_rows = all_data.size();
    for(int row = 0; row < t_rows; row++)
	{
            if (reg==all_data[row][0])
             {
                 days = to_string (stoi(all_data [row][4]));
                 bill = to_string (stoi(days)*300);
                 all_data [row][2] = bill;
                 cout << " Bill of Registration number " << reg << " is " << all_data [row][2];
             }
        
    }

    name = "tempfile.csv";
    fstream newfile ;
    newfile.open(name, ios:: out| ios :: app);
    for(int row = 0; row < t_rows; row++) 
	{
        t_cols = all_data[row].size(); 
		for(int col = 0; col < t_cols; col++) 
		{
			if (col < (t_cols - 1)) 
            {
                newfile << all_data[row][col] << ","; 
            }
            else if (col == (t_cols - 1)) 
            {
                newfile << all_data[row][col] << "\n"; 
            }
		} 
	}
    file.close();
    newfile.close();
    
    remove("data.csv");
    rename("tempfile.csv","data.csv");
    
}
void delete_student()
{
    string name,days;
    string status;
    char con;
    string reg, fname, word, line;
    fname="data.csv";
    vector<vector<string>> all_data;
	vector<string> row_data;
    cout<< "Enter Reg number: ";
    cin >> reg;
    int t_rows, t_cols;
    
	fstream file(fname, ios::in);
	while(getline(file, line)) 
    {
        row_data.clear(); 
        stringstream str(line); 
        while(getline(str, word, ',')) 
        {
            row_data.push_back(word); 
        } 
        all_data.push_back(row_data); 
    }


    t_rows=all_data.size();
    int s;
    for (int i=0; i<t_rows; i++)
    {
        if (reg==all_data[i][0])
        {
            s=i;
        }
    }
    for (int k=s; k<t_rows; k++)
    {

        if (k+1!=t_rows)

        {
            swap(all_data[k],all_data[k+1]);   
        }
    }
    for (int col=0; col<5; col++)
    {
        all_data[t_rows-1][col].erase();
        //all_data[t_rows-1][col]="";
    }
    
    name = "tempfile.csv";
    fstream newfile ;
    newfile.open(name, ios:: out| ios :: app);
    for(int row = 0; row < t_rows; row++) 
	{
        t_cols = all_data[row].size(); 
		for(int col = 0; col < t_cols; col++) 
		{
			if (col < (t_cols - 1)) 
            {
                newfile << all_data[row][col] << ","; 
            }
            else if (col == (t_cols - 1)) 
            {
                newfile << all_data[row][col] << "\n" ; 
            }
		} 
	}
    file.close();
    newfile.close();
    
    remove("data.csv");
    rename("tempfile.csv","data.csv");
}
void in_out()
{
    int in=0, out=0;
    string fname, word, line;
    fname="data.csv";
    vector<vector<string>> all_data;
	vector<string> row_data;
    int t_rows, t_cols; 
    
	fstream file(fname, ios::in);
	while(getline(file, line)) 
    {
        row_data.clear(); 
        stringstream str(line); 
        while(getline(str, word, ',')) 
        {
            row_data.push_back(word); 
        } 
        all_data.push_back(row_data); 
    }
    t_rows = all_data.size();
    

    for(int row = 0; row < t_rows; row++)
	{
            if (all_data[row][3]=="in" || all_data[row][3]=="In" || all_data[row][3]=="IN")
            {
                in=in+1;
            }else{
                if (all_data[row][3]=="out" || all_data[row][3]=="Out" || all_data[row][3]=="OUT")
            {
                out=out+1;
            }
        }
    }

    cout << "Total number of IN stidents are " << in;
    cout << endl;
    cout << "Total number of OUT stidents are " << out;    
}
void sort_file()
{ 
    string word, line;
    vector<vector<string>> all_data;
    vector<string> row_data;
    int t_rows, t_cols;
    fstream file("data.csv", ios::in);
	while(getline(file, line)) 
        {
            row_data.clear(); 
            stringstream str(line); 
            while(getline(str, word, ',')) 
            {
                row_data.push_back(word); 
            } 
            all_data.push_back(row_data); 
        }
    t_rows = all_data.size();



    string tab[t_rows][5];   // Or string [100][5]  for Visual Studio Community to avoid dinamic array problem

    for (int row=0; row<t_rows; row++)
    {
        for (int col=0; col<5; col++)
    {
        tab[row][col]=all_data[row][col];
    }
    }

    //sorting 

    int out,in;
    string temp1;
    string temp2;
    string temp3;
    string temp4;
    string temp5;  
       
       for(out=1;out<t_rows-1;out++)  
       {  
        for(in=out+1;in<t_rows;in++)  
        {  
         if(tab[in][0]<tab[out][0])  
            {   
                temp1=tab[out][0];  
                temp2=tab[out][1];
                temp3=tab[out][2];  
                temp4=tab[out][3];
                temp5=tab[out][4];

                tab[out][0]=tab[in][0];
                tab[out][1]=tab[in][1];
                tab[out][2]=tab[in][2];  
                tab[out][3]=tab[in][3];
                tab[out][4]=tab[in][4];
        
                tab[in][0]=temp1;  
                tab[in][1]=temp2;
                tab[in][2]=temp3;  
                tab[in][3]=temp4;
                tab[in][4]=temp5; 
            }                        
        }  
    }  


    for (int row=0; row<t_rows; row++)
    {
        for (int col=0; col<5; col++)
    {
        all_data[row][col]=tab[row][col];
    }
    }
    string name = "tempfile.csv";
    fstream newfile ;
    newfile.open(name, ios:: out| ios :: app);
    for(int row = 0; row < t_rows; row++) 
	{
        t_cols = all_data[row].size(); 
		for(int col = 0; col < t_cols; col++) 
		{
			if (col < (t_cols - 1)) 
            {
                newfile << all_data[row][col] << ","; 
            }
            else if (col == (t_cols - 1)) 
            {
                newfile << all_data[row][col] << "\n"; 
            }
		} 
	}
    file.close();
    newfile.close();
    
    remove("data.csv");
    rename("tempfile.csv","data.csv");

    
}
