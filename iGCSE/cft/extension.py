golfers = {}

while True:
    goon = input("would you like to add a players score\n")
    if goon == "yes":
        (name, gender, age) = (input("name: "), input("gender: "), input("age: "))
        print("Golfer Registered: %s is %s and is %s years old" %(name, gender, age))
        (hole1, hole2, hole3, hole4) = (int(input("hole1 score: ")), int(input("hole2 score: ")), int(input("hole3 score: ")), int(input("hole4 score: ")))
        total = (hole1+hole2+hole3+hole4)
        print("your total is:", total)
        if total < 15:
            print("your score does qualify")
        elif total == 15:
            print("your score was one off from qualifying")
        else:
            print("your score does not qualify")
        golfers[name] = total
    else:
        print("thanks for the scores, we have saved %s golfers data" %len(golfers))
        # print the average value of the values in golfers
        print("the average score is:", sum(golfers.values())/len(golfers))scree
        # print the lowest score
        print("the lowest score is:", min(golfers.values()))
        # print the highest score
        print("the highest score is:", max(golfers.values()))
        break  