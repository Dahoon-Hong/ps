
N = int(input())
ps = input()
qs = input()
pil = [int(x) for x in ps.split()][1:]
qil = [int(x) for x in qs.split()][1:]

pq_set = set()
pq_set.update(pil)
pq_set.update(qil)

if len(pq_set) == N:
    print('I become the guy.')
else:
    print('Oh, my keyboard!')