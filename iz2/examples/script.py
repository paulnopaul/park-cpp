import string
import random

file = open('neutral.txt', 'w')
letters = string.ascii_lowercase
count = 100
for _ in range(count):
    file.write(':)')
    file.write(''.join([letters[random.randint(0, len(letters) - 1)] for i in range(random.randint(0, 10))]))
    file.write(':(')
file.close()
