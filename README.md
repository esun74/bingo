# bingo

plays bingo for you

The class structure mimics a stack of bingo sheets, using the deck class and the cards class. 
Each individual bingo card contains an integer array and a boolean array. 
The deck contains the array of cards, and an integer keeping track of how many cards there are in the deck.
The integer array contains the numbers on the bingo sheet, while the boolean array keeps track of which number was already called. 


A deck creates multiple cards, and the deck has functions to:

- write into the cards, using the card number and location.
- check each individual card for a bingo pattern and prints it.
- "patterncheck" each card by comparing the card's bool array to another bool array i.e. a custom pattern. 
- mark each card, or in other words, attempt to find the called number in all cards, flipping the corresponding bool value if it is found.
- print all cards (not really used). 
- clears all cards by resetting all numbers to 0 and the corresponding bool array to false. 

Each individual card has functions to write, check, mark, and print; in other words, the deck's functions call each individual card's corresponding function. 
e.g. if a deck has 20 cards, the check() function calls the cardcheck() function for each of the 20 cards. 

There is also a function that takes a card number and returns a pointer to the card, which helps with calling individual cards. 


