"Game of Life"
------------------------------------------------------------------------------------------
Introduction

It is a problem developed by a mathematician named John Conway. It represents bacterial multiplication in a petri dish.
The following are the rules:
1. Death Rule: The occupied cell dies if it has 0,1,4,5,6,7 or 8 neigbors. It dies of loneliness if there are 0 or 1 neighbor. It dies of overcrowding if the neighbors are 4-8 in number.
2. Survival Rule: The occupied cell continues to next generation if it has 2 or 3 neighbors.
3. Birth Rule: Any unoccupied cell comes to life if it has exactly 3 neighbors.
------------------------------------------------------------------------------------------
Terminating Conditions

The "Game of Life" has the following terminating conditions:
1. All provided generations are played
2. Every cell dies, nothing is occupied
3. The same pattern is repeated in 1 or 2 generations.
------------------------------------------------------------------------------------------
Playing the Game

The program "Game of Life" takes the following inputs:
NR NC gens inputfile [print] [pause]
Where:
NR: Number of rows of board
NC: Number of columns of board
gens: The maximum number of generations to be played
inputfile: The text file containing the generation to start
print: 'y' for printing the board after every generation, 'n' otherwise(default)
pause: 'y' for pausing after every generation, 'n' otherwise(default)
[...] is an optional argument
------------------------------------------------------------------------------------------
Functions used

The program contains several functions:
1. production: Helps to take input from the command line and set up the arguments. 
               Returns error if any necessary argument if missing and calls on the 
  	       generate function to carry on generations of the board upto a certaing number.
2. playOne(taken from MoreStrippedLife starter): Plays the board for one generation according to the rules of the game.
3. usage(taken from MoreStrippedLife starter): prints a message if the number of arguments are not provided correctly.
4. getLetter(taken from MoreStrippedLife starter): returns the letter at the specified position on the provided board.
5. HowManyNeighbors(taken from MoreStrippedLife starter): returns the number of neighbors to a specified position.
6. readFileIntoArray(taken from MoreStrippedLife starter): reads the given input file and sets up an array to represent the board.
7. generate(taken from MoreStrippedLife starter and developed partially): plays the game until given generation or any terminating conditions are met.
8. anyX: checks if the array contains any occupied cell or not
9. sameContent: returns if the two given arrays are equal
10. printThis: prints the elements of a given array.
-------------------------------------------------------------------------------------------