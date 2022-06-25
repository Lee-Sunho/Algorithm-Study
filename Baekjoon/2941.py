import sys
alpha = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
input = list(sys.stdin.readline().rstrip())

input.reverse()
sum = 0
while len(input) > 1:
    str = input.pop()
    if str == 'c' or str == 'd' or str == 'l' or str == 'n' or str == 's' or str == 'z':
        str = str + input[-1]
        if str in alpha:
            input.pop()
            sum = sum + 1

        elif str == 'dz' and len(input) > 1:
            str = str + input[-2]
            if str in alpha:
                input.pop()
                input.pop()
                sum = sum + 1
            else:
                sum = sum + 1
        else:
            sum = sum + 1

    else:
        sum = sum + 1

sum = sum + len(input)
print(sum)
