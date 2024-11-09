#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 100
#define WORD_LIST "words.txt"

typedef struct {
    char* selectedWord;
    char* displayWord;
    int wordLength;
    int maxMisses;
    int misses;
} HangmanGame;

void selectWord(HangmanGame* game) {
    FILE* file = fopen(WORD_LIST, "r");
    if (file == NULL) {
        perror("Cannot open the file.");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    while (fgets(word, sizeof(word), file)) {
        if (strlen(word) - 1 == game->wordLength) {
            wordCount++;
        }
    }

    if (wordCount == 0) {
        printf("No words of length %d found.\n", game->wordLength);
        exit(1);
    }

    int randomIndex = rand() % wordCount;
    rewind(file);

    int currentIndex = 0;
    while (fgets(word, sizeof(word), file)) {
        if (strlen(word) - 1 == game->wordLength) {
            if (currentIndex == randomIndex) {
                strncpy(game->selectedWord, word, game->wordLength);
                game->selectedWord[game->wordLength] = '\0';
                break;
            }
            currentIndex++;
        }
    }

    fclose(file);
}

void setDifficulty(HangmanGame* game) {
    int difficulty;
    printf("Choose difficulty (1 = Easy, 2 = Medium, 3 = Hard): ");
    scanf("%d", &difficulty);

    switch (difficulty) {
        case 1:  // Easy
            game->wordLength = 5;
            game->maxMisses = 10;
            break;
        case 2:  // Medium
            game->wordLength = 7;
            game->maxMisses = 8;
            break;
        case 3:  // Hard
            game->wordLength = 9;
            game->maxMisses = 6;
            break;
        default:
            printf("Invalid choice. Setting to Easy by default.\n");
            game->wordLength = 5;
            game->maxMisses = 10;
            break;
    }
}

int main() {
    srand(time(NULL));

    HangmanGame game;
    setDifficulty(&game);

    game.selectedWord = (char*)malloc((game.wordLength + 1) * sizeof(char));
    game.displayWord = (char*)malloc((game.wordLength + 1) * sizeof(char));

    if (game.selectedWord == NULL || game.displayWord == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    game.misses = 0;
    char guess;

    selectWord(&game);

    for (int i = 0; i < game.wordLength; i++) {
        game.displayWord[i] = '-';
    }
    game.displayWord[game.wordLength] = '\0';

    while (game.misses < game.maxMisses) {
        printf("Word: %s\n", game.displayWord);
        printf("Guess a letter: ");
        scanf(" %c", &guess);

        int found = 0;
        for (int i = 0; i < game.wordLength; i++) {
            if (game.selectedWord[i] == guess) {
                game.displayWord[i] = guess;
                found = 1;
            }
        }

        if (!found) {
            game.misses++;
            printf("Incorrect! Misses: %d\n", game.misses);
        }

        if (strcmp(game.selectedWord, game.displayWord) == 0) {
            printf("Congratulations! You guessed the word: %s\n", game.selectedWord);
            break;
        }
    }

    if (game.misses >= game.maxMisses) {
        printf("Game Over! The word was: %s\n", game.selectedWord);
    }

    free(game.selectedWord);
    free(game.displayWord);

    return 0;
}
