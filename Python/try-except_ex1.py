
while True:
    try:
        num1 = int(input("Enter a number: "))
        print("Number entered was:",num1)
    except ValueError:
        print("Error: Invalid input. Please enter a valid number.")
    except KeyboardInterrupt:
        print("\nProgram terminated by user.")
        break
    break