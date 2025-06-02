#Yaroslav Kolesnik
def solve_agent(n, k, edges):
    pq = [(0, 0, 0)] 
    
    dist = {}
    
    while pq:
        min_idx = 0
        for i in range(1, len(pq)):
            if pq[i][0] < pq[min_idx][0]:
                min_idx = i
        
        cost, node, stops = pq.pop(min_idx)
        
        state = (node, stops)
        if state in dist and dist[state] <= cost:
            continue
        
        dist[state] = cost
        

        if node == n - 1:
            continue

  
        if stops >= k + 1:
            continue
        
 
        for a, b, c in edges:
            if a == node:  
                new_cost = cost + c
                new_stops = stops + 1
                new_state = (b, new_stops)
                

                if new_state not in dist or dist[new_state] > new_cost:
                    pq.append((new_cost, b, new_stops))

    min_cost = float('inf')
    for stops_used in range(k + 2):     
        state = (n - 1, stops_used)
        if state in dist and dist[state] < min_cost:
            min_cost = dist[state]
    
    return min_cost if min_cost != float('inf') else -1

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