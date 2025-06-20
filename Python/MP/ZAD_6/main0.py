def tarjan_scc(graph):
    n = len(graph)
    if n == 0:
        return []
    
    index_counter = [0]
    stack = []
    lowlinks = [-1] * n
    index = [-1] * n
    on_stack = [False] * n
    sccs = []
    
    def strongconnect(v):
        index[v] = index_counter[0]
        lowlinks[v] = index_counter[0]
        index_counter[0] += 1
        stack.append(v)
        on_stack[v] = True
        
        for w in graph[v]:
            if index[w] == -1:
                strongconnect(w)
                lowlinks[v] = min(lowlinks[v], lowlinks[w])
            elif on_stack[w]:
                lowlinks[v] = min(lowlinks[v], index[w])
        
        if lowlinks[v] == index[v]:
            component = []
            while True:
                w = stack.pop()
                on_stack[w] = False
                component.append(w)
                if w == v:
                    break
            sccs.append(component)
    
    for v in range(n):
        if index[v] == -1:
            strongconnect(v)
    
    return sccs

def solve_group(n, edges):
    if n == 0:
        return -1
    if n == 1:
        return 0
    
    graph = [[] for _ in range(n)]
    for a, b in edges:
        graph[a].append(b)
    
    sccs = tarjan_scc(graph)
    
    vertex_to_scc = [-1] * n
    for i, scc in enumerate(sccs):
        for v in scc:
            vertex_to_scc[v] = i

    scc_count = len(sccs)
    scc_graph = [set() for _ in range(scc_count)]
    
    for u in range(n):
        for v in graph[u]:
            scc_u = vertex_to_scc[u]
            scc_v = vertex_to_scc[v]
            if scc_u != scc_v:
                scc_graph[scc_u].add(scc_v)
    
    for i in range(scc_count):
        scc_graph[i] = list(scc_graph[i])
    
    def can_reach_all_sccs(start_scc):
        visited = [False] * scc_count
        stack = [start_scc]
        visited[start_scc] = True
        count = 1
        
        while stack:
            curr = stack.pop()
            for neighbor in scc_graph[curr]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    stack.append(neighbor)
                    count += 1
        
        return count == scc_count
    
    # Check each vertex in order
    for v in range(n):
        scc_id = vertex_to_scc[v]
        if can_reach_all_sccs(scc_id):
            return v
    
    return -1

# Read input and solve
G = int(raw_input())
for _ in range(G):
    line = raw_input().strip()
    parts = line.split()
    n = int(parts[0])
    m = int(parts[1])
    
    edges = []
    for i in range(m):
        a = int(parts[2 + 2*i])
        b = int(parts[2 + 2*i + 1])
        edges.append((a, b))
    
    result = solve_group(n, edges)
    print result