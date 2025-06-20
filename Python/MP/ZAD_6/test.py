import time
import random
from collections import defaultdict

def generate_test_case(n, m, has_universal_sink=True):
    edges = []
    if has_universal_sink:
        universal_sink = random.randint(0, n-1)
        for i in range(n):
            if i != universal_sink:
                edges.append((i, universal_sink))
        remaining_edges = m - (n - 1)
        for _ in range(remaining_edges):
            a = random.randint(0, n-1)
            b = random.randint(0, n-1)
            if a != b:
                edges.append((a, b))
    else:
        for _ in range(m):
            a = random.randint(0, n-1)
            b = random.randint(0, n-1)
            if a != b:
                edges.append((a, b))
    random.shuffle(edges)
    edges_str = ' '.join("{} {}".format(a, b) for a, b in edges)
    return "{}\n{} {}\n{}".format(1, n, m, edges_str)  # Format: 1 test case, then n m, then edges

def mock_raw_input(test_case):
    input_lines = test_case.split('\n')
    def mocked_input():
        if not input_lines:
            return ""
        return input_lines.pop(0)
    return mocked_input

def run_test(test_case, desc):
    original_raw_input = __builtins__.raw_input
    __builtins__.raw_input = mock_raw_input(test_case)

    print("\nRunning:", desc)
    print("Test case:", test_case.replace('\n', ' | '))

    # Test solve_NO_ADJ
    start_time = time.time()
    try:
        solve_NO_ADJ()
    except Exception as e:
        print("Error in solve_NO_ADJ:", str(e))
    no_adj_time = time.time() - start_time

    # Reset for solve
    __builtins__.raw_input = mock_raw_input(test_case)

    # Test solve
    start_time = time.time()
    try:
        solve()
    except Exception as e:
        print("Error in solve:", str(e))
    adj_time = time.time() - start_time

    __builtins__.raw_input = original_raw_input
    print("{} | {:.6f} | {:.6f}".format(desc, no_adj_time, adj_time))

def main():
    # Manually formatted test cases
    test_cases = [
        ("2\n4 4 0 1 0 2 1 3 2 3\n3 2 1 0 2 0", "Original Test Cases"),
        (generate_test_case(10, 15, True), "Small Graph with Universal Sink"),
        (generate_test_case(10, 15, False), "Small Graph without Universal Sink"),
        (generate_test_case(100, 150, True), "Medium Graph with Universal Sink"),
        (generate_test_case(10000, 1000, False), "Medium Graph without Universal Sink"),
    ]

    print("Test Case Description | solve_NO_ADJ Time | solve Time")
    print("-----------------------------------------------------")
    for test_case, desc in test_cases:
        run_test(test_case, desc)

if __name__ == "__main__":
    # Define the functions here to ensure they're available
    def solve_NO_ADJ():
        G = int(raw_input())
        for _ in range(G):
            parts = raw_input().split()
            n = int(parts[0])
            m = int(parts[1])
            edges = parts[2:]
            
            visited = [False] * n
            last_finished = 0
            
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
                        for j in range(0, 2 * m, 2):
                            if j+1 >= len(edges):
                                continue
                            a = int(edges[j])
                            b = int(edges[j+1])
                            if a == node and not visited[b]:
                                stack.append((b, False))
            
            visited = [False] * n
            stack = [last_finished]
            visited[last_finished] = True
            count = 0
            while stack:
                node = stack.pop()
                count += 1
                for j in range(0, 2 * m, 2):
                    if j+1 >= len(edges):
                        continue
                    a = int(edges[j])
                    b = int(edges[j+1])
                    if a == node and not visited[b]:
                        visited[b] = True
                        stack.append(b)
            
            print(1 if count == n else -1)

    def solve():
        G = int(raw_input())
        for _ in range(G):
            parts = raw_input().split()
            n = int(parts[0])
            m = int(parts[1])
            edges = parts[2:]
            adj = [[] for _ in range(n)]
            index = 0
            for _ in range(m):
                if index+1 >= len(edges):
                    break
                a = int(edges[index])
                b = int(edges[index+1])
                adj[a].append(b)
                index += 2
            
            visited = [False] * n
            last_finished = 0
            
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
                        for neighbor in reversed(adj[node]):
                            if not visited[neighbor]:
                                stack.append((neighbor, False))
            
            visited = [False] * n
            stack = [last_finished]
            visited[last_finished] = True
            count = 0
            while stack:
                node = stack.pop()
                count += 1
                for neighbor in adj[node]:
                    if not visited[neighbor]:
                        visited[neighbor] = True
                        stack.append(neighbor)
            
            print(1 if count == n else -1)

    main()