k = int(input())

tree = {}

for i in range(k):
    code = int(input()).split()
    tree[code[0]] = code[1:]

encryptedtext = input() # a binary sequence.
 
# recursive function to decrypt the text.
def decrypt(text):
    if text in tree:
        return decrypt(tree[text][0]) + decrypt(tree[text][1])
    else:
        return text

# decrypt encryptedtext
print(decrypt(encryptedtext))