#!/usr/bin/python
#coding=utf8
#加权随机
import random
#法一 区间法
def randomWeight(ads_weights):
    if len(ads_weights) == 0:
        return None
    total = 0
    all_total = []

    for w in ads_weights.values():
        total += w
        all_total.append(total)
    results = {  }
    for j in range(100000):
        randomid = random.random() * total
        for i in range(len(ads_weights)):
            if randomid < all_total[i]:
                break
        results[ads_weights.keys()[i]] = results.get(ads_weights.keys()[i], 0) + 1
    print results

#法二 产生权重数量的KEY，再随机选取
def randomChoice(weightsmap):
    """
    weightsmap = {"key":weight}
    """
    dist = []
    for x in weightsmap.keys():
        dist += weightsmap[x] * x
    
    results = {}
    for i in range(100000):
        wRndChoice = random.choice(dist)
        results[wRndChoice] = results.get(wRndChoice, 0) + 1

    print results




wMap = {'A' : 2,
        'B' : 1,
        'C' : 3,
        'D' : 5,
        'E' : 4,
        } 

randomWeight(wMap)
randomChoice(wMap)
