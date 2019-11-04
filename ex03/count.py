import sys
import re
import string

def text_analyzer(text = ""):
    "this fonction count the space, lower, upper, et punctuation d'un text"
    ponct = 0
    if (len(sys.argv) > 1):
        text = sys.argv[1]
    else:
        text = input("What is the text to analyze\n")
    for c in text:
        if c in string.punctuation:
            ponct += 1
    print(str(len(re.findall('\s+', text))) + " spaces")
    print(str(ponct) + " pontuation marks")
    print(str(len(re.findall('[a-z]', text))) + " lower case letters")
    print(str(len(re.findall('[A-Z]', text))) + " upper case letters")
