#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int oyun();
int main()
{
  oyun();
        return 0;

    } oyun()
    {
    int bilgisayarin_urettikleri[100],kullanicinin_girdigi[100];  //hamleleri saklamak i�in iki ayr� dizi tan�mlad�m
    int sayac=0;

    int T=1, K=2, M=3;
    int oyuncu,bilgisayar;
    int skor_oyuncu=0, skor_bilgisayar=0;  //ba�lang��ta iki taraf�n puan� da yok.
    printf("------------------------------------------------TAS KAGIT MAKAS OYUNU------------------------------------------------\n");
    printf("Tas=1\nKagit=2\nMakas=3\n");
    printf("Bes puan alan kazanir ve oyun biter\n");

    srand(time(NULL));  //bilgisayar�n rastgele say� �retmesi i�in kulland�m.

    while(skor_bilgisayar!=5 && skor_oyuncu!=5)  // iki taraftan biri 5 olana kadar d�ng� devam edecek.
    {

        int bilgisayar= (rand()%3)+1;  //%3+1 kulland�m ��nk� bilgisayar�n �retti�i de�erlerin 1-3 aras�nda olmas� gerek. (T-K-M'� 0-1-2 olarak tan�mlasayd�m +1 kullanmama gerek kalmayacakt�.)
        bilgisayarin_urettikleri[sayac]=bilgisayar;  //bilgisayar�n girdi�i de�eri diziye aktarmak i�in b�yle bir e�itlik kulland�m. Bu sayede de�er �retildi�i gibi diziye ksydedilmi� olacak.

        printf("\n1-3 arasinda bir deger giriniz:");
        scanf("%d",&oyuncu);
        kullanicinin_girdigi[sayac]=oyuncu; // ayn� �ekilde oyuncunun girdi�i de�eri diziye aktarmak i�in b�yle bir e�itlik olu�turdum.

        printf("%d",bilgisayar); //bilgisayar�n girdi�i de�eri ekranda bast�rmak i�in yazd�m.
                                                 //BURADAN �T�BAREN OLASILIKLARI YAZACA�IM.
        if(oyuncu==2 && bilgisayar==1)           //36,42 ve 47. sat�rlarda oyuncunun kazand��� durumlar� belirttim.
        {
            printf("\nkagit tasi yener!!\n\n 1 Puan aldiniz!!");
            skor_oyuncu=skor_oyuncu+1;    //Oyuncu 1 puan kazand�.
        }
        else if(oyuncu==3 && bilgisayar==2)
        {
            printf("\n makas kagidi yener!!\n\n 1 Puan aldiniz!!");
            skor_oyuncu=skor_oyuncu+1;    //Oyuncu 1 puan kazand�.
        }
        else if(oyuncu==1 && bilgisayar==3)
        {
            printf("\ntas makasi yener!!\n\n 1 Puan aldiniz!!");
            skor_oyuncu=skor_oyuncu+1;    //Oyuncu 1 puan kazand�.
        }
        else if(oyuncu==1 && bilgisayar==2)       //51.56 ve 61. sat�rlarda bilgisayar�n kazand��� durumlardan bahsettim.
        {
            printf("\nkagit tasi yener!!\n\n Bilgisayar 1 puan aldi!!");
            skor_bilgisayar=skor_bilgisayar+1;   //bilgisayar 1 puan kazand�.
        }
        else if(oyuncu==2 && bilgisayar==3)
        {
            printf("\nmakas kagidi yener!!\n\n Bilgisayar 1 puan aldi!!");
            skor_bilgisayar=skor_bilgisayar+1;    //bilgisayar 1 puan kazand�.
        }
        else if(oyuncu==3 && bilgisayar==1)
        {
            printf("\n tas makasi yener!!\n\n Bilgisayar 1 puan aldi!!");
            skor_bilgisayar=skor_bilgisayar+1;    //bilgisayar 1 puan kazand�.
        }
        else if (oyuncu==bilgisayar)      //berabere olunan durum
        {
            printf("\nBerabere!\n puan yok  :( ");  //puanda bir de�i�iklik yok. (iki taraf da 0 puan ald�.)
        }
        else     //1-3 aral��� d���nda bir say� girilmesi durumuda uyar� vermek i�in yazd�m.
            printf("\nYanlis bir sayi girdiniz!!");

        sayac++; //while d�ng�s�n� tekrar takrar d�nd�rmek i�in(oyunu ba�tan ba�latmak i�in)  diziye aktarmak i�in
    }

        for(int i=0;i<sayac;i++){  //burda ama� oyunun hamlelerini bast�rmak. Mesela 10 hamlede(sayac) 5 puana ula��ls�n o zaman oyun 10 defa d�nm�� demektir. for d�ng�s�yle bu hamleleri bast�r�yoruz.
            printf("Bilgisayar: %d ***** ",bilgisayarin_urettikleri[i]);
            printf("Kullanici: %d\n",kullanicinin_girdigi[i]);
        }
        if(skor_bilgisayar>skor_oyuncu)
            printf("Bilgisayar Kazandi! Skor:%d-%d",skor_bilgisayar,skor_oyuncu);
        else
            printf("Siz kazandiniz. Tebrikler! Skor:%d-%d",skor_oyuncu,skor_bilgisayar);
    }
