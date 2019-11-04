import sys
import string

newstring = ""
table = str.maketrans(dict.fromkeys(string.punctuation))
i = 0
if (not len(sys.argv) == 3):
    print("ERROR")
elif (sys.argv[1].isnumeric()):
    print("ERROR")
elif (not sys.argv[2].isnumeric()):
    print("ERROR")
else:
    for word in sys.argv[1].split(" "):
        if (len(word) > int(sys.argv[2])):
            if (i == 0):
                newstring += word
            else:
                newstring += ' ' + word
            i += 1

print(newstring.translate(table))