# Function to generate a Fibonacci sequence up to n terms
def generate_fibonacci(n):
    fibonacci_sequence = []
    a, b = 0, 1  # Initialize the first two Fibonacci numbers

    for _ in range(n):
        fibonacci_sequence.append(a)
        a, b = b, a + b  # Calculate the next Fibonacci number

    return fibonacci_sequence

# Define the number of terms you want in the sequence
n = 10  # Change this to the number of terms you want

# Call the function and print the Fibonacci sequence
fib_sequence = generate_fibonacci(n)
print(fib_sequence)



