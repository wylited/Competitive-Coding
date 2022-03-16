goon = True
while goon:
  cars = ["Ford", "Porsche", "BMW", "Audi", "Lamborghini"]  # array
  i = cars[0]
  for i in cars:
    print(i)
  typeofcar = input("Please enter exactly Ford, Porsche, BMW, Audi or Lamborghini")
  while True:
    if typeofcar in cars:
      print("Great choice")
      break
    else:
        print("Invalid choice, try again")
        typeofcar = input("Please enter exactly Ford, Porsche, BMW, Audi or Lamborghini")
  goon = input("Do you want to continue? (y/n)") == "y"

