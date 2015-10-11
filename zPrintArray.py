#/usr/bin/python
#coding=utf8
#z型遍历矩阵

def zPrintArr(arr):
    arr_len = len(arr[0])
    tmprow = row = 0;
    tmpcol = col = arr_len - 1
    result = []

    down = False
    while not (tmprow == arr_len - 1 and tmpcol == 0):
        if col > arr_len - 1:
            tmpcol -= 1
            col = tmpcol
            row = 0
        elif col < 0:
            tmprow += 1
            row = tmprow
            col = 0
            down = False
        else:
            result.append(arr[row][col])
            if down:
                row += 1
                col -= 1
            else:
                row += 1
                col += 1
        if row > arr_len - 1:
            tmprow += 1
            row = tmprow
            col = 0
    result.append(arr[arr_len - 1][0])
    return result

#Arr =[[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25]]
#Arr = [[1]]
Arr = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
l = zPrintArr(Arr)
for x in Arr:
    for y in x:
        print "%s" % y,
    print ""
for i in l:
    print "%s " % i,




