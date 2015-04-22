// Практ2.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"


#include "material.cpp"
#include <stdio.h>
#include <iostream>

 #include <stdlib.h>
     //#include <termios.h>
     #include <string.h>

using namespace std;

bool isNumber(string str, int j)
{
    unsigned length = str.length();
    if (length>j)
    {
        return false;
    }
    for (unsigned i=0; i<length; ++i)
   if (str[i] <'9' || str[i] >'0' || str[i]=='.'  ) return true;
   return false;
  //if (str[i] >'9' || str[i] <'0' || str[i]!='.'  ) return false;
    //return true;

}


source dataSet(){
	source tmp;
	double temp;
	bool prov=false;
	string num;
	//cout << "Enter id library" << "\n";
	//cin >> tmp.id;
	//while ((tmp.id < 0)){
	//cerr << "Error while reading the integer value > 0" << endl;
	 do {
	 do
        {
        cout << "Enter id" << "\n";
             cin >> num;
            prov=isNumber(num, 6);

        } while ((prov==false));
        temp=atof(num.c_str());
 if (temp==0 or temp<0)
        cout << "retry" << "\n";
        tmp.id =temp;
        } while(temp==0 or temp<0);
	//cin.clear();
	//cin.sync();
	//cin >> tmp.id;
	//}
	cout << "Enter  Name   " << "\n";
	cin >> tmp.Name;
 do {
	 do
        {
        cout << "Enter price " << "\n";
             cin >> num;
            prov=isNumber(num, 6);

        } while ((prov==false));
        temp=atof(num.c_str());
 if (temp==0)
        cout << "retry" << "\n";
        tmp.Price=temp;
        } while(temp==0);
	 do{
	 do
        {
       	cout << "Enter Weight " << "\n";
            cin >> num;

            prov=isNumber(num, 6);

        } while ((prov==false));

       temp=atof(num.c_str());
        if (temp==0)
        cout << "retry" << "\n";
        tmp.Weight=temp;
        }
        while(temp==0);


	return tmp;
}

int  main()
{
	char i = '0';
	int id;
	char tmp;

	ListNode DB;

	do {
		switch (i)
		{
		case '0':
			/* Main menu*/

	//		cin.clear();
		//	cin.sync();
			cout << "Add (1)"<<"\n" ;
			cout << "Delete(2)" << "\n";
 			cout << "Change(3)" << "\n";
 			cout << "Show list(4)" << "\n";
			cout << "File write(5)" << "\n";
			cout << "File read(6)" << "\n";
			cout << "Exit(7)" << "\n";
			//cin >> i;

			break;

		case '1':
			/* Добавление */

			cout << "Enter new  data" << "\n";
			DB.add(dataSet());
			i = '0';
			break;

		case '2':
			/*Удаление */

			cout << "Enter record id, you want to delete " << "\n";
			while (!(cin >> id) || (id < 0)){
				cerr << "Error while reading the integer value > 0" << endl;
				cin.clear();
				cin.sync();
			}
			DB.delList(id);
			i = '0';
			break;

		case '3':
			/*Изменение */

			cout << "Enter record id, you want to change " << "\n";
			while (!(cin >> id) || (id < 0)){
				cerr << "Error while reading the integer value > 0" << endl;
				cin.clear();
				cin.sync();
			}
			DB.GetElemByPos(id, dataSet());
			i = '0';
			break;

		case '4':
			/* Просмотр */

			DB.showList();

			cin>>tmp;
			i = '0';
			break;

	 case '5':


	 if (!(DB.FileWrite()))
	 {
	 cerr << "File error!!" << endl;
	 }
	 i = '0';
	 break;

 case '6':


	 if (!(DB.FileRead()))
	 {
	 cerr << "File error!!" << endl;

	 }
	 i = '0';
	 break;

 case '7':

	 DB.clear();
	 cin>>tmp;

	break;
//default:
//cout << "You entered the wrong character! Try again"<<"\n";
//break;
}
i=getchar();
//i=getchar();
} while (i != '7');
	DB.clear();
	return 0;
};
