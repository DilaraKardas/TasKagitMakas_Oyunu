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
    int bilgisayarin_urettikleri[100],kullanicinin_girdigi[100];  //hamleleri saklamak için iki ayrý dizi tanýmladým
    int sayac=0;

    int T=1, K=2, M=3;
    int oyuncu,bilgisayar;
    int skor_oyuncu=0, skor_bilgisayar=0;  //baþlangýçta iki tarafýn puaný da yok.
    printf("------------------------------------------------TAS KAGIT MAKAS OYUNU------------------------------------------------\n");
    printf("Tas=1\nKagit=2\nMakas=3\n");
    printf("Bes puan alan kazanir ve oyun biter\n");

    srand(time(NULL));  //bilgisayarýn rastgele sayý üretmesi için kullandým.

    while(skor_bilgisayar!=5 && skor_oyuncu!=5)  // iki taraftan biri 5 olana kadar döngü devam edecek.
    {

        int bilgisayar= (rand()%3)+1;  //%3+1 kullandým çünkü bilgisayarýn ürettiði deðerlerin 1-3 arasýnda olmasý gerek. (T-K-M'ý 0-1-2 olarak tanýmlasaydým +1 kullanmama gerek kalmayacaktý.)
        bilgisayarin_urettikleri[sayac]=bilgisayar;  //bilgisayarýn girdiði deðeri diziye aktarmak için böyle bir eþitlik kullandým. Bu sayede deðer üretildiði gibi diziye ksydedilmiþ olacak.

        printf("\n1-3 arasinda bir deger giriniz:");
        scanf("%d",&oyuncu);
        kullanicinin_girdigi[sayac]=oyuncu; // ayný þekilde oyuncunun girdiði deðeri diziye aktarmak için böyle bir eþitlik oluþturdum.

        printf("%d",bilgisayar); //bilgisayarýn girdiði deðeri ekranda bastýrmak için yazdým.
                                                 //BURADAN ÝTÝBAREN OLASILIKLARI YAZACAÐIM.
        if(oyuncu==2 && bilgisayar==1)           //36,42 ve 47. satýrlarda oyuncunun kazandýðý durumlarý belirttim.
        {
            printf("\nkagit tasi yener!!\n\n 1 Puan aldiniz!!");
            skor_oyuncu=skor_oyuncu+1;    //Oyuncu 1 puan kazandý.
        }
        else if(oyuncu==3 && bilgisayar==2)
        {
            printf("\n makas kagidi yener!!\n\n 1 Puan aldiniz!!");
            skor_oyuncu=skor_oyuncu+1;    //Oyuncu 1 puan kazandý.
        }
        else if(oyuncu==1 && bilgisayar==3)
        {
            printf("\ntas makasi yener!!\n\n 1 Puan aldiniz!!");
            skor_oyuncu=skor_oyuncu+1;    //Oyuncu 1 puan kazandý.
        }
        else if(oyuncu==1 && bilgisayar==2)       //51.56 ve 61. satýrlarda bilgisayarýn kazandýðý durumlardan bahsettim.
        {
            printf("\nkagit tasi yener!!\n\n Bilgisayar 1 puan aldi!!");
            skor_bilgisayar=skor_bilgisayar+1;   //bilgisayar 1 puan kazandý.
        }
        else if(oyuncu==2 && bilgisayar==3)
        {
            printf("\nmakas kagidi yener!!\n\n Bilgisayar 1 puan aldi!!");
            skor_bilgisayar=skor_bilgisayar+1;    //bilgisayar 1 puan kazandý.
        }
        else if(oyuncu==3 && bilgisayar==1)
        {
            printf("\n tas makasi yener!!\n\n Bilgisayar 1 puan aldi!!");
            skor_bilgisayar=skor_bilgisayar+1;    //bilgisayar 1 puan kazandý.
        }
        else if (oyuncu==bilgisayar)      //berabere olunan durum
        {
            printf("\nBerabere!\n puan yok  :( ");  //puanda bir deðiþiklik yok. (iki taraf da 0 puan aldý.)
        }
        else     //1-3 aralýðý dýþýnda bir sayý girilmesi durumuda uyarý vermek için yazdým.
            printf("\nYanlis bir sayi girdiniz!!");

        sayac++; //while döngüsünü tekrar takrar döndürmek için(oyunu baþtan baþlatmak için)  diziye aktarmak için
    }

        for(int i=0;i<sayac;i++){  //burda amaç oyunun hamlelerini bastýrmak. Mesela 10 hamlede(sayac) 5 puana ulaþýlsýn o zaman oyun 10 defa dönmüþ demektir. for döngüsüyle bu hamleleri bastýrýyoruz.
            printf("Bilgisayar: %d ***** ",bilgisayarin_urettikleri[i]);
            printf("Kullanici: %d\n",kullanicinin_girdigi[i]);
        }
        if(skor_bilgisayar>skor_oyuncu)
            printf("Bilgisayar Kazandi! Skor:%d-%d",skor_bilgisayar,skor_oyuncu);
        else
            printf("Siz kazandiniz. Tebrikler! Skor:%d-%d",skor_oyuncu,skor_bilgisayar);
    }
