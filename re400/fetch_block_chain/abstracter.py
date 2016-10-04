#!/usr/bin/python3
import struct

with open("blk00000.dat",'rb') as fd:
    nf = open("newblocks","wb")
    cnt=0
    while True:
        b = fd.read(8)
        if b:
            (label,size) = struct.unpack("<II", b)
            if not label == 0xd9b4bef9:
                print("Failed: Unexcepted token.")
                exit(-1)
            cnt+=1
            print("%d at %d"%(cnt,fd.tell()))
            nf.write(fd.read(80))
            fd.seek(size-80,1)
            if cnt==3400:
                break
        else:
            break
    nf.close()
