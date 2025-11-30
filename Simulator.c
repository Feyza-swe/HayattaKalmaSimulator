#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    
    int saglik = 100;
    int enerji = 100;
    int yemek = 0;
    int siginak = 0;
    char komut;
    
   
    srand(time(NULL));
    
    printf("=== HAYATTA KALMA SIMULATORU ===\n");
    printf("Komutlar: A-vlan, S-iginak ara, E-nvanter, R-dinlen, F-tehlike, P-sifre, X-cikis\n\n");
    
  
    do {
        printf("Komut girin: ");
        scanf(" %c", &komut);
        komut = toupper(komut);  
        
        switch(komut) {
            case 'A':
                printf("Avlaniyorsunuz...\n");
                
              
                enerji -= 20;
                if(enerji < 0) enerji = 0;
                
               
                int avBasari = (rand() % 100) < 60; 
                int yaralanma = (rand() % 100) < 30; 
                if(avBasari && !yaralanma) {
                    printf("Av basarili! Yemek buldunuz.\n");
                    yemek++; 
                } 
                else if(avBasari && yaralanma) {
                    printf("Av basarili ama yaralandiniz! Yemek ve -20 saglik.\n");
                    yemek++;
                    saglik -= 20;
                }
                else {
                    printf("Av basarisiz. Enerjiniz azaldi.\n");
                }
                break;
                
            case 'S': 
                printf("Siginak ariyorsunuz...\n");
                
                
                if(!siginak) {
                    int siginakSansi = (rand() % 100) < 40;
                    
                    if(siginakSansi || enerji > 70) { 
                        printf("Siginak buldunuz! Guvende hissediyorsunuz.\n");
                        siginak = 1;
                    } else {
                        printf("Siginak bulamadiniz. Daha fazla aramalisiniz.\n");
                    }
                } else {
                    printf("Zaten bir sinaganiginiz var.\n");
                }
                break;
                
            case 'E': 
                printf("=== ENVANTER ===\n");
                printf("Saglik: %d\n", saglik);
                printf("Enerji: %d\n", enerji);
                printf("Yemek: %d\n", yemek);
                printf("Siginak: %s\n", siginak ? "Evet" : "Hayir");
                break;
                
            case 'R': 
                printf("Dinleniyorsunuz...\n");
                
               
                enerji += 30;
                if(enerji > 100) enerji = 100;
                
              
                if(saglik < 100 && siginak) {
                    saglik += 10;
                    if(saglik > 100) saglik = 100;
                    printf("Siginakta dinlendiniz. Enerji ve saglik artti.\n");
                } else {
                    printf("Dinlendiniz. Enerji artti.\n");
                }
                break;
                
            case 'F': 
                printf("Tehlike bolgesine girdiniz! 5 tur hayatta kalmalisiniz.\n");
                
                int hasarToplam = 0;
                int kacmaSansi;
                
               
                for(int tur = 1; tur <= 5; tur++) {
                    printf("Tur %d: ", tur);
                    
                    kacmaSansi = rand() % 100;
                    
                    if(kacmaSansi < 20) { 
                        printf("Tebrikler! Tehlikeden kactiniz.\n");
                        break;
                    } 
                    else if(kacmaSansi < 60) {
                        int hasar = 5 + (rand() % 10);
                        saglik -= hasar;
                        hasarToplam += hasar;
                        printf("Hasar aldiniz! -%d saglik.\n", hasar);
                    }
                    else { 
                        printf("Guvenli bir nokta buldunuz.\n");
                    }
                    
                    
                    if(saglik <= 0) {
                        printf("Saglik sifira ulasti! Oyunu kaybettiniz.\n");
                        break;
                    }
                }
                
                if(saglik > 0) {
                    printf("Tehlike bolgesinden kurtuldunuz. Toplam hasar: %d\n", hasarToplam);
                }
                break;
                
            case 'P': 
                printf("Sifreli bir kapi buldunuz. Gecmek icin 'G' harfini girmelisiniz.\n");
                
                char girilenKarakter;
                int denemeSayisi = 0;
                
                
                do {
                    printf("Sifreyi girin: ");
                    scanf(" %c", &girilenKarakter);
                    girilenKarakter = toupper(girilenKarakter);
                    
                    denemeSayisi++;
                    
                    if(girilenKarakter != 'G') {
                        printf("Yanlis sifre! Tekrar deneyin.\n");
                        
                        
                        if(denemeSayisi % 2 == 0) {
                            enerji -= 5;
                            printf("Enerjiniz azaldi: %d\n", enerji);
                        }
                    }
                    
                } while(girilenKarakter != 'G' && enerji > 0);
                
                if(girilenKarakter == 'G') {
                    printf("Tebrikler! Kapiyi actiniz. Yeni bir bolgeye ulastiniz.\n");
                    
                    yemek += 2;
                    printf("2 yemek odulu kazandiniz.\n");
                } else {
                    printf("Enerjiniz bitti. Kapiyi acamadiniz.\n");
                }
                break;
                
            case 'X': 
                printf("Oyundan cikiliyor...\n");
                break;
                
            default:
                printf("Gecersiz komut! Kullanilabilir komutlar: A, S, E, R, F, P, X\n");
                break;
        }
        
       
        if(saglik <= 0) {
            printf("Saglik sifira ulasti. Oyun bitti!\n");
            break;
        }
        
        if(enerji <= 0) {
            printf("Enerjiniz tukendi. Oyun bitti!\n");
            break;
        }
        
        printf("\n");
        
    } while(komut != 'X' && saglik > 0 && enerji > 0);
    
    printf("=== OYUN SONU ===\n");
    printf("Final durumu: Saglik: %d, Enerji: %d, Yemek: %d\n", saglik, enerji, yemek);
    
    return 0;
}
