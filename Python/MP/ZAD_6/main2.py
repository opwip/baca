#Yaroslav Kolesnik
def tarjan_scc(graph):
    # TIME: O(V + E) - Tarjan's algorithm visits each vertex once and each edge once
    # SPACE: O(V) - recursion stack, index arrays, and component storage
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
        # Each vertex is visited exactly once, each edge is examined exactly once
        index[v] = index_counter[0]
        lowlinks[v] = index_counter[0]
        index_counter[0] += 1
        stack.append(v)
        on_stack[v] = True
        
        # TIME: O(degree(v)) - we iterate through all outgoing edges of v
        for w in graph[v]:
            if index[w] == -1:
                strongconnect(w)
                lowlinks[v] = min(lowlinks[v], lowlinks[w])
            elif on_stack[w]:
                lowlinks[v] = min(lowlinks[v], index[w])
        
        # Root of SCC found - pop the entire component
        if lowlinks[v] == index[v]:
            component = []
            while True:
                w = stack.pop()
                on_stack[w] = False
                component.append(w)
                if w == v:
                    break
            sccs.append(component)
    
    # TIME: O(V + E) total - each vertex visited once, though this loop is O(V)
    # the recursive calls ensure each edge is processed exactly once
    for v in range(n):
        if index[v] == -1:
            strongconnect(v)
    
    return sccs

def solve_group(n, edges):
    # TIME: O(V + E) - dominated by Tarjan's algorithm and SCC reachability
    # SPACE: O(V + E) - graph storage, SCC data structures
    if n == 0:
        return -1
    if n == 1:
        return 0
    
    # Build adjacency list
    # TIME: O(E), SPACE: O(V + E)
    graph = [[] for _ in range(n)]
    for a, b in edges:
        graph[a].append(b)
    
    # Find SCCs using Tarjan's algorithm
    # TIME: O(V + E), SPACE: O(V)
    sccs = tarjan_scc(graph)
    
    # Create mapping from vertex to SCC index
    # TIME: O(V) - we visit each vertex once across all SCCs
    # SPACE: O(V)
    vertex_to_scc = [-1] * n
    for i, scc in enumerate(sccs):
        for v in scc:
            vertex_to_scc[v] = i
    
    # Build condensation graph
    # TIME: O(V + E) - might seem O(V*E)
    # Why not: total iterations = V (outer) + E (inner edges check)
    # SPACE: O(E) in worst case all edges are between different SCCs
    scc_count = len(sccs)
    scc_graph = [set() for _ in range(scc_count)]
    
    for u in range(n):  
        for v in graph[u]:  
            scc_u = vertex_to_scc[u]
            scc_v = vertex_to_scc[v]
            if scc_u != scc_v:
                scc_graph[scc_u].add(scc_v)
    
    # TIME: O(E) - total edges in condensation graph <= original edges
    for i in range(scc_count):
        scc_graph[i] = list(scc_graph[i])
    
    # Find which SCCs can reach all other SCCs
    def can_reach_all_sccs(start_scc):
        # TIME: O(SCC_V + SCC_E) where SCC_V <= V, SCC_E <= E
        # SPACE: O(SCC_V) <= O(V)
        visited = [False] * scc_count
        stack = [start_scc]
        visited[start_scc] = True
        count = 1
        
        while stack:
            curr = stack.pop()
            # Each SCC edge once per DFS call
            for neighbor in scc_graph[curr]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    stack.append(neighbor)
                    count += 1
        
        return count == scc_count
    
    for v in range(n):
        scc_id = vertex_to_scc[v]
        if can_reach_all_sccs(scc_id):
            return v
    
    return -1

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
    
#Yaroslav Kolesnik