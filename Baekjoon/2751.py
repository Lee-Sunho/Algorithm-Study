n = int(input())
data = []
for i in range(n):
    data.append(int(input()))
    
def quicksort(array):
    if len(array) == 0 or len(array) == 1:
        return array
    
    pivot = array[0]
    tail = array[1:]
    
    left = [x for x in tail if x <= pivot]
    right = [x for x in tail if x > pivot]
    
    return quicksort(left) + [pivot] + quicksort(right)

data = quicksort(data)

for i in range(len(data)):
    print(data[i])