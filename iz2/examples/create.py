import random
import sys

alphabet = 'abc:()'
with open(sys.argv[1], 'w') as file:
	for i in range(int(sys.argv[2])):
		file.write(alphabet[random.randint(0, len(alphabet) - 1)])
	
		
