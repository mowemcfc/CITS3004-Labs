from hashlib import sha256
x = 5
y = 0  # start from 0
while sha256(str(x*y).encode()).hexdigest()[:6] != "000000":
    y += 1

print(sha256(str(x*y).encode()).hexdigest())
print('solution value is {}'.format(y))