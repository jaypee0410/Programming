
w = float(input("Input Weight: "))
h = float(input("Input Height: "))

BMI = float(w/(h*h))

if BMI >= 30:
    print("Obesity")
elif BMI >= 25 and BMI <= 30:
    print("Overweight")
elif BMI >= 18.5 and BMI <= 25:
    print("Normal")
elif BMI < 18.5:
    print("Underweight")
else:
    print("Enter valid number")