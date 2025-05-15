class AdjecentHanoi:
    def __init__(self, n):
        self.n = n
        self.towers = [list(range(n, 0, -1)), [], []]
        self.moves = []

    def move_left(self, tower):
        if tower == 0:
            # Nigdy nie będzie takiego prypadku naprawde
            raise ValueError("Cannot move left from tower 0")
        disk = self.towers[tower].pop()
        self.towers[tower - 1].append(disk)
        self.moves.append((tower, tower - 1))

    def move_right(self, tower):
        if tower == 2:
            # Nigdy nie będzie takiego prypadku naprawde
            raise ValueError("Cannot move right from tower 2")
        
        disk = self.towers[tower].pop()
        self.towers[tower + 1].append(disk)
        self.moves.append((tower, tower + 1))
    

    def solve(self):
        self._solve_hanoi(self.n, 0, 2, 1)

    def _solve_hanoi(self, n, from_tower, to_tower, aux_tower):
        if n == 1:
            if from_tower < to_tower:
                for _ in range(to_tower - from_tower):
                    self.move_right(from_tower + _)
            else:
                for _ in range(from_tower - to_tower):
                    self.move_left(from_tower - _)
        else:
            self._solve_hanoi(n - 1, from_tower, aux_tower, to_tower)
            if from_tower < to_tower:
                for _ in range(to_tower - from_tower):
                    self.move_right(from_tower + _)
            else:
                for _ in range(from_tower - to_tower):
                    self.move_left(from_tower - _)
            self._solve_hanoi(n - 1, aux_tower, to_tower, from_tower)
            
    
    def display(self):
        for i in range(3):
            print(f'Tower {i}: {self.towers[i]}')
        print('Moves:', self.moves)


tow = AdjecentHanoi(10)
tow.display()
tow.solve()
tow.display()
        