This program first read the maze, then we have two mice to run the maze.
One is at (0,0) called RatA ,and the other one at (99,99) called RatB.

RatA have priorities right > down > left > up ,and RatB have priorities left > up > right > down.
They move to next place, if this road can go,  then we store the movement into a stack.

If they run to a blind alley, we pop the stack to go back to the last sideroad.
Their end are different, if they arrive at the end, the program will stop.

In addition,if this two mice met each other, the program also will stop. 
Their movements will output to the .txt file called result.txt.
