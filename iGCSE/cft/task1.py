while True:
    goon = input("would you like to add another players values\n")
    if goon == "yes":
        (name, gender, age) = (input("name\n"), input("gender\n"), input("age\n"))
        print("Golfer Registered: %s is %s and is %s years old" %(name, gender, age))
        (hole1, hole2, hole3, hole4) = (int(input("hole1 score")), int(input("hole2 score")), int(input("hole3 score")), int(input("hole4 score")))
        total = (hole1+hole2+hole3+hole4)
        print("your total is:", total)
        if total < 15:
            print("your score does qualify")
        elif total == 15:
            print("your score was one off from qualifying")
        else:
            print("your score does not qualify")
    else:
        print("thanks for the scores")
        break
