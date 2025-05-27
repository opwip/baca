#Yaroslav Kolesnik
def slicer(arr, l, r):
    
    x = arr[r]
    i = l
    for j in range(l, r):
        
        if arr[j] <= x:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            
    arr[i], arr[r] = arr[r], arr[i]
    return i

def find_kth_smallest(arr, left, right, k):
    if (k > 0 and k <= right - left + 1):

        index = slicer(arr, left, right)

        if (index - left == k - 1):
            return arr[index]
        
        if (index - left > k - 1):
            return find_kth_smallest(arr, left, index - 1, k)

        return find_kth_smallest(arr, index + 1, right, 
                            k - index + left - 1)
    return "brak"

Z = int(raw_input())



for k in range(Z):
    arr_N = []
    N_len = int(raw_input())
    nums = raw_input().split()
    for i in nums:
        arr_N.append(int(i))
    M_len = int(raw_input())
    instr = raw_input().split()
    for i in range(M_len):
        print('{} {}'.format(int(instr[i]), find_kth_smallest(arr_N[:], 0, len(nums)-1, int(instr[i]))))
