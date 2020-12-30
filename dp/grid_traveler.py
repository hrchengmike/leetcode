import numpy as np 
def grid_traveler(m, n):
    if(m==1 and n==1):
        return 1
    if(m==0 or n==0):
        return 0
    return grid_traveler(m-1, n)+grid_traveler(m, n-1)

def grid_traveler_memo(m, n, dict = {}):
    if(m==1 and n==1):
        return 1
    if(m==0 or n==0):
        return 0
    if m > n:
        m, n = n, m
    if dict.has_key((m,n)):
        return dict[(m,n)]
    ans = grid_traveler_memo(m-1, n)+grid_traveler_memo(m, n-1)
    dict[(m,n)] = ans
    return ans

def grid_traveler_tab(m, n):
    tab = np.zeros((m+1,n+1))
    for r in range(1,m+1,1):
        for c in range(1,n+1,1):
            if r==1 and c==1:
                tab[r,c] = 1
            else:
                tab[r,c] = tab[r-1, c]+tab[r, c-1]
    return tab[m,n]

if __name__ == "__main__":
    for i in range(1,20,1):
        print grid_traveler_memo(i, i)
    for i in range(1,20,1):
        print grid_traveler_tab(i, i) 
    '''
    for i in range(1,20,1):
        print grid_traveler(i, i)  
    ''' 
