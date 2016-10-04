#!/usr/bin/python3

import requests
import json
from requests.adapters import HTTPAdapter

source_hash = "000000004a81b9aa469b11649996ecb0a452c16d1181e72f9f980850a1c5ecce"
root_hash = "000000000019d6689c085ae165831e934ff763ae46a2a6c172b3f1b60a8ce26f"
zero_hash = "0000000000000000000000000000000000000000000000000000000000000000"
info_url  = lambda node:"https://blockchain.info/rawblock/%s"%(node)

node_list = []
current_hash = source_hash

s = requests.Session()
s.mount('https://', HTTPAdapter(max_retries=10))

while True:
    if current_hash == zero_hash:
        break
    txt = s.get(info_url(current_hash)).text
    try:
        obj = json.loads(txt)
    except:
        print(txt)
        exit(-1)
    node_list.insert(0,obj)
    current_hash = obj["prev_block"]
    if (len(node_list)%100 == 0):
        print(len(node_list))

open('blocks.txt', 'w').write(json.dumps(node_list))
