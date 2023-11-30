# Hangman-Game-in-C
Overview
This is a simple hangman game written in C as a homework project for my school. In this game the user 
tries to guess words that are in a file. The user sets the number of max misses and can challenge himself 
by setting it low. Read the documentation fully to understand how to run it. 
File Structure
• Hangman/
• Hangman.project: Project file containing settings for the development environment.
• main.c: Source file containing the game's code.
Prerequisites
• A C compiler (such as gcc) to compile the source code.
• A text editor to view or modify the source code.
• A command-line interface to run the compiled program.
Setup
• Place a text file named words.txt in the same directory as your compiled program. 
This file should contain a list of words, one per line, that the game will use.
• Compile the main.c source file using a C compiler:
• gcc -o Hangman main.c
• Run the compiled program:
• bash
• ./Hangman
How to Play
• When prompted, enter the desired word length. The game will then select a word of 
that length from words.txt.
• Enter the maximum number of incorrect guesses allowed.
• The game will display a series of dashes representing the letters of the word. For 
example, for a 5-letter word: -----.
• Guess one letter at a time. If the letter is in the word, the game will reveal its 
positions in the word: -a---.
• If the letter is not in the word, the number of misses will increase.
• Continue guessing letters until you either guess the word correctly or exceed the 
allowed number of misses.
Game End
• If you guess the word correctly before reaching the maximum number of misses, 
you win, and the game will congratulate you.
• If you reach the maximum number of misses without guessing the word, the game 
ends, and it will reveal the word.
Troubleshooting
• If the game cannot open words.txt, ensure the file is in the correct location and is 
named correctly.
• If there are no words of the specified length in words.txt, the game will terminate. 
Ensure there are suitable words of various lengths in the file.
Support and assistance
If you have any kind of questions or issues at my code, please contact me via 
my LinkedIn:
https://www.linkedin.com/in/navai-suleymanli
