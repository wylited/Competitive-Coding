import time

print("Hi")
time.sleep(1)  # slow down the print
print("which car brand would you like")
time.sleep(1)  # slow down the print
cars = ["Ford", "Porsche", "BMW", "Audi", "Lamborghini"]  # array
i = cars[0]
for i in cars:
    print(i)
    time.sleep(0.7)  # slow down the print
typeofcar = input("Please enter exactly Ford, Porsche, BMW, Audi or Lamborghini")
if typeofcar in cars:
    print("Great choice")
else:
    print("Invalid choice")

print("Choose 1 number for your number plate")
number = 1
while number < 10:
    print(number)
    time.sleep(0.5)  # slow down the print
    number += 1
platenum = (int(input()))
if (1 < platenum) and (platenum <
 10):
    print("Good choice")
else:
    print("Pick again")