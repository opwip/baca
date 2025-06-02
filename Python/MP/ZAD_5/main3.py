#Yaroslav Kolesnik
def solve_agent(n, k, edges):
    INF = float('inf')
    # Only keep two arrays: previous layer and current layer
    # prev[i] = min cost to reach node i in previous iteration
    # curr[i] = min cost to reach node i in current iteration
    prev = [INF] * n
    prev[0] = 0  
    

    for step in range(k + 1):
        curr = prev[:]  
        

        for a, b, c in edges:
            if prev[a] != INF:  
                if curr[b] > prev[a] + c:
                    curr[b] = prev[a] + c
        
        prev = curr
    
    return prev[n-1] if prev[n-1] != INF else -1

def main():
    L = int(raw_input())
    
    for _ in range(L):
        line = raw_input().strip().split()
        n = int(line[0])
        k = int(line[1])
        m = int(line[2])
        
        edges = []
        for i in range(m):
            a = int(line[3 + i * 3])
            b = int(line[3 + i * 3 + 1])
            c = int(line[3 + i * 3 + 2])
            edges.append((a, b, c))
        
        result = solve_agent(n, k, edges)
        print result

main()