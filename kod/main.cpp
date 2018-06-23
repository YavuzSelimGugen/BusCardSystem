#include <iostream>
#include "person.h"
#include "admin.h"
#include "user.h"
using namespace std;
//Ön tanımlar.
void menu(person *dizi[10]);
void adminPanel(int i, person *dizi[10]);
void adminGiris(person *dizi[10]);
void userPanel(int i, person *dizi[10]);

//Admin panelinde işlemler yapıldıktan sonra y/n işlemini yapar.
void admingecis(int i,person *dizi[10]){
    char cevap;
    cout<<"Ana menuye devam etmek icin y/n";
    cin>>cevap;
    if(cevap == 'y'){
        menu(dizi);
    } else if (cevap == 'n'){
        adminPanel(i,dizi);
    }
}
//User panelinde işlemler yapıldıktan sonra anamenüye gidilip gidilmeyeceğini kontrol eder.
void usergecis(int i,person *dizi[10]){
    char cevap;
    cout<<"Anamenuye devam etmek icin y/n";
    cin>>cevap;
    if(cevap == 'y'){
        menu(dizi);
    } else if (cevap == 'n'){
        userPanel(i,dizi);
    }
}
//Admin işlemlerinin yapıldığı panel.
void adminPanel(int i, person *dizi[10]){
    system("cls");
    int girdi;
    admin *admin1 = (admin *)dizi[i];
    cout<< "1) Kullanici olustur."<<endl;
    cout<< "2) Kullanici sil."<<endl;
    cout<< "3) Kullanici durumunu goster."<<endl;
    cout<< "4) Kullanici bul."<<endl;
    cout<< "5) Kullanici kartlarini birlestir."<<endl;
    cout<< "6) Kullanici bilgilerini degistir."<<endl;
    cout<< "7) Ana menuye don."<<endl;
    cin>>girdi;

    string ad,soyad;
    int tc;
    user *u1 = new user();

    if(girdi == 1){
        system("cls");
        cout<<"Kullanici adini giriniz:";
        cin>>ad;
        cout<<"Kullanici soyadini giriniz: ";
        cin>>soyad;
        cout<<"Tc girniz: ";
        cin>>tc;
        admin1->CreateUser(ad,soyad,tc,dizi);
        admingecis(i,dizi);

    } else if( girdi == 2){
        system("cls");
        cout<<"Silinecek kullanicinin Tc nosunu giriniz: ";
        cin>>tc;
        admin1->DeleteUser(tc, dizi);
        admingecis(i,dizi);
    } else if (girdi == 3){
        system("cls");
        cout<<"aragidin tc yi gir: ";
        cin>>tc;
        u1 = admin1->FindUser(tc,dizi);
        admin1->ShowUserState(u1);
        admingecis(i,dizi);
    } else if (girdi == 4){
        system("cls");
        cout<<"aragidin tc yi gir: ";
        cin>>tc;
        u1 = admin1->FindUser(tc,dizi);
        admin1->ShowPersonState(u1);
        admingecis(i,dizi);
    } else if (girdi == 5) {
        system("cls");
        cout<<"Kullanici tc yi gir: ";
        cin>>tc;
        u1 = admin1->FindUser(tc,dizi);
        admin1->CombineUserCards(u1);
        admingecis(i,dizi);
    } else if (girdi == 6) {
        system("cls");
        cout<<"Kullanici tc yi gir: ";
        cin>>tc;
        u1 = admin1->FindUser(tc,dizi);
        cout<<u1->getName()<<u1->getSurname()<<" isimli kullancinin degistirmek istediginiz Adini giriniz:"<<endl;
        cin>>ad;
        u1->setName(ad);
        cout<<u1->getName()<<u1->getSurname()<<" isimli kullancinin degistirmek istediginiz Soyadini giriniz:"<<endl;
        cin>>soyad;
        u1->setSurname(soyad);
        cout<<"Guncellenmis ad, soyad: "<<u1->getName()<<u1->getSurname();
        admingecis(i,dizi);
    } else if (girdi == 7) {
        menu(dizi);
    } else {
        cout<< "Yanlis girdi!"<<endl;
        adminPanel(i,dizi);
    }


}
//Ana menüden gelen kullanıcının admin olup olmadığını kontrol eder.
void adminGiris(person *dizi[10]){
    system("cls");
    int tc,i,boo=0;
    cout<<"Yonetici TC giriniz:"<<endl;
    cin>>tc;
    for (i = 0; i < 10; ++i) {
        if (dizi[i]->getTc()==tc && dizi[i]->getPersonType()==Admin){
            cout<<"Yonetici girisi basarili"<<endl;
            adminPanel(i,dizi);
            boo = 1;
            break;
        }
    }
    if(boo == 0){
        cout<<"Araginiz Tc de bir yonetici bulunmamaktadir."<<endl;
        menu(dizi);
    }
}
//Kullanıcı işlemlerinin yapıldığı sekme.
void userPanel(int i, person *dizi[10]){
    system("cls");
    int girdi;
    user *user1 = (user *)dizi[i];
    cout<< "1) Bakiye yukle."<<endl;
    cout<< "2) Kart okut."<<endl;
    cout<< "3) Kart durumunu goster."<<endl;
    cout<< "4) Ana Menu."<<endl;
    cin>>girdi;

    if(girdi == 1){
        int bakiye,k;
        cout<<"Hangi kart ? 1/2"<<endl;
        cin>>k;
        if(k == 1){
            cout<<"yuklemek istediginiz miktari giriniz:";
            cin>>bakiye;
            user1->LoadBalance((user1->getCard1()),bakiye);
            cout<<"yukleme islemi basarili yeni bakiyeniz: "<<user1->getCard1()->getBalance()<<endl;
        } else if (k == 2){
            cout<<"yuklemek istediginiz miktari giriniz:";
            cin>>bakiye;
            user1->LoadBalance((user1->getCard2()),bakiye);
            cout<<"yukleme islemi basarili yeni bakiyeniz: "<<user1->getCard2()->getBalance()<<endl;
        } else {
            cout<<"Yanlis girdi!!!"<<endl;
            menu(dizi);
        }
        usergecis(i,dizi);
    } else if (girdi == 2){
        int k;
        cout<<"Hangi kart ? 1/2"<<endl;
        cin>>k;
        if(k == 1){
            user1->ReadCard((user1->getCard1()));
        } else if (k == 2) {
            user1->ReadCard((user1->getCard2()));
        } else {
            cout<<"Yanlis girid!!!"<<endl;
            menu(dizi);
        }
        usergecis(i,dizi);

    } else if (girdi == 3){
        user1->ShowCardState();
        usergecis(i,dizi);
    } else if (girdi ==4){
        menu(dizi);
    } else {
        cout<<"yanlis girdi!!!"<<endl;
        userPanel(i,dizi);
    }
}
//Girilen tc nin kullanıcı olup olmadığını kontrol eder.
void userGiris(person *dizi[10]){
    system("cls");
    int tc,i,boo=0;
    cout<<"Kullanici TC giriniz:"<<endl;
    cin>>tc;
    for (i = 0; i < 10; ++i) {
        if (dizi[i]->getTc()==tc && dizi[i]->getPersonType()==User){
            cout<<"Kullanici girisi basarili"<<endl;
            userPanel(i,dizi);
            boo = 1;
            break;
        }
    }
    if(boo == 0){
        cout<<"Araginiz Tc de bir kullanici bulunmamaktadir."<<endl;
        menu(dizi);
    }
}
//Menu akışını sağlar.
void menu(person *dizi[10]){
    system("cls");
    puts("<<GidereGidere Turizm>>");
    int secim;

    printf("1)\tYonetici islemleri.\n");
    printf("2)\tKullanici islemleri.\n");
    printf("3)\tCikis.\n");

    cin>>secim;

    printf("seciminiz %d\n",secim);
    if(secim == 1){
        adminGiris(dizi);
    } else if (secim == 2) {
        userGiris(dizi);
    } else if (secim == 3) {
        return;
    }  else {
        puts("Gecersiz girdi.");
        menu(dizi);
    }
}
//Program  başlangıcındaki diziyi doldurur.
void fillPersons(person *dizi[10]){
    for (int i = 0; i <10 ; i++) {
        person *p = new person();
        dizi[i] = p ;
        dizi[i]->setTc(0);
    }
    admin *admin1 = new admin();
    admin1->setName("Hakki");
    admin1->setSurname("Hakili");
    admin1->setPersonType(1);
    admin1->setTc(1234);

    user *user1 = new user();
    user1->setName("Selin");
    user1->setSurname("sakli");
    user1->setTc(4321);
    user1->setPersonType(0);

    card *card1 = new card();
    card1->setBalance(10000);
    card1->setCardType(1);

    card *card2 = new card();
    card2->setBalance(200);
    card2->setCardType(1);

    user1->setCard1(card1);
    user1->setCard2(card2);
    dizi[0] = admin1;
    dizi[1] = user1;

}
int main() {
    person *dizi[10];
    fillPersons(dizi);

    menu(dizi);

    return 0;
}