class Pair:
    def __init__(self,n1,n2):
        self.sum = find_cube_sum(n1,n2)
        self.n1 = n1
        self.n2 = n2
    
    def __eq__(self, other):
        if self.n1 == other.n1 and self.n2 == other.n2:
            return True
        if self.n1 == other.n2 and self.n2 == other.n1:
            return True
        return False

    def __ne__(self,other):
        return not(self == other)

    def __lt__(self,other):
        return ((self.n1,self.n2) < (other.n1, other.n2))   

def find_cube_sum(num1, num2):
    return num1*num1*num1 + num2*num2*num2

def isSolution(pair, seen):
    # check that they arent the same numbers
    for i in seen:
        if pair == i:
            return False
        if pair.sum == i.sum:
            print("found! sum = {} pair1 ({},{}) pair2 ({},{}).".format(pair.sum,pair.n1,pair.n2,i.n1,i.n2))
            return True
    
    # check if the sum of the cubes are the same
        
def list_contains(the_list, item):
    for stuff in the_list:
        if stuff == item:
            return True
    return False

storage = []
for i in range(1,1000):
    for j in range(1, i):
        temp = Pair(i,j)
        
        if isSolution(temp,storage):
            exit()
        elif not list_contains(storage,temp):
            storage.append(temp)
            storage.sort()





