# Yaroslav Kolesnik
def kosaraju_scc(n, edges):
    """
    Kosaraju's Algorithm: Finds groups of vertices that can all reach each other
    
    SCC - Strongly Connected Component(group of verticies)
    basically a group of verticies that can find paths to each other in the group(The point of Kosaraju's alg)
    
    Time Complexity: O(n + m)
    Space Complexity: O(n)
    """
    
    # First DFS
    visited = [False] * n  # Space O(n)
    finish_order = []      # Space O(n) 
    
    # Create adjacency list for faster edge access
    adj = [[] for _ in range(n)]
    for a, b in edges:
        adj[a].append(b)
    
    def dfs1(v):
        stack = [v]
        visited[v] = True
        
        while stack:
            vertex = stack[-1]
            found = False
            for neighbor in adj[vertex]:  # Time: O(m) across all calls
                if not visited[neighbor]:
                    visited[neighbor] = True
                    stack.append(neighbor)
                    found = True
                    break
            if not found:
                finish_order.append(vertex)
                stack.pop()
    
    for i in range(n):     # Time: O(n) 
        if not visited[i]:
            dfs1(i)        # Time: O(n + m) 
    
    # Second DFS
    visited = [False] * n  # Space: O(n)
    scc_id = [-1] * n      # Space: O(n) - result
    scc_count = 0         
    
    # Create transposed adjacency list
    adj_t = [[] for _ in range(n)]
    for a, b in edges:
        adj_t[b].append(a)
    
    def dfs2(v, group_number):
        stack = [v]
        visited[v] = True
        scc_id[v] = group_number
        
        while stack:
            vertex = stack[-1]
            found = False
            for neighbor in adj_t[vertex]:  # Time: O(m) across all calls
                if not visited[neighbor]:
                    visited[neighbor] = True
                    scc_id[neighbor] = group_number
                    stack.append(neighbor)
                    found = True
                    break
            if not found:
                stack.pop()
    
    for i in range(n-1, -1, -1):  # Time: O(n) 
        v = finish_order[i]
        if not visited[v]:
            dfs2(v, scc_count)  # Time: O(n + m)
            scc_count += 1
    
    return scc_count, scc_id
def solve_group(n, edges):
    if n == 0:
        return -1
    if n == 1:
        return 0

    # Time: O(m + n) Space: O(n)
    scc_count, scc_id = kosaraju_scc(n, edges)
    if scc_count == 1:
        return 0

    # Time: O(m)  Space: O(n)
    has_incoming = [False] * scc_count  # Space: O(scc_count) <= O(n) 
    for a, b in edges:  # Time: O(m)
        if scc_id[a] != scc_id[b]:
            has_incoming[scc_id[b]] = True

    source_groups = []  # Space: O(scc_count) <= O(n) 
    for group in range(scc_count):  # Time : O(n) 
        if not has_incoming[group]:
            source_groups.append(group)
    
    if len(source_groups) != 1:
        return -1
    
    source_group = source_groups[0]

    # Time: O(m + n) , Space: O(n)
    visited_groups = [False] * scc_count  # Space: O(scc_count) <= O(n) 
    stack = [source_group]   # Space: O(scc_count) <= O(n) 
    visited_groups[source_group] = True
    reachable_count = 1

    while stack:  # Time: O(n) scc_count <= n
        current_group = stack.pop()
        for a, b in edges:  # O(m) per SCC, BUT each edge is processed ONCE across ALL SCCs
            if scc_id[a] == current_group and scc_id[a] != scc_id[b]:
                target_group = scc_id[b]
                if not visited_groups[target_group]:
                    visited_groups[target_group] = True
                    stack.append(target_group)
                    reachable_count += 1
                    # Why O(n + m) and not O(n * m)?
                    # - Each edge (a, b) is checked ONLY when current_group == scc_id[a].
                    # - Since each node a belongs to ONE SCC => each edge is processed ONCE across ALL iterations.
                    # - Total edge checks: O(m). Total SCC visits: O(n) => O(n + m).

    if reachable_count != scc_count:
        return -1

    # Time: O(n)
    min_forger = n
    for forger in range(n):  # O(n) time
        if scc_id[forger] == source_group:
            min_forger = min(min_forger, forger)

    return min_forger

G = int(raw_input())  
for _ in range(G):    
    line = raw_input().split()  
    n = int(line[0])  
    m = int(line[1]) 
    
    edges = []        # Space: O(m) - edge pairs
    for i in range(m):  # Time: O(m) 
        a = int(line[2 + 2*i])      
        b = int(line[2 + 2*i + 1])  
        edges.append((a, b))        
    
    result = solve_group(n, edges)  # Time: O(n + m) Space: O(n)
    print result  
    
# Yaroslav Kolesnik