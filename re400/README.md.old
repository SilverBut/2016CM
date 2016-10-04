# XDCTF Reverse 399

## Description

We have got a sample, named "2083236893" at a few years later. After some analyse, we think another similar sample might be captured at xxxx-xx-xx xx:xx:xx UTC.

*TODO: Add time of data*

**Hint 1**: Hash could NOT be used directly as the key.
**Hint 2**: Hash comes from several next blocks in the MAIN chain.

## Explaination

This program is actually a bitcoin miner, carrying some nodes before a certain point. After it has digged out two blocks, it would hash several following blocks as the key, and encrypt a AES cipher text. You are supposed to find it out, and, since it is nearly impossible to calculate two blocks in two days, you might want to search for some related info of those two blocks, and decrypt the cipher text.

We assumed each 10 minutes a vaild block could be generated, so in order to maintain the blocks are, theoretically speaking, "unable to solve in 2 days", we think the program itself should contains not less than 1500 blocks (and related records), and the program should use the hash result of the following 1000 blocks as the key. The program will always believe the key it got is not orphan, and vaild for payment. 
