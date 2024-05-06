def bubble_sort(l):
    for i in range(0, len(l)):
        for j in range(0, len(l)):
            if l[i] < l[j]:
                l[i], l[j] = l[j], l[i]

    return l


print(bubble_sort([3, 4, 2, 3, 5, 1, 1, 2, 4]))
