def merge(array, start, mean, end):
	l1 = []
	l2 = []
	merged = []
	for i in range(start, mean+1):
		l1.append(array[i])
	for i in range(mean+1, end+1):
		l2.append(array[i])
	print(l1)
	print(l2)
	while(len(l1) > 0 and len(l2) > 0):
		if(l1[0] < l2[0]):
			merged.append(l1.pop(0))
		else:	
			merged.append(l2.pop(0))
	if(len(l1) == 0 and len(l2) > 0):
		for each in l2:
			merged.append(each)
	elif(len(l2) == 0 and len(l1) > 0):
		for each in l1:
			merged.append(each)
	print(merged)
	for i in range(start, end+1):
		array[i] = merged[i - start]


def mergeSort(array, start, end):
	if(start < end):
		mean = start + ((end - start) // 2)
		mergeSort(array, start, mean)
		mergeSort(array, mean + 1, end)
		merge(array, start, mean, end)


array = input().split(" ")
for i in range(0, len(array)):
	array[i] = int(array[i])

mergeSort(array, 0, len(array)-1)
print(array)
