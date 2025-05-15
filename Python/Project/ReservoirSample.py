import random
# A utility function 
# to print an array
def printArray(stream,n):
    for i in range(n):
        print(stream[i],end=" ")
    print()
 
# A function to randomly select
# k items from stream[0..n-1].
def selectKItems(stream, n, k):
        i=0; 
        # index for elements
        # in stream[]
         
        # reservoir[] is the output 
        # array. Initialize it with
        # first k elements from stream[]
        reservoir = [0]*k
        for i in range(k):
            reservoir[i] = stream[i]
         
        # Iterate from the (k+1)th
        # element to nth element
        while(i < n):
            # Pick a random index
            # from 0 to i.
            j = random.randrange(i+1)
             
            # If the randomly picked
            # index is smaller than k,
            # then replace the element
            # present at the index
            # with new element from stream
            if(j < k):
                reservoir[j] = stream[i]
            i+=1
         
        print("Following are k randomly selected items")
        printArray(reservoir, k)
     
# Driver Code
 
if __name__ == "__main__":
    stream = [i for i in range(100)]
    n = len(stream)
    k = 40
    selectKItems(stream, n, k)