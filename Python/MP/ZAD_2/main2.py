class HistogramNode:
    def __init__(self, key):
        self.key = key
        self.count = 1
        self.left = None
        self.right = None

class HistogramTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if not self.root:
            self.root = HistogramNode(key)
            return "Added: " + str(key)
        
        def _insert(node, key):
            if node.key == key:
                return "Element already exists"
            if key < node.key:
                if node.left:
                    result = _insert(node.left, key)
                    if "Added" in result:
                        node.count += 1
                    return result
                node.left = HistogramNode(key)
                node.count += 1
                return "Added: " + str(key)
            else:
                if node.right:
                    result = _insert(node.right, key)
                    if "Added" in result:
                        node.count += 1
                    return result
                node.right = HistogramNode(key)
                node.count += 1
                return "Added: " + str(key)
        
        return _insert(self.root, key)

    def delete(self, key):
        def _min_node(node):
            current = node
            while current.left:
                current = current.left
            return current

        def _delete(node, key):
            if not node:
                return None, "Element does not exist"
            
            if key < node.key:
                node.left, result = _delete(node.left, key)
                if "Deleted" in result:
                    node.count -= 1
                return node, result
            elif key > node.key:
                node.right, result = _delete(node.right, key)
                if "Deleted" in result:
                    node.count -= 1
                return node, result
            else:
                if not node.left:
                    return node.right, "Deleted: " + str(key)
                elif not node.right:
                    return node.left, "Deleted: " + str(key)
                else:
                    successor = _min_node(node.right)
                    node.key = successor.key
                    node.right, _ = _delete(node.right, successor.key)
                    node.count -= 1
                    return node, "Deleted: " + str(key)
        
        self.root, result = _delete(self.root, key)
        return result

    def search(self, key):
        current = self.root
        while current:
            if key == current.key:
                return "YES"
            elif key < current.key:
                current = current.left
            else:
                current = current.right
        return "NO"

    def count_in_range(self, start, end):
        def count_range(node, start, end):
            if not node:
                return 0
            if node.key < start:
                return count_range(node.right, start, end)
            if node.key > end:
                return count_range(node.left, start, end)
            left_count = (node.left.count if node.left else 0) if start <= node.key else count_range(node.left, start, end)
            right_count = (node.right.count if node.right else 0) if node.key <= end else count_range(node.right, start, end)
            return left_count + right_count + (1 if start <= node.key <= end else 0)
        
        count = count_range(self.root, start, end)
        return "Elements in range [" + str(start) + ", " + str(end) + "]: " + str(count)

    def count_less_than(self, key):
        def count_less(node, key):
            if not node:
                return 0
            if node.key >= key:
                return count_less(node.left, key)
            return (node.left.count if node.left else 0) + 1 + count_less(node.right, key)
        
        count = count_less(self.root, key)
        return "Elements less than " + str(key) + ": " + str(count)

    def count_greater_than(self, key):
        def count_greater(node, key):
            if not node:
                return 0
            if node.key <= key:
                return count_greater(node.right, key)
            return (node.right.count if node.right else 0) + 1 + count_greater(node.left, key)
        
        count = count_greater(self.root, key)
        return "Elements greater than " + str(key) + ": " + str(count)

    def find_kth_smallest(self, k):
        def find_kth(node, k):
            if not node:
                return None
            left_count = node.left.count if node.left else 0
            if left_count + 1 == k:
                return node.key
            if k <= left_count:
                return find_kth(node.left, k)
            return find_kth(node.right, k - left_count - 1)
        
        result = find_kth(self.root, k)
        return str(result) if result is not None else "Invalid index"

    def inorder_traversal(self):
        result = []
        def inorder(node):
            if node:
                inorder(node.left)
                result.append(node.key)
                inorder(node.right)
        inorder(self.root)
        return "[ " + ", ".join(str(x) for x in result) + " ]"

def main():
    tree = HistogramTree()
    while True:
        cmd = raw_input().split()
        if cmd[0] == "EXIT":
            break
        if cmd[0] == "INSERT":
            print(tree.insert(int(cmd[1])))
        elif cmd[0] == "DELETE":
            print(tree.delete(int(cmd[1])))
        elif cmd[0] == "SEARCH":
            print(tree.search(int(cmd[1])))
        elif cmd[0] == "COUNT_RANGE":
            print(tree.count_in_range(int(cmd[1]), int(cmd[2])))
        elif cmd[0] == "COUNT_LESS":
            print(tree.count_less_than(int(cmd[1])))
        elif cmd[0] == "COUNT_GREATER":
            print(tree.count_greater_than(int(cmd[1])))
        elif cmd[0] == "FIND_KTH":
            print(tree.find_kth_smallest(int(cmd[1])))
        elif cmd[0] == "INORDER":
            print(tree.inorder_traversal())

if __name__ == "__main__":
    main()