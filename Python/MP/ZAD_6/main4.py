# Yaroslav Kolesnik
# Even wrote test generation to ensure that time complexity is indeed like that
def solve_NO_ADJ():
    # Note: This approach does not maintain O(n + m) time complexity because there is NO ADJ_LIST THE TIME COMPLEXITY IS O(n*m) INSTEAD(BAD) 
    G = int(raw_input())
    for _ in range(G):
        parts = raw_input().split()
        n = int(parts[0])
        m = int(parts[1])
        edges = parts[2:]
      
        visited = [False] * n
        last_finished = 0
        
        # First DFS pass to find the last finished node
        for i in range(n):
            if not visited[i]:
                stack = [(i, False)]
                while stack:
                    node, processed = stack.pop()
                    if processed:
                        last_finished = node
                        continue
                    if visited[node]:
                        continue
                    visited[node] = True
                    stack.append((node, True))
                    # Find all neighbors by scanning edges
                    for j in range(0, 2 * m, 2):
                        a = int(edges[j])
                        b = int(edges[j + 1])
                        if a == node and not visited[b]:
                            stack.append((b, False))
        
        # Second DFS pass to check if last_finished can reach all nodes
        visited = [False] * n
        stack = [last_finished]
        visited[last_finished] = True
        count = 0
        while stack:
            node = stack.pop()
            count += 1
            # Find all neighbors by scanning edges
            for j in range(0, 2 * m, 2):
                a = int(edges[j])
                b = int(edges[j + 1])
                if a == node and not visited[b]:
                    visited[b] = True
                    stack.append(b)
        
        if count == n:
            print last_finished
        else:
            print -1
            

def solve():
    G = int(raw_input())  
    for _ in range(G):  
        parts = raw_input().split()  
        n = int(parts[0]) 
        m = int(parts[1]) 
        edges = parts[2:]  
        adj = [[] for _ in range(n)]  # TIME O(n) SPACE O(n+m) for adjacency list - THIS IN INPUT SO I DO NOT KNOW IF IT CONSIDERED AS A PART OF THE ALGORITHM
        index = 0  
        for _ in range(m): 
            a = int(edges[index]) 
            b = int(edges[index + 1])  
            adj[a].append(b)  
            index += 2  
        # THE ALGORITHM IS O(n+m) TIME AND O(n) SPACE
        visited = [False] * n  # TIME O(n) SPACE O(n)
        last_finished = 0  
        
        # First DFS pass to find the last "finished" node
        for i in range(n):  
            if not visited[i]: 
                stack = [(i, False)] 
                while stack:  # TIME O(n + m) (each node and edge visited once)
                    node, processed = stack.pop()  
                    if processed:  
                        last_finished = node  
                        continue  
                    if visited[node]:  
                        continue  
                    visited[node] = True  
                    stack.append((node, True))  
                    for neighbor in reversed(adj[node]):  
                        if not visited[neighbor]:  
                            stack.append((neighbor, False))  
        
        # Second DFS pass to check if "last_finished" can reach all nodes
        visited = [False] * n  
        stack = [last_finished] 
        visited[last_finished] = True  
        count = 0 
        while stack:  # TIME O(n + m) in the worst case (visiting all nodes and edges)
            node = stack.pop()  
            count += 1  
            for neighbor in adj[node]:  
                if not visited[neighbor]: 
                    visited[neighbor] = True  
                    stack.append(neighbor) 
        
        if count == n:
            print last_finished  
        else: 
            print -1  

solve()  

# Yaroslav Kolesnik

# THE ALGORITHM IS O(n+m) TIME AND O(n) SPACE Line 71