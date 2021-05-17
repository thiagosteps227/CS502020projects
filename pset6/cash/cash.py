from cs50 import get_float
import numpy as np

#prompt the user for change in dollar
while True:
    dollar = get_float("change owed: ")
#break the loop if the given input is valid
    if dollar >= 0:
        break
#convert the given input(dollar) to cents
cents = dollar * 100
#rounding the cents to two decimal
cents = round(cents, 2)
#creating a variable for counting the coins
coins = 0
#creating an array for quarter, dime, nickel, penny
denominators = np.array([25, 10, 5, 1])
#substracting the cents by the array and count the coins
for i  in range(len(denominators)):
    while cents>=denominators[i]:
        cents -= denominators[i]
        coins +=1
print("", coins)