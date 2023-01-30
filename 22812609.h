#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include <stdio.h>
struct nodeFB
{
	int id;
	int age;
	struct nodeFB *next;
};

struct nodeGS
{
	int id;
	struct nodeGS *next;
};

struct newNodeFB
{
	int id;
	int age;
	struct newNodeGS *next;
};

struct newNodeGS
{
	int id;
	struct newNodeFB *next;
};

// Bu lab kapsaminda kullanilacak butun fonksiyon tanimlarini bu dosyanin icine yazmaniz gerekmektedir.
// Tanimlanmasi zorunlu fonksiyonlar icerisinden kendi tanimayacaginiz baska fonksiyonlari cagirabilirsiniz.
// main.c dosyasinda bir degisiklik yapmayiniz.
// Sisteme function.h dosyasinin ismini OgrenciNumarasi.h olarak yukleyiniz.


//Artan siraya gore, ilk arguman pointer of pointer
void insertFB(struct nodeFB **startFB, int id, int age) //Fenerbahce bagli listesine eleman ekleme fonksiyonu
{
    if(*startFB == NULL){
        *startFB = (struct nodeFB *) malloc(sizeof(struct nodeFB ));
        (*startFB)->id = id;
        (*startFB)->age = age;
        (*startFB)->next = NULL;
    }else{
        struct nodeFB *itr;

        if(id < (*startFB)->id){
            //ilk eleman kucuk, bu sekilde artik ilk eleman yeni gelen elemandir
            itr = (*startFB);
            *startFB = (struct nodeFB *) malloc(sizeof(struct nodeFB ));
            (*startFB)->id = id;
            (*startFB)->age = age;
            (*startFB)->next = itr;
        }else{
            struct nodeFB *newNode;
            itr = *startFB;
             // Uygun yeri bul
              while(itr->next && itr->next->id < id)
              {
                  itr = itr->next;
              }
            newNode = (struct nodeFB *) malloc(sizeof(struct nodeFB ));
            newNode->id = id;
            newNode->age = age;
            newNode->next = itr->next;
            itr->next = newNode;
        }
    }
}

//Azalan siraya gore
void insertGS(struct nodeGS **startGS, int id) //Galatasaray bagli listesine eleman ekleme fonksiyonu
{

    if(*startGS == NULL){

        *startGS = (struct nodeGS *) malloc(sizeof(struct nodeGS ));
        (*startGS)->id = id;
        (*startGS)->next = NULL;
    }else{
        struct nodeGS *itr;

        if(id > (*startGS)->id){
            //ilk eleman kucuk, bu sekilde artik ilk eleman yeni gelen elemandir
            itr = (*startGS);
            *startGS = (struct nodeGS *) malloc(sizeof(struct nodeGS ));
            (*startGS)->id = id;
            (*startGS)->next = itr;

        }else{
            struct nodeGS *newNode;
            itr = *startGS;
             // Uygun yeri bul
              while(itr->next && itr->next->id > id)
              {
                  itr = itr->next;
              }
            newNode = (struct nodeGS *) malloc(sizeof(struct nodeGS ));
            newNode->id = id;
            newNode->next = itr->next;
            itr->next = newNode;
        }


    }

}

void printFB(struct nodeFB *startFB) //Fenerbahce bagli listesini yazdiran fonksiyon
{
    struct nodeFB *itr= startFB;

    
    while(itr)
    {
        printf("%d %d\n", itr->id, itr->age);
        itr = itr->next;
    }


}
void printGS(struct nodeGS *startGS) //Galatasaray bagli listesini yazdiran fonksiyon
{
    struct nodeGS *itr= startGS;
    printf("\n");
    while(itr)
    {
        printf("%d\n", itr->id);
        itr = itr->next;
    }

}



void createFinalList(struct newNodeFB **startNewFB, struct nodeFB *startFB, struct nodeGS *startGS) //Iki bagli listeyi birlestiren fonksiyon
{
    struct nodeFB *itr_fb = startFB;
    struct nodeGS *itr_gs = startGS;
    struct newNodeFB *itrNewNodeFB = NULL;
    struct newNodeGS *itrNewNodeGS = NULL;

    while(itr_fb){


         if(*startNewFB == NULL){

            *startNewFB = (struct newNodeFB *) malloc(sizeof(struct newNodeFB ));
            (*startNewFB)->id = itr_fb->id;
            (*startNewFB)->age = itr_fb->age;
            (*startNewFB)->next = (struct newNodeGS *) malloc(sizeof(struct newNodeGS));
            (*startNewFB)->next->id = itr_gs->id;
            (*startNewFB)->next->next = NULL;

            itrNewNodeFB = (*startNewFB);
            itrNewNodeGS = (*startNewFB)->next;
        }else{
            itrNewNodeGS->next = (struct newNodeFB *) malloc(sizeof(struct newNodeFB ));
            itrNewNodeFB = itrNewNodeGS->next;
            itrNewNodeFB->id = itr_fb->id;
            itrNewNodeFB->age = itr_fb->age;

            itrNewNodeFB->next = (struct newNodeGS *) malloc(sizeof(struct newNodeGS ));
            itrNewNodeGS = itrNewNodeFB->next;
            itrNewNodeGS->id = itr_gs->id;
            itrNewNodeGS->next = NULL;
        }

        // forward next item for both linked lists
        itr_fb = itr_fb->next;
        itr_gs = itr_gs->next;
    }




}
void printAll(struct newNodeFB *startNewFB) //Birlestirilmis yeni bagli listeyi yazdiran fonksiyon
{
    struct newNodeFB *itr_fb= startNewFB;
    struct newNodeGS *itr_gs= startNewFB->next;

    printf("\n");
    while(1)
    {
        printf("%d %d\n", itr_fb->id, itr_fb->age);
        printf("%d\n", itr_gs->id);

        itr_fb = itr_gs->next;
        if(itr_fb)
            itr_gs = itr_fb->next;
        else
            break;
    }
}

#endif // FUNCTION_H_INCLUDED
