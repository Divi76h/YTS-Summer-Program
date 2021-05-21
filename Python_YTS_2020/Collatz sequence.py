n = input("Please enter a number: ")
n = int(n)
i = 0
i = int(i)
while n != 1:
    i += 1
    if n % 2 == 0:
        n = n/2
        print(n)
    elif n % 2 != 0:
        n = 3*n + 1
        print(n)


print("The number of terms are: ", i)
