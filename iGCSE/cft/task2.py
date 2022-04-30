start_num = int(input("Please enter the start number: "))
last_num = int(input("Please enter the last number: "))
step = int(input("enter step value: "))

# print all the values between the start number and the last number with the step.
for i in range(start_num, last_num, step):
    print(i)
    