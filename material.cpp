
//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <locale>
#include <fstream>


using namespace std;



 struct  source {
    int id;
    string Name;
    double Price;
	double Weight;
};

struct List{
   source data;
    List *next;
};

class ListNode
{
    private:
        List *Head;
		ifstream FileOut;
		ofstream  FileIn;
		 char*  NameFile ;
		 int Count;

    public:

        ListNode():Head(NULL) {}




         void  GetElemByPos( int Pos, const  source value )             //добавление в указанную
        {
			 if (Head != NULL)
			 {
				 List *tmp = Head;


				 int Kol_el = 0;
				 while (tmp->next != NULL && tmp->data.id != Pos )
				 {
					 tmp = tmp->next;
					 ++Kol_el;
				 }
				 if (tmp->data.id == Pos){
					 tmp->data = value;
				 }
			 }
        }

        void delList(const int value)
        {
            List *tmp = Head;
            List *cur = NULL;

            if(Head != NULL)
            {
                if((Head -> data.id) == value)                 //если удаляем 1 элемент
                {
                    cur = Head -> next;
                    delete Head;
                    Head = cur;

                }
                else
                {
                    while((tmp->next != NULL) && (tmp -> data.id != value))
                    {
                        cur = tmp;
                        tmp = tmp -> next;
                    }

					if ((tmp->next == NULL) && (tmp->data.id == value))          //если элемент между
                    {
															                     //1 и последним
							delete tmp;
							cur->next = NULL;
                    }
                    else                                    //если элемент последний
                    {
						if (tmp->data.id == value){
							cur->next = tmp->next;
							delete tmp;
						}
                    }
                }
            }
        }

	void clear(){
		List *temp = Head;
 		 List *cur = NULL;
            if(Head != NULL)
            {
                while(temp != NULL)
                {
               	    cur=   temp ;
	                    temp = temp -> next;
          	    delete cur;
		 }
            }
	}
        void showList()
        {
            List *temp = Head;

            if(Head != NULL)
            {
                while(temp != NULL)
                {
                    cout << temp -> data.id << ";  "<<temp -> data. Name << ";  "<<temp -> data.Price << ";  "<<temp -> data.Weight<<";"<<"\n";


                   temp = temp -> next;
                }
            }
            else
                cout << "list is empty!"<<"\n";
        }


bool FileWrite()
		{
			NameFile= " DB";
			int sizeName;
			int sizePrice;

			try
			{

				List *temp = Head;

				if (Head != NULL)
				{
					FileIn.open(NameFile, ios_base::binary | ios::out);



					FileIn.write((char*)&Count, sizeof(int));
					while (temp != NULL)
					{
						FileIn.write((char*)&temp->data.id, sizeof(temp->data.id));
						sizeName = temp->data.Name.length();

						FileIn.write((char*)&sizeName, sizeof(sizeName));

						FileIn.write((char*)temp->data.Name.c_str(), sizeof(char) * sizeName);

//					sizePrice = temp->data.Price.length();

						FileIn.write((char*)&temp->data.Price, sizeof(temp->data.Price));
                        FileIn.write((char*)&temp->data.Weight, sizeof(temp->data.Weight));

						//FileIn.write((char*)temp->data.Price.c_str(), sizeof(char)*sizePrice);
						temp = temp->next;
					}
					FileIn.close();
				}
				else
					throw 1;
			}
			catch(...)
			{
				return false;
			}
			return true;
		}

		bool FileRead()
		{
			NameFile= " DB";
			int sizeName=0;
			int sizePrice=0;
			bool out = true;
			source data;
			int i=0;
			int Col;
			try
			{

					FileOut.open(NameFile, ios_base::binary | ios::in);

					if (FileOut.is_open()) {

						FileOut.read((char*)&Col, sizeof(int));
						while (i < Col)
						{
							FileOut.read((char*)&data.id, sizeof(int));

							FileOut.read((char*)&sizeName, sizeof(int));
							char *tmp = new char[sizeName + 1];
							tmp[sizeName] = '\0';
							FileOut.read(tmp, sizeof(char)*sizeName);
							data.Name = (string)tmp;
							FileOut.read((char*)&data.Price, sizeof(double));
							FileOut.read((char*)&data.Weight, sizeof(double));
							//FileOut.read((char*)&sizePrice, sizeof(int));
							//char *tmp1 = new char[sizePrice + 1];
							//tmp1[sizePrice] = '\0';
							//FileOut.read(tmp1, sizeof(char)*sizePrice);
//							data.Price = (string)tmp1;

							add(data);
							i++;
						}
						FileOut.close();

					}
					else{ throw 4; }
			}
			catch (...)
			{
				out = false;
			}
			return out;
		}



		 void add(const  source value)                 //добавление в конец
        {
            List *Ptr = new (List);
            Ptr -> data = value;

            if(Head == NULL)
            {
                Head = Ptr;
                Ptr -> next = NULL;
				Count=1;
            }
            else
            {
                List *temp = Head;

                while(temp -> next != NULL)
                    temp = temp -> next;

                temp -> next = Ptr;
                Ptr -> next = NULL;

  	Count++;
            }
        }
		 };
