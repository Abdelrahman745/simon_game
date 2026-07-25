### simon_game
## problems 
first I was trying to make the full code without functions but this was hard to do and hard to understand , so i made each step in a function to make easier to debug as everything in a separate function so i can know the problem easly 
after finishing I found that the sequence is always the same everytime I restart so I searched for the solution or how I make the random values change every time , i found that there is random seed function works with floating pin as the voltage of the floating pin always change so the random values will always change 
i also noticed that every time I start with one led on , i want to make it random also , so every  time different number of led start high , but I can't do this.
## extensions 
i added feature while every time the user press any button it's matching led lights 
## code
first I assign all inputs and outputs and some variables , sequence[100] have 100 empty spaces so i can have 100 sequence in the game 
then there is some functions in the setup before the loop serial begin to allow serial communication , then setup pins to setup outputs and inputs with pullup resistors
ask difficulty function asks for difficulty in serial monitor and waits for answer and it changes the speed due to difficulity
then the intial step is made randomly 
get led for step make mapping 0=left ,1=right,...
i used millis function to make the 5000 ms extension
i made boolean funtion that return true or false it tells me whether the user made the sequence true or false
round win function increase the score 
and game over print the final score
AI helped me in some functions but not all the code 
