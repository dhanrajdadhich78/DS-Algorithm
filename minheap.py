class minHeap():
    def __init__(self):
        self.heap = []
        self._size = 0

    def top(self):
        return self.heap[0]

    def size(self):
        return self._size

    def push(self, element):
        self.heap.append(element)
        self._size += 1
        currIndex = int(len(self.heap) - 1)

        while(True):
            if currIndex == 0:
                break
            parentIndex = int((currIndex - 1) / 2)
            if self.heap[parentIndex] <= self.heap[currIndex]:
                break
            self.heap[parentIndex], self.heap[currIndex] = self.heap[currIndex], self.heap[parentIndex]
            currIndex = parentIndex

    def pop(self):
        self.heap[0] = self.heap[-1]
        self.heap.pop()
        self._size -= 1
        currIndex = 0
        next = True

        while(next):
            next = False
            minIndex = currIndex
            child = int(2 * currIndex + 1)

            if child < len(self.heap) and self.heap[minIndex] > self.heap[child]:
                minIndex = child
            child += 1
            if child < len(self.heap) and self.heap[minIndex] > self.heap[child]:
                minIndex = child
            if minIndex != currIndex:
                next = True
                self.heap[currIndex], self.heap[minIndex] = self.heap[minIndex], self.heap[currIndex]
                currIndex = minIndex
