import hashlib

seed = 9932305
tohash = "00852"

# Hash the to hash value and print it
hashed = hashlib.sha256(str(tohash).encode()).hexdigest()
print(hashed)

x = input()
print(hashlib.sha256(x.encode()).hexdigest())