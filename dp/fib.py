def fib(n):
    if(n==1 or n==2):
        return 1
    return fib(n-1) + fib(n-2)

def fib_memo(n, dict = {}):
    if n==1 or n==2:
        return 1
    if dict.has_key(n):
        return dict[n]
    ans = fib_memo(n-1, dict) + fib_memo(n-2, dict)
    dict[n] = ans 
    return ans  

def fib_tab(n):
    if n==0:
        return 0
    if n==1:
        return 1
    tab = [0]*(n+1)
    tab[0] = 0
    tab[1] = 1
    for i in range(2,n+1,1):
        tab[i]=tab[i-1]+tab[i-2]
    return tab[n]

def fib_tab2(n):
    if n==0:
        return 0
    if n==1:
        return 1
    tab = [0]*(n+2)
    tab[0] = 0
    tab[1] = 1
    for i in range(0,n,1):
        tab[i+1]+=tab[i]
        tab[i+2]+=tab[i]
    return tab[n]

if __name__ == "__main__":
    for i in range(1,1000,100):
        print fib_memo(i)
    for i in range(1,1000,100):
        print fib_tab(i)
    for i in range(1,1000,100):
        print fib_tab2(i)
        '''
    for i in range(1,1000,100):
        print fib(i)
        '''
