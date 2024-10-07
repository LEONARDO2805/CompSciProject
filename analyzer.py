import time

from stringdata import get_data

def main():
    string1 = 'not_here'
    string2 = 'mzzzz'
    string3 = 'aaaaa'

    container = get_data()

    start = time.time()
    index = linear_search(container,string1)
    stop = time.time()
    print("time for linear search for not_here:", (stop-start) , "index found at:", index)

    start = time.time()
    index = binary_search(container, string1)
    stop = time.time()
    print("time for binary search for not_here:", (stop-start),"index found at:", index)

    start  = time.time()
    index = linear_search(container, string2)
    stop = time.time()
    print("time for linear search for mzzzz:", (stop-start),"index found at:", index)

    start = time.time()
    index = binary_search(container, string2)
    stop = time.time()
    print("time for binary search for mzzzz:", (stop-start),"index found at:", index)

    start = time.time()
    index = linear_search(container, string3)
    stop = time.time()
    print("time for linear search for aaaaa:", (stop-start),"index found at:", index)

    start = time.time()
    index = binary_search(container, string3)
    stop = time.time()
    print("time for linear search for aaaaa:",(stop-start),"index found at:", index)





def linear_search(container: tuple, element: str):
    for j in range(len(container)):
        if (container[j] == element):
            return j

    return -1

def binary_search(container: tuple,element:str):
    count =0
    high = int(len(container))
    low=0
    done = False
    prevMid=-1
    while (done==False):
        middle = low + (high-low)//2
        if(container[middle] == element):
            return middle
        elif(container[middle]<element):
            if(middle+1)<len(container):
                low = middle+1
            else:
                return False


        elif(container[middle]>element):
            if((middle-1)>=0):
                high = middle-1
            else:
                return False
        if(middle==prevMid):
            return -1
        prevMid= middle

    return -1





if __name__ == '__main__':
    main()