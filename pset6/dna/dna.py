from sys import argv
from csv import reader


#ensures correct number of arguments
if (len(argv) != 3):
    print("usage: python dna.py data sample")


#dict for storage
peps = {}
#storage for strands we look for.
types = []

#opens csv table
with open(argv[1],'r') as file:
    data = reader(file)
    line = 0
    number = 0
    for l in data:
        if line == 0:
            for col in l:
                if col[2].islower() and col != 'name':
                    break
                if col == 'name':
                    continue
                else:
                    types.append(col)
            line += 1
        else:
            row_mark = 0
            for col in l:
                if row_mark == 0:
                    peps[col] = []
                    row_mark += 1
                else:
                    peps[l[0]].append(col)



#convert sample to string
samples = ""

with open(argv[2], 'r') as sample:
    for c in sample:
        samples = samples + c




#DNA STR GROUPS
dna = { "AGATC" : 0,
        "AATG" : 0,
        "TATC" : 0,
        "TTTTTTCT" : 0,
        "TCTAG" : 0,
        "GATA" : 0,
        "GAAA" : 0,
        "TCTG" : 0 }

#go through all the strs in dna
for keys in dna:
    #the longest run of sequnace
    longest = 0
    #the current run of sequances
    run = 0
    size = len(keys)
    #look through sample for longest
    i = 0
    while i < len(samples):
        hold = samples[i:(i + size)]
        if hold == keys:
            run += 1
            #ensure the code does not go outside len of samples **( I added =)**
            if ((i + size) <= len(samples)):
                i = i + size
            continue
        else: #only if there is no longer sequence match, check this.
            if run > longest:
                longest = run
                run = 0
            else: #if the number of sequence match is still smaller then longest, then make run zero.
                run = 0
        i += 1
    dna[keys] = longest

#see who it is
positive = True
person = ''
for key in peps:
    positive = True
    for entry in types:
        x = types.index(entry)
        test = dna.get(entry)
        can = int(peps.get(key)[x])
        if (test != can):
            positive = False
    if positive == True:
        person = key
        break
if person != '':
    print(person)
else:
    print("No match")