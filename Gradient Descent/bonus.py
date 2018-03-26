
import numpy as np
import matplotlib
import matplotlib.pyplot as plt

def display(x,indx):
    star = "************************\n"
    dash = "----------"
    print star + "=>>" + str(indx) + ".iteration\n" + star + "x:\n" + dash
    print x
    print dash + "\nf(x):\n" + dash + "\n" +str(f(x)) + "\n" + dash + "\nGradF:\n" + dash
    print gradF(x)

def gradF(x):
    grad = np.empty([2,1], dtype=float)
    grad[0] = (-400*x[0]*(x[1]-(x[0]**2))) - 2*(1-x[0])
    grad[1] = (200*(x[1]-(x[0]**2)))
    return grad

def iterF(inVect):
    currentX = inVect
    k = 0
    for k in range(25001):
        if (k%100 == 0):
            display(currentX,k)
        prevX = currentX
        currentX += (-1 * alpha) * gradF(prevX).reshape(2)
        funcValue = abs(f(currentX) - f(prevX))
        if (np.linalg.norm(currentX)<eps2) and (funcValue <= eps1):
            break
    return currentX

if __name__ == '__main__':
    alpha = 0.001
    eps1 = 1e-18
    eps2 = 1e-4
    f = lambda x : (100.0*((x[0]-(x[1]**2))**2)) - (1.0-(x[0])**2)
    inX = np.array([1.2,1.2],dtype=np.double)
    locMin = iterF(inX)
    print "----------\nLocal minimizer of function is \n", locMin
    axes = plt.gca()
    axes.set_xlim([-0.1,5])
    axes.set_ylim([-0.1,5])
    ax = plt.axes()
    ax.arrow(0, 0, locMin[0], locMin[1], head_width=0.05, head_length=0.1, fc='k', ec='k')
    plt.show()
