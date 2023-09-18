while True:
    try:
        x = int(input("Please enter a number: "))
        print(f"You entered {x}")
        break
    except:
        print("Oops!  That was no valid number.  Try again...")