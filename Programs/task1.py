import random
import sys

def f(point): 
    return (1.5 - point[0] + point[0] * point[1]) ** 2 + (2.25 - point[0] + point[0] * point[1] * point[1]) ** 2 + (2.625 - point[0] + point[0] * point[1] * point[1] * point[1]) ** 2

def neighbor(point, z):
    v = (random.uniform(-z, z), random.uniform(-z, z))
    return (point[0] + v[0], point[1] + v[1])

def RHC(sp, p, z, seed, total_solutions):
    random.seed(seed)
    sol = f(sp)
    solutions = total_solutions
    neighbors = []
    neighbors_f = []
    for num in range(p):
        newNeighbor = neighbor(sp, z)
        newNeighbor_f = f(newNeighbor)
        neighbors.append(newNeighbor)
        neighbors_f.append(newNeighbor_f)

    best_solution = min(neighbors_f)

    if best_solution < sol:
        sp = neighbors[neighbors_f.index(best_solution)]
        sol = best_solution
        solutions += p
        return RHC(sp, p, z, seed, solutions)
    else:
        return (sp), sol, total_solutions




if __name__ == "__main__":
    sys.setrecursionlimit(8000)
    sp = [(3, 1), (1, 1), (-1, 4), (4, -3)]
    seed=450
    for p in sp:
        print(f"Starting Point: {p}")
        print(f"p=50, z = 0.05, seed = {seed}")
        best_solution, best_f, total_solutions = RHC(p, 50, 0.05, seed, 1)
        print(f"Local Min: {best_solution} \nf(x, y): {best_f} \nSolutions: {total_solutions} \n")

        print(f"Starting Point: {p}")
        print(f"p=50, z = 0.2, seed = {seed}")
        best_solution, best_f, total_solutions = RHC(p, 50, 0.2, seed, 1)
        print(f"Local Min: {best_solution} \nf(x, y): {best_f} \nSolutions: {total_solutions} \n")

        print(f"Starting Point: {p}")
        print(f"p=350, z = 0.05, seed = {seed}")
        best_solution, best_f, total_solutions = RHC(p, 350, 0.05, seed, 1)
        print(f"Local Min: {best_solution} \nf(x, y): {best_f} \nSolutions: {total_solutions} \n")

        print(f"Starting Point: {p}")
        print(f"p=350, z = 0.2, seed = {seed}")
        best_solution, best_f, total_solutions = RHC(p, 350, 0.2, seed, 1)
        print(f"Local Min: {best_solution} \nf(x, y): {best_f} \nSolutions: {total_solutions} \n")