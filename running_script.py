import os
import sys
import time

program = sys.argv[1]
if(program not in os.listdir('./')):
    print 'Compiling.'
    os.system('g++ -std=c++0x -O3 ' + program + '.cc -o ' + program)
    print 'Compiling done.'

directory = './Datasets/cantrbry/'

L = 100
N = 10000
P = 0.73

for filename in os.listdir(directory):
    if(os.path.isdir(directory + filename)):
        continue
    start = time.clock()
    os.system('xxd -b -c1 '+ directory + filename + ' | cut -d" " -f2 | tr -d "\n" | ./' + program + ' ' + str(L) + ' ' + str(N) + ' ' + str(P) + ' > Output/out_' + filename + '.txt')
    print filename, '\t\t\t\t', time.clock() - start
