import random

number = random.randint(1,10)

for i in range(3):
     numGuess = int(input("Enter a guess: "))

     if numGuess < number:
         print("Guess is too low")

     elif numGuess > number:
         print("Guess is too high")
     else:
         print("Correct!")
         break

if numGuess != number:
    print("Better luck next time...")