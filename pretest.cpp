#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

struct ElemtList{
    char npm[14];
    char nama[40];
    float ipk;
    ElemtList* next;
};
typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First){
    First = NULL;
}

void banyakData(int& n){
    cout << "Masukkan banyak data : "; cin >> n;
}

void createElement(pointer& pBaru){
    pBaru = new ElemtList;
    cout << "Masukkan NPM   : "; cin >> pBaru->npm;
    cout << "Masukkan nama  : "; cin.ignore(); cin.getline(pBaru->nama,40);
    cout << "Masukkan IPK   : "; cin >> pBaru->ipk;
    pBaru->next = NULL;
}

void insertSortNama(List& First, pointer pBaru, int n){
    ElemtList sortnama;
    if(First==NULL){
        First = pBaru;
    }
    else{
        pBaru->next = First;
        First = pBaru;
    }

	for(int i=0; i<n;i++){
		for(int j=1;j<n;j++){
			if(strcmp(pBaru[j-1].nama, pBaru[j].nama)>0){
				sortnama = pBaru[j-1];
				pBaru[j-1] = pBaru[j];
				pBaru[j] = sortnama;
			}
		}
	}
}

void traversal(List First){
    pointer pBantu;
    if(First==NULL){
        cout << "List kosong\n";
    }
    else{
        pBantu = First;while(pBantu != NULL){
            cout << pBantu->npm << "\t" << pBantu->nama << "\t" << pBantu->ipk << endl;
            pBantu = pBantu->next;
        }
        cout << endl;
    }
}

int main()
{
    List l;
    pointer p;
    int n;

    banyakData (n);
    createList(l);


    cout << "----------------------------------------------\n";
    cout << "NPM\t\t" << "Nama\t\t" << "IPK\t\n";
    cout << "----------------------------------------------\n";

    for(int i=0;i<n;i++){
        createElement(p);
        traversal(l);
    }

}
