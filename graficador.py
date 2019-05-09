import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import imageio

data=np.loadtxt("intento.dat")

def plot_for_offset(ind):
    # Data for plotting
    t = np.arange(0.0, 1.01, 0.01)
    s = data[ind]
    time= np.array(range(201))*0.01

    fig, ax = plt.subplots(figsize=(6,6))
    ax.plot(t, s)
    ax.grid()
    ax.set(xlabel="Posicion [metros]", ylabel='U', title="Tiempo: "+"%.2f" % (time[ind], )+" segundos")

    # IMPORTANT ANIMATION CODE HERE
    # Used to keep the limits constant
    ax.set_ylim(-0.05,0.05)
    ax.set_xlim(0.0,1.0)

    # Used to return the plot as an image rray
    fig.canvas.draw()       # draw the canvas, cache the renderer
    image = np.frombuffer(fig.canvas.tostring_rgb(), dtype='uint8')
    image  = image.reshape(fig.canvas.get_width_height()[::-1] + (3,))
    return image

kwargs_write = {'fps':1.0, 'quantizer':'nq'}
imageio.mimsave('./movie.gif', [plot_for_offset(i) for i in range(201)], fps=10)
