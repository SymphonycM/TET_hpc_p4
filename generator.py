from sys import argv
import random

script, n_input = argv
n_dataset = int(n_input)
rna = 'AGTC'
file = open('dataset.txt', 'w')

for rand in range(n_dataset):
    #print (random.choice(rna))
    file.write(random.choice(rna))

file.close()
