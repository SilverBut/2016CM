# XDCTF Reverse 399

## Description

We have got a sample, named "2083236893". After some analyse, we think another similar sample might be captured at xxxx-xx-xx xx:xx:xx UTC.

*TODO: Add time of data*

**Hint 1**: Hash could NOT be used directly as the key.
**Hint 2**: Hash comes from several next blocks in the MAIN chain.

## Explaination

This program is actually a bitcoin miner, carrying some nodes before a certain point. After it has digged out two blocks, it would hash those two blocks as the key, and encrypt a AES cipher text. You are supposed to find it out, and, since it is nearly impossible to calculate two blocks in two days, you might want to search for some related info of those two blocks, and decrypt the cipher text.
