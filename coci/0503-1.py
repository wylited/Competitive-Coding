def splitter(k):
    valry = []
    temp = ""
    previous = False
    for i in range(len(k)):
        # Split the value if it is a character (nondigit)
        if k[i].isdigit():
            temp += k[i]
            previous = False
        elif previous == True:
            valry.append(temp)
            temp = ""
            temp = k[i]
            previous = True
        else:
            temp = k[i]
            previous = True
        if i == len(k) - 1:
            valry.append(temp)
    return valry


def main():
    n = int(input()) # n is a value between ""1"" - "1""0" which defines how many chemical equations are inserted
    # Each chemical equation is seperated by a -> which shows the left and right side.
    # Each side is split up with molecules, the molecule can have a first value
    equations = []
    for i in range(n):
        equations.append(input())

    sides = {}
    molecules = {} # hashmap or an index array
    amount = {
        "0": {},
        "1": {}
    } # the amount of molecules on each side.
    amount0 = {}
    amount1 = {}
    output = []
    for i in range(n):
        sides[0] = equations[i-1].split("->")[0]
        sides[1] = equations[i-1].split("->")[1]
        # Split the sides into molecules
        molecules["0"] = sides[0].split("+")
        molecules["1"] = sides[1].split("+")
        # Split the molecules into values
        for j in molecules["0"]:
            print("currently testing " + j)
            if j[0].isdigit():
                print("there is a multiplicatory value")
                multi = j[0] # the amount of times the molecule is multiplied which is the first value
                # for each value in returned valry of splitter, add it to the amount hashmap with the key being which side its on multiplied by the amount of times it is multiplied
                for k in splitter(j[1:]):
                    if len(k) > 1:
                        amount0[multi * k[1]] = k[0]
                        print("value is", amount0[multi * k[1]])
                    else:
                        print("value is", amount0[multi])
                        amount0[multi] = k[0]
            else:
                print("there is no multiplicatory value")
                multi = 1
                # for each value in returned valry of splitter, add it to the amount hashmap with the key being which side its on multiplied by the amount of times it is multiplied
                for k in splitter(j):
                    if len(k) > 1:
                        amount0[multi * k[1]] = k[0]
                        print("value is", amount0[multi * k[1]])
                    else:
                        print("value is", amount0[multi])
                        amount0[multi] = k[0]
        for j in molecules["1"]:
            print("currently testing " + j)
            if j[0].isdigit():
                multi = j["0"]
                # for each value in returned valry of splitter, add it to the amount hashmap with the key being which side its on multiplied by the amount of times it is multiplied
                print(splitter(j[1:]))
                for k in splitter(j[1:]):
                    if len(k) > 1:
                        amount1[multi * k[1]] = k[0]
                    else:
                        amount1[multi] = k[0]
            else:
                multi = 1
                # for each value in returned valry of splitter, add it to the amount hashmap with the key being which side its on multiplied by the amount of times it is multiplied
                print("split values", splitter(j), "for molecule", j)
                for k in splitter(j):
                    if len(k) > 1:
                        amount1[multi * k[1]] = k[0]
                    else :
                        amount1[multi] = k[0]
        # If the values of each amount on both sides the equation is true and add DA to the output array
        # Otherwise output NE
        print(amount)
        if amount0 == amount1:
            output.append("DA")
        else :
            output.append("NE")
    # Output all the values in output on seperate lines.
    for i in output:
        print(i)

main()