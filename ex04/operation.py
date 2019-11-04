import sys

def do_math(num1, num2):
    "do all the math"
    if (not num1.isnumeric() or not num2.isnumeric()):
        print("Input error : Numbers please")
        print("Usage = python operation.py number1 number2")
        return 
    print("sum : " + str(int(num1) + int(num2)))
    print("Difference : " + str(int(num1) - int(num2)))
    print("Product : " + str(int(num1) * int(num2)))
    if (not int(num2) == 0):
        print("Quotient : " + str(int(num1) / int(num2)))
        print("remainder : " + str(int(num1) % int(num2)))
    else:
        print("can't divide by zero") 

usage = "python operation.py number1 number2"

if (len(sys.argv) < 3):
    print("not enough argument")
    print("usage = " + usage)
elif (len(sys.argv) > 3):
    print("too many argument")
else:
    do_math(sys.argv[1], sys.argv[2])