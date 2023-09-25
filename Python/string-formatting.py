# Python3 program introducing f-string
val1 = 'Hello'
val2 = "Hi"
val3 = 'Good day'

print(f"{val1} and {val2} is a word for {val3}.")
 
name = 'jp'
age = 27
print(f"{val1}, My name is {name} and I'm {age} years old.")

# Prints today's date with help
# of datetime library
import datetime
 
today = datetime.datetime.today()
print(f"Today is {today:%B %d, %Y}")