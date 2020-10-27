import string
import random

f = open('dirty_negative.txt', 'w')
letters = string.ascii_lowercase

for _ in range(20):
    f.write(''.join([letters[random.randint(0, len(letters) - 1)] for i in range(random.randint(0, 10))]))
    f.write(':(')

f.close()
