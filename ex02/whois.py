import sys

if(len(sys.argv) < 2):
    pass
elif (len(sys.argv) > 2):
    print('EROOR')
elif (sys.argv[1].isnumeric() == False):
    print('ERROR')
elif int(sys.argv[1]) == 0:
    print('I\'m Zero')
elif (int(sys.argv[1]) % 2) == 0:
    print('EVEN')
else:
    print('ODD')