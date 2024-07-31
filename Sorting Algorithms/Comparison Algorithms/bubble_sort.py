def ascending(a, b):
    return a > b

def descending(a, b):
    return a < b

def bubble_sort(array, comparison):
    n = len(array) - 1
    swapped = True

    while swapped:
        swapped = False

        for i in range(0, n):
            if comparison(array[i], array[i + 1]):
                array[i], array[i + 1] = array[i + 1], array[i]
                swapped = True
        
        n = n - 1

    return array

if __name__ == "__main__":
    arr = [545, 752, 947, 546, 563, 806, 281, 292, 102, 796, 203, 730, 509, 599, 624, 273,
           816, 626, 105, 388, 553, 44, 100, 537, 198, 142, 365, 51, 808, 699, 138, 362, 965,
           470, 592, 194, 428, 357, 579, 572, 52, 747, 932, 641, 122, 266, 290, 183, 567, 791,
           865, 830, 272, 832, 770, 571, 586, 201, 282, 946, 892, 792, 768, 655, 299, 970, 135,
           964, 716, 192, 744, 17, 983, 852, 612, 944, 49, 576, 385, 10, 753, 308, 870, 775, 574,
           749, 831, 982, 973, 181, 648, 441, 980, 223, 881, 79, 977, 627, 154, 737]
    
    sorted = bubble_sort(arr, ascending)
    print(sorted)