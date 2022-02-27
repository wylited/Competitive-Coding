file = open("/home/wylited/Documents/coding/Competitive Programming/ccc/2015/s3.9.in")

ports = int(file.readline())
numPlanes = int(file.readline())

planes = []
total = 0

for i in range(ports + 1):
    planes.append(0)

j = 0
planesLeft = True
while j < numPlanes and planesLeft:
    incPlane = int(file.readline()) # read in the next plane

    while incPlane > 0 and planes[incPlane] > 0: # if plane is already in the port
        cport = planes[incPlane] # get the port it's in
        planes[incPlane] = planes[incPlane] + 1 # increment the port
        incPlane = incPlane - cport # move the plane to the next port

    if incPlane <= 0:
        planesLeft = False # if no planes left, stop

    else:
        planes[incPlane] = 1 # add plane to port
        total = total + 1 # if plane is added, add to total

    j = j + 1

print(total)
