## Setup

1. Clone the repository:
   ```bash
   git clone https://github.com/Navai-Suleymanli/Hangman-Game-in-C.git
   ```

2. Create a `words.txt` file with a list of words. For example:
   ```
   apple
   banana
   orange
   grape
   pineapple
   ```
   Ensure that the words have various lengths to accommodate different word length inputs during the game.

3. Compile the code:
   ```bash
   gcc -o hangman main.c
   ```

4. Run the game:
   ```bash
   ./hangman
   ```

## How It Works

- The game uses a structure `HangmanGame` to store the state of the game, including the selected word, the displayed word (with guessed letters and dashes), the word length, the number of misses, and the maximum number of misses allowed.
- Words are read from the `words.txt` file, and the program selects a word randomly based on the length provided by the player.
- The player guesses one letter at a time, and the game checks if the letter is in the word. If the guess is incorrect, the number of misses increases.
- If the word is guessed correctly, the player wins; otherwise, the game ends when the player reaches the maximum number of allowed misses.

## Example Gameplay

```
Enter word length: 5
Enter maximum number of misses allowed please: 6
Word: -----
Guess a letter: a
Incorrect! Misses: 1
Word: -----
Guess a letter: e
Word: -e---
Guess a letter: r
Word: re---
Guess a letter: s
Incorrect! Misses: 2
Word: re---
Guess a letter: d
Word: red--
Guess a letter: o
Congratulations! You guessed the word: redox
```

## Contribution

Feel free to fork the repository and make improvements! You can create pull requests with enhancements or bug fixes. If you have suggestions for new features or better implementation, feel free to open an issue.

## License

This project is licensed under the MIT License.

