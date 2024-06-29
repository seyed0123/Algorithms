def insert_sort(l):
    for i in range(1, len(l)):
        key = l[i]
        j = i - 1
        while l[j] > key and j >= 0:
            l[j], l[j + 1] = l[j + 1], l[j]
            j -= 1
        l[j + 1] = key

    return l


print(insert_sort([4, 5, 2, 8, 4, 9, 3, 1]))
