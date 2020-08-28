import random

def modInverse(a, m) : 
    a = a % m; 
    for x in range(1, m) : 
        if ((a * x) % m == 1) : 
            return x 
    return 1

def main():
    p = int("F7E75FDC469067FFDC4E847C51F452DF", 16)
    q = int("E85CED54AF57E53E092113E62F436F4F", 16)
    e = int("0D88C3", 16)

    n = p * q

    phi = (p-1) * (q-1)

    d = modInverse(e, phi)

    print(d)

    return

if __name__ == "__main__":
    main()