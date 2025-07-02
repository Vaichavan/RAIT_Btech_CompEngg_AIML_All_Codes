from logic import FolKB, expr, fol_fc_ask

def main():
    # Create an array to hold clauses
    clauses = []

    # Add first-order logic clauses (rules and facts)
    clauses.append(expr("Criminal(x) <- (American(x) & Weapon(y) & Sells(x, y, z) & Hostile(z))"))
    clauses.append(expr("Enemy(Nono, America)"))
    clauses.append(expr("Owns(Nono, M1)"))
    clauses.append(expr("Missile(M1)"))
    clauses.append(expr("Missile(x) -> Weapon(x)"))
    clauses.append(expr("(Missile(x) & Owns(Nono, x)) -> Sells(West, x, Nono)"))
    clauses.append(expr("American(West)"))
    clauses.append(expr("Enemy(x, America) -> Hostile(x)"))

    # Create a first-order logic knowledge base (KB) with clauses
    KB = FolKB(clauses)

    # Add more rules and facts using tell()
    KB.tell(expr("Enemy(Jojo, America)"))

    # Get information from the knowledge base with forward chaining inference
    hostile = fol_fc_ask(KB, expr("Hostile(x)"))
    criminal = fol_fc_ask(KB, expr("Criminal(x)"))

    # Print answers
    print("Hostile?")
    print(list(hostile))

    print("\nCriminal?")
    print(list(criminal))

if __name__ == "__main__":
    main()
