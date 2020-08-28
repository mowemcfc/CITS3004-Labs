import hashlib

def main():
    g = 2879
    n = 9929

    a = 9
    b = 6
    c = 5

    k = pow(g, a*b) % n

    k2 = pow(g, b*c) % n

    print(k)
    print(k2)

    return

if __name__ == "__main__":
    main()
