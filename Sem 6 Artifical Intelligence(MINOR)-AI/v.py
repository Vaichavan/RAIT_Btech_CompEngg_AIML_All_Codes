from collections import deque 
class WaterJugs: 
    def __init__(self): 
        self.a_max = 4 
        self.b_max = 3 
        self.target = 2 
 
    def goal_reached(self, jugs): 
        return jugs[0] == self.target 
 
    def next_moves(self, jugs): 
        a, b = jugs 
        return [ 
            (self.a_max, b), 
            (a, self.b_max), 
            (0, b), 
            (a, 0), 
            (a - min(a, self.b_max - b), b + min(a, self.b_max - b)), 
            (a + min(b, self.a_max - a), b - min(b, self.a_max - a)) 
        ] 
 
    def solve(self): 
        start = (0, 0) 
        q = deque([(start, [start])]) 
        seen = set() 
 
        while q: 
            state, trace = q.popleft() 
 
            if self.goal_reached(state): 
                return trace 
 
            if state in seen: 
                continue 
 
            seen.add(state) 
 
            for nxt in self.next_moves(state): 
                if nxt not in seen: 
                    q.append((nxt, trace + [nxt])) 
 
        return None 
 
if __name__ == "__main__": 
    wj = WaterJugs() 
    result = wj.solve() 
 
    if result: 
        print("Shortest Solution Path (6 Steps):") 
        for s in result: 
            print(f"Jug A: {s[0]} liters, Jug B: {s[1]} liters") 
    else: 
        print("No solution found.") 
