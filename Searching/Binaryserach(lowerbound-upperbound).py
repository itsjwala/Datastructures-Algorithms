def search(a,key,lower=None):

	low = 0
	high = len(a)-1
	mid = None

	while low<=high:
		mid = (low+high)//2

		if(a[mid] == key and lower == None):
			return mid
			
		if( key < a[mid] or (key == a[mid] and lower ==True)):
			high = mid - 1
		else:
			low = mid + 1 

	return low


a = [1,1,1,1,1,1,]



print(search(a,1,lower = False))

