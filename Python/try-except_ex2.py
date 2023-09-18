# Function to divide two numbers and handle exceptions
def divide_numbers(a, b):
    try:
        result = a / b
        print("Result:", result)
    except ZeroDivisionError:
        print("Error: Division by zero")
    except Exception as e:
        print("An error occurred:", e)

# Test the function with different inputs
while True:
    try:
        num1 = float(input("Enter a number: "))
        num2 = float(input("Enter another number: "))
        divide_numbers(num1, num2)
    except ValueError:
        print("Error: Invalid input. Please enter a valid number.")
    except KeyboardInterrupt:
        print("\nProgram terminated by user.")
        break