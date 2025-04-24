#include <stdio.h>
#include <stdlib.h>     // rand() ve srand() için
#include <time.h>       // time() için

int main(void)
{
    char name[15];
    char blank[] = "─────────────────────────────────\n";

    printf("🎯 Merhaba, sayı tahmini oyununa hoşgeldin!\n%s", blank);
    printf("📝 Lütfen ismini gir: ");
    scanf("%s", name);

    int gameModeInput, gameMode;

    printf("%s👋 Tekrardan hoşgeldin, %s!\n", blank, name);
    printf("%s🎮 Oyun modu seç:\n", blank);
    printf("   1️⃣ Kolay\t\t(1 - 10)\n");
    printf("   2️⃣ Orta\t\t(1 - 100)\n");
    printf("   3️⃣ Zor\t\t(1 - 1000)\n");
    printf("👉 Seçimin:\t\t");
    scanf("%d", &gameModeInput);

    printf("%s", blank);

    switch (gameModeInput)
    {
        case 1:
            gameMode = 1;
            printf("\tOyun modu 'Kolay' seçildi.\n");
            break;
        case 2:
            gameMode = 2;
            printf("\tOyun modu 'Orta' seçildi.\n");
            break;
        case 3:
            gameMode = 3;
            printf("\tOyun modu 'Zor' seçildi.\n");
            break;
        default:
            gameMode = 2;
            printf("!!! HATA - Yanlış seçim yaptınız.\nLütfen tekrar deneyiniz.\n%s",blank);
            return 0;
    }

    printf("%s", blank);


    srand(time(NULL));      // Rastgele sayı üretimini başlatmak için seed ayarlanır

    int guess = 0, life = 3;
    double money = 100;
    int selectedNumber = 0;
    int currentNumber = 0;

    while (life > 0)
    {


        if (gameMode == 1)
        {
            selectedNumber = rand() % 10 + 1;       // 1 ile 10 arasında bir sayı üretir
            currentNumber = selectedNumber;
        }
        else if (gameMode == 2)
        {
            selectedNumber = rand() % 100 + 1;      // 1 ile 100 arasında bir sayı üretir
            currentNumber = selectedNumber;
        }
        else if (gameMode == 3)
        {
            selectedNumber = rand() % 1000 + 1;     // 1 ile 1000 arasında bir sayı üretir
            currentNumber = selectedNumber;
        }
        else
        {
            printf("!!! HATA - PROGRAM KAPATILIYOR.\n");
            break;
        }

        while (life > 0)
        {
            printf("    ");
            for (int i = 0; i < life; i++){printf("❤️ ");}              // Can göstergesi

            printf("\t💵: %3.2f TL\n%s", money, blank);                 // Para göstergesi

            printf("▸ Tahmininizi girin: ");                            // Bu kısım kullanıcılar için kullanılmalıdır.
            //printf("▸ (%d) Tahmininizi girin: ",selectedNumber);        // Bu kısım geliştiriciler için kullanılmalıdır.
            scanf("%d", &guess);        // Kullanıcının tahminini alır

            if (guess == selectedNumber)
            {
                printf("%s🏆 Bravo %s! Sayıyı doğru bildin! 🎉\n%s", blank,name,blank);
                money *= 2;     // Doğru tahminde para 2 katına çıkar
                life = 3;       // Canlar sıfırlanır
                break;
            }
            else if (guess < selectedNumber)
            {
                if (life > 1)
                    printf("%s📈 Daha büyük bir sayı dene!\n",blank);
            }
            else
            {
                if (life > 1)
                    printf("%s📉 Daha küçük bir sayı dene!\n",blank);
            }

            life--;     // Yanlış cevaptan dolayı can eksilmesi
        }
    }

    if (life == 0)
    {
        money /= 2;     // Canlar bitince para yarıya düşer
        printf("%s💀 Oyunu kaybettin! Doğru sayı şuydu: %d 😢\n", blank, currentNumber);
        printf("🎉 Toplam kazancın: %3.2f TL\n%s", money,blank);
    }
    
    return 0;
    
    //mcanerarslan
}
