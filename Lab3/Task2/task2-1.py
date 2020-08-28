import hashlib

def main():
    g = 2879
    n = 9929

    a = 9
    b = 6
    c = 5

    alice_id = 2791
    bob_id = 8507
    eve_id = 4617

    sig_b = (str(pow(g,a)) + str(pow(g, b)) + str(eve_id)).encode()

    m = hashlib.sha1()
    m.update(sig_b)

    print(m.hexdigest())

    return

if __name__ == "__main__":
    main()