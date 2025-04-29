#include <stdio.h>
#include <stdlib.h> // rand, srand gibi rastgele sayı üretimi için gerekli
#include <time.h>   // srand, time gibi rastgelelik ve zaman fonksiyonları için gerekli



void drawLine(void);
void displayStatus(int life, double money);
int getGuess(int selectedNumber);
int generateRandomNumber(int gameMode);
int selectGameMode(void);
void processCorrectGuess(char name[], double *money, int *life);
void giveHint(int guess, int selectedNumber, int life);
void displayGameOver(int selectedNumber, double money);

int main(void)
{
    srand(time(0));      // Rastgele sayı üretimini başlatmak için seed ayarlanır
    char name[15];
    printf("\n🎯 Merhaba, sayı tahmini oyununa hoşgeldin!\n");
    drawLine();
    printf("📝 Lütfen ismini gir: ");
    scanf("%14s", name);
    while (getchar() != '\n');
    
    int gameMode;
    int playAgain = 0;
    double money = 100;
    
    drawLine();
    printf("\n👋 Tekrardan hoşgeldin, %s!\n", name);
    
    do {
        gameMode = selectGameMode();
        drawLine();
        
        int selectedNumber = generateRandomNumber(gameMode);
        int guess = 0, life = 3;
        
        
        while (life > 0)
        {
            displayStatus(life, money);
            drawLine();
            guess = getGuess(selectedNumber);
            
            if (guess == selectedNumber)
            {
                processCorrectGuess(name, &money, &life);
                selectedNumber = generateRandomNumber(gameMode);
                continue;
            }
            giveHint(guess, selectedNumber, life);
            life--;
        }
        
        if (life == 0)
        {
            money /= 2;
            displayGameOver(selectedNumber, money);
            printf("Tekrar oynamak ister misin? (1 = Evet, 0 = Hayır): ");
            scanf("%d", &playAgain);
            while (getchar() != '\n');
            drawLine();
        }
    } while (playAgain == 1);
    
    return 0;
}

void drawLine(void) {
    printf("─────────────────────────────────\n");
}

void processCorrectGuess(char name[], double *money, int *life) {
    printf("\n🏆 Bravo %s! Sayıyı doğru bildin! 🎉\n", name);
    *money *= 2;
    *life = 3;
    drawLine();
    printf("✨ Yeni bir sayı türetildi! 🌟\n");
}

void giveHint(int guess, int selectedNumber, int life) {
    if (guess < selectedNumber && life > 1) {
        printf("📈 Daha büyük bir sayı dene!\n");
    }
    else if (guess > selectedNumber && life > 1) {
        printf("📉 Daha küçük bir sayı dene!\n");
    }
    drawLine();
}

void displayGameOver(int selectedNumber, double money) {
    printf("💀 Oyunu kaybettin! Doğru sayı şuydu: %d 😢\n", selectedNumber);
    printf("🎉 Toplam kazancın: %3.2f TL\n", money);
}

void displayStatus(int life, double money) {
    printf("    ");
    for (int i = 0; i < life; i++) {
        printf("❤️ ");
    }
    printf("\t💵: %3.2f TL\n", money);
}

int getGuess(int selectedNumber) {
    int guess;
    printf("▸ Tahmininizi girin: ");
    //printf("▸ (%d) Tahmininizi girin: ",selectedNumber);  // Bu kısım geliştiriciler için kullanılmalıdır.
    scanf("%d", &guess);
    while (getchar() != '\n');
    return guess;
}

int generateRandomNumber(int gameMode) {
    if (gameMode == 1) {
        return rand() % 10 + 1;
    }
    else if (gameMode == 2) {
        return rand() % 100 + 1;
    }
    else if (gameMode == 3) {
        return rand() % 1000 + 1;
    }
    else {
        printf("!!! HATA - PROGRAM KAPATILIYOR.\n");
        exit(1);
    }
}

int selectGameMode(void) {
    int input;
    printf("🎮 Oyun modu seç:\n");
    printf("   1️⃣ Kolay\t\t(1 - 10)\n");
    printf("   2️⃣ Orta\t\t(1 - 100)\n");
    printf("   3️⃣ Zor\t\t(1 - 1000)\n");
    printf("👉 Seçimin:\t\t");
    scanf("%d", &input);
    while (getchar() != '\n');
    
    drawLine();
    switch (input) {
        case 1: printf("\tOyun modu 'Kolay' seçildi.\n"); return 1;
        case 2: printf("\tOyun modu 'Orta' seçildi.\n"); return 2;
        case 3: printf("\tOyun modu 'Zor' seçildi.\n"); return 3;
        default:
            printf("!!! HATA - Yanlış seçim yaptınız.\nLütfen tekrar deneyiniz.\n");
            exit(1);
    }
}
