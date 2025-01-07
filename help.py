MAX_EDGE = 3
cube = [[[0 for k in range(MAX_EDGE)] for j in range(MAX_EDGE)] for i in range(MAX_EDGE)]
for i in range(MAX_EDGE):
    for j in range(MAX_EDGE):
        for k in range(MAX_EDGE):
            cube[i][j][k] = 0
edge = 2
for i in range(edge):
    for j in range(edge):
        for k in range(edge):
            cube[i][j][k] = int(input())
def intersection(start_1,start_2,start_3, size_1,size_2,size_3):
    sum = 0
    for i in range(start_1,  start_1+size_1+1):
        for j in range(start_2,start_2+size_2+1):
            for k in range(start_3, start_3+size_3+1):
                print(i,j,k)
                try:
                    sum+=cube[i][j][k]
                except IndexError:
                    pass
    print(sum)

while (True):
    intersection(int(input()),int(input()),int(input()),int(input()),int(input()),int(input()))
    
    print(cube)