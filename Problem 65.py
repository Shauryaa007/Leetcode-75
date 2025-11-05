class Solution(object):
    def maxProfit(self, prices, fee):
        #state
        zero=0
        one=0-prices[0]

        for i in range(1,len(prices)):
            newzero = max(zero,(one+prices[i]-fee)) # amt with one stock + price for today - fee ,zero stck from prev day
            newone = max(one,(zero-prices[i]))
            zero,one=newzero,newone
        return zero