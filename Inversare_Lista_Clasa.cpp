/*
II
1. Extindeti clasa ce descrie lista simplu inlantuita dezvoltata in decursul laboratorului printr-o functie noua. 
Functia inverseaza legaturile acestei liste simplu inlantuite.
Nu folositi alta lista temporara sau alt fel de container (std::set, std::vector, std::list, Node[] etc.). 
Verificati prin afisarea listei.
*/

#include <iostream>
#include <vector>
using namespace std;

struct MyData
{
    int value;
    MyData* next;
};

class List
{
public:
    MyData* head = NULL;
    
    void push_back(const MyData& data)
    {
        if(head == NULL)
        {
            head = new MyData;
            head->value = data.value;
            head->next = data.next;
            return;
        }
        
        MyData* ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        
        ptr->next = new MyData;
        ptr->next->value = data.value;
        ptr->next->next = data.next;
    }
    
    void push_front(const MyData& data)
    {
        MyData* newData=new MyData;
        newData->value=data.value;
        newData->next=head;
        head=newData;
    }
    
    void insertAfter(int poz, const MyData& data)
    {
        if (poz<0 || head==NULL)
            return;
        if(poz==0){
            MyData* newData=new MyData;
            newData->value=data.value;
            newData->next=head->next;
            head->next=newData;
            return;
        }
        MyData* ptr=head;
        for(int i=0; i<poz;i++)
        {
            ptr=ptr->next;
            if(ptr==NULL)
                return;                  
        }
        
        MyData* newData=new MyData;
        newData->value=data.value;
        newData->next=ptr->next;
        ptr->next=newData;
    }
    
    void printList()
    {
        MyData* ptr=head;
        while(ptr!=NULL)
        {
            cout<<ptr->value << " ";
            ptr=ptr->next;
        }
        cout << endl;
    }
    
    void remove(int poz)
    {
        if (poz<0 || head==NULL)
            return;
        
        if(poz==0)
        {
            MyData* aux=head;           
            head=head->next;
            delete aux;
            return;
        }
        
        MyData* ptr=head;
        for(int i=0; i<poz-1;i++)
        {
            ptr=ptr->next;
            if(ptr==NULL)
                return;                  
        }
        
        MyData* aux = ptr->next;
        if(aux==NULL)
            return;
        
        ptr->next=ptr->next->next;
        delete aux;
    }
    
    void modificare(int poz, const MyData& data)
    {
        if (poz<0 || head==NULL)
            return;
        if(poz==0){
            head->value=data.value;
            return;
        }
        MyData* ptr=head;
        for(int i=0; i<poz;i++)
        {
            ptr=ptr->next;
            if(ptr==NULL)
                return;                  
        }
        ptr->value=data.value;
    }
    
    
    //Construim functia de inversare a legaturilor:
    void reverse_list()
{
	if(head == NULL) return;

    MyData *prev = NULL, *current = NULL, *next = NULL;
    current = head;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
}
};


int main()
{
    List myList;
    
    MyData firstData;
    firstData.value = 4;
    firstData.next = NULL;    
    
    MyData secondData;
    secondData.value = 7;
    secondData.next = NULL;
	
	MyData thirdData;
	thirdData.value = 2;
	thirdData.next = NULL;
	
	MyData fourthData;
	fourthData.value = 6;
	fourthData.next = NULL;
    
    
    
    myList.push_back(firstData); 
    myList.push_back(secondData); 
    myList.push_back(thirdData); 
    myList.push_back(fourthData); 
    
    cout << "Lista initiala:                      ";
    myList.printList();
    cout<<"Lista cu legaturile inversate:          ";
    myList.reverse_list();
    myList.printList();

    
    
    return 0;
}
