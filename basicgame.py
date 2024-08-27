import random
computer = random.choice([-1,1,0])
youstr = input("enter your choice :")
youDict = {'s':1 , 'w':-1, 'g' :0}
reverseDict = { 1: "snake", -1 : "water" , 0 : "gun"}
you = youDict[youstr]


print (f"you choose {reverseDict[you]}\n Computer choose{reverseDict[computer]}")
if(computer == you):
    print("it's a draw ! please try again")
else:
    if(computer == -1 and you == 1):
        print("hurray! you win")

    elif(computer == -1 and you == 0):
         print("alas! you lost")
    
    elif(computer == 1 and you == -1):
        print("Alas! you lost")

    elif(computer == 1 and you == 0):
        print("hurray! you win")

    elif(computer == 0 and you == 1):
        print("Alas! you lost")

    elif(computer == 0 and you == -1):
        print("hurray! you win")

    else:
        print("something went wrong!")

