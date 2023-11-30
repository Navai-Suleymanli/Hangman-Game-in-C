#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 100
#define WORD_LIST "words.txt"

// Function to select a random word of the specified length from the file
void selectWord(char *selectedWord, int wordLength) {
    FILE *file = fopen(WORD_LIST, "r");
    if (file == NULL) {
        perror("cann'ot to open the file.");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    while (fgets(word, sizeof(word), file)) {
        if (strlen(word) - 1 == wordLength) { // -1 to account for newline character
            wordCount++;
        }
    }

    // Error handling if no words of the specified length are found
    if (wordCount == 0) {
        printf("No words of length %d found.\n", wordLength);
        exit(1);
    }

    int randomIndex = rand() % wordCount;
    rewind(file); // Reset file pointer to the beginning of the file

    int currentIndex = 0;
    while (fgets(word, sizeof(word), file)) {
        if (strlen(word) - 1 == wordLength) {
            if (currentIndex == randomIndex) {
                strncpy(selectedWord, word, wordLength);
                selectedWord[wordLength] = '\0'; // Ensure string is null-terminated
                break;
            }
            currentIndex++;
        }
    }

    fclose(file);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int wordLength, maxMisses;
    printf("Enter word length: ");
    scanf("%d", &wordLength);
    printf("enter maximum number of misses allowed please: ");
    scanf("%d", &maxMisses);

    char selectedWord[wordLength + 1];
    char displayWord[wordLength + 1];
    int misses = 0;
    char guess;

    // Select a random word of the specified length
    selectWord(selectedWord, wordLength);

    // Initialize the display word with dashes
    for (int i = 0; i < wordLength; i++) {
        displayWord[i] = '-';
    }
    displayWord[wordLength] = '\0'; // Null-terminate the string

    // main game loop
    while (misses < maxMisses) {
        printf("Word: %s\n", displayWord);
        printf("Guess a letter: ");
        scanf(" %c", &guess);

        // Check if the guess lwtter is in the word
        int found = 0;
        for (int i = 0; i < wordLength; i++) {
            if (selectedWord[i] == guess) {
                displayWord[i] = guess;
                found = 1;
            }
        }

        if (!found) {
            misses++;
            printf("Incorrect! Misses: %d\n", misses);
        }

        // Check if word is fully guessed
        if (strcmp(selectedWord, displayWord) == 0) {
            printf("Congratulations! You guessed the word: %s\n", selectedWord);
            break;
        }
    }

    // Check if the player has exceeded the maximm number of misses
    if (misses >= maxMisses) {
        printf("Game Over! The word was: %s\n", selectedWord);
    }

    return 0;
}
