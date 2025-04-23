#include <stdio.h>
#include <stdlib.h>  // rand() ve srand() için
#include <time.h>    // time() için

int main(void) {
    char name[15];
    char blank[] = "─────────────────────────────\n";
    printf("🎯 Merhaba, sayı tahmini oyununa hoşgeldin!\n%s📝 Lütfen ismini gir: ", blank);
    scanf("%s", name);

    int gameModeInput, gameMode;
    printf("%s👋 Tekrardan hoşgeldin, %s!\n%s🎮 Oyun modu seç:\n   1️⃣ Kolay\t\t(1 - 10)\n   2️⃣ Normal\t(1 - 100)\n   3️⃣ Zor\t\t(1 - 1000)\n👉 Seçimin: ", blank, name, blank);
    scanf("%d", &gameModeInput);
    printf("%s",blank);
    switch (gameModeInput) {
        case 1:
            gameMode = 1;
            printf("Oyun modu 'Kolay' seçildi. Bol şanslar :)\n");
            break;
        case 2:
            gameMode = 2;
            printf("Oyun modu 'Normal' seçildi. Bol şanslar :)\n");
            break;
        case 3:
            gameMode = 3;
            printf("Oyun modu 'Zor' seçildi. Bol şanslar :)\n");
            break;
        default:
            gameMode = 2;
            printf("!!! HATA - Yanlış seçim yaptınız. Oyun modu 'Normal' seçildi.\n");
            break;
    }
    printf("%s",blank);

    int selectedNumber = 0;
    srand(time(NULL));           // Rastgele sayı üretimini başlatmak için seed ayarlanır
    if (gameMode == 1) {
        selectedNumber = rand() % 10 + 1;        // 1 ile 10 arasında bir sayı üretir
    } else if (gameMode == 2) {
        selectedNumber = rand() % 100 + 1;       // 1 ile 100 arasında bir sayı üretir
    } else if (gameMode == 3) {
        selectedNumber = rand() % 1000 + 1;      // 1 ile 1000 arasında bir sayı üretir
    } else {
        printf("!!! HATA - PROGRAM KAPATILIYOR.\n");
    }

    printf("Geliştirici modu tutulan sayı: %d", selectedNumber);

    printf("\n%s🚀 Oyun Başlıyor! Bol şans! 🍀\n%s",blank ,blank);
    int guess, life = 3;

    while (life > 0) {
        // Can göstergesi
        for (int i = 0; i < life; i++) {
            printf("❤️ ");
        }
        printf("\n");

        printf("▸ Tahmininizi girin: ");
        scanf("%d", &guess);

        if (guess == selectedNumber) {
            printf("🏆 Bravo %s! Sayıyı doğru bildin! 🎉\n", name);
            break;
        } else if (guess < selectedNumber) {
            printf("📈 Daha büyük bir sayı dene!\n");
        } else {
            printf("📉 Daha küçük bir sayı dene!\n");
        }

        life--;
    }

    if (life == 0) {
        printf("💀 Oyunu kaybettin! Doğru sayı şuydu: %d 😢\n", selectedNumber);
    }
    
}
