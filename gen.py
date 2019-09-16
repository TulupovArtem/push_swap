import random
import sys

a = list(range(int(sys.argv[1])))
random.shuffle(a)
for n in a:
    print n,

print
