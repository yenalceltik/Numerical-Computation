import gnuplotlib as gn
import numpy as np

in_file = open("function.txt","r")
func = in_file.readline()
lst = func.split(" ")
a = lst[0]
b = lst[1]
c = lst[2]

x = np.arange(50)
g1 = gn.gnuplotlib(title = "Quadratic fitting", _with="line")
g1.plot(a*x**2, b*x, c, legend= "Parabola")
