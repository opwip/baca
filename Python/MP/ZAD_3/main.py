def knapsack_with_max_items(capacity, values, weights, n):
    dp = [(0, 0)] * (capacity + 1) # +1 because dp[w] is the best solution for Weight w==index dp[0] always (0,0)
    # (value, count of jewels (x out of n))
    for i in range(n):
        for w in range(capacity, weights[i] - 1, -1): # capacity -> weights[i] - 1, -1 to include weights[i]
            curr_val, curr_count = dp[w - weights[i]]
            new_val = curr_val + values[i]
            new_count = curr_count + 1
            
            old_val, old_count = dp[w]
            
            if new_val > old_val or (new_val == old_val and new_count > old_count):
                dp[w] = (new_val, new_count)
    
    return dp[capacity][0]

L = int(raw_input())

for _ in range(L):
    line = raw_input().strip().split()
    M = int(line[0]) 
    pairs = line[1:]
    
    values = []
    weights = []
    for i in range(0, len(pairs), 2):
        values.append(int(pairs[i]))
        weights.append(int(pairs[i + 1]))
    
    n = len(values)
    result = knapsack_with_max_items(M, values, weights, n)
    print(result)