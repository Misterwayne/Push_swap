import os

cookbook = {
    'sandwich': {
    'ingredients': ['ham', 'bread', 'cheese', 'tomatoes'],
    'meal': 'lunch',
    'prep_time': 10,
    },
    'Cake': {
    'ingredients': ['flour', 'sugar', 'eggs'],
    'meal': 'dessert',
    'prep_time': 60,
    },
    'Salad': {
    'ingredients': ['avocado', 'arugula', 'tomatoes', 'spinach'],
    'meal': 'lunch',
    'prep_time': 15,
    }
}

def print_cookbook(cookbook):
    os.system("clear")
    for recipe in cookbook:
        print ("\nRecipe for " + recipe)
        print()
        for y in cookbook[recipe]:
            print(y,':',cookbook[recipe][y])
    if (int(input()) == 0):
        print_menu()

def print_a_recipe(cookbook):
    os.system("clear")
    recipe = input("whish recipe to print?\n")
    if (recipe not in cookbook):
        print('Error no such key')
        return
    print("Recipe for " + recipe)
    for key in cookbook[recipe]:
        print(key + ' ' + str(cookbook[recipe][key]))
    if (int(input()) == 0):
        print_menu()

def del_recipe(cookbook):
    os.system("clear")
    for recipe in cookbook:
        print (recipe)
    choice = input("Whish recipe to delete ?\n")
    if (recipe not in cookbook):
        print('Error no such key')
        return
    del cookbook[choice]
    if (int(input()) == 0):
        print_menu()

def add_recipe(cookbook):
    choice = input("\nName of the recipe?\n")
    cookbook[choice] = {
        'ingredients' : [input('ingredients ?\n'), input(), input()],
        'meal' : input("meal?\n"),
        'prep_time' : input("prep_time ?") 
    }
    if (int(input()) == 0):
        print_menu()


def print_menu():
    os.system("clear")
    print("___________________________")
    print("|       The Cookbook      |")
    print("|_________________________|")
    print("1 ) Add a recipe\n")
    print("2 ) Delete a recipe\n")
    print("3 ) Print a recipe\n")
    print("4 ) Print Cookbook\n")
    print("5 ) Quit")
    take_input()

def take_input():
    choice = input()
    if int(choice) == 1:
        add_recipe(cookbook)
    if int(choice) == 2:
        del_recipe(cookbook)
    if int(choice) == 3:
        print_a_recipe(cookbook)
    if int(choice) == 4:
        print_cookbook(cookbook)
    if int(choice) == 5:
        return

print_menu()