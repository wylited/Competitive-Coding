import getpass
import hashlib

# Keywords
monday = ["Wake","Shake","Bake"]
tuesday = ["Red","Green","Blue"]
wednesday = ["Terminator","Matrix","The Imitation Game"]
thursday = ["0","8","3"]
friday = ["Eat","Drink","Sleep"]

# Hashmap of the user hours
userhours = {}

# The password hashed using sha256, 
# hashlib.sha256("000852".encode()).hexdigest()
hashedpassword = "75af2274e98408b6e4c9b4984c44bb63356a3d4bb027b60edf30568702d167cc"

def strinput(strlen = None, prompt = "", vals = []): # a function that takes in a valid string input only if it follows the bounds provided and is a string
    while True:
        try:
            x = input(prompt)
            if strlen == None: # no bounds present
                return x
            elif not(strlen == len(x)): # bounds present, check if x is within the bounds
                raise ValueError("Invalid length")
            if vals != []:
                if x not in vals:
                    raise ValueError("Invalid value")
            return str(x) # Return the casted string x
        except ValueError:
            print("Invalid input", ValueError) # if there is a value error, output it and try again.

def intinput(prompt: str = "", minint: int = None, maxint: int = None) -> int: # inclusive lower limit and exclusive upper limit (pythonic way for the stl) bound checking for an integer.
    while True:
        try:
            x = input(prompt)
            if x.isdigit():
                if minint == None and maxint == None: # no bounds, return the int value
                    return int(x)
                elif minint != None: # minimum bounds are present, check if x is within the bounds
                    if int(x) < minint:
                        raise ValueError("Invalid value")

                elif maxint != None: # maximum bounds are present, check if x is within the bounds
                    if int(x) >= maxint:
                        raise ValueError("Invalid value")
                return int(x) # return the casted integer x
            else:
                raise ValueError("Not a digit")

        except ValueError:
            print("Invalid input", ValueError) # if there is a value error, output it and try again.

def displaykeywords(): # Function which displays the days of the week and the keywords for each day depending on input.
    day = strinput(None, "Which day would you like to view? (m/t/w/th/f)", ["m","t","w","th","f"]) # minimal input reduces chance of making a mistake while typing
    # Checks for each letter
    if day == "m":
        print("\nMonday:")
        for i in range(len(monday)):
            print(str(i+1) + ": " + monday[i])
    elif day == "t":
        print("\nTuesday:")
        for i in range(len(tuesday)):
            print(str(i+1) + ": " + tuesday[i])
    elif day == "w":
        print("\nWednesday:")
        for i in range(len(wednesday)):
            print(str(i+1) + ": " + wednesday[i])
    elif day == "th":
        print("\nThursday:")
        for i in range(len(thursday)):
            print(str(i+1) + ": " + thursday[i])
    elif day == "f":
        print("\nFriday:")
        for i in range(len(friday)):
            print(str(i+1) + ": " + friday[i])

def changehours(user: str): # takes in a user hour change and returns the hours the inputted as well as storing it.
    hours = intinput(prompt = "How many hours did you work? ")
    userhours[user] = hours
    return hours

def login():
    username = strinput(prompt = "Username: ")
    password = getpass.getpass(prompt = "Password: ") # Hides the userinput so passwords arent stolen.
    if hashlib.sha256(password.encode()).hexdigest() == hashedpassword:
        menu(username)
    else:
        print(hashlib.sha256(password.encode()).hexdigest())
        print("invalid password, try again")
        login()

def menu(user: str):
    print("\n    The Kilo Golf Victor Squad Program - We. Think. We. Do.        ")
    print("\n    Hi", user, "What would you like to do:")
    print("\n    1. Display keywords")
    print("\n    2. Enter the hours you worked and show pay")
    print("\n    3. Logout")
    option = intinput("\n    Enter your option: ", minint = 1, maxint = 4) # check for the numbers between 1-3
    print(option)
    if int(option) == 1:
        print("\n    The Kilo Golf Victor Squad Program - We. Think. We. Do.")
        displaykeywords()
        menu(user) # recursively call on the function to keep it going.
    elif int(option) == 2:
        pay = changehours(user)
        print("\n    You worked", pay, "hours at $5 per hour.")
        print("\n    You got payed", pay * 5, "dollars.")
        menu(user)
    if int(option) == 3:
        print("\n    Thank you for using the Kilo Golf Victor Squad Program.\n")
        main()

def main():
    print("\n    The Kilo Golf Victor Squad Program - We. Think. We. Do.        ")
    islogin = strinput(1, "Would you like to login (y/n)? ", ["y","n"])
    if islogin == "y":
        login()
    else:
        print("\n    Thank you for using the Kilo Golf Victor Squad Program.\n")
        return


if __name__ == "__main__":
    main()