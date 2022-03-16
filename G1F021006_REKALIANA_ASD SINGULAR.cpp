#include <iostream>
using namespace std;

struct laptop{
  string merek, jenis, harga;

  laptop *next;
};

laptop *head, *tail, *newNode, *cur, *del;

void createCircularSingleLinkedList(string dataBaru[4]){

  head = new laptop();
  head->merek = dataBaru[0];
  head->jenis = dataBaru[1];
  head->harga = dataBaru[2];
  tail = head;
  tail->next = head;

}


void addFirst( string data[3] ){
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    newNode = new laptop();
    newNode->merek = data[0];
    newNode->jenis = data[1];
    newNode->harga = data[2];
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
  }
}


void addLast( string data[3] ){
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    newNode = new laptop();
    newNode->merek = data[0];
    newNode->jenis = data[1];
    newNode->harga = data[2];
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
  }
}


void addMiddle(string data[3], int posisi)
{
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    if( posisi == 1 ){
      cout << "Posisi satu bukan posisi tengah!!!" << endl;
    }else{
      newNode = new laptop();
      newNode->merek = data[0];
      newNode->jenis = data[1];
      newNode->harga = data[2];

      
      int nomor = 1;
      cur = head;
      while (nomor < posisi - 1)
      {
        cur = cur->next;
        nomor++;
      }
      newNode->next = cur->next;
      cur->next = newNode;
    }
  }
}


void removeFirst(){
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    del = head;
    head = head->next;
    tail->next = head;
    delete del;
  }
}


void removeLast()
{
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    del = tail;
    cur = head;
    while( cur->next != tail ){
      cur = cur->next;
    }
    tail = cur;
    tail->next = head;
    delete del;
  }
}


void removeMiddle(int posisi)
{
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    
    int nomor = 1;
    cur = head;
    while( nomor < posisi - 1 ){
      cur = cur->next;
      nomor++;
    }
    del = cur->next;
    cur->next = del->next;
    delete del;
  }
}


void printCircular()
{
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    cout << " List laptop " << endl;
    cout << "________________________________________________________________" << endl; 
    cout << "| MEREK\t\t| JENIS\t\t| HARGA\t|" << endl;
    cout << "________________________________________________________________" << endl; 
    cur = head;
    while (cur->next != head)
    {
      
      cout << "| " << cur->merek << "\t\t| " << cur->jenis << "\t| " << cur->harga << "\t\t|" << endl;
      cur = cur->next;
    }
    cout << "| " << cur->merek << "\t\t| " << cur->jenis << "\t| " << cur->harga << "\t\t|" << endl;
    cout << "_________________________________________________________________" << endl;
  }
}


int main(){
  string dataBaru[3] = {"Asus", "CrhomeBook", "8000000"};
  createCircularSingleLinkedList(dataBaru);

  printCircular();

  string data[3] = {"Xiaomi", "RedmiBook 15", "9000000 "};
  addFirst(data);

  printCircular();

  string data2[3] = {"HP", "14s-dq0508TU", "5999000"};
  addLast(data2);

  printCircular();

  string data3[3] = {"APPLE", "MACBOOK Air", "12199000"};
  addMiddle(data3, 5);

  printCircular();

  removeMiddle(6);

  printCircular();

  removeFirst();

  printCircular();

  removeLast();

  printCircular();
}
