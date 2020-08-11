import sys

def main():

    for arg in sys.argv:
        print(arg)

    if(len(sys.argv) != 3):
        print("Incorrect # of arguments, exiting")
        exit()
    
    if(int(sys.argv[2]) not in range(-25,26)):
        print("Key value out of alphabetical range (1 < K < 26)")
        exit()

    message = sys.argv[1]
    key = int(sys.argv[2])

    cipher = ''.join(chr(ord(c) + key) for c in message)

    print(cipher)


if __name__ == "__main__":
    main()